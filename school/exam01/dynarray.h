typedef struct {
    int size;
    int capacity;
    int max_capacity;
    int *data;
} Dynarray;

void Dynarray_init(Dynarray *dynarray);

void Dynarray_append(Dynarray *dynarray, int value);

int Dynarray_get(Dynarray *dynarray, int index);

void Dynarray_set(Dynarray *dynarray, int index, int value);

void Dynarray_double_capacity_if_full(Dynarray *dynarray);

void Dynarray_free(Dynarray *dynarray);