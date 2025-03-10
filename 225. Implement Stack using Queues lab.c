#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        
        int* newData = (int*)realloc(queue->data, 2 * queue->capacity * sizeof(int));
        if (newData == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
         queue->data = newData;
         queue->capacity *= 2;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        return -1; 
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(10);
    stack->q2 = createQueue(10);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q1, x);
}

int myStackPop(MyStack* obj) {
    if (isEmpty(obj->q1)) {
        return -1;
    }
    while (obj->q1->front < obj->q1->rear) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    int top = dequeue(obj->q1);
    
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return top;
}

int myStackTop(MyStack* obj) {
    if (isEmpty(obj->q1)) {
        return -1;
    }
    while (obj->q1->front < obj->q1->rear) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    int top = dequeue(obj->q1);
    enqueue(obj->q2, top);
    
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return top;
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    free(obj->q1);
    free(obj->q2->data);
    free(obj->q2);
    free(obj);
}
