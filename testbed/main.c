#include <stdio.h>

#include "memora/uapi_mm.h"

int
main(void)
{
   mm_init();
   printf("[INFO]: Page Size = %lu\n", get_system_page_size());
   void *addr1 = mm_get_new_vm_page_from_kernel(1);
   void *addr2 = mm_get_new_vm_page_from_kernel(1);
   printf("[TEST]: Page 1 = %p, Page 2 = %p\n", addr1, addr2);
   return 0;
}

