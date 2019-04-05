# Soal Shift modul 3 [ Kelompok D9 ]

## Soal No. 1

Buatlah program C yang bisa menghitung faktorial secara parallel lalu menampilkan hasilnya secara berurutan
Contoh:
 - ./faktorial 5 3 4
   - 3! = 6
   - 4! = 24
   - 5! = 120


### Jawab
Pertama saya membuat fungsi untuk factorial itu sendiri yaitu
```c
void *factorial(void *x){
        int hasil=1;
        int z=*((int *)x);              // dibuat dua variabel dengan isi yang sama dikarenakan
        int temp=*((int *)x);           // dipakai di dalam perulangan serta print
        while(z>0){
                hasil = hasil * z;
                z--;
        }
        printf("%d! = %d\n",temp,hasil);
}
```
lalu dari situ didalam main akan digunakan untuk melakukan **sorting** serta **pembuatan thread**
akan tetapi sebelumnya untuk bisa melakukan input dari bash diperlukan penggunaan argument yaitu sbg berikut  
```c
int main(int argc, char** argv){
        int n[100];         // array untuk menyimpan urutan input
        pthread_t tid;
        for(int i=1;i<argc;i++){
                n[i-1]=atoi(argv[i]);   // untuk mengubah char menjadi int
        }
```
setelah diubah menjadi integer (diubah karena char tidak bisa mencari faktorial)dilakukan sorting dengan bantuan command **qsort**
```c
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );                  // fungsi untuk men-sort dari kecil ke besar
}

qsort(n,argc-1,sizeof(int),cmpfunc);               
```
terakhir baru dibuat looping untuk membuat thread sesuai jumlah array dan dibuat join agar hasilnya ditampilkan secara berurutan tanpa mendahului

Command | Description 
--- | -----
atoi | digunakan untuk mengubah string menjadi integer
qsort | fungsi yang disediakan library untuk men-sort array

###### reference:
* [Command Line Argument](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)
* [Qsort](https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm)
* [Atoi](http://www.cplusplus.com/reference/cstdlib/atoi/)

## Soal No. 2

Pada suatu hari ada orang yang ingin berjualan 1 jenis barang secara private, dia memintamu membuat program C dengan spesifikasi sebagai berikut:
1. Terdapat 2 server: server penjual dan server pembeli
2. server hanya bisa terkoneksi dengan 1 client
3. Server penjual dan server pembeli memiliki stok barang yang selalu sama
4. Client yang terkoneksi ke server penjual hanya bisa menambah stok
    * Cara menambah stok: client yang terkoneksi ke server penjual mengirim string “tambah” ke server lalu stok bertambah 1
5. Client yang terkoneksi ke server pembeli hanya bisa mengurangi stok
    * Cara mengurangi stok: client yang terkoneksi ke server pembeli mengirim string “beli” ke server lalu stok berkurang 1
6. Server pembeli akan mengirimkan info ke client yang terhubung dengannya apakah transaksi berhasil atau tidak berdasarkan ketersediaan stok
    * Jika stok habis maka client yang terkoneksi ke server pembeli akan mencetak “transaksi gagal”
    * Jika stok masih ada maka client yang terkoneksi ke server pembeli akan mencetak “transaksi berhasil”
7. Server penjual akan mencetak stok saat ini setiap 5 detik sekali
8. Menggunakan thread, socket, shared memory

### Jawab


## Soal 3
Agmal dan Iraj merupakan 2 sahabat yang sedang kuliah dan hidup satu kostan, sayangnya mereka mempunyai gaya hidup yang berkebalikan, dimana Iraj merupakan laki-laki yang sangat sehat,rajin berolahraga dan bangun tidak pernah kesiangan sedangkan Agmal hampir menghabiskan setengah umur hidupnya hanya untuk tidur dan ‘ngoding’. Dikarenakan mereka sahabat yang baik, Agmal dan iraj sama-sama ingin membuat satu sama lain mengikuti gaya hidup mereka dengan cara membuat Iraj sering tidur seperti Agmal, atau membuat Agmal selalu bangun pagi seperti Iraj. Buatlah suatu program C untuk menggambarkan kehidupan mereka dengan spesifikasi sebagai berikut:
a. Terdapat 2 karakter Agmal dan Iraj
b. Kedua karakter memiliki status yang unik
  * Agmal mempunyai WakeUp_Status, di awal program memiliki status 0
  * Iraj memiliki Spirit_Status, di awal program memiliki status 100
  * Terdapat 3 Fitur utama
    - All Status, yaitu menampilkan status kedua sahabat
      Ex: Agmal WakeUp_Status = 75 
          Iraj Spirit_Status = 30
    - “Agmal Ayo Bangun” menambah WakeUp_Status Agmal sebesar 15 point
    - “Iraj Ayo Tidur” mengurangi Spirit_Status Iraj sebanyak 20 point
  * Terdapat Kasus yang unik dimana:
    - Jika Fitur “Agmal Ayo Bangun” dijalankan sebanyak 3 kali, maka Fitur “Iraj Ayo Tidur” Tidak bisa dijalankan selama 10                         detik (Dengan mengirim pesan ke sistem “Fitur Iraj Ayo Tidur disabled 10 s”)
    - Jika Fitur  “Iraj Ayo Tidur” dijalankan sebanyak 3 kali, maka Fitur “Agmal Ayo Bangun” Tidak bisa dijalankan selama     10 detik (Dengan mengirim pesan ke sistem “Agmal Ayo Bangun disabled 10 s”)
  * Program akan berhenti jika Salah Satu :  
    - WakeUp_Status Agmal >= 100 (Tampilkan Pesan “Agmal Terbangun,mereka bangun pagi dan berolahraga”)
    - Spirit_Status Iraj <= 0 (Tampilkan Pesan “Iraj ikut tidur, dan bangun kesiangan bersama Agmal”)
  * Syarat Menggunakan Lebih dari 1 Thread

### Jawab
Pertama-tama untuk memenuhi poin **a** yaitu 2 karakter Agmal dan Iraj maka saya buat dua fungsi yang berbeda
dan untuk poin **b** saya buat dua variabel WakeUp_Status = 0 dan Spirit_Status = 100
```c
-- VARIABEL UTAMA --
int WakeUp_Status = 0;
int Spirit_Status = 100;
int mark=3;               // mark digunakan untuk menandakan tiap thread ex : mark=3 yaitu menu utama
int iterA, iterI;         // untuk mencounter jumlah banyaknya fitur dijalankan
int slpA=1;               // untuk menandakan apakah fitur di disabled atau tidak
int slpI=1;               
```
lalu untuk menjelaskan fiturnya saya akan memberi contoh **fungsi Agmal** :
```c
void *Agmal(void *a){
        while(1){
                while(mark!=0){}                  // jika bukan mark dia maka dia akan melakukan infinite loop         
                if(iterI==3){                     // melanjutkan apabila counter Iraj melebihi 3
                        printf("Agmal Ayo Bangun disabled 10s\n");
                        iterI=0;                  // mereset counter
                        mark=3;                   // mengembalikan ke mark menu
                        slpA=0;                   // men-flag disable
                        sleep(10);
                        slpA=1;
                        continue;
                }
                WakeUp_Status+=15;                // menambahkan 15 poin dalam fitur WakeUp_Status
                printf("WakeUp_Status : %d\n",WakeUp_Status);
                iterA++;                          // menghitung counter fitur Agmal
                if(iterA==3){                     // jika counter mencapai 3 maka pindah ke mark Iraj(1)
                        mark=1;
                        continue;
                }

                mark=3;                           // mengembalikan ke mark menu
        }
}
```
untuk fitur Iraj hampir sama tapi kebalikannya dan ada juga fitur All Status untuk memprint nilai sekarang
lalu untuk mainnya berisi pembuatan tiga thread yaitu Agmal, Iraj , dan All Status
dan terakhir untuk bagian I/O nya yaitu :
```c
        while(WakeUp_Status<100 && Spirit_Status>0){
                while(mark!=3){}                  // jika bukan mark dia maka dia akan melakukan infinite loop
                scanf("%[^\n]%*c",i);
                if(slpA==1 && strcmp(a,i)==0) mark=0;   // pindah ke thread Agmal
                if(slpI==1 && strcmp(b,i)==0) mark=1;   // pindah ke thread Iraj
                if(strcmp(c,i)==0) mark=2;              // pindah ke thread All Status
                printf("%d\n",mark);
        }
        if(WakeUp_Status>=100) printf("Agmal Terbangun,mereka bangun pagi dan berolahraga");
        if(Spirit_Status<=0) printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal");
```
###### reference:
[Scanf](https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/)

## Soal No. 4

Buatlah sebuah program C dimana dapat menyimpan list proses yang sedang berjalan (ps -aux) maksimal 10 list proses. Dimana awalnya list proses disimpan dalam di 2 file ekstensi .txt yaitu  SimpanProses1.txt di direktori /home/Document/FolderProses1 dan SimpanProses2.txt di direktori /home/Document/FolderProses2 , setelah itu masing2 file di  kompres zip dengan format nama file KompresProses1.zip dan KompresProses2.zip dan file SimpanProses1.txt dan SimpanProses2.txt akan otomatis terhapus, setelah itu program akan menunggu selama 15 detik lalu program akan mengekstrak kembali file KompresProses1.zip dan KompresProses2.zip 
Dengan Syarat : 
* Setiap list proses yang di simpan dalam masing-masing file .txt harus berjalan bersama-sama
* Ketika mengkompres masing-masing file .txt harus berjalan bersama-sama
* Ketika Mengekstrak file .zip juga harus secara bersama-sama
* Ketika Telah Selesai melakukan kompress file .zip masing-masing file, maka program akan memberi pesan “Menunggu 15 detik untuk mengekstrak kembali”
* Wajib Menggunakan Multithreading
* Boleh menggunakan system

### Jawab

Untuk membuat program dengan ketentuan seperti di atas, maka digunakanlah beberapa command seperti dibawah ini

Command | Description 
--- | -----
``` system() ``` | sebuah perintah yang digunakan untuk menjalankan perintah seperti pada command line
``` head ``` | sebuah perintah pada command line yang berfungsi untuk melihat proses paling atas
``` tail ``` | sebuah perintah pada command line yang berfungsi untuk melihat proses paling bawah


Untuk dapat menjalankan program dengan memanfaatkan multithreading, maka dibuatlah fungsi-fungsi yang menjalankan perintah secara individu. Beberapa fungsi tersebut dapat dilihat seperti berikut
```c
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
	status1=1;
}

void* kompres2(){			//Fungsi untuk mengkompres file dan menghapus file aslinya
	while(status1!=1 && status2!=1){}
	status2=0;
	system("zip -r -j -m KompresProses2.zip /home/ivan/Documents/FolderProses2/SimpanProses2.txt");
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
```

Setelah itu dibuatlah main untuk menjalankan fungsi-fungsi di atas. Main program dari file tersebut dapat dilihat seperti berikut.

```c

int main(){

    pthread_create(&(tid1), NULL, (void*)tulis1, NULL);		//Memanggil fungsi tulis1
    pthread_create(&(tid1), NULL, (void*)tulis2, NULL);		//Memanggil fungsi tulis2
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_create(&(tid1), NULL, (void*)kompres1, NULL);	//Memanggil fungsi kompres1
 	pthread_create(&(tid2), NULL, (void*)kompres2, NULL);	//Memanggil fungsi kompres2
 	pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sleep(15);							//Untuk menunda pragram selama 15 detik

    pthread_create(&(tid1), NULL, (void*)unzip1, NULL);		//Memanggil fungsi unzip1
 	pthread_create(&(tid2), NULL, (void*)unzip2, NULL);	//Memanggil fungsi unzip2
 	pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
 
    return 0;
}
```