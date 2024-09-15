#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


int initialize(Queue *q)
{
    if(q != NULL)
    {
        q -> count = 0;
        q -> front = NULL;
        q -> rear = NULL;
        return 1;
    }
    return 0;

}

int isEmpty(Queue *q)
{
    if(q -> front == NULL)
        return 1;
    return 0;
}

int enqueue(Queue *q, my_type data)
{
    Node * temp;
    temp = malloc(sizeof(Node));

    if( temp != NULL)
    {
        temp -> nodeData = data;
        if(isEmpty(q) == 1)
        {
            q -> front = q -> rear = temp;
        }
        else
        {
            q -> rear -> next = temp;
            q -> rear = temp;
            q -> rear -> next = NULL;
        }
        q -> count++;
        return 1;
    }
    else
        return 0;


}

my_type dequeue(Queue *q)
{
    if(isEmpty(q) == 0)
    {
        Node * temp;
        my_type number = q -> front -> nodeData;
        temp = q -> front;
        q -> front = q -> front -> next;
        q -> count--;
        free(temp);
        return(number);
    }
    else
    {
        return MISTAKE;
    }

}

my_type getFirst(Queue *q)
{
    if(isEmpty(q) == 0)
    {
        my_type number = q -> front -> nodeData;
        return(number);
    }
    else
    {
        return MISTAKE;
    }
}

int isFull(Queue *q)
{
    Node * temp;
    temp = malloc(sizeof(Node));
    if(temp == NULL)
    {
        free(temp);
        return 1;
    }
    else
    {
        free(temp);
        return 0;
    }


}

void display(Queue *q)
{
    if(isEmpty(q) == 0)
    {
        Node *temp;
        temp = q -> front;
        while(temp != NULL)
        {
            printf(PRINT, temp -> nodeData);
            temp = temp -> next;
        }
        printf("\n");
    }
    else
        return;
}

void destroy(Queue *q)
{
    Node * tmp;
    while (q->front != NULL)
    {
       tmp = q->front;
       q->front = q->front->next;
       free(tmp);
    }
}
