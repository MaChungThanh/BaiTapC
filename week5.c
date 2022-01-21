#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Q_node{
    int* data;
    int max_size;
    int front, rear;
};

typedef struct Q_node *queue;

queue create_queue(int max_size){
    queue p = (struct Q_node*)malloc(sizeof(struct Q_node));
    p->max_size = max_size;
    p->rear = 0;
    p->front = 0;
    p->data = (int*)malloc(max_size*sizeof(int));
    return p;
}

int is_empty(queue Q){
    return Q->rear == Q->front;    
}

int is_full(queue Q){
    return (Q->rear - Q->front+1) % Q->max_size == 0;
}

void enQueue(queue Q, int data){
    if(is_full(Q)){
        printf("Queue full\n");
        return;
    } else{
        Q->data[Q->rear] = data;
        printf("%d enqueued to queue %d\n",data,Q->rear);

        Q->rear = (Q->rear+1) % Q->max_size;
    }
}

void deQueue(queue Q){
    if(is_empty(Q)){
        printf("Queue empty\n");
        return;
    } else{
        Q->front = (Q->front+1) % Q->max_size;
        printf("%d\n",Q->front);
    }
}

void displayQueue(queue Q){
    if (Q->rear == Q->front){
        printf("Queue is Empty\n");
        return;
    }

    printf("Elements in Circular Queue are:\n");

    if (Q->rear > Q->front){
        for (int i = Q->front; i < Q->rear; i++)
            printf("%d %d\n",Q->data[i],i);
    } 
    else if(Q->rear < Q->front){
        for (int i = Q->front; i < Q->max_size; i++){
            printf("%d %d\n",Q->data[i],i);
        }

        for(int i = 0; i < Q->rear; i++){
            printf("%d %d\n",Q->data[i],i);
        }
    }
    printf("\n\n");
}

int main(){
    int n;
    queue Q = create_queue(6);
    for(int i=1; i<=5; i++){
        scanf("%d",&n);
        enQueue(Q,n);
    }
    displayQueue(Q);
    

    deQueue(Q);
    enQueue(Q,6);
    displayQueue(Q);

    deQueue(Q);
    enQueue(Q,7);
    displayQueue(Q);

}