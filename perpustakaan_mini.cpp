#include <iostream>
#include <fstream>

using namespace std;

struct Buku {
    string judul;
    string pengarang;
    int tahunTerbit;
    int jumlah;
};

int main() {

    int pilihan;
    
    cout << "-----Selamat datang di Perpustakaan Mini-----" << endl;
    cout << "1. Peminjaman Buku" << endl;
    cout << "2. Pengembalian Buku" << endl;
    cout << "3. Lihat Daftar Buku" << endl;
    cout << "4. Cari Buku" << endl;
    cout << "5. Tambah Buku" << endl;
    cout << "6. Update Buku" << endl;
    cout << "7. Hapus Buku" << endl;
    cout << "8. Exit" << endl;

    do
    {
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        if(pilihan == 1) {
            cout << "Peminjaman Buku" << endl;
        } else if(pilihan == 2) {
            cout << "Pengembalian Buku" << endl;
        } else if(pilihan == 3) {
            cout << "Lihat Daftar Buku" << endl;
        } else if(pilihan == 4) {
            cout << "Cari Buku" << endl;
        } else if(pilihan == 5) {
            cout << "Tambah Buku" << endl;
        } else if(pilihan == 6) {
            cout << "Update Buku" << endl;
        } else if(pilihan == 7) {
            cout << "Hapus Buku" << endl;
        } else if(pilihan == 8) {
            cout << "Exit" << endl;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
        
    } while (pilihan != 8);
    
    return 0;
}