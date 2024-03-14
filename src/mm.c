#include "memora/uapi_mm.h"

static size_t SYSTEM_PAGE_SIZE = 0;

void
mm_init()
{
    SYSTEM_PAGE_SIZE = getpagesize();
}

size_t
get_system_page_size()
{
    return SYSTEM_PAGE_SIZE;
}

void *
mm_get_new_vm_page_from_kernel(int units)
{
    char *vm_page = (char *)mmap(
            0,
            units * SYSTEM_PAGE_SIZE,
            PROT_READ | PROT_WRITE | PROT_EXEC,
            MAP_ANON | MAP_PRIVATE,
            0, 0);

    if (vm_page == MAP_FAILED)
    {
        printf("[ERROR]: VM Page allocation failed!\n");
        return NULL;
    }

    memset(vm_page, 0, units * SYSTEM_PAGE_SIZE);
    return (void *) vm_page;
}

void
mm_return_vm_page_to_kernel(void *vm_page, int units)
{
    if (munmap(vm_page, units * SYSTEM_PAGE_SIZE))
    {
        printf("[ERROR]: Could not munmap VM Page to kernel!\n");
    }
}

