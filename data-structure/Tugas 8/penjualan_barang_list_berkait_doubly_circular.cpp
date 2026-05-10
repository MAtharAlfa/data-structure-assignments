/*
Nama Program : Pengelola Penjualan Barang Doubly Linked List
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 26/04/2026
Deskripsi    : Program akan mengelola data penjualan barang berikut ➔ Barang (kodeBrg, namaBrg, 
               harga, banyak) namun program ini akan ditulis dengan menggunakan 
               struktur data doubly circular linked list
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
void traversalForward(const List first);
Pointer deleteFirst(List& first);
Pointer deleteLast(List& first);
Pointer linearSearch(List& first, int key, bool& found);
bool isFound(bool found);
void insertAfter(List& first, Pointer& pSearch, Pointer& pNew);
void insertBefore(List& first, Pointer& pSearch , Pointer& pNew);
Pointer deleteAfter(List& first, Pointer& pSearch);
Pointer deleteBefore(List& first, Pointer& pSearch);
Pointer deleteCurrent(List& first, Pointer& pSearch);
int getSumJumlahList(const List first);
float getMeanPriceList(const List first);
int getLowestList(const List first);
int getHighestList(const List first);
void printOutputList(const List barang);
void destroyList(List& first);

void destroyList(List& first) {
    if (first == nullptr) return;
    
    Pointer pHelp = first, last = first->prev, pHapus = nullptr;

    while (pHelp != last)
    {
        pHapus = pHelp;
        pHelp = pHelp->next;
        
        delete pHapus;
    }
    
    delete last;
    first = nullptr;
}

Pointer linearSearch(List& first, int key, bool& found) {
    found = 0;
    Pointer pSearch = first;

    do 
    {
        if (pSearch->barang.kodeBrg == key)
        {
            found = 1;
            return pSearch;
        } else
        {
            pSearch = pSearch->next;
        }
    } while (pSearch != first && !found);

    return nullptr;
}

Pointer deleteBefore(List& first, Pointer& pSearch) {
    Pointer pHapus = nullptr;

    if (pSearch->prev == first)
    {
        pHapus = deleteFirst(first);

        return pHapus;
    } else 
    {
        pHapus = pSearch->prev;
        
        pHapus->prev->next = pSearch;
        pSearch->prev = pHapus->prev;

        pHapus->next = nullptr;
        pHapus->prev = nullptr;

        return pHapus;
    }
}

Pointer deleteCurrent(List& first, Pointer& pSearch) {
    Pointer pHapus = nullptr;
    
    if (pSearch == first)
    {
        pHapus = deleteFirst(first);
        return pHapus;
    } else if (first->next == first) 
    {
        pHapus = first;
        first = nullptr;

        return pHapus;
    } else
    {   
        pSearch->next->prev = pSearch->prev;
        pSearch->prev->next = pSearch->next;
        pHapus = pSearch;

        pHapus->next = nullptr;
        pHapus->prev = nullptr;
        
        return pHapus;
    } 
}

Pointer deleteAfter(List& first, Pointer& pSearch) {
    Pointer pHapus = nullptr;

    if (pSearch->next == first)
    {
        pHapus = deleteFirst(first);
        return pHapus;
    } else
    {
        pHapus = pSearch->next;
        pHapus->next->prev = pSearch;
        pSearch->next = pHapus->next;

        pHapus->prev = nullptr;
        pHapus->next = nullptr;

        return pHapus;
    }
}

void insertBefore(List& first, Pointer& pSearch , Pointer& pNew) {
    if (pSearch == first)
    {
        insertFirst(first, pNew);
    } else
    {    
        pNew->next = pSearch;
        pSearch->prev->next = pNew;
        pNew->prev = pSearch->prev;
        pSearch->prev = pNew;
    }
}

void insertAfter(List& first, Pointer& pSearch, Pointer& pNew) {
    pNew->next = pSearch->next;
    pSearch->next->prev = pNew;
    pNew->prev = pSearch;
    pSearch->next = pNew;
} 

bool isFound(bool found) {
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
        first->next = first;
        first->prev = first;
    } else 
    {
        Pointer tail = first->prev;

        pBaru->next = tail->next;
        pBaru->prev = tail;
        tail->next = pBaru;
        first->prev = pBaru;

        first = pBaru;
    }
}

void insertLast(List& first, Pointer& pBaru) {
    if (!first) 
    {
        first = pBaru;
        first->next = first;
        first->prev = first;
    } else 
    {
        Pointer last = first->prev;

        last->next = pBaru;
        pBaru->prev = last;
        pBaru->next = first;
        first->prev = pBaru;

        last = pBaru;
    }
}

void traversalForward(const List first) {
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
        } while (pBantu != first);
    }
}

Pointer deleteFirst(List& first) {
    Pointer pHapus = nullptr;

    if (!first)
    {
        std::cout << "list kosong, tidak ada yang dihapus\n\n";
        
        return nullptr;
    } else if (first->next == first) 
    {
        pHapus = first;
        first = nullptr;

        return pHapus;
    } else 
    {
        Pointer last = first->prev;

        last->next = first->next;
        first->next->prev = last;
        
        pHapus = first;
        first = first->next;

        pHapus->next = nullptr;
        pHapus->prev = nullptr;
        return pHapus;
    }   
}

Pointer deleteLast(List& first) {
    Pointer pHapus = nullptr;

    if(!first)
    {
        std::cout << "list kosong, tidak ada yang dihapus\n\n";

        return nullptr;
    } else if (first->next == first)
    {
        pHapus = first;
        first = nullptr;

        return pHapus;
    } else 
    {
        Pointer last = first->prev;

        last->prev->next = first;
        first->prev = last->prev;
        
        last->prev = nullptr;
        last->next = nullptr;

        pHapus = last;
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
        } while (pBantu != first);
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
        } while (pBantu != first);
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
        } while (pBantu != first);
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
        } while (pBantu != first);
    }

    return sum;
}

void printOutputList(List barang) {
    if (barang == nullptr)
    {
        std::cout << "\nerror: list kosong!\n\n";
        return;
    }

    std::cout << std::right << std::setfill(' '); // reset to normal state for concistency

    std::cout << "\n" << std::setw(50) << "Daftar Barang PT Informatika\n";

    // bagian atas
    std::cout << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') //75 total width dari setw
    << std::left << std::setw(SHORT_WIDTH) << "NO" << std::setw(MEDIUM_WIDTH) << "KODE" << std::setw(LONG_WIDTH) << "NAMA BARANG" 
    << std::setw(MEDIUM_WIDTH) << "HARGA" << std::setw(MEDIUM_WIDTH) << "BANYAK" << std::setw(LONG_WIDTH) << "JUMLAH"
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n";

    //bagian isi
    traversalForward(barang);
    
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
        << "4. Masukan barang setelah kode barang\n" // insert after
        << "5. Masukan barang sebelum kode barang\n" // insert before
        << "6. Hapus barang setelah kode barang\n" // delete after
        << "7. Hapus barang sebelum kode barang\n" // delete before
        << "8. Hapus barang pada kode barang ke-n\n" // delete current
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
            bool found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            pCari = linearSearch(brgToko, key, found);

            if(!isFound(found)) continue;

            createElement(pNew);
            insertAfter(brgToko, pCari , pNew);
            break;
        }
        case 5:
        {
            int key;
            bool found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            pCari = linearSearch(brgToko, key, found);
            
            if(!isFound(found)) continue;

            createElement(pNew);
            insertBefore(brgToko, pCari , pNew);
            break;
        }
        case 6:
        {
            int key;
            bool found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            pCari = linearSearch(brgToko, key, found);

            if(!isFound(found)) continue;

            pNew = deleteAfter(brgToko, pCari);
            delete pNew;
            break;
        }
        case 7:
        {
            int key;
            bool found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            pCari = linearSearch(brgToko, key, found);

            if(!isFound(found)) continue;

            pNew = deleteBefore(brgToko, pCari);
            delete pNew;
            break;
        }
        case 8:
        {
            int key;
            bool found;
            Pointer pCari = nullptr;

            std::cout << "\nMasukan Kode Barang:\n";
            key = getValueInt();
            pCari = linearSearch(brgToko, key, found);

            if(!isFound(found)) continue;

            pNew = deleteCurrent(brgToko, pCari);
            delete pNew;
            break;
        }
        case 9:
            pNew = deleteFirst(brgToko);
            delete pNew;
            break;
        case 10:
            pNew = deleteLast(brgToko);
            delete pNew;
            break;
        }
    } while (input != 0);
    
    destroyList(brgToko);
}