#ifndef UAPI_MM_H
#define UAPI_MM_H

#include <stdio.h>
#include <memory.h>
#include <unistd.h>     // For getpagesize
#include <sys/mman.h>   // For mmap



// Initializes the memory management system
void mm_init();

// Returns the system's page size
size_t get_system_page_size();

// Requests a new virtual memory page from the kernel.
// The 'units' parameter specifies the number of pages to be allocated.
void *mm_get_new_vm_page_from_kernel(int units);

// Returns a virtual memory page back to the kernel.
// The 'vm_page' parameter is a pointer to the memory page to be returned,
// and 'units' is the number of pages that the pointer represents.
void mm_return_vm_page_to_kernel(void *vm_page, int units);

#endif // UAPI_MM_H

