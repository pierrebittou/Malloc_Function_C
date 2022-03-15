/*
** EPITECH PROJECT, 2021
** realloc.c
** File description:
** realloc
*/

#include "malloc.h"

void *destroy_and_new(void *ptr, size_t size)
{
    free(ptr);
    return malloc(size);
}

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    return destroy_and_new(ptr, size);
}