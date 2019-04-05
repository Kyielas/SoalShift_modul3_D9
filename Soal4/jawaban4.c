#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1, tid2;
int status1, status2;
int nomor;

void* tulis1(){				//Fungsi untuk mencatat 10 proses paling atas pada file
	status1=0;
	system("ps -aux | head >> /home/ivan/Documents/FolderProses1/SimpanProses1.txt");
	status1=1;
}
void* tulis2(){				//Fungsi untuk mencatat 10 proses paling atas kedua pada file
	status2=0;
	system("ps -aux | head -20 | tail >> /home/ivan/Documents/FolderProses2/SimpanProses2.txt");
	status2=1;
}

void* kompres1(){			//Fungsi untuk mengkompres file dan menghapus file aslinya
	while(status1!=1 && status2!=1){}
	status1=0;
	system("zip -r -j -m KompresProses1.zip /home/ivan/Documents/FolderProses1/SimpanProses1.txt");
	//system("rm /home/ivan/Documents/FolderProses1/SimpanProses1.txt");
	status1=1;
}

void* kompres2(){			//Fungsi untuk mengkompres file dan menghapus file aslinya
	while(status1!=1 && status2!=1){}
	status2=0;
	system("zip -r -j -m KompresProses2.zip /home/ivan/Documents/FolderProses2/SimpanProses2.txt");
	//system("rm /home/ivan/Documents/FolderProses2/SimpanProses2.txt");
	status2=1;
}

void* unzip1(){				//Fungsi untuk mengekstrak file zip
	while(status1!=1 && status2!=1){}
	status1=0;
	system("unzip /home/ivan/Sisop/Praktikum3/Soal4/KompresProses1.zip");
	status1=1;
}

void* unzip2(){				//Fungsi untuk mengekstrak file zip
	while(status1!=1 && status2!=1){}
	status2=0;
	system("unzip /home/ivan/Sisop/Praktikum3/Soal4/KompresProses2.zip");
	status2=1;
}


int main(){

    pthread_create(&(tid1), NULL, (void*)tulis1, NULL);		//Memanggil fungsi tulis1
    pthread_create(&(tid1), NULL, (void*)tulis2, NULL);		//Memanggil fungsi tulis2
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_create(&(tid1), NULL, (void*)kompres1, NULL);	//Memanggil fungsi kompres1
 	pthread_create(&(tid2), NULL, (void*)kompres2, NULL);	//Memanggil fungsi kompres2
 	pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sleep(15);												//Untuk menunda pragram selama 15 detik

    pthread_create(&(tid1), NULL, (void*)unzip1, NULL);		//Memanggil fungsi unzip1
 	pthread_create(&(tid2), NULL, (void*)unzip2, NULL);		//Memanggil fungsi unzip2
 	pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
 
    return 0;
}
