#include "kv.h"

#include <stdlib.h>
#include <string.h>

#define TOMBSTONE (void*)0x1

kv_t * kv_init(size_t capacity) {
    if (capacity == 0) return NULL;

    kv_t *table = malloc(sizeof(kv_t));
    if (table == NULL) return NULL;

    table->capacity = capacity;
    table->count = 0;

    table->entries = calloc(capacity, sizeof(kv_entry_t));
    if (table->entries == NULL) {
        free(table);
        return NULL;
    }

    return table;
}

void kv_free(kv_t * table) {
    if (table == NULL) return;

    for (size_t i = 0; i < table->capacity; ++i) {
        if (table->entries[i].key != NULL && table->entries[i].key != TOMBSTONE) {
            free(table->entries[i].key);
            free(table->entries[i].value);
        }
    }

    free(table->entries);
    free(table);
}

size_t hash(char * key, size_t capacity) {
    size_t hash = 0x13371337deadbeef;

    while (*key) {
        hash ^= *key;
        hash <<= 8;
        hash += *key;
        ++key;
    }

    return hash % capacity;
}

int kv_put(kv_t * table, char * key, char * value) {
    if (table == NULL || key == NULL || value == NULL) return -1;

    size_t index = hash(key, table->capacity);

    for (size_t i = 0; i < table->capacity; ++i) {
        size_t real_idx = (index + i) % table->capacity;
        kv_entry_t * entry = &table->entries[real_idx];

        if (entry->key != NULL &&
            entry->key != TOMBSTONE &&
            strcmp(entry->key, key) == 0) {
            // found matching key/value pair, update the value
            char * new_value = strdup(value);
            if (new_value == NULL) return -1;
            free(entry->value);
            entry->value = new_value;
            return 0;
        }

        if (entry->key == NULL || entry->key == TOMBSTONE) {
            // insert new key/value pair at this index
            char * new_key = strdup(key);
            if (new_key == NULL) return -1;
            char * new_value = strdup(value);
            if (new_value == NULL) {
                free(new_key);
                return -1;
            }

            entry->key = new_key;
            entry->value = new_value;
            table->count++;
            return 0;
        }
    }

    // table is at capacity and we didn't find the provided key
    return -2;
}
