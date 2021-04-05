#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include "big_int.h"
struct ConsultantType{
    int totalConsultants;
    int timeForOneClient;
};
typedef struct ConsultantType Consultant;
void readData(Consultant *experiencedConsultant,Consultant *newConsultant,int *prob){
    FILE *readData=fopen("duota.txt", "r");
    fscanf(readData, "%d%*[^\n]",&(experiencedConsultant->totalConsultants));
    fscanf(readData, "%d%*[^\n]",&(experiencedConsultant->timeForOneClient));
    fscanf(readData, "%d%*[^\n]",&(newConsultant->totalConsultants));
    fscanf(readData, "%d%*[^\n]",&(newConsultant->timeForOneClient));
    fscanf(readData, "%d%*[^\n]",prob);
    fclose(readData);
}
void checkWork(Consultant consultant,int prob,int specificTime,int seed){
    //data for statistics
    int queSize=0;
    int *clientsWaitTime=calloc(specificTime, sizeof(int));
    int clients=0;
    double *totalOneConsultantClients=calloc(consultant.totalConsultants, sizeof(double));

    srand(seed);
    Queue listOfCustomers;
    initialize(&listOfCustomers);
    int *consultantList=calloc(consultant.totalConsultants, sizeof(int));
    for(int i=1;i<=specificTime;i++){
        for(int j=0;j<consultant.totalConsultants;j++){
            if(consultantList[j]>0){
                consultantList[j]--;
            }
        }
        if(rand()%100<prob){
            if(isEmpty(&listOfCustomers)){
                int in=0;
                for(int j=0;j<consultant.totalConsultants;j++){
                    if(consultantList[j]==0){
                        clients++;//person did not wait
                        consultantList[j]=consultant.timeForOneClient;
                        totalOneConsultantClients[j]++;
                        in=1;
                        break;
                    }
                }
                if(!in){
                    if(!isFull(&listOfCustomers)){
                        enqueue(&listOfCustomers, i);
                    }
                }
            }
            else{
                if(!isFull(&listOfCustomers)){
                    enqueue(&listOfCustomers, i);
                }
            }
        }
        for(int j=0;j<consultant.totalConsultants;j++){
            if(consultantList[j]==0&&(listOfCustomers.count)>0){
                clientsWaitTime[clients]=i-getFirst(&listOfCustomers);//time Spent in queue
                clients++;//how many cliens came to The concultants
                consultantList[j]=consultant.timeForOneClient;
                totalOneConsultantClients[j]++;
                dequeue(&listOfCustomers);
            }
        }
       queSize=(queSize<(listOfCustomers.count)?(listOfCustomers.count):queSize);
    }
    /* statistics */
    double sum=0;
    int maxTime=0;
    for(int i=0;i<clients;i++){
        sum+=clientsWaitTime[i];
        maxTime=(clientsWaitTime[i]<maxTime?maxTime:clientsWaitTime[i]);
    }
    if(clients!=0){
        for(int i =0;i<consultant.totalConsultants;i++){
            printf("%2.0d Consultant was busy with %f%% of clients\n",i+1,(totalOneConsultantClients[i]/clients)*100);
        }
        printf("avg wait: %f\nmax wait: %d\n",sum/clients,maxTime);
        printf("max queue size: %d\n",queSize);
    }
    else{
        printf("no one came\n");
    }
    free(consultantList);
    free(clientsWaitTime);
    free(totalOneConsultantClients);
    destroy(&listOfCustomers);
}
int main(){
    int prob,specificTime;
    int seed;
    /* seed=10; */
    printf("iveskite norima seed'a\n");
    scanf("%d",&seed);
    Consultant newConsultant,experiencedConsultant;
    readData(&experiencedConsultant,&newConsultant,&prob);
    printf("choose specific time to see the results\n");
    scanf("%d",&specificTime);
    /* specificTime=100; */
    printf("\nexperienced Consultant\n");
    checkWork(experiencedConsultant, prob,specificTime,seed);
    printf("\nnew Consultant\n");
    checkWork(newConsultant, prob,specificTime,seed);
    return 0;
}
