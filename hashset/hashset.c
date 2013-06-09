/* -*- Mode: C; tab-width: 4; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
 *     Copyright 2012 Couchbase, Inc.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include <stdio.h>
#include "hashset.h"
#include <stdio.h>
#include <assert.h>

static const unsigned int prime_1 = 73;
static const unsigned int prime_2 = 5009;

hashset_t hashset_create()
{
    hashset_t set = calloc(1, sizeof(struct hashset_st));

    if (set == NULL) {
        return NULL;
    }
    set->nbits = 3;
    set->capacity = (size_t)(1 << set->nbits);
    set->mask = set->capacity - 1;
    set->items = calloc(set->capacity, sizeof(size_t));
    if (set->items == NULL) {
        hashset_destroy(set);
        return NULL;
    }
    set->nitems = 0;
    return set;
}

size_t hashset_num_items(hashset_t set)
{
    return set->nitems;
}

void hashset_destroy(hashset_t set)
{
    if (set) {
        free(set->items);
    }
    free(set);
}

static int hashset_add_member(hashset_t set, char *item)
{
    size_t ii;

    if (item == NULL) {
        return -1;
    }

    ii = set->mask & (prime_1 * ((size_t)item));

    while ((size_t)set->items[ii] != 0 && (size_t)set->items[ii] != 1) {
        if (strcmp(set->items[ii], item) == 0) {
            return 0;
        } else {
            /* search free slot */
            ii = set->mask & (ii + prime_2);
        }
    }
    set->nitems++;
    set->items[ii] = item;
    return 1;
}

static void maybe_rehash(hashset_t set)
{
    char **old_items;
    size_t old_capacity, ii;


    if ((float)set->nitems >= (size_t)((double)set->capacity * 0.85)) {
        old_items = set->items;
        old_capacity = set->capacity;
        set->nbits++;
        set->capacity = (size_t)(1 << set->nbits);
        set->mask = set->capacity - 1;
        set->items = calloc(set->capacity, sizeof(char*));
        set->nitems = 0;
        assert(set->items);
        for (ii = 0; ii < old_capacity; ii++) {
            hashset_add_member(set, (void *)old_items[ii]);
        }
        free(old_items);
    }
}

int hashset_add(hashset_t set, char *item)
{
    int rv = hashset_add_member(set, item);
    maybe_rehash(set);
    return rv;
}

int hashset_remove(hashset_t set, char *item)
{
    size_t ii = set->mask & (prime_1 * ((size_t)item));

    while (set->items[ii] != 0) {
        if (set->items[ii] == item) {
            set->items[ii] = (char*)1;
            set->nitems--;
            return 1;
        } else {
            ii = set->mask & (ii + prime_2);
        }
    }
    return 0;
}

int hashset_is_member(hashset_t set, char *item)
{
    size_t ii = set->mask & (prime_1 * ((size_t)item));

    while (set->items[ii] != 0) {
        if (set->items[ii] == item) {
            return 1;
        } else {
            ii = set->mask & (ii + prime_2);
        }
    }
    return 0;
}

/*
 * added by Markus Mohanty
 */
void hashset_union(hashset_t set, hashset_t toJoin)
{

    int len_toJoin = sizeof(set->items);    
    
    int i;
    for(i = 0;i<=len_toJoin;i++)
    {
        char* value = toJoin->items[i];
        if(value !=0)
        {
            hashset_add(set, value);
        }
    }
}

void hashset_print(hashset_t set)
{
    int len = sizeof(set->items);    
    printf("{ ");

    int i;
    for(i = 0; i < len; i++)
    {
        char* value = set->items[i];
        if(value != NULL)
        {
            printf("%s, ", value);
        }
    }

    printf(" }");
}
