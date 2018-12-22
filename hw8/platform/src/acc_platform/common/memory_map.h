#pragma once

enum ePoolFunction {is_maximum = 0, is_average = 1, is_minimum = 2};

/* The following width and size are all specified in bytes */

#define BUS_WIDTH 4

#define SHARED_MEMORY_ADDRESS 0x00000000
#define SHARED_MEMORY_SIZE    0x20000000

/* Accelerator address scope */
#define ACC_START_ADDRESS     0x40000000
#define ACC_END_ADDRESS       0x47FFFFFF

/* Accelerator address start */
#define POOL_DMA_BASE_ADDRESS 0x40000000
#define DMA_CHANNEL_NUM       16

#define POOL_BASE_ADDRESS     0x40100000
#define POOL_REG_NUM          14

#define POOL_BUFFER_ADDRESS   0x40200000
#define POOL_BUFFER_SIZE      0x00100000

#define GLOBAL_BUFFER_ADDRESS 0x44000000
#define GLOBAL_BUFFER_SIZE    0x04000000
/* Accelerator address end */

#define STACK_RAM_END_ADDRESS 0xFFFFFFFF
#define STACK_RAM_SIZE        0x00100000
