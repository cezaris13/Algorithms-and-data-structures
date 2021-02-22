#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include "vector.c"
#define vector(vec) vector vec;  vector_init(&vec);
// sios funkcijos yra sukurtos vektoriaus duomenu tipui:
// vector v;
// v.Size(v); grazina esamu nariu vektoriuje skaiciu
// v.isEmpty(v); patikrina ar esamas vektorius tuscias t.y. v.size(v)==0
// v.resize(&v,size); resizes vector
// v.push_back(&v,val) add value to the end of vector
// v.set(&v,index,val) sets value of vector given element
// v.get(v,index) get value of given index
// v.delete(&v,index) removes element with given index
// v.destroy(&v) cleans vector
//
/* int vector_size(vector v); */
/* int is_empty(vector v); */
/* int is_full(vector v); */
/* int vector_resize(vector *v, int capacity); */
/* int vector_push_back(vector *v, void *item); */
/* int vector_set(vector *v, int index, void *item); */
/* void *vector_get(vector *v, int index); */
/* int vector_delete(vector *v, int index); */
/* int vector_free(vector *v); */
void vector_init(vector *v);
/* int find_val_id(vector v,void *val); */
void print_vector(vector v);
#endif // SARASAS_H_INCLUDED
