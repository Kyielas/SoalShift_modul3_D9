#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
int WakeUp_Status = 0;
int Spirit_Status = 100;
int mark=3;
int iterA, iterI;
int slpA=1;
int slpI=1;

void *Agmal(void *a){
	while(1){
		while(mark!=0){}
		if(iterI==3){
			printf("Agmal Ayo Bangun disabled 10s\n");
			iterI=0;
			mark=3;
			slpA=0;
			sleep(10);
			slpA=1;
			continue;
		}
		WakeUp_Status+=15;
		printf("WakeUp_Status : %d\n",WakeUp_Status);
		iterA++;
		if(iterA==3){
			mark=1;
			continue;
		}
		
		mark=3;
	}
}

void *Iraj(void *i){
	while(1){
		while(mark!=1){}
		if(iterA==3){
			printf("Iraj Ayo Tidur disabled 10s\n");
			iterA=0;
			mark=3;
			slpI=0;
			sleep(10);
			slpI=1;
			continue;
		}
		Spirit_Status = Spirit_Status - 20;
		printf("Spirit_Status : %d\n",Spirit_Status);
		iterI++;
		if(iterI==3){
			mark=0;
			continue;
		}

		mark=3;
	}
}

void *All_Status(void *as){
	while(1){
		while(mark!=2){}
		printf("WakeUp_Status : %d\n",WakeUp_Status);
		printf("Spirit_Status : %d\n",Spirit_Status);
		mark=3;
	}
}

int main(){
	char *i;
	char *a="Agmal Ayo Bangun";
	char *b="Iraj Ayo Tidur";
	char *c="All Status";
	pthread_t tid1,tid2,tid3;
	pthread_create(&(tid1),NULL,Agmal,NULL);
	pthread_create(&(tid2),NULL,Iraj,NULL);
	pthread_create(&(tid3),NULL,All_Status,NULL);
	while(WakeUp_Status<100 && Spirit_Status>0){
		while(mark!=3){}
		scanf("%[^\n]%*c",i);
		if(slpA==1 && strcmp(a,i)==0) mark=0;
		if(slpI==1 && strcmp(b,i)==0) mark=1;
		if(strcmp(c,i)==0) mark=2;
		printf("%d\n",mark);
	}
	if(WakeUp_Status>=100) printf("Agmal Terbangun,mereka bangun pagi dan berolahraga\n");
	if(Spirit_Status<=0) printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal\n");
}
