#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include "big_int.h"
struct ConsultantType{
    int totalConsultants;
    char timeForOneClient[256];//big int
    big_int *timeForOneClientBig;
};
typedef struct ConsultantType Consultant;
void readData(Consultant *experiencedConsultant,Consultant *newConsultant,int *prob){
    FILE *readData=fopen("duota.txt", "r");
    fscanf(readData, "%d%*[^\n]",&(experiencedConsultant->totalConsultants));
    fscanf(readData, "%s%*[^\n]",(experiencedConsultant->timeForOneClient));
    fscanf(readData, "%d%*[^\n]",&(newConsultant->totalConsultants));
    fscanf(readData, "%s%*[^\n]",(newConsultant->timeForOneClient));
    fscanf(readData, "%d%*[^\n]",prob);
    fclose(readData);
}
void printBigIntCustom(big_int* num,FILE *write){
    if(num->sign=='-'&&num->data[0]!=0){
        fprintf(write,"%c",num->sign);
    }
    for(int i=0;i<num->len;++i){
        fprintf(write,"%c", (num->data[i] + '0'));
    }
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
    FILE *write=fopen("rez.txt", "a");
    big_int **consultantList=calloc(consultant.totalConsultants, sizeof(big_int));
    for (int i=0;i<consultant.totalConsultants;i++) {
       consultantList[i]=new_big_int("0");
    }
    for(int i=1;i<=specificTime;i++){
        for(int j=0;j<consultant.totalConsultants;j++){
            if(compare_big_int(consultantList[j],new_big_int("0"))){
                consultantList[j]=sub_big_int(consultantList[j],new_big_int("1"));
            }
        }
        if(rand()%100<prob){
            fprintf(write,"\nclient did come to the meeting %d\n\n",i);

            if(isEmpty(&listOfCustomers)){
                int in=0;
                for(int j=0;j<consultant.totalConsultants;j++){
                    if(!compare_big_int(consultantList[j],new_big_int("0"))){
                        clients++;//client did not wait
                        consultantList[j]=consultant.timeForOneClientBig;
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
        else{
            fprintf(write,"\nclient did not come to the meeting %d\n\n",i);
        }
        for(int j=0;j<consultant.totalConsultants;j++){
            if(!compare_big_int(consultantList[j],new_big_int("0"))&&(listOfCustomers.count)>0){
                clientsWaitTime[clients]=i-getFirst(&listOfCustomers);//time Spent in queue
                clients++;//how many cliens came to The concultants
                consultantList[j]=consultant.timeForOneClientBig;
                totalOneConsultantClients[j]++;
                dequeue(&listOfCustomers);
            }
        }
         for(int j=0;j<consultant.totalConsultants;j++){
             fprintf(write,"%d-th worker works with client ",j+1);
             printBigIntCustom(consultantList[j],write);
             fprintf(write," time left\n");
        }
       fprintf(write,"queue size:%d\n",listOfCustomers.count);
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
    //freeing memory
    for (int i=0;i<consultant.totalConsultants;i++) {
       free_big_int(consultantList[i]);
    }
    free(consultantList);
    free(clientsWaitTime);
    free(totalOneConsultantClients);
    destroy(&listOfCustomers);
    fclose(write);
}
int main(){
    int prob,specificTime;
    FILE *write=fopen("rez.txt", "w");
    fclose(write);
    int seed;
    /* seed=10; */
    printf("iveskite norima seed'a\n");
    scanf("%d",&seed);
    Consultant newConsultant,experiencedConsultant;
    readData(&experiencedConsultant,&newConsultant,&prob);
    printf("choose specific time to see the results\n");
    scanf("%d",&specificTime);
    experiencedConsultant.timeForOneClientBig=new_big_int(experiencedConsultant.timeForOneClient);
    newConsultant.timeForOneClientBig=new_big_int(newConsultant.timeForOneClient);
    /* specificTime=100; */
    printf("\nexperienced Consultants\n");
    checkWork(experiencedConsultant, prob,specificTime,seed);
    printf("\nnew Consultants\n");
    checkWork(newConsultant, prob,specificTime,seed);
    return 0;
}
