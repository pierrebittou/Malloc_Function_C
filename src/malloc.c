/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc p.b
*/

#include "malloc.h"

metadata_t *head = NULL;

metadata_t *last_node_finder(void)
{
    metadata_t *tmp = head;
    for (; tmp->next != NULL ; tmp = tmp->next);
    return tmp;
}

void *new_alloc_needed(size_t size)
{
    int pages_number = 2;
    metadata_t *last_node = last_node_finder();
    metadata_t *new_node;
    for (; (long unsigned int)(pages_number * 4096) < size + sizeof(metadata_t);
    pages_number = pages_number * 2);
    new_node = sbrk(pages_number * 4096);
    if (new_node == (void *)-1)
        return NULL;
    last_node->size += pages_number * 4096;
    new_node = last_node->data_begin + size;
    new_node->is_free = true;
    new_node->size = last_node->size - (size + sizeof(metadata_t));
    new_node->data_begin = new_node + sizeof(metadata_t);
    new_node->next = NULL;
    last_node->next = new_node;
    last_node->is_free = false;
    last_node->size = size;
    return last_node->data_begin;
}

void *free_space_fill(size_t size)
{
    metadata_t *tmp = head;
    metadata_t *new_metadata = NULL;
    while (tmp != NULL) {
        if (tmp->is_free == true && tmp->size > size + sizeof(metadata_t)) {
            new_metadata = tmp->data_begin + size;
            new_metadata->size = tmp->size - (size + sizeof(metadata_t));
            new_metadata->data_begin = new_metadata + sizeof(metadata_t);
            new_metadata->is_free = true;
            new_metadata->next = tmp->next;
            tmp->size = size;
            tmp->is_free = false;
            tmp->next = new_metadata;
            tmp->data_begin = tmp + sizeof(metadata_t);
            return tmp->data_begin;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void *init_metalist(size_t size)
{
    int pages_number = 2;
    metadata_t *secondnode = NULL;

    for (;
    (long unsigned int)(pages_number * 4096) < size +(sizeof(metadata_t) * 2);
    pages_number = pages_number * 2);
    head = sbrk(pages_number * 4096);
    if (head == (void *)-1)
        return NULL;
    head->data_begin = head + sizeof(metadata_t);
    head->size = size;
    head->is_free = false;
    head->next = secondnode;
    secondnode = head->data_begin + size;
    secondnode->size =
            (pages_number * 4096) - ((sizeof(metadata_t) * 2) + size);
    secondnode->data_begin = secondnode + sizeof(metadata_t);
    secondnode->is_free = true;
    secondnode->next = NULL;
    return head->data_begin;
}

void *malloc(size_t size)
{
    void *ptr_to_data = NULL;

    if (size == 0)
        return NULL;
    size = power_of_two(size);
    if (head == NULL)
        return init_metalist(size);
    ptr_to_data = free_space_fill(size);
    if (ptr_to_data != NULL)
        return ptr_to_data;
    ptr_to_data = new_alloc_needed(size);
    return ptr_to_data;
}