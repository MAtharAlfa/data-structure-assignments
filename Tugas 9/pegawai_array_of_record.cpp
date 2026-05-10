/*
Nama Program : Pengelola Gaji Pegawai Array of Record
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 29/04/2026
Deskripsi    : Program akan menampilkan gaji pegawai sesuai dengan golongan yang didapat dengan menggunakan
               struktur data Array
*/

const int SHORT_WIDTH = 5;
const int long LONG_WIDTH = 15;

#include <iostream>
#include <iomanip>

struct Pegawai {
    std::string NIP;
    std::string nama;
    int gol;
};

typedef Pegawai Larik[100];

bool checkFound(bool found);
void inputLarik(Larik& pegawai, int n, int i);
void initLarik(Larik& pegawai, int& n);
int linearSearch(Larik pegawai, int n, bool& found, std::string key);
void insertAfter(Larik& pegawai, int& n, bool found, int index);
void deleteCurrent(Larik& pegawai, int& n, bool found, int index);
long long getGaji(Larik pegawai, int i);
long long getTunjangan(Larik pegawai, int i);
long long getTotal(Larik pegawai, int i);
long long getJumlahGaji(Larik pegawai, int n);
long long getJumlahTunjangan(Larik pegawai, int n);
long long getJumlahTotal(Larik pegawai, int n);
long long getRata(Larik pegawai, int n);
void printTable(Larik pegawai, int n);
int getChoice();
void printChoices();
void runMenu(Larik& pegawai, int n);

bool checkFound(bool found) {
    if (!found) 
    {
        std::cerr << "Nilai tidak ditemukan!";
        return false;
    }

    return true;
}

void inputLarik(Larik& pegawai, int n, int i) {
    std::cout << "Masukan NIP: ";
    std::cin >> pegawai[i].NIP;

    std::cout << "Masukan nama: ";
    std::cin.ignore();
    std::getline(std::cin, pegawai[i].nama);

    std::cout << "Masukan Gol: ";
    std::cin >> pegawai[i].gol;
    std::cout << "\n";
}

void initLarik(Larik& pegawai, int& n) {
    int i = 0;

    std::cout << "Total data: ";
    std::cin >> n;

    while (i < n)
    {
        inputLarik(pegawai, n, i);    
        i++;
    }
}

int linearSearch(Larik pegawai, int n, bool& found, std::string key) {
    found = 0; int index = 0;

    while (index < n && !found)
    {
        if (pegawai[index].NIP == key)
        {
            found = 1;
            return index;
        }

        index++;
    }
    
    return -1;
}

void insertAfter(Larik& pegawai, int& n, bool found, int index) {
    if (!checkFound(found)) return;

    n++; int i = n;

    while (i > index + 1)
    {
        pegawai[i] = pegawai[i-1];

        i--;
    }
    
    inputLarik(pegawai, n, index + 1);
}

void deleteCurrent(Larik& pegawai, int& n, bool found, int index) {
    if (!checkFound(found)) return;

    int i = index;
    while (i < n)
    {
        pegawai[i] = pegawai[i+1];
        i++;
    }
    
    n--;
}

long long getGaji(Larik pegawai, int i) {
    if (pegawai[i].gol == 1) return 3000000;
    if (pegawai[i].gol == 2) return 4000000;
    if (pegawai[i].gol == 3) return 5000000;

    return -1;
}

long long getTunjangan(Larik pegawai, int i) {
    if (pegawai[i].gol == 1) return (long long)getGaji(pegawai, i)*1;
    if (pegawai[i].gol == 2) return (long long)getGaji(pegawai, i)*1.25;
    if (pegawai[i].gol == 3) return (long long)getGaji(pegawai, i)*1.5;

    return -1;
}

long long getTotal(Larik pegawai, int i) {
    long long total = 0;

    total += getGaji(pegawai, i);
    total += getTunjangan(pegawai, i);

    return total;
}

long long getJumlahGaji(Larik pegawai, int n) {
    long long jumlah = 0;

    int i = 0;
    while (i < n)
    {
        jumlah += getGaji(pegawai, i);
        i++;
    }
    
    return jumlah;
}

long long getJumlahTunjangan(Larik pegawai, int n) {
    long long jumlah = 0;

    int i = 0;
    while (i < n)
    {
        jumlah += getTunjangan(pegawai, i);
        i++;
    }
    
    return jumlah;
}

long long getJumlahTotal(Larik pegawai, int n) {
    long long jumlah = 0;

    int i = 0;
    while (i < n)
    {
        jumlah += getTotal(pegawai, i);
        i++;
    }
    
    return jumlah;
}

long long getRata(Larik pegawai, int n) {
    int i = 0; long long jumlah = 0;

    while (i < n)
    {
        jumlah += getTotal(pegawai, i);

        i++;
    }
    
    return (long long)jumlah/n;
}

void printTable(Larik pegawai, int n) {
    int i = 0; int nomor = 1;

    std::cout << std::setw(25) << " " << "DAFTAR GAJI PEGAWAI PT. INFORMATIKA\n";
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    std::cout << std::setw(SHORT_WIDTH) << "Nomor"
        << std::setw(LONG_WIDTH) << "NIP"
        << std::setw(LONG_WIDTH) << "Nama"
        << std::setw(SHORT_WIDTH) << "Gol"
        << std::setw(LONG_WIDTH) << "Gaji"
        << std::setw(LONG_WIDTH) << "Tunjangan"
        << std::setw(LONG_WIDTH) << "Total" << "\n";
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    while (i < n)
    {
        std::cout << std::setw(SHORT_WIDTH) << nomor
        << std::setw(LONG_WIDTH) << pegawai[i].NIP
        << std::setw(LONG_WIDTH) << pegawai[i].nama
        << std::setw(SHORT_WIDTH) << pegawai[i].gol
        << std::setw(LONG_WIDTH) << getGaji(pegawai, i)
        << std::setw(LONG_WIDTH) << getTunjangan(pegawai, i)
        << std::setw(LONG_WIDTH) << getTotal(pegawai, i) << "\n";

        i++; nomor++;
    }
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    std::cout << std::setw(SHORT_WIDTH + LONG_WIDTH) << "Jumlah: " << std::setw(LONG_WIDTH + SHORT_WIDTH) << " "
    << std::setw(LONG_WIDTH) << getJumlahGaji(pegawai, n)
    << std::setw(LONG_WIDTH) << getJumlahTunjangan(pegawai, n)
    << std::setw(LONG_WIDTH) << getJumlahTotal(pegawai, n) << "\n";
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    std::cout << "Rata-rata Gaji: " << getRata(pegawai, n) << "\n"; 
}

int getChoice() {
    int choice = 0;

    std::cout << "Masukan pilihan: ";
    std::cin >> choice;
    
    return choice;
}

void printChoices() {
    std::cout << "\n\nPILIHAN TABEL\n"
    << "1. Print tabel\n"
    << "2. Masukan data setelah suatu NIP\n"
    << "3. Hapus data NIP\n"
    << "0. keluar\n";
}

void runMenu(Larik& pegawai, int n) {
    int choice = -1;
    do
    {
        printChoices();
        choice = getChoice();

        switch (choice)
        {
        case 1:
            printTable(pegawai, n);
            break;
        case 2:
        {
            bool found = 0; std::string key = "";

            std::cout << "Masukan setelah NIP: ";
            std::cin >> key;
            int index = linearSearch(pegawai, n, found, key);

            if(!found)
            {
                std::cerr << "Data tidak ditemukan!\n";
                break;
            }

            std::cout << "\nDitemukan!\n\nMasukan Data!\n";

            insertAfter(pegawai, n, found, index);
            break;
        }
        case 3:
        {
            bool found = 0; std::string key = "";

            std::cout << "Masukan setelah NIP: ";
            std::cin >> key;
            int index = linearSearch(pegawai, n, found, key);

            if(!found)
            {
                std::cerr << "Data tidak ditemukan!\n";
                break;
            }

            deleteCurrent(pegawai, n, found, index);
            std::cout << "\nDitemukan!\nData berhasil dihapus!\n";

            break;
        }
        
        default:
            std::cout << "Terima kasih sudah menggunakan program ini!";
            break;
        }
    } while (choice != 0);
}

int main() {
    int n = 0; Larik pegawai; 
    initLarik(pegawai, n);
    runMenu(pegawai, n);
}