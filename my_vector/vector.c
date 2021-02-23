#ifndef filec
#define filec
#include <stdlib.h>
#include <stdio.h>
#define INIT_CAP 6
#define UNDEFINED -1
#define SUCCESS 0
//tepedef var
typedef struct vector vector;
struct vector{
    void **items;
    int capacity;
    int size;
    int (*Size)(vector);
    int (*is_empty)(vector);
    int (*is_full)(vector);
    int (*resize)(vector *,int);
    int (*push_back)(vector *,void *);
    int (*set)(vector *,int, void *);
    void *(*get)(vector *,int);
    int (*delete)(vector *,int);
    int (*destroy)(vector *);
    int (*find)(vector ,void *);
};

int vector_size(vector v){
    return v.size;
}
int is_empty(vector v){
    return (v.size>0?1:0);
}
int is_full(vector v){//malloc todo
    return(v.size==v.capacity?1:0);
}
int vector_resize(vector *v,int size){
    int status=UNDEFINED;
    if(v){
        if(size>v->capacity){
            v->capacity=size;
            v->items=realloc(v->items,sizeof(void*)*size);
            status=SUCCESS;
        }
    }
    return status;
}
int vector_push_back(vector *v,void *item){
    int status=UNDEFINED;
    v->size=v->size+1;
    if(v->size>v->capacity){
        if(vector_resize(v,v->size)==0){
            status=SUCCESS;
        }
    }
    else{
        status=SUCCESS;
    }
    v->items[v->size-1]=item;
    return status;
}
int vector_set(vector *v,int index, void *item){
    int status=UNDEFINED;
    if(v){
        if(index<0||index>=v->size){
            return status;
        }
        v->items[index]=item;
        status=SUCCESS;
    }
    return status;
}
void* vector_get(vector *v,int index){
    if(index<0||index>=v->size){
        return NULL;
    }
    return v->items[index];
}
int vector_delete(vector *v,int index){
    int status=UNDEFINED;
    if(index<0||index>=v->size){
        return status;
    }
    v->size--;
    for(int i=index;i<v->size;i++){
        v->items[i]=v->items[i+1];
    }
    v->items[v->size+1]=NULL;
    status=SUCCESS;
    return status;
}
int vector_free(vector *v){
    int status=UNDEFINED;
    if(v){
        v->size=0;
        v->capacity=0;
        free(v->items);
        status=SUCCESS;
    }
    return status;
}
int find_val_id(vector v,void *val){
    for(int i=0;i<v.size;i++){
        if(v.items[i]==val){
            return i;
        }
    }
    return UNDEFINED;
}
void print_vector(vector v){
    printf("vector v size: %d\n",v.size);
    printf("vector v capacity: %d\n",v.capacity);
    for(int i=0;i<v.size;i++){
         printf("vector element v[%d]: %d\n",i,(int)(v.items[i]));//for now with int
    }
    printf("\n");
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
