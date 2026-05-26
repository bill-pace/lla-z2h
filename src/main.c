#include "kv.h"

#include <assert.h>
#include <string.h>

int main() {
    kv_t * table = kv_init(16);
    assert(table != NULL);
    assert(table->capacity == 16);
    assert(table->count == 0);

    kv_put(table, "hehe", "haha");
    char * value = kv_get(table, "hehe");
    assert(strcmp(value, "haha") == 0);

    kv_put(table, "hehe", "hoho");
    value = kv_get(table, "hehe");
    assert(strcmp(value, "haha") != 0);

    int deleted = kv_delete(table, "hehe");
    assert(deleted == 0);
    assert(table->count == 0);
    deleted = kv_delete(table, "hehe");
    assert(deleted == -1);

    kv_free(table);
}
