//studento nr. 2016036

#ifndef queue_h
#define queue_h

typedef int my_type;
#define PRINT "%d " //used in display function, change if you have changed the data type

#define MISTAKE -11

#include "queueStructs.h"

int initialize(Queue *q); //creates an empty queue, return 1 - if success, 0 - if not

int isEmpty(Queue *q); // returns 1 - if empty, return 0 - if not

int enqueue(Queue *q, my_type data); // insert an element at the end of the queue, 1 - if success, 0 - if not

my_type dequeue(Queue *q); //Remove and return the first element of the queue, if the queue is empty returns MISTAKE

my_type getFirst(Queue *q); //Return the first element without removing it, if the queue is empty returns MISTAKE

int isFull(Queue *q); //Return 1 - if full, 0 if not;

void display(Queue *q); //Display the queue

void destroy(Queue *q);

#endif
