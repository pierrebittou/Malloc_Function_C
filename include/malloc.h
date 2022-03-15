/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc p.b
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct metadata {
    bool is_free;
    unsigned long size;
    void *data_begin;

    struct metadata *next;
}metadata_t;

extern metadata_t *head;

// malloc functions :
void *malloc(size_t size);
metadata_t *last_node(void);
int power_of_two(int a);

//free functions :
void free(void *ptr);
void merge_free_blocks();
void merger(metadata_t *node);

//calloc functions :
void *calloc(size_t nmemb, size_t size);
void *memeset_calloc(void *ptr, int size);

//realloc functions :
void *realloc(void *ptr, size_t size);

//realloc array fonction
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif //MALLOC_MALLOC_H
