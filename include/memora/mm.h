#ifndef MEMORA_MM_H
#define MEMORA_MM_H

#include <stdint.h> // uint32_t

#define MM_MAX_STRUCT_NAME 32

typedef struct vm_page_family_t
{
  char struct_name[MM_MAX_STRUCT_NAME];
  uint32_t struct_size;
} vm_page_family_t;

typedef struct vm_page_for_families_t
{
  struct vm_page_for_families_ *next;
  vm_page_family_t vm_page_family[0];
} vm_page_for_families_t;

#define MAX_FAMILIES_PER_VM_PAGE                                               \
  (SYSTEM_PAGE_SIZE - sizeof(vm_page_for_families_t *)) /                      \
      sizeof(vm_page_family_t)

#endif // MEMORA_MM_H
