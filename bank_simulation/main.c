#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include "big_int.h"
#define totalTime 100
struct Workers{
    int totalWorkers;
    int timeForOneClient;
};
typedef struct Workers Workers;
void read(Workers *experiencedWorkers,Workers *newWorkers,int *prob){
    FILE *read=fopen("duota.txt", "r");
    fscanf(read, "%d%*[^\n]",&((*experiencedWorkers).totalWorkers));
    fscanf(read, "%d%*[^\n]",&((*experiencedWorkers).timeForOneClient));
    fscanf(read, "%d%*[^\n]",&((*newWorkers).totalWorkers));
    fscanf(read, "%d%*[^\n]",&((*newWorkers).timeForOneClient));
    fscanf(read, "%d%*[^\n]",prob);
}
int checkClient(int prob){
     int n=rand()%100;
     if(n<prob){
         return 1;
     }
     else{
         return 0;
     }
}
void checkWork(Workers type,int prob){
    int seed;
    seed=10;
    /* printf("iveskite norima seed'a\n"); */
    /* scanf("%d",&seed); */
    srand(seed);
    Queue listOfCustomers;
    /* int *workerList=calloc(type.totalWorkers, sizeof(int)); */
    int workerList[100];
    for(int i =0;i<type.totalWorkers;i++){
        workerList[i]=0;
    }
    for(int i=1;i<=totalTime;i++){
        for(int j=0;j<type.totalWorkers;j++){
            if(workerList[j]>0){
                workerList[j]--;
            }
        }
        if(checkClient(prob)){
            printf("\nperson did come to the meeting %d\n\n",i);
            if(Queue_isEmpty(listOfCustomers)){
                int j,in=0;
                for(j=0;j<type.totalWorkers;j++){
                    if(workerList[j]==0){
                        workerList[j]=type.timeForOneClient;
                        in=1;
                        break;
                    }
                }
                if(!in){
                    Enqueue_int(&listOfCustomers, i);
                }
            }
            else{
                Enqueue(&listOfCustomers, i);
                int a;
                Queue_Peek(listOfCustomers,&a);
                printf("person %d\n",a);
                for(int j=0;j<type.totalWorkers;j++){
                    if(workerList[j]==0&&Queue_Size(listOfCustomers)>0){
                        int a;
                        Queue_Peek(listOfCustomers,&a);
                        printf("size:%d\nperson:%d\n",Queue_Size(listOfCustomers),a);
                        workerList[j]=type.timeForOneClient;
                        int queue_int=0;
                        Dequeue(&listOfCustomers, &queue_int);
                    }
                }
            }
        }
        else{
            printf("\nperson did not come to the meeting %d\n\n",i);
            for(int j=0;j<type.totalWorkers;j++){
                if(workerList[j]==0&&Queue_Size(listOfCustomers)>0){
                    int a;
                    Queue_Peek(listOfCustomers,&a);
                    printf("size:%d\nperson:%d\n",Queue_Size(listOfCustomers),a);
                    workerList[j]=type.timeForOneClient;
                    int queue_int=0;
                    Dequeue(&listOfCustomers, &queue_int);
                }
            }
        }
        for(int j=0;j<type.totalWorkers;j++){
            printf("%d-th worker works with client %d time left\n",j+1,workerList[j]);
        }
       printf("queue size:%d\n",Queue_Size(listOfCustomers));
    }
    /* while(!Queue_isEmpty(listOfCustomers)){ */
    /*      for(int j=0;j<workers;j++){ */
    /*          if(workerList[j]==0){ */
    /*              workerList[j]=clientsTime; */
    /*              int queue_int=0; */
    /*              /\* Dequeue(&listOfCustomers, &queue_int); *\/ */
    /*              break; */
    /*          } */
    /*      } */
    /* } */
    Queue_Clear(&listOfCustomers);
    /* free(workerList); */
}
int main(){
    int workers,clientsTime,prob;
    Workers newWorkers,experiencedWorkers;
    read(&experiencedWorkers,&newWorkers,&prob);
    printf("workers %d\nClientTime %d\nProb %d%%\n",newWorkers.totalWorkers,newWorkers.timeForOneClient,prob);
    checkWork(experiencedWorkers, prob);
    checkWork(newWorkers, prob);
    return 0;
}
