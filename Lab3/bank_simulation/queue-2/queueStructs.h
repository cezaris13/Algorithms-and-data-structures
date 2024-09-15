//studento nr. 2016036

#ifndef queueStructs_h
#define queueStructs_h

struct node
{
    my_type nodeData;
    struct node *next;

};

typedef struct node Node;

typedef struct
{
     Node *front;
     Node *rear;
     int count;

} Queue;

#endif
