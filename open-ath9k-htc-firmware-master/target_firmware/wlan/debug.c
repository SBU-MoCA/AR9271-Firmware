#include "debug.h"
#include "ah_internal.h"

// Inspired by the modwifi print system
// http://modwifi.bitbucket.org/
struct {
    a_uint8_t data[DBG_MEM_SIZE];
    a_uint16_t size;
    a_uint16_t read_ptr;
} dbg_memory = {"", 0, 0};

a_uint16_t dbg_mem_store(a_uint8_t* buffer, a_uint16_t size) {
    a_uint16_t max_size = AH_MIN(DBG_MEM_SIZE, size);

    A_MEMSET(dbg_memory.data, 0, DBG_MEM_SIZE);
    A_MEMCPY(dbg_memory.data, buffer, max_size);
    dbg_memory.size = max_size;
    dbg_memory.read_ptr = 0;

    return max_size;
}

a_uint16_t dbg_mem_read(a_uint8_t* buffer, a_uint16_t size) {
    if(dbg_memory.read_ptr >= dbg_memory.size)
        return 0;

    a_uint16_t size_to_read = AH_MIN(size, dbg_memory.size);
    A_MEMCPY(buffer, dbg_memory.data + dbg_memory.read_ptr, size_to_read);
    dbg_memory.read_ptr += size_to_read;

    return size_to_read;
}