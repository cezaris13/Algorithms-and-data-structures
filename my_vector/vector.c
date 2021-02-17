#ifndef filec
#define filec
#include <stdlib.h>
#include <stdio.h>
#define INIT_CAP 6
typedef struct vector vector;
struct vector{
    void **items;//one * wont help me to store data
    int capacity;
    int size;
    int (*Size)(vector);
    int (*is_empty)(vector);
    int (*is_full)(vector);
    void (*resize)(vector *,int);
    void (*push_back)(vector *,void *);
    void (*set)(vector *,int, void *);
    void *(*get)(vector *,int);
    void (*delete)(vector *,int);
    void (*destroy)(vector *);
    int (*find)(vector ,void *);
};


int vector_size(vector v){
    return v.size;
}
int is_empty(vector v){
    return (v.size>0?1:0);
}
int is_full(vector v){
    return(v.size==v.capacity?1:0);
}
void vector_resize(vector *v,int size){
    if(size>v->capacity){
        v->capacity=size;
        v->items=realloc(v->items,sizeof(void*)*size);
    }
}
void vector_push_back(vector *v,void *item){
    v->size=v->size+1;
    if(v->size>v->capacity){
        vector_resize(v,v->size);
    }
    v->items[v->size-1]=item;
}
void vector_set(vector *v,int index, void *item){
    if(index<0||index>=v->size){
        return;
    }
    v->items[index]=item;
}
void* vector_get(vector *v,int index){
    if(index<0||index>=v->size){
        return NULL;
    }
    return v->items[index];
}
void vector_delete(vector *v,int index){
    if(index<0||index>=v->size){
        return;
    }
    v->size--;
    for(int i=index;i<v->size;i++){
        v->items[i]=v->items[i+1];
    }
    v->items[v->size+1]=NULL;
}
void vector_free(vector *v){
    v->size=0;
    v->capacity=0;
    free(v->items);
}
int find_val_id(vector v,void *val){
    for(int i=0;i<v.size;i++){
        if(v.items[i]==val){
            return i;
        }
    }
    return -1;
}
void print_vector(vector v){
    printf("vector v size: %d\n",v.size);
    printf("vector v capacity: %d\n",v.capacity);
    for(int i=0;i<v.size;i++){
         printf("vector element v[%d]: %s\n",i,(char*)(v.items[i]));//for now with string
    }
}
void vector_init(vector *v){
    v->capacity=INIT_CAP;
    v->size=0;
    v->items=malloc(INIT_CAP*sizeof(void*));
    v->Size=vector_size;
    v->is_empty=is_empty;
    v->is_full=is_full;
    v->resize=vector_resize;
    v->push_back=vector_push_back;
    v->set=vector_set;
    v->get=vector_get;
    v->delete=vector_delete;
    v->destroy=vector_free;
    v->find=find_val_id;
}
#endif // filec
