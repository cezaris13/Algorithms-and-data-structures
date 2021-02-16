#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
int main()
{
    vector(v);
//    vector v;
//    vector_init(&v);
    print_vector(v);
    v.resize(&v,10);
    print_vector(v);
    v.push_back(&v,"11");
    v.push_back(&v,12);
    v.push_back(&v,"13");
    v.push_back(&v,"14");
    v.push_back(&v,"15");
    v.push_back(&v,"16");
    v.push_back(&v,"17");
    v.push_back(&v,"18");
    v.push_back(&v,"19");
    v.push_back(&v,"20");
    v.push_back(&v,"21");
    v.set(&v,3, "69");
    print_vector(v);
    v.set(&v,3, "69");
    print_vector(v);
    printf("new elemento %s\n",(char*)(v.get(&v,3)));
    v.delete(&v,4);
    print_vector(v);
    printf("id %d\n",v.find(v,"20"));
    v.destroy(&v);
    print_vector(v);
    return 0;
}
