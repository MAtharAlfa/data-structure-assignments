/*
Nama Program : Pengelola Penjualan Barang Doubly Linked List
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 19/04/2026
Last Updated : 26/04/2026 
Deskripsi    : Program akan mengelola data penjualan barang berikut ➔ Barang (kodeBrg, namaBrg, 
               harga, banyak) namun program ini akan ditulis dengan menggunakan 
               struktur data doubly linked list
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
    NodeBarang* prev;
};


typedef NodeBarang* Pointer;
typedef Pointer List;

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
void createList(List& first);
void createElement(Pointer& pBaru);
void insertFirst(List& first, Pointer& pBaru);
void traversalPrintList(const List first);
void deleteFirst(List& first, Pointer& pHapus);
void deleteLast(List& first, Pointer& pHapus);
void linearSearch(List first, int key, int& found, Pointer& pSearch);
bool isFound(int found);
void insertAfter(List& first, Pointer& pSearch, Pointer& pNew);
void deleteAfter(List& first, Pointer& pSearch, Pointer& pHapus);
void deleteCurrent(List& first, Pointer& pSearch, Pointer& pHapus);
int getSumJumlahList(const List first);
float getMeanPriceList(const List first);
int getLowestList(const List first);
int getHighestList(const List first);
void printOutputList(const List barang);
void destroyList(List& first);



void createList(List& first) {
    first = nullptr;
}

void createElement(Pointer& pBaru) {
    pBaru = new NodeBarang;

    std::cout << "Masukan kode barang\ninput: ";
    pBaru->barang.kodeBrg = getValueInt(0, 999);

    std::cout << "Masukan nama barang\ninput: ";
    std::cin.ignore();
    std::getline(std::cin, pBaru->barang.namaBrg);

    std::cout << "Masukan harga barang\ninput: ";
    pBaru->barang.harga = getValueInt();

    std::cout << "Masukan jumlah barang\ninput: ";
    pBaru->barang.banyak = getValueInt();

    pBaru->next = nullptr;
    pBaru->prev = nullptr;
}

void insertFirst(List& first, Pointer& pBaru) {
    if (!first)
    {
        first = pBaru;
    } else 
    {
        pBaru->next = first;
        first->prev = pBaru;
        first = pBaru;
    }
}

void insertLast(List& first, Pointer& pBaru) {
    if (!first) 
    {
        first = pBaru;
    } else 
    {
        Pointer pLast = first;

        while (pLast->next != nullptr)
        {
            pLast = pLast->next;
        }
        
        pBaru->prev = pLast;
        pLast->next = pBaru;
    }
}

void traversalForward(List first) {
    if (first == nullptr)
    {
        std::cout << "list kosong" << std::endl;
        return;
    } else
    {
        Pointer pBantu = first;
        int list = 1;

        do
        {
            std::cout << std::left << std::setw(SHORT_WIDTH) << list 
            << std::right << std::setfill('0') << std::setw(3) << pBantu->barang.kodeBrg << std::left << std::setfill(' ') << std::setw(7) << " " //setw 7+3  == setw MEDIUM 
            << std::setw(LONG_WIDTH) << pBantu->barang.namaBrg 
            << std::setw(MEDIUM_WIDTH) << pBantu->barang.harga 
            << std::setw(MEDIUM_WIDTH) << pBantu->barang.banyak 
            << std::setw(LONG_WIDTH) << pBantu->barang.harga*pBantu->barang.banyak << "\n";
            pBantu = pBantu->next;

            list++;
        } while (pBantu != nullptr);
    }
}

Pointer deleteFirst(List& first) {
    Pointer pHapus = nullptr;

    if (!first)
    {
        std::cout << "list kosong, tidak ada yang dihapus\n\n";
        
        return nullptr;
    } else if (!first->next) 
    {
        pHapus = first;
        first = nullptr;

        return pHapus;
    } else 
    {
        pHapus = first;
        first = first->next;
        first->prev = nullptr;
        pHapus->next = nullptr;

        return pHapus;
    }   
}

Pointer deleteLast(List& first) {
    Pointer pHapus = nullptr;

    if(!first)
    {
        std::cout << "list kosong, tidak ada yang dihapus\n\n";

        return nullptr;
    } else if (!first->next)
    {
        pHapus = first;
        first = nullptr;

        return pHapus;
    } else 
    {
        Pointer pLast = first;

        while (pLast->next != nullptr)
        {
            pLast = pLast->next;
        }
        
        pHapus = pLast;
        pLast->prev->next = nullptr;
        pLast->prev = nullptr;

        return pHapus;
    }
}

int getHighest(List& first) {
    int highest = INT_MIN;
    
    Pointer pBantu = nullptr;
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

int getLowest(List& first) {
    int lowest = INT_MAX;

    Pointer pBantu = nullptr;
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


float getMeanPrice(List& first) {
    int sum = 0;
    int totalList = 0;

    if (first == nullptr)
    {
        std::cout << "list kosong" << std::endl;
        return -1;
    } else
    {
        Pointer pBantu = first;
        do
        {
            sum += pBantu->barang.harga;
            totalList++;

            pBantu = pBantu->next;
        } while (pBantu != nullptr);
    }

    return (float)sum/totalList;
}

int getSumJumlah(List& first) {
    int sum = 0;
    if (first == nullptr)
    {
        std::cout << "list kosong" << std::endl;
        return -1;
    } else
    {
        Pointer pBantu = first;
        do
        {
            sum += (pBantu->barang.banyak * pBantu->barang.harga);

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
    traversalForward(barang) 
    
    //bagian jumlah total
    std::cout << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n"
    << std::left << std::setw(55) << "JUMLAH TOTAL:" << getSumJumlah(barang)
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ');

    //bagian catatan
    std::cout << "\n" << "HARGA TERTINGGI: " << std::setw(MEDIUM_WIDTH) << getHighest(barang) <<  "\n"
    << "HARGA TERENDAH: " << std::setw(MEDIUM_WIDTH) << getLowest(barang) << "\n"
    << "RATA-RATA HARGA: " << std::setw(MEDIUM_WIDTH) << getMeanPrice(barang)
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n";
}

void printInterface() {
    std::cout << "Pilih aksi yang ingin dilakukan:\n"
    << "1. Lihat Tabel dari atas list\n"
    << "2. Lihat Tabel dari bawah list\n"
    << "3. Masukan barang dari atas list\n"
    << "4. Masukan barang dari bawah list\n"
    << "5. Hapus barang paling atas list\n"
    << "6. Hapus barang paling bawah list\n"
    << "0. Keluar\n\n";
    
    std::cout << "input: ";
}

int main() {
    std::cout << "Selamat datang di Program Pengelola Penjualan Barang!\n\n";

    List brgToko;
    createList(brgToko);

    Pointer pNew = nullptr;

    int input = -1;

    do
    {

        std::cout << "Pilih aksi yang ingin dilakukan:\n"
        << "1. Lihat Tabel\n"
        << "2. Masukan barang dari atas barisan\n" // insert first
        << "3. Masukan barang dari bawah barisan\n" // insert last
        << "4. Masukan barang setelah kode NPM\n" // insert after
        << "5. Masukan barang sebelum kode NPM\n" // insert before
        << "6. Hapus barang setelah kode NPM\n" // delete after
        << "7. Hapus barang sebelum kode NPM\n" // delete before
        << "8. Hapus barang pada kode NPM\n" // delete current
        << "9. Hapus barang paling atas\n" //delete first
        << "10. Hapus barang paling bawah\n" //delete last
        << "0. Keluar\n\n";

        std::cout << "input: ";
        input = getValueInt(0, 10);

        switch (input)
        {
        case 0:
            std::cout << "\n\nTerima kasih sudah menggunakan program ini!"; 
            break;

        case 1 :
            std::cout << "\n" << std::setw(50) << "Daftar Barang PT Informatika\n";
            printOutputList(brgToko);
            break;

        case 2 :
            createElement(pNew);
            insertFirst(brgToko, pNew);
            break;
        case 3:
            createElement(pNew);
            insertLast(brgToko, pNew);
            break;
        case 4:
        {
            int key;
            int found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            linearSearch(brgToko, key, found, pCari);

            if(!isFound(found)) continue;

            createElement(pNew);
            insertAfter(brgToko, pCari , pNew);
            break;
        }
        case 5:
        {
            int key;
            int found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            linearSearch(brgToko, key, found, pCari);

            if(!isFound(found)) continue;

            createElement(pNew);
            insertBefore(brgToko, pCari , pNew);
            break;
        }
        case 6:
        {
            int key;
            int found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            linearSearch(brgToko, key, found, pCari);

            if(!isFound(found)) continue;

            deleteAfter(brgToko, pCari , pNew);
            delete pNew;
            break;
        }
        case 7:
        {
            int key;
            int found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            linearSearch(brgToko, key, found, pCari);

            if(!isFound(found)) continue;

            deleteBefore(brgToko, pCari , pNew);
            delete pNew;
            break;
        }
        case 8:
        {
            int key;
            int found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            linearSearch(brgToko, key, found, pCari);

            if(!isFound(found)) continue;

            deleteCurrent(brgToko, pCari , pNew);
            delete pNew;
            break;
        }
        case 9:
            deleteFirst(brgToko, pNew);
            delete pNew;
            break;
        case 10:
            deleteLast(brgToko, pNew);
            delete pNew;
            break;
        }
    } while (input != 0);
    
    destroyList(brgToko);
}