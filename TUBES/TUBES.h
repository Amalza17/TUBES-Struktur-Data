#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

struct Lagu {
    int id;
    string judul;
    string penyanyi;
    string genre;
    int tahun;
};

struct BSTNode {
    Lagu info;
    BSTNode* left;
    BSTNode* right;
};

struct DLLNode {
    Lagu* info;
    DLLNode* next;
    DLLNode* prev;
};

struct QueueNode {
    Lagu info;
    QueueNode* next;
};

struct DLL {
    DLLNode* first;
    DLLNode* last;
};

struct Queue {
    QueueNode* head;
    QueueNode* tail;
};

BSTNode* createBSTNode(Lagu lagu);
BSTNode* insertBST(BSTNode* node, Lagu lagu);
void inorderBST(BSTNode* node);
Lagu* findNodeBST(BSTNode* node, int id);
BSTNode* findMin(BSTNode* node);
BSTNode* deleteBST(BSTNode* node, int id);
void collectByGenre(BSTNode* node, string genre, Lagu hasil[], int& count, int max);
void tampilkanLagu(Lagu lagu);
void searchByJudul(BSTNode* node, string judul, bool &found);
void searchByPenyanyi(BSTNode* node, string penyanyi, bool &found);
void searchByGenre(BSTNode* node, string genre, bool &found);
void searchByTahun(BSTNode* node, int tahun, bool &found);
void createDLL(DLL &L);
bool isEmptyDLL(DLL L);
DLLNode* createDLLNode(Lagu* lagu);
void insertLastDLL(DLL &L, Lagu* lagu);
void deleteDLL(DLL &L, int id);
void displayDLL(DLL L);
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
void enqueue(Queue &Q, Lagu lagu);
Lagu* dequeue(Queue &Q);
void clearQueue(Queue &Q);
void adminTambahLagu(BSTNode*& root);
void adminLihatLagu(BSTNode* root);
void adminUpdateLagu(BSTNode* root);
void adminHapusLagu(BSTNode*& root, DLL& playlist);
void menuAdmin(BSTNode*& root, DLL &playlist);
void userCariLagu(BSTNode* root);
void userLihatSemuaLagu(BSTNode* root);
void userPutarDariLibrary(BSTNode* root, Lagu*& currentSong, bool& isPlayingFromPlaylist, Queue& queueMirip);
void userPutarDariPlaylist(DLL& playlist, Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool& isPlayingFromPlaylist);
void userNext(Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool isPlayingFromPlaylist, Queue& queueMirip);
void userPrev(Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool isPlayingFromPlaylist);
void hapusDariSemuaPlaylist(DLL& playlist, int id);
void userTambahKePlaylist(BSTNode* root, DLL& playlist);
void userHapusDariPlaylist(DLL& playlist);
void userLihatPlaylist(DLL& playlist);
void userStopLagu(Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool& isPlayingFromPlaylist);
void menuUser(BSTNode* root, DLL& playlist, Queue& queueMirip, Lagu*& currentSong, DLLNode*& currentPlaylistNode, bool& isPlayingFromPlaylist);

#endif // TUBES_H_INCLUDED
