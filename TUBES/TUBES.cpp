#include "TUBES.h"
using namespace std;

BSTNode* createBSTNode(Lagu lagu) {
    BSTNode* P = new BSTNode;
    P->info = lagu;
    P->left = nullptr;
    P->right = nullptr;
    return P;
}

BSTNode* insertBST(BSTNode* node, Lagu lagu) {
    if (node == nullptr) {
        return createBSTNode(lagu);
    }
    if (lagu.id < node->info.id) {
        node->left = insertBST(node->left, lagu);
    } else if (lagu.id > node->info.id) {
        node->right = insertBST(node->right, lagu);
    } else {
        cout << "ID sudah ada!\n";
    }

    return node;
}

void inorderBST(BSTNode* node) {
    if (node != nullptr) {
        inorderBST(node->left);
        cout << "ID: " << node->info.id
             << " | " << node->info.judul
             << " - " << node->info.penyanyi
             << " (" << node->info.genre << ", " << node->info.tahun << ")\n";
        inorderBST(node->right);
    }
}

Lagu* findNodeBST(BSTNode* node, int id) {
    if (node == nullptr) {
        return nullptr;
    } else if (node->info.id == id) {
        return &(node->info);
    } else if (id < node->info.id) {
        return findNodeBST(node->left, id);
    }
    return findNodeBST(node->right, id);
}

BSTNode* findMin(BSTNode* node) {
    while (node != nullptr && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BSTNode* deleteBST(BSTNode* node, int id) {
    if (node == nullptr) {
        return node;
    }
    if (id < node->info.id) {
        node->left = deleteBST(node->left, id);
    } else if (id > node->info.id) {
        node->right = deleteBST(node->right, id);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        else {
            BSTNode* temp = findMin(node->right);
            node->info = temp->info;
            node->right = deleteBST(node->right, temp->info.id);
        }
    }
    return node;
}

void collectByGenre(BSTNode* node, string genre, Lagu hasil[], int& count, int max) {
    if (node == nullptr || count >= max) return;

    collectByGenre(node->left, genre, hasil, count, max);

    if (node->info.genre == genre && count < max) {
        hasil[count] = node->info;
        count++;
    }

    collectByGenre(node->right, genre, hasil, count, max);
}

void tampilkanLagu(Lagu lagu) {
    cout << "ID: " << lagu.id
         << " | " << lagu.judul
         << " - " << lagu.penyanyi
         << " (" << lagu.genre << ", " << lagu.tahun << ")\n";
}

void searchByJudul(BSTNode* node, string judul, bool &found) {
    if (node == nullptr) return;
    searchByJudul(node->left, judul, found);
    if (node->info.judul == judul) {
        tampilkanLagu(node->info);
        found = true;
    }
    searchByJudul(node->right, judul, found);
}

void searchByPenyanyi(BSTNode* node, string penyanyi, bool &found) {
    if (node == nullptr) return;
    searchByPenyanyi(node->left, penyanyi, found);
    if (node->info.penyanyi == penyanyi) {
        tampilkanLagu(node->info);
        found = true;
    }
    searchByPenyanyi(node->right, penyanyi, found);
}

void searchByGenre(BSTNode* node, string genre, bool &found) {
    if (node == nullptr) return;
    searchByGenre(node->left, genre, found);
    if (node->info.genre == genre) {
        tampilkanLagu(node->info);
        found = true;
    }
    searchByGenre(node->right, genre, found);
}

void searchByTahun(BSTNode* node, int tahun, bool &found) {
    if (node == nullptr) return;
    searchByTahun(node->left, tahun, found);
    if (node->info.tahun == tahun) {
        tampilkanLagu(node->info);
        found = true;
    }
    searchByTahun(node->right, tahun, found);
}

void createDLL(DLL &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyDLL(DLL L) {
    return L.first == nullptr;
}

DLLNode* createDLLNode(Lagu* lagu) {
    DLLNode* P = new DLLNode;
    P->info = lagu;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertLastDLL(DLL &L, Lagu* lagu) {
    DLLNode* P = createDLLNode(lagu);

    if (isEmptyDLL(L)) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }

    cout << "Lagu ditambahkan ke playlist: " << lagu->judul << "\n";
}

void deleteDLL(DLL &L, int id) {
    if (isEmptyDLL(L)) {
        cout << "Playlist kosong.\n";
        return;
    }

    DLLNode* P = L.first;

    while (P != nullptr) {
        if (P->info->id == id) {
            if (P == L.first && P == L.last) {
                L.first = nullptr;
                L.last = nullptr;
            }
            else if (P == L.first) {
                L.first = P->next;
                L.first->prev = nullptr;
            }
            else if (P == L.last) {
                L.last = P->prev;
                L.last->next = nullptr;
            }
            else {
                P->prev->next = P->next;
                P->next->prev = P->prev;
            }

            cout << "Lagu dihapus dari playlist: " << P->info->judul << "\n";
            delete P;
            return;
        }
        P = P->next;
    }

    cout << "Lagu tidak ditemukan.\n";
}

void displayDLL(DLL L) {
    if (isEmptyDLL(L)) {
        cout << "Playlist kosong.\n";
        return;
    }

    DLLNode* P = L.first;

    cout << "\n=== PLAYLIST ===\n";
    while (P != nullptr) {
        cout << "ID: " << P->info->id
             << " | " << P->info->judul
             << " - " << P->info->penyanyi << "\n";
        P = P->next;
    }
}

void createQueue(Queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == nullptr;
}

void enqueue(Queue &Q, Lagu lagu) {
    QueueNode* P = new QueueNode;
    P->info = lagu;
    P->next = nullptr;

    if (isEmptyQueue(Q)) {
        Q.head = P;
        Q.tail = P;
    } else {
        Q.tail->next = P;
        Q.tail = P;
    }
}

Lagu* dequeue(Queue &Q) {
    if (isEmptyQueue(Q)){
        return nullptr;
    }

    QueueNode* P = Q.head;
    Lagu* hasil = new Lagu(P->info);

    Q.head = Q.head->next;
    if (Q.head == nullptr){
        Q.tail = nullptr;
    }

    delete P;
    P = nullptr;

    return hasil;
}

void clearQueue(Queue &Q) {
    while (!isEmptyQueue(Q)){
            dequeue(Q);
    }
}

void adminTambahLagu(BSTNode*& root) {
    Lagu lagu;
    cout << "\n=== TAMBAH LAGU ===\n";

    cout << "ID: ";
    cin >> lagu.id;

    if (findNodeBST(root, lagu.id) != nullptr) {
        cout << "ID sudah ada! Masukkan ID lain.\n";
        return;
    }

    cout << "Judul (tanpa spasi): ";
    cin >> lagu.judul;

    cout << "Penyanyi (tanpa spasi): ";
    cin >> lagu.penyanyi;

    cout << "Genre (tanpa spasi): ";
    cin >> lagu.genre;

    cout << "Tahun: ";
    cin >> lagu.tahun;

    root = insertBST(root, lagu);
    cout << "Lagu berhasil ditambahkan!\n";
}

void adminLihatLagu(BSTNode* root) {
    cout << "\n=== SEMUA LAGU ===\n";
    if (root == nullptr) {
        cout << "Library kosong.\n";
    } else {
        inorderBST(root);
    }
}

void adminUpdateLagu(BSTNode* root) {
    int id;
    cout << "\nMasukkan ID lagu yang ingin diupdate: ";
    cin >> id;

    Lagu* lagu = findNodeBST(root, id);

    if (lagu == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
        return;
    }

    cout << "Judul baru (tanpa spasi): ";
    cin >> lagu->judul;

    cout << "Penyanyi baru (tanpa spasi): ";
    cin >> lagu->penyanyi;

    cout << "Genre baru (tanpa spasi): ";
    cin >> lagu->genre;

    cout << "Tahun baru: ";
    cin >> lagu->tahun;

    cout << "Update berhasil.\n";
}

void adminHapusLagu(BSTNode*& root, DLL &playlist) {
    int id;
    cout << "\nID lagu yang ingin dihapus: ";
    cin >> id;

    if (findNodeBST(root, id) == nullptr) {
        cout << "Lagu dengan ID tersebut tidak ditemukan.\n";
        return;
    }

    hapusDariSemuaPlaylist(playlist, id);
    root = deleteBST(root, id);
    cout << "Lagu berhasil dihapus dari library.\n";
}

void menuAdmin(BSTNode*& root, DLL &playlist) {
    int pilih;
    do {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Tambah Lagu\n";
        cout << "2. Lihat Semua Lagu\n";
        cout << "3. Update Lagu\n";
        cout << "4. Hapus Lagu\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) adminTambahLagu(root);
        else if (pilih == 2) adminLihatLagu(root);
        else if (pilih == 3) adminUpdateLagu(root);
        else if (pilih == 4) adminHapusLagu(root, playlist);

    } while (pilih != 5);
}

void userCariLagu(BSTNode* root) {
    int pilihan;
    bool found = false;

    cout << "\n=== CARI LAGU ===\n";
    cout << "1. Berdasarkan ID\n";
    cout << "2. Berdasarkan Judul\n";
    cout << "3. Berdasarkan Penyanyi\n";
    cout << "4. Berdasarkan Genre\n";
    cout << "5. Berdasarkan Tahun\n";
    cout << "Pilih: ";
    cin >> pilihan;

    if (pilihan == 1) {
        int id;
        cout << "Masukkan ID: ";
        cin >> id;

        Lagu* lagu = findNodeBST(root, id);
        if (lagu == nullptr)
            cout << "Lagu tidak ditemukan.\n";
        else
            tampilkanLagu(*lagu);
    }
    else if (pilihan == 2) {
        string judul;
        cout << "Judul (tanpa spasi): ";
        cin >> judul;

        searchByJudul(root, judul, found);
        if (!found) cout << "Lagu tidak ditemukan.\n";
    }
    else if (pilihan == 3) {
        string penyanyi;
        cout << "Penyanyi (tanpa spasi): ";
        cin >> penyanyi;

        searchByPenyanyi(root, penyanyi, found);
        if (!found) cout << "Lagu tidak ditemukan.\n";
    }
    else if (pilihan == 4) {
        string genre;
        cout << "Genre (tanpa spasi): ";
        cin >> genre;

        searchByGenre(root, genre, found);
        if (!found) cout << "Lagu tidak ditemukan.\n";
    }
    else if (pilihan == 5) {
        int tahun;
        cout << "Tahun: ";
        cin >> tahun;

        searchByTahun(root, tahun, found);
        if (!found) cout << "Lagu tidak ditemukan.\n";
    }
    else {
        cout << "Pilihan tidak valid.\n";
    }
}

void userLihatSemuaLagu(BSTNode* root) {
    cout << "\n=== SEMUA LAGU ===\n";
    if (root == nullptr) {
        cout << "Library kosong.\n";
    } else {
        inorderBST(root);
    }
}

void userPutarDariLibrary(BSTNode* root, Lagu*& currentSong, bool& isPlayingFromPlaylist, Queue& queueMirip) {
    int id;
    cout << "\nID lagu yang ingin diputar: ";
    cin >> id;

    Lagu* lagu = findNodeBST(root, id);
    if (!lagu) {
        cout << "Tidak ditemukan.\n";
        return;
    }

    currentSong = lagu;
    isPlayingFromPlaylist = false;

    clearQueue(queueMirip);

    Lagu mirip[10];
    int count = 0;

    collectByGenre(root, lagu->genre, mirip, count, 10);

    for (int i = 0; i < count; i++) {
        if (mirip[i].id != lagu->id)
            enqueue(queueMirip, mirip[i]);
    }

    cout << "Memutar: " << lagu->judul << " - " << lagu->penyanyi << "\n";
}

void userPutarDariPlaylist(DLL& playlist, Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool& isPlayingFromPlaylist) {
    if (isEmptyDLL(playlist)) {
        cout << "Playlist kosong.\n";
        return;
    }

    currentPlaylistNode = playlist.first;
    currentSong = (currentPlaylistNode->info);
    isPlayingFromPlaylist = true;

    cout << "Memutar: " << currentSong->judul << " - " << currentSong->penyanyi << "\n";
}

void userNext(Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool isPlayingFromPlaylist, Queue& queueMirip) {
    if (!currentSong) {
        cout << "Tidak ada lagu yang sedang diputar.\n";
        return;
    }

    if (isPlayingFromPlaylist) {
        if (currentPlaylistNode->next) {
            currentPlaylistNode = currentPlaylistNode->next;
            currentSong = (currentPlaylistNode->info);
            cout << "Next: " << currentSong->judul << "\n";
        } else {
            cout << "Sudah di akhir playlist.\n";
        }
    }
    else {
        Lagu* next = dequeue(queueMirip);
        if (!next) {
            cout << "Tidak ada lagu mirip lagi.\n";
        } else {
            currentSong = next;
            cout << "Next (lagu mirip): " << next->judul << "\n";
        }
    }
}

void userPrev(Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool isPlayingFromPlaylist) {
    if (!currentSong) {
        cout << "Tidak ada lagu yang sedang diputar.\n";
        return;
    }

    if (!isPlayingFromPlaylist) {
        cout << "Prev hanya tersedia saat memutar dari playlist.\n";
        return;
    }

    if (currentPlaylistNode->prev) {
        currentPlaylistNode = currentPlaylistNode->prev;
        currentSong = (currentPlaylistNode->info);
        cout << "Prev: " << currentSong->judul << "\n";
    }
    else {
        cout << "Sudah di awal playlist.\n";
    }
}

void hapusDariSemuaPlaylist(DLL& playlist, int id) {
    DLLNode* P = playlist.first;

    while (P != nullptr) {
        DLLNode* next = P->next;

        if (P->info->id == id) {
            if (P == playlist.first && P == playlist.last) {
                playlist.first = nullptr;
                playlist.last = nullptr;
            }
            else if (P == playlist.first) {
                playlist.first = P->next;
                playlist.first->prev = nullptr;
            }
            else if (P == playlist.last) {
                playlist.last = P->prev;
                playlist.last->next = nullptr;
            }
            else {
                P->prev->next = P->next;
                P->next->prev = P->prev;
            }

            delete P;
            cout << "[Auto] Lagu dihapus dari playlist.\n";
        }

        P = next;
    }

}

void userTambahKePlaylist(BSTNode* root, DLL& playlist) {
    int id;
    cout << "ID lagu yang ingin ditambahkan: ";
    cin >> id;

    Lagu* lagu = findNodeBST(root, id);
    if (lagu == nullptr) {
        cout << "Lagu tidak ditemukan.\n";
    } else {
        insertLastDLL(playlist, lagu);
    }
}

void userHapusDariPlaylist(DLL& playlist) {
    int id;
    cout << "ID lagu yang ingin dihapus: ";
    cin >> id;
    deleteDLL(playlist, id);
}

void userLihatPlaylist(DLL& playlist) {
    displayDLL(playlist);
}

void userStopLagu(Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool& isPlayingFromPlaylist) {
    if (!currentSong) {
        cout << "Tidak ada lagu yang sedang diputar.\n";
    } else {
        cout << "Stop: " << currentSong->judul << "\n";
        currentSong = nullptr;
        currentPlaylistNode = nullptr;
        isPlayingFromPlaylist = false;
    }
}

void menuUser(BSTNode* root, DLL& playlist, Queue& queueMirip, Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool& isPlayingFromPlaylist) {
    int pilih;
    do {
        cout << "\n=== MENU USER ===\n";
        cout << "1. Cari Lagu\n";
        cout << "2. Lihat Semua Lagu\n";
        cout << "3. Putar dari Library\n";
        cout << "4. Putar Playlist\n";
        cout << "5. Next\n";
        cout << "6. Prev\n";
        cout << "7. Tambah ke Playlist\n";
        cout << "8. Hapus dari Playlist\n";
        cout << "9. Lihat Playlist\n";
        cout << "10. Stop Lagu\n";
        cout << "11. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) userCariLagu(root);
        else if (pilih == 2) userLihatSemuaLagu(root);
        else if (pilih == 3) userPutarDariLibrary(root, currentSong, isPlayingFromPlaylist, queueMirip);
        else if (pilih == 4) userPutarDariPlaylist(playlist, currentSong, currentPlaylistNode, isPlayingFromPlaylist);
        else if (pilih == 5) userNext(currentSong, currentPlaylistNode, isPlayingFromPlaylist, queueMirip);
        else if (pilih == 6) userPrev(currentSong, currentPlaylistNode, isPlayingFromPlaylist);
        else if (pilih == 7) userTambahKePlaylist(root, playlist);
        else if (pilih == 8) userHapusDariPlaylist(playlist);
        else if (pilih == 9) userLihatPlaylist(playlist);
        else if (pilih == 10) userStopLagu(currentSong, currentPlaylistNode, isPlayingFromPlaylist);

    } while (pilih != 11);
}

