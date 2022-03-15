/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** free.c
*/

#include "malloc.h"

int power_of_two(int a)
{
    int res = 2;
    while (a > res)
        res *= 2;
    return res;
}

void merger(metadata_t *node)
{
    node->size = node->size + node->next->size + sizeof(metadata_t);
    if (node->next->next != NULL)
        node->next = node->next->next;
    else
        node->next = NULL;
}

void merge_free_blocks(void)
{
    metadata_t *tmp = head;

    for (; tmp != NULL && tmp->next != NULL; tmp = tmp->next) {
        if (tmp->is_free == true && tmp->next->is_free == true)
            merger(tmp);
    }
}

void free(void *ptr)
{
    metadata_t *tmp = head;

    while (tmp != NULL) {
        if (tmp->data_begin == ptr)
            tmp->is_free = true;
        tmp = tmp->next;
    }
    merge_free_blocks();
}
