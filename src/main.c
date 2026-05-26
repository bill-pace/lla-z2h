#include "kv.h"

#include <assert.h>
#include <string.h>

int main() {
    kv_t * table = kv_init(16);
    assert(table != NULL);
    assert(table->capacity == 16);
    assert(table->count == 0);

    size_t index = kv_put(table, "hehe", "haha");
    assert(strcmp(table->entries[index].key, "hehe") == 0);

    kv_free(table);
}
