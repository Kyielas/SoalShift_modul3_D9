#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *factorial(void *x){
	int hasil=1;
	int z=*((int *)x);
	int temp=*((int *)x);
	while(z>0){
		hasil = hasil * z;
		z--;
	}
	printf("%d! = %d\n",temp,hasil);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char** argv){
	int n[100];
	pthread_t tid;
	for(int i=1;i<argc;i++){
		n[i-1]=atoi(argv[i]);
	}
	qsort(n,argc-1,sizeof(int),cmpfunc);
	for(int i=0;i<argc-1;i++){
		pthread_create(&tid,NULL,factorial,&n[i]);
		pthread_join(tid,NULL);
	}
}
