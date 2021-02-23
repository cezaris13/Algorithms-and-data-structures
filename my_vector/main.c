#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
void test(){
//    vector(v);
    vector v;
    vector_init(&v);
    printf("initialization\n");
    print_vector(v);
    v.resize(&v,10);
    printf("resized vector\n");
    print_vector(v);
    for(int i=0;i<15;i++){
        v.push_back(&v,i);
    }
//    v.push_back(&v,"11");
////    v.push_back(&v,12);
//    v.push_back(&v,"13");
//    v.push_back(&v,"14");
//    v.push_back(&v,"15");
//    v.push_back(&v,"16");
//    v.push_back(&v,"17");
//    v.push_back(&v,"18");
//    v.push_back(&v,"19");
//    v.push_back(&v,"20");
//    v.push_back(&v,"21");
////    v.set(&v,3, "64");
    printf("push_back() function\n");
    print_vector(v);
    v.set(&v,3, 100);
    printf("setting variable value\n");
    print_vector(v);
    printf("getting value of selected element\nvalue=%d\n",(v.get(&v,3)));
    v.delete(&v,4);
    printf("delete element\n");
    print_vector(v);
    printf("find element by its value\nid %d\n\n",v.find(v,14));// change to "14"
    v.destroy(&v);
    printf("destroying vector\n");
    print_vector(v);
}
int main()
{
    test();
    return 0;
}
