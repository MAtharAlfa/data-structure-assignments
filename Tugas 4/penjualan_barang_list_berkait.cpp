/*
Nama Program : Pengelola Penjualan Barang Linked List
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 29/03/2026
Deskripsi    : Program akan mengelola data penjualan barang berikut ➔ Barang (kodeBrg, namaBrg, 
               harga, banyak) namun program ini akan ditulis dengan menggunakan data struktur list berkait
*/

const int SHORT_WIDTH = 5;
const int MEDIUM_WIDTH = 10;
const int LONG_WIDTH = 20; // for UI setw

#include <iostream>
#include <string>
#include <iomanip>

struct Barang {
    int kodeBrg;
    std::string namaBrg;
    int harga;
    int banyak;
};

struct NodeBarang {
    Barang barang;
    NodeBarang* next;
};


typedef NodeBarang* PtrToBarang;
typedef PtrToBarang List;

int getValueInt(int min = INT_MIN, int max = INT_MAX) {
    int input;

    while (true)
    {
        std::cin >> input;
    
        if (std::cin.fail() || input < min || input > max)
        {
            std::cout << "input tidak valid! silakan coba lagi\ninput: ";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            continue;
        }

        return input;
    }
}

//linkedlist

void createList(List& first) {
    first = nullptr;
}

void createElement(PtrToBarang& pBaru) {
    pBaru = new NodeBarang;

    std::cout << "Masukan kode barang\ninput: ";
    pBaru->barang.kodeBrg = getValueInt(0, 999);

    std::cout << "Masukan nama barang\ninput: ";
    std::cin >> pBaru->barang.namaBrg;

    std::cout << "Masukan harga barang\ninput: ";
    std::cin >> pBaru->barang.harga;

    std::cout << "Masukan jumlah barang\ninput: ";
    std::cin >> pBaru->barang.banyak;

    pBaru->next = nullptr;
}

void insertFirst(List& first, PtrToBarang& pBaru) {
    if (pBaru == nullptr) 
    {
        std::cout << "pointer baru mengarah ke NULL" << std::endl;
        return;
    }

    if (first == nullptr)
    {
        first = pBaru;
    } else {
        pBaru->next = first;
        first = pBaru;
    }
}

void traversalPrintList(List& first) {
    int baris = 1;
    PtrToBarang pBantu = nullptr;
    if (first == nullptr)
    {
        std::cout << "list kosong" << std::endl;
        return;
    } else
    {
        pBantu = first;
        do
        {
            std::cout << std::left << std::setw(SHORT_WIDTH) << baris 
            << std::right << std::setfill('0') << std::setw(3) << pBantu->barang.kodeBrg << std::left << std::setfill(' ') << std::setw(7) << " " //setw 7+3  == setw MEDIUM 
            << std::setw(LONG_WIDTH) << pBantu->barang.namaBrg 
            << std::setw(MEDIUM_WIDTH) << pBantu->barang.harga 
            << std::setw(MEDIUM_WIDTH) << pBantu->barang.banyak 
            << std::setw(LONG_WIDTH) << pBantu->barang.harga*pBantu->barang.banyak << "\n";
            pBantu = pBantu->next;

            baris++;
        } while (pBantu != nullptr);
    }
}

void deleteFirst(List& first, PtrToBarang& pHapus) {
    if (pHapus == nullptr)
    {
        std::cout << "pointe hapus mengarah ke NULL";
        return;
    }
    

    if (first == nullptr)
    {
        std::cout << "list kosong, tidak ada yang dihapus";
        return;
    } else if (first->next == nullptr) 
    {
        pHapus = first;
        delete pHapus;
        pHapus = nullptr;
        first = nullptr;
    } else 
    {
        pHapus = first;
        first = first->next;
        delete pHapus;
        pHapus = nullptr;
    }   
}

int getHighestList(List& first) {
    int highest = INT_MIN;
    
    PtrToBarang pBantu = nullptr;
    if (first == nullptr)
    {
        std::cout << "list kosong" << std::endl;
        return -1;
    } else
    {
        pBantu = first;
        do
        {
            if (pBantu->barang.harga > highest)
            {
                highest = pBantu->barang.harga;
            }
            
            pBantu = pBantu->next;
        } while (pBantu != nullptr);
    }

    return highest;
}

int getLowestList(List& first) {
    int lowest = INT_MAX;

    PtrToBarang pBantu = nullptr;
    if (first == nullptr)
    {
        std::cout << "list kosong" << std::endl;
        return -1;
    } else
    {
        pBantu = first;
        do
        {
            if (pBantu->barang.harga < lowest)
            {
                lowest = pBantu->barang.harga;
            }

            pBantu = pBantu->next;
        } while (pBantu != nullptr);
    }

    return lowest;
}


float getMeanPriceList(List& first) {
    int sum = 0;
    int totalList = 0;

    PtrToBarang pBantu = nullptr;
    if (first == nullptr)
    {
        std::cout << "list kosong" << std::endl;
        return -1;
    } else
    {
        pBantu = first;
        do
        {
            sum += pBantu->barang.harga;
            totalList++;

            pBantu = pBantu->next;
        } while (pBantu != nullptr);
    }

    return (float)sum/totalList;
}

int getSumJumlahList(List& first) {
    int sum = 0;
    PtrToBarang pBantu = nullptr;
    if (first == nullptr)
    {
        std::cout << "list kosong" << std::endl;
        return -1;
    } else
    {
        pBantu = first;
        do
        {
            sum += (pBantu->barang.banyak*pBantu->barang.harga);
            pBantu = pBantu->next;
        } while (pBantu != nullptr);
    }

    return sum;
}

void printOutputList(List barang) {
    std::cout << std::right << std::setfill(' '); // reset to normal state for concistency

    std::cout << "\n" << std::setw(50) << "Daftar Barang PT Informatika\n";

    // bagian atas
    std::cout << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') //75 total width dari setw
    << std::left << std::setw(SHORT_WIDTH) << "NO" << std::setw(MEDIUM_WIDTH) << "KODE" << std::setw(LONG_WIDTH) << "NAMA BARANG" 
    << std::setw(MEDIUM_WIDTH) << "HARGA" << std::setw(MEDIUM_WIDTH) << "BANYAK" << std::setw(LONG_WIDTH) << "JUMLAH"
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n";

    //bagian isi
    traversalPrintList(barang);
    
    //bagian jumlah total
    std::cout << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n"
    << std::left << std::setw(55) << "JUMLAH TOTAL:" << getSumJumlahList(barang)
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ');

    //bagian catatan
    std::cout << "\n" << "HARGA TERTINGGI: " << std::setw(MEDIUM_WIDTH) << getHighestList(barang) <<  "\n"
    << "HARGA TERENDAH: " << std::setw(MEDIUM_WIDTH) << getLowestList(barang) << "\n"
    << "RATA-RATA HARGA: " << std::setw(MEDIUM_WIDTH) << getMeanPriceList(barang)
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n";
}

int main() {
    std::cout << "Selamat datang di Program Pengelola Penjualan Barang!\n\n";

    List barang = nullptr;
    PtrToBarang pNew = nullptr;

    createList(barang);

    int input = -1;

    do
    {

        std::cout << "Pilih aksi yang ingin dilakukan:\n"
        << "1. Lihat Tabel\n"
        << "2. Masukan barang dari bawah barisan\n"
        << "0. Keluar\n\n";

        std::cout << "input: ";
        input = getValueInt(0, 3);

        switch (input)
        {
        case 0:
            std::cout << "\n\nTerima kasih sudah menggunakan program ini!"; 
            break;

        case 1 :
            if (barang == nullptr)
            {
                std::cout << "error: list kosong!\n\n";
                break;
            }
            
            printOutputList(barang);
            break;

        case 2 :
            createElement(pNew);
            insertFirst(barang, pNew);
            break;
        }
    } while (input != 0);
    

    return 0;
}