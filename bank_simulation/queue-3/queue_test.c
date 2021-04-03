#include <queue.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    Queue que;
    int a = 1;
    int b = Queue_Peek(que, &a);
    assert(a == 1);
    assert(b == 0);
    
    int c = 2;
    int d = Dequeue(&que, &a);
    assert(c == 2);
    assert(d == 0);
    
    assert(Queue_Size(que) == 0);
    assert(Queue_isEmpty(que) == 1);
    assert(Queue_Clear(&que) == 0);
    assert(Queue_isFull(que) == 0);
    
    printf("Make queue = {'a', 10, 5.5, 20, 'k'}\n");
    Enqueue(&que, 'a');
    Enqueue(&que, 10);
    Enqueue(&que, (float)5.5);
    Enqueue(&que, 20);
    Enqueue(&que, 'k');
    
    printf("Queue size %d.\n", Queue_Size(que));
    int que_int = 0;
    float que_float = 0;
    char que_char = ' ';
    Dequeue(&que, &que_char);
    printf("Dequeue char %c, size %d\n", que_char, Queue_Size(que));
    Dequeue(&que, &que_int);
    printf("Dequeue int %d, size %d\n", que_int, Queue_Size(que));
    Dequeue(&que, &que_float);
    printf("Dequeue float %f, size %d\n", que_float, Queue_Size(que));
    int que_int1 = 0;
    Queue_Peek(que, &que_int1);
    printf("Peek int %d, size %d\n", que_int1, Queue_Size(que));
    Queue_Clear(&que);
    printf("After clear size %d.\n", Queue_Size(que));
    
    return 0;
}

