/*
** EPITECH PROJECT, 2021
** reallocarray.c
** File description:
** reallocarray function reproduction
*/

#include "malloc.h"
#include <limits.h>


int check_overflow(size_t nmemb, size_t size)
{
    if (nmemb > INT_MAX / size)
        return -1;
    return 1;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if (nmemb <= 0 || size <= 0)
        return NULL;
    if (check_overflow(nmemb, size) == 1)
        return realloc(ptr, (nmemb * size));
    return NULL;
}