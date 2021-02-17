#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include "vector.c"
#define vector(vec) vector vec;  vector_init(&vec);
/* int vector_size(vector v); */
/* int is_empty(vector v); */
/* int is_full(vector v); */
/* void vector_resize(vector *v, int capacity); */
/* void vector_push_back(vector *v, void *item); */
/* void vector_set(vector *v, int index, void *item); */
/* void *vector_get(vector *v, int index); */
/* void vector_delete(vector *v, int index); */
/* void vector_free(vector *v); */
void vector_init(vector *v);
/* int find_val_id(vector v,void *val); */
void print_vector(vector v);
#endif // SARASAS_H_INCLUDED
