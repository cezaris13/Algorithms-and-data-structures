// Studento nr. 2016016
// SUCCESS = 0
// UNDEFINED = -1
//
//This is the list of functions defined for vector data type:
//
//a - any vector data type variable name
//
//
// a.Size(vector a); returns current vector size
// a.is_empty(vector a); returns 1 if vector is empty and 0 if not
// a.is_full(vector a); returns 1 if vector is full and 0 if not
// a.resize(vector *a,int size); Resizes vector, returns SUCCESS if success,UNDEFINED if not
// a.push_back(vector *v,void *val); add value to the end of vector, returns SUCCESS if success, UNDEFINED if not
// a.set(vector *a,int index,void *val); sets value of vector given element, returns SUCCESS if success, UNDEFINED if not
// a.get(vector *a,int index); get value of given index. returns ( void type variable ) (null if index ouf of bounds)
// a.delete(vector *a,int index); removes element with given index, returns SUCCESS if success, UNDEFINED if not
// a.destroy(vector *a); cleans vector, returns SUCCESS if success, UNDEFINED if not
// a.find(vector a,void *val); finds element with the given value and returns its position, else returns UNDEFINED
//
// Example:
//
// vector v;
// v.isEmpty(v);
// v.is_full(v);
// v.resize(&v,size);
// v.push_back(&v,val);
// v.set(&v,index,val);
// v.get(v,index);
// v.delete(&v,index);
// v.destroy(&v);
// v.find(v,val);

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#define INIT_CAP 6
#define UNDEFINED -1
#define SUCCESS 0
#define MAX_SIZE 200
#include "vector.c"

void vector_init(vector *v);//initialize vector (size 0, capacity=INIT_CAP)
void print_vector(vector v);//prints vector elements(if you want to print vector elements, write yout own printing function,
                            //because you have to convert *void value to your data type
                            //(Ex. *void->int    printf("%d",(int)(v.items[i]);) ) )
#endif
