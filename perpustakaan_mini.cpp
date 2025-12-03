#include <iostream>
#include <fstream>

using namespace std;

struct Buku {
    string judul;
    string pengarang;
    int tahunTerbit;
    int jumlah;
};

void loadData(Buku buku[], int &jumlahData);
void tampilkanData(Buku buku[], int &jumlahData);
void tambahData(Buku *buku[]);
void saveData(Buku buku[], int &jumlahData);

int main() {

    Buku buku[100];
    int jumlahData = 0;
    loadData(buku, jumlahData);
    int pilihan = 0;
    
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
            tampilkanData(buku, jumlahData);
        } else if(pilihan == 4) {
            cout << "Cari Buku" << endl;
        } else if(pilihan == 5) {
            tambahData(&buku[jumlahData]);
            jumlahData++;
            
        } else if(pilihan == 6) {
            cout << "Update Buku" << endl;
        } else if(pilihan == 7) {
            cout << "Hapus Buku" << endl;
        } else if(pilihan == 8) {
            saveData(buku, jumlahData);
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
        
    } while (pilihan != 8);
    
    return 0;
}

void loadData(Buku buku[], int &jumlahData) {
    ifstream file("buku.txt");
    if(file.is_open()) {
        while(file >> buku[jumlahData].judul >> buku[jumlahData].pengarang >> buku[jumlahData].tahunTerbit >> buku[jumlahData].jumlah) {
            jumlahData++;
        }
        file.close();
    } else {
        ofstream file("buku.txt");
        file.close();
        cout << "File buku.txt tidak ditemukan, file baru telah dibuat." << endl;
    }
}

void tampilkanData(Buku buku[], int &jumlahData) {
    for(int i = 0; i < jumlahData; i++) {
        cout << "Judul: " << buku[i].judul << endl;
        cout << "Pengarang: " << buku[i].pengarang << endl;
        cout << "Tahun terbit: " << buku[i].tahunTerbit << endl;
        cout << "Jumlah: " << buku[i].jumlah << endl;
    }
}

void tambahData(Buku *buku) {
    cout << "Judul: ";
    getline(cin, buku->judul);

    cout << "Pengarang: ";
    getline(cin, buku->pengarang);

    cout << "Tahun terbit: ";
    cin >> buku->pengarang;
    
    cout << "Jumlah: ";
    cin >> buku->jumlah;
    cin.ignore();
}

void saveData(Buku buku[], int &jumlahData) {
    ofstream file;
    file.open("buku.txt", ios::app);
    for(int i = 0; i < jumlahData; i++) {
        file << buku[i].judul << " " << buku[i].pengarang << " " << buku[i].tahunTerbit << " " << buku[i].jumlah << endl;
    }
    file.close();
    cout << "Data berhasil disimpan" << endl;
}
