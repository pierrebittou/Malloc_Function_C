/*
** EPITECH PROJECT, 2021
** calloc.c
** File description:
** calloc function
*/

#include "malloc.h"

void *memeset_calloc(void *ptr, int size)
{
    unsigned char *cast = ptr;

    for (int i = 0; i < size; ++i) {
        *cast = 0;
        cast++;
    }
    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
    void *ptr_return;
    int total_size;

    if (nmemb <= 0 || size <= 0)
        return NULL;
    total_size = nmemb * (power_of_two(size));
    ptr_return = malloc(total_size);
    if (ptr_return != NULL)
        ptr_return = memeset_calloc(ptr_return, total_size);
    return ptr_return;
}