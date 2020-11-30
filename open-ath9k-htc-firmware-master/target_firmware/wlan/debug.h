#include "ah.h" // Types

#ifndef _DEBUG_H_
#define _DEBUG_H_

#define DBG_MEM_SIZE 2700

a_uint16_t dbg_mem_store(a_uint8_t* buffer, a_uint16_t size);
a_uint16_t dbg_mem_read(a_uint8_t* buffer, a_uint16_t size);

#endif /* _DEBUG_H_ */