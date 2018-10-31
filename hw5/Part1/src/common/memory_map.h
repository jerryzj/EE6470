#pragma once

enum ePoolFunction {is_maximum = 0, is_average = 1, is_minimum = 2};

/* The following width and size are all specified in bytes */

#define BUS_WIDTH 4

#define POOL_DMA_BASE_ADDRESS 0x40000000
#define DMA_CHANNEL_NUM       16

#define POOL_BASE_ADDRESS     0x40100000
#define POOL_REG_NUM          14

#define POOL_BUFFER_ADDRESS   0x40200000
#define POOL_BUFFER_SIZE      0x00100000

#define GLOBAL_BUFFER_ADDRESS 0x44000000
#define GLOBAL_BUFFER_SIZE    0x00400000
