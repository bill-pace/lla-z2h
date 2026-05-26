#include "kv.h"

#include <assert.h>

int main() {
    kv_t * table = kv_init(16);
    assert(table != NULL);
    assert(table->capacity == 16);
    assert(table->count == 0);

    kv_put(table, "hehe", "haha");

    kv_free(table);
}
