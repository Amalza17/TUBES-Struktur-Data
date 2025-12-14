#include "TUBES.h"
using namespace std;

int main() {

    BSTNode* root = nullptr;
    DLL playlist;
    Queue queueMirip;
    Lagu* currentSong = nullptr;
    DLLNode* currentPlaylistNode = nullptr;
    bool isPlayingFromPlaylist = false;

    createDLL(playlist);
    createQueue(queueMirip);

    root = insertBST(root, {1, "RockWithYou", "Seventeen", "Rock", 2017});
    root = insertBST(root, {2, "ShapeOfYou", "EdSheeran", "Pop", 2019});
    root = insertBST(root, {3, "Overdose", "Exo", "Rock", 2017});
    root = insertBST(root, {4, "Happier", "EdSheeran", "Pop", 2018});
    root = insertBST(root, {5, "PrettyU", "Seventeen", "Pop", 2016});

    int role;

    do {
        cout << "\n=== APLIKASI MUSIK ===\n";
        cout << "1. Login Admin\n";
        cout << "2. Login User\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> role;

        if (role == 1) {
            menuAdmin(root, playlist);
        }
        else if (role == 2) {
            menuUser(root, playlist, queueMirip,
                     currentSong, currentPlaylistNode,
                     isPlayingFromPlaylist);
        }

    } while (role != 3);

    return 0;
}
