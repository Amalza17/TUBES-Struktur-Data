# Tugas Besar Struktur Data – Aplikasi Manajemen Musik (C++)

## Deskripsi

Proyek ini merupakan aplikasi manajemen musik berbasis terminal yang dikembangkan menggunakan bahasa pemrograman **C++**.
Aplikasi ini dirancang untuk mengelola **pustaka lagu (library)** dan **playlist**, dengan pemisahan hak akses antara **Admin** dan **User**.

Admin bertanggung jawab atas pengelolaan data lagu, sedangkan User difokuskan pada pengalaman mendengarkan musik, seperti pencarian lagu, pengelolaan playlist, dan pemutaran lagu.

Proyek ini dibuat sebagai bagian dari **Tugas Besar Mata Kuliah Struktur Data**.

## Fitur Utama

### Menu Admin

* **Tambah Lagu**
  Menambahkan lagu baru ke dalam library musik.
* **Lihat Semua Lagu**
  Menampilkan seluruh koleksi lagu yang tersimpan, terurut berdasarkan ID.
* **Update Lagu**
  Memperbarui informasi lagu yang sudah ada.
* **Hapus Lagu**
  Menghapus lagu dari library dan secara otomatis menghapus lagu tersebut dari seluruh playlist user.

### Menu User

* **Pencarian Lanjut**
  Mencari lagu berdasarkan:

  * ID
  * Judul
  * Penyanyi
  * Genre
  * Tahun rilis
* **Manajemen Playlist**

  * Menambahkan lagu ke playlist
  * Menghapus lagu dari playlist
  * Melihat daftar lagu favorit
* **Pemutaran Musik**

  * **Putar dari Library**
    Memutar lagu tertentu dan secara otomatis membuat antrean lagu lain dengan genre yang sama.
  * **Putar dari Playlist**
    Memutar lagu secara berurutan sesuai isi playlist.
* **Navigasi Lagu**

  * **Next** untuk memutar lagu berikutnya
  * **Prev** untuk kembali ke lagu sebelumnya

## Struktur Data yang Digunakan

1. **Binary Search Tree (BST)**

   * Digunakan untuk menyimpan pustaka lagu utama (library).
   * Memungkinkan operasi insert, search, dan delete lagu berdasarkan ID secara efisien.

2. **Doubly Linked List (DLL)**

   * Digunakan untuk mengelola playlist user.
   * Mendukung navigasi dua arah (Next dan Prev) dengan mudah.

3. **Queue (Antrean)**

   * Digunakan pada fitur pemutaran lagu dengan genre yang sama.
   * Menyimpan urutan lagu yang akan diputar selanjutnya berdasarkan prinsip FIFO (First In First Out).

## Struktur File

* `TUBES.h`
  Berisi definisi struktur data (Lagu, BSTNode, DLLNode, QueueNode) serta prototipe fungsi.
* `TUBES.cpp`
  Berisi implementasi seluruh fungsi manajemen BST, DLL, Queue, dan alur menu aplikasi.
* `main.cpp`
  Merupakan entry point aplikasi yang menangani inisialisasi data awal serta pemilihan peran (Admin/User).

## Cara Menjalankan 

1. Kompilasi: Pastikan Anda memiliki compiler C++ (seperti GCC). Jalankan perintah 
berikut di terminal: 

g++ -o aplikasi_musik main.cpp TUBES.cpp 

2. Jalankan 

./aplikasi_musik 


