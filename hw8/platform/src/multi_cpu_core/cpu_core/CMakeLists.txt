set(IMP_LIB_INC ${OVP_ROOT}/ImperasLib/source/ovpworld.org)
set(MODEL_SUPPORT_DIR ${IMP_LIB_INC}/modelSupport)

set(TLM_MEM    ${IMP_LIB_INC}/memory/ram/1.0/tlm2.0)
set(TLM_MMC    ${MODEL_SUPPORT_DIR}/tlmMMC/1.0/tlm2.0)
set(TLM_PERIPH ${MODEL_SUPPORT_DIR}/tlmPeripheral/1.0/tlm2.0)
set(TLM_PROC   ${MODEL_SUPPORT_DIR}/tlmProcessor/1.0/tlm2.0)
set(TLM_PLAT   ${MODEL_SUPPORT_DIR}/tlmPlatform/1.0/tlm2.0)
set(IMP_PUBLIC_DIR ${OVP_ROOT}/ImpPublic/source/host/)

set(tlm_support_src
    ${TLM_MEM}/tlmMemory.cpp
    ${TLM_MMC}/tlmMmc.cpp
    ${TLM_PERIPH}/tlmPeripheral.cpp
    ${TLM_PROC}/tlmProcessor.cpp
    ${TLM_PLAT}/tlmPlatform.cpp
    ${IMP_PUBLIC_DIR}/icm/icmCpuManager.cpp
)

file(GLOB src *.cpp)
add_library(cpu_core_lib STATIC ${src} ${tlm_support_src})
