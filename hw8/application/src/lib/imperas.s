/* This code is part of libimperas.a, which is originally developed */
/* by Imperas.org. I borrow it because including whole library is   */
/* compiled with preceding underline function names                 */

.globl impProcessorId;
.globl _impProcessorId;
#.type _impProcessorId,@function;
#.align 4
impProcessorId:
_impProcessorId:
   addi sp,sp,0xffffffec
   addi sp,sp,0x14
   jr ra
