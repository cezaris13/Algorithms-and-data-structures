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
void checkWork(Workers type,int prob,int specificTime){
    FILE *write=fopen("rex.txt", "a");
    int seed;
    int que=0;
    seed=10;
    /* printf("iveskite norima seed'a\n"); */
    /* scanf("%d",&seed); */
    srand(seed);
    Queue listOfCustomers;
    int *workerList=calloc(type.totalWorkers, sizeof(int));
    double *totalWorkerClients=calloc(type.totalWorkers, sizeof(double));
    double totalClients=0;
    int *times=calloc(specificTime, sizeof(int));
    int index=0;
    for(int i=1;i<=specificTime;i++){
        for(int j=0;j<type.totalWorkers;j++){
            if(workerList[j]>0){
                workerList[j]--;
            }
        }
        if(checkClient(prob)){
            /* printf("\nperson did come to the meeting %d\n\n",i); */
            if(Queue_isEmpty(listOfCustomers)){
                int j,in=0;
                for(j=0;j<type.totalWorkers;j++){
                    if(workerList[j]==0){
                        index++;//person did not wait
                        workerList[j]=type.timeForOneClient;
                        totalWorkerClients[j]++;
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
            }
        }
        for(int j=0;j<type.totalWorkers;j++){
            if(workerList[j]==0&&Queue_Size(listOfCustomers)>0){
                int a;
                Queue_Peek(listOfCustomers,&a);
                times[index]=i-a;
                index++;
                printf("size:%d\nperson:%d\n",Queue_Size(listOfCustomers),a);
                workerList[j]=type.timeForOneClient;
                totalWorkerClients[j]++;
                int queue_int=0;
                Dequeue(&listOfCustomers, &queue_int);
            }
        }
       /*  for(int j=0;j<type.totalWorkers;j++){ */
       /*      printf("%d-th worker works with client %d time left\n",j+1,workerList[j]); */
       /*  } */
       /* printf("queue size:%d\n",Queue_Size(listOfCustomers)); */
       que=(que<Queue_Size(listOfCustomers)?Queue_Size(listOfCustomers):que);
    }
    for(int i =0;i<type.totalWorkers;i++){
        totalClients+=totalWorkerClients[i];
    }
    double sum=0;
    int maxTime=0;
    for(int i=0;i<index;i++){
        fprintf(write,"arr[%d]=%d\n",i,times[i]);
        sum+=times[i];
        maxTime=(times[i]<maxTime?maxTime:times[i]);
            }
    for(int i =0;i<type.totalWorkers;i++){
        printf("worker[%d] busy: %f%%\n",i,(totalWorkerClients[i]/totalClients)*100);
    }
    printf("avg wait: %f\nmax wait: %d\n",sum/index,maxTime);//fix if index==0
    Queue_Clear(&listOfCustomers);
    free(workerList);
    printf("max queue size: %d\n",que);
}
int main(){
    int prob,specificTime;
    Workers newWorkers,experiencedWorkers;
    read(&experiencedWorkers,&newWorkers,&prob);
    /* printf("workers %d\nClientTime %d\nProb %d%%\n",newWorkers.totalWorkers,newWorkers.timeForOneClient,prob); */
    /* printf("choose specific time to see the results\n"); */
    /* scanf("%d",&specificTime); */
    specificTime=totalTime;
    checkWork(experiencedWorkers, prob,specificTime);
    checkWork(newWorkers, prob,specificTime);
    return 0;
}
