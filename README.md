# Soal Shift modul 3 [ Kelompok D9 ]

## Soal No. 1

Buatlah program C yang bisa menghitung faktorial secara parallel lalu menampilkan hasilnya secara berurutan
Contoh:
    ./faktorial 5 3 4
    3! = 6
    4! = 24
    5! = 120


### Jawab

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


## Soal No. 3


### Jawab

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