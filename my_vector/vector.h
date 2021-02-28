// Studento nr. 2016016
// SUCCESS = 0
// UNDEFINED = -1
// sios funkcijos yra sukurtos vektoriaus duomenu tipui:
// vector v;
// v.Size(v); returns number of elements in the vector
// v.isEmpty(v); checks if v.size(v)==0 returns SUCCESS if true
// v.is_full(v); checks if v.size(v)==v.capacity(v) returns SUCCESS if true
// v.resize(&v,size); resizes vector
// v.push_back(&v,val); add value to the end of vector.
// v.set(&v,index,val); sets value of vector given element
// v.get(v,index); get value of given index. returns ( void type variable )
// v.delete(&v,index); removes element with given index
// v.destroy(&v); cleans vector
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include "vector.c"
//#define vector(vec) vector vec;  vector_init(&vec);

void vector_init(vector *v);
void print_vector(vector v);
#endif // SARASAS_H_INCLUDED
