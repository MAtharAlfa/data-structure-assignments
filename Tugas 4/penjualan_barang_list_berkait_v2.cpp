/*
Nama Program : Pengelola Penjualan Barang Linked List
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 05/03/2026
Lat Updated  : 12/04/2026 
Deskripsi    : Program akan mengelola data penjualan barang berikut ➔ Barang (kodeBrg, namaBrg, 
               harga, banyak) namun program ini akan ditulis dengan menggunakan 
               struktur data list berkait
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

void createList(List& first) {
    first = nullptr;
}

void createElement(Pointer& pBaru) {
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

void insertFirst(List& first, Pointer& pBaru) {
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
    Pointer pBantu = nullptr;
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

void deleteFirst(List& first, Pointer& pHapus) {
    if (first == nullptr)
    {
        std::cout << "\nlist kosong, tidak ada yang dihapus\n\n";
        return;
    } else if (first->next == nullptr) 
    {
        std::cout << "\nbarisan paling atas berhasil dihapus\n";
        pHapus = first;
        pHapus = nullptr;
        first = nullptr;
    } else 
    {
        std::cout << "\nbarisan paling atas berhasil dihapus\n\n";
        pHapus = first;
        first = first->next;
        pHapus->next = nullptr;
    }   
}

void insertLast(List& first, Pointer& pNew) {
    Pointer last;

    if (first == nullptr)
    {
        first = pNew;
    } else {
        last = first;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = pNew;
    }
}

void deleteLast(List& first, Pointer& pHapus) {
    Pointer last;
    
    if (first == nullptr)
    {
        std::cout << "\nlist kosong, tidak ada yang dihapus\n\n";
        pHapus = nullptr;
    } else if (first->next == nullptr) {
        pHapus = first;
        first = nullptr;
    } else {
        last = first;
        Pointer precLast = nullptr;

        while (last->next != nullptr)
        {
            precLast = last;
            last = last->next;
        }
        pHapus = last;
        precLast->next = nullptr;
    }
}

void linearSearch(List first, int key, int& found, Pointer& pSearch) {
    found = 0;
    pSearch = first;
    while (!found && pSearch != nullptr)
    {
        if (pSearch->barang.kodeBrg == key)
        {
            found = 1;
            return;
        } else {
            pSearch = pSearch->next;
        }
    }
}

bool isFound(int found) {
    if (!found) 
    {
        std::cout << "\nitem not found\n\n"; 
        return false;
    } else 
    {
        std::cout << "\nitem found\n\n"; 
        return true;
    }
}

void insertAfter(List& first, Pointer pSearch, Pointer pNew) {
    if (pSearch->next == nullptr)
    {
        pSearch->next = pNew;
    } else
    {
        pNew->next = pSearch->next;
        pSearch->next = pNew;
    }
} 

void deleteAfter(List& first, Pointer pSearch, Pointer& pHapus) {
    if (pSearch->next == nullptr)
    {
        pHapus = nullptr;
        std::cout << "tidak ada yang dihapus\n\n";
    } else
    {
        pHapus = pSearch->next;
        pSearch->next = pHapus->next;

        pHapus->next = nullptr;
    }
}

int getHighestList(List& first) {
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

int getLowestList(List& first) {
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


float getMeanPriceList(List& first) {
    int sum = 0;
    int totalList = 0;

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
            sum += pBantu->barang.harga;
            totalList++;

            pBantu = pBantu->next;
        } while (pBantu != nullptr);
    }

    return (float)sum/totalList;
}

int getSumJumlahList(List& first) {
    int sum = 0;
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
            sum += (pBantu->barang.banyak*pBantu->barang.harga);
            pBantu = pBantu->next;
        } while (pBantu != nullptr);
    }

    return sum;
}

void printOutputList(List barang) {
    if (barang == nullptr)
    {
        std::cout << "\nerror: list kosong!\n\n";
        return;
    }

    std::cout << std::right << std::setfill(' ') << "\n"; // reset to default state for concistency

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
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n\n";
}

void destroyList(List& first) {
    if (first == nullptr) return;

    Pointer pTraverse = first;
    do
    {
        Pointer pErase = pTraverse;

        pTraverse = pTraverse->next;

        delete pErase;
    } while (pTraverse != nullptr);
    
    first = nullptr;
}

int main() {
    std::cout << "Selamat datang di Program Pengelola Penjualan Barang!\n\n";

    List brgToko, brgRusak;
    createList(brgToko);
    createList(brgRusak);

    Pointer pNew = nullptr;

    int input = -1;

    do
    {

        std::cout << "Pilih aksi yang ingin dilakukan:\n"
        << "1. Lihat Tabel\n"
        << "2. Masukan barang dari atas barisan\n" // insert first
        << "3. Masukan barang dari bawah barisan\n" // insert last
        << "4. Masukan barang setelah kode NPM\n" // insert after
        << "5. Pindahkan barang dari bawah barisan\n" // delete after
        << "6. Pindahkan barang paling atas ke list barang rusak\n" //delete first
        << "7. Pindahkan barang paling bawah ke list barang rusak\n" //delete last
        << "0. Keluar\n\n";

        std::cout << "input: ";
        input = getValueInt(0, 7);

        switch (input)
        {
        case 0:
            std::cout << "\n\nTerima kasih sudah menggunakan program ini!"; 
            break;

        case 1 :
            std::cout << "\n" << std::setw(50) << "Daftar Barang PT Informatika\n";
            printOutputList(brgToko);
            std::cout << "\n" << std::setw(50) << "Daftar Barang Rusak PT Informatika\n";
            printOutputList(brgRusak);
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

            deleteAfter(brgToko, pCari , pNew);
            insertLast(brgRusak, pNew);
            break;
        }
        case 6:
            deleteFirst(brgToko, pNew);
            insertFirst(brgRusak, pNew);
            break;
        case 7:
            deleteLast(brgToko, pNew);
            insertLast(brgRusak, pNew);
            break;
        }
    } while (input != 0);
    
    destroyList(brgToko);
    destroyList(brgRusak);

    return 0;
}