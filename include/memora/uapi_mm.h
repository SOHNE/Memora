#ifndef UAPI_MM_H
#define UAPI_MM_H

#include <stdio.h>


/** Initializes the memory management system. */
void mm_init();

/** Get the system page size */
size_t get_system_page_size();

/**
 * Requests a new virtual memory page from the kernel.
 * 
 * Input:
 *  units The number of pages to be allocated.
 * 
 * Output:
 *  void *: A pointer to the allocated memory page.
 */
void *mm_get_new_vm_page_from_kernel(int units);

/**
 * Returns a virtual memory page back to the kernel.
 * 
 * Input:
 *  void *vm_page: A pointer to the memory page to be returned.
 *  int units: The number of pages that the pointer represents.
 */
void m_return_vm_page_to_kernel(void *vm_page, int units);

#endif // UAPI_MM_H

