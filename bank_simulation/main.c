#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include "big_int.h"
struct WorkersType{
    int totalWorkers;
    int timeForOneClient;
};
typedef struct WorkersType Workers;
void readData(Workers *experiencedWorkers,Workers *newWorkers,int *prob){
    FILE *readData=fopen("duota.txt", "r");
    fscanf(readData, "%d%*[^\n]",&((*experiencedWorkers).totalWorkers));
    fscanf(readData, "%d%*[^\n]",&((*experiencedWorkers).timeForOneClient));
    fscanf(readData, "%d%*[^\n]",&((*newWorkers).totalWorkers));
    fscanf(readData, "%d%*[^\n]",&((*newWorkers).timeForOneClient));
    fscanf(readData, "%d%*[^\n]",prob);
    fclose(readData);
}
void checkWork(Workers type,int prob,int specificTime,int seed){
    int queSize=0;
    srand(seed);
    Queue listOfCustomers;
    initialize(&listOfCustomers);
    int *workerList=calloc(type.totalWorkers, sizeof(int));
    double *totalWorkerClients=calloc(type.totalWorkers, sizeof(double));
    double totalClients=0;
    int *clientsWaitTime=calloc(specificTime, sizeof(int));
    int clients=0;
    for(int i=1;i<=specificTime;i++){
        for(int j=0;j<type.totalWorkers;j++){
            if(workerList[j]>0){
                workerList[j]--;
            }
        }
        if(rand()%100<prob){
            if(isEmpty(&listOfCustomers)){
                int j,in=0;
                for(j=0;j<type.totalWorkers;j++){
                    if(workerList[j]==0){
                        clients++;//person did not wait
                        workerList[j]=type.timeForOneClient;
                        totalWorkerClients[j]++;
                        in=1;
                        break;
                    }
                }
                if(!in){
                    enqueue(&listOfCustomers, i);
                }
            }
            else{
                enqueue(&listOfCustomers, i);
            }
        }
        for(int j=0;j<type.totalWorkers;j++){
            if(workerList[j]==0&&(listOfCustomers.count)>0){
                int clientQueTime=getFirst(&listOfCustomers);
                clientsWaitTime[clients]=i-clientQueTime;
                clients++;
                workerList[j]=type.timeForOneClient;
                totalWorkerClients[j]++;
                int queue_int=0;
                dequeue(&listOfCustomers);
            }
        }
       queSize=(queSize<(listOfCustomers.count)?(listOfCustomers.count):queSize);
    }
    /* statistics */
    for(int i=0;i<type.totalWorkers;i++){
        totalClients+=totalWorkerClients[i];
    }
    double sum=0;
    int maxTime=0;
    for(int i=0;i<clients;i++){
        sum+=clientsWaitTime[i];
        maxTime=(clientsWaitTime[i]<maxTime?maxTime:clientsWaitTime[i]);
    }
    if(clients!=0){
        for(int i =0;i<type.totalWorkers;i++){
            printf("worker[%d] busy: %f%%\n",i,(totalWorkerClients[i]/totalClients)*100);
        }
        printf("avg wait: %f\nmax wait: %d\n",sum/clients,maxTime);
    }
    else{
        printf("no one came\n");
    }
    free(workerList);
    free(clientsWaitTime);
    free(totalWorkerClients);
    destroy(&listOfCustomers);
    printf("max queue size: %d\n",queSize);
}
int main(){
    int prob,specificTime;
    int seed;
    seed=10;
    printf("iveskite norima seed'a\n");
    scanf("%d",&seed);
    Workers newWorkers,experiencedWorkers;
    readData(&experiencedWorkers,&newWorkers,&prob);
    printf("choose specific time to see the results\n");
    scanf("%d",&specificTime);
    specificTime=100;
    printf("\nexperienced workers\n");
    checkWork(experiencedWorkers, prob,specificTime,seed);
    printf("\nnew workers\n");
    checkWork(newWorkers, prob,specificTime,seed);
    return 0;
}
