/*
Nama Program : Pengelola Gaji Pegawai Array of Record
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 29/04/2026
Deskripsi    : Program akan menampilkan gaji pegawai sesuai dengan golongan yang didapat dengan menggunakan
               struktur data circular doubly linked list
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

struct Node {
    Pegawai Data;
    Node* next;
    Node* prev;
};

typedef Node* Pointer;
typedef Pointer List;

bool checkFound(bool found);
Pointer createNode();
Pointer initList(List& list);
Pointer linearSearch(List head, bool& found, std::string key);
void insertAfter(List& head, bool found, Pointer pSearch, Pointer& pNew);
Pointer deleteLast(List& head);
long long getGaji(int gol);
long long getTunjangan(int gol);
long long getTotal(int gol);
long long getJumlahGaji(List head);
long long getJumlahTunjangan(List head);
long long getJumlahTotal(List head);
long long getRata(List head);
void printTable(List head);
int getChoice();
void printChoices();
void runMenu(List& pegawai);

bool checkFound(bool found) {
    if (!found) 
    {
        return false;
    }

    return true;
}

Pointer createNode() {
    Pointer pNew = new Node;

    std::cout << "Masukan NIP: ";
    std::cin >> pNew->Data.NIP;

    std::cout << "Masukan nama: ";
    std::cin >> pNew->Data.nama;

    std::cout << "Masukan Gol: ";
    std::cin >> pNew->Data.gol;

    return pNew;
}

Pointer initList(List& list) {
    list = nullptr;

    return list;
}

Pointer linearSearch(List head, bool& found, std::string key) {
    found = 0; Pointer pSearch = head;

    do
    {
        if(!head) break;

        if (pSearch->Data.NIP == key)
        {
            found = 1;
            return pSearch;
        }

        pSearch = pSearch->next;
    } while (pSearch != head);
    
    if (!(head || found)) found = 1;

    return nullptr;
}

void insertFirst(List& head, Pointer& pNew) {
    if (!head) 
    {
        head = pNew;
        pNew->next = head;
        pNew->prev = head;
    } else 
    {
        Pointer last = head->prev;

        pNew->next = head;
        last->next = pNew;
        pNew->prev = last;
        head->prev = pNew;
    }
}

void insertAfter(List& head, bool found, Pointer pSearch, Pointer& pNew) {
    if (!checkFound(found)) 
    {
        insertFirst(head, pNew);
        return;
    }

    if (pSearch->next == head) {
        insertFirst(head, pNew);
    } else 
    {
        pNew->next = pSearch->next;
        pSearch->next = pNew;
        pNew->next->prev = pNew;
        pNew->prev = pSearch;
    }
}

Pointer deleteLast(List& head) {
    Pointer pHapus = nullptr;

    if (!head) {
        std::cerr << "List kosong, tidak ada yang dihapus!";
        return nullptr;
    } else if (head->next == head)
    {
        pHapus = head;

        head->next = nullptr;
        head->prev = nullptr;
        head = nullptr;
    } else 
    {
        Pointer last = head->prev, precLast = last->prev;

        precLast->next = head;
        head->prev = precLast;

        pHapus = last;
        pHapus->next = nullptr;
        pHapus->prev = nullptr;
    }

    return pHapus;
}

long long getGaji(int gol) {
    if (gol == 1) return 3000000;
    if (gol == 2) return 4000000;
    if (gol == 3) return 5000000;

    return 0;
}

long long getTunjangan(int gol) {
    if (gol == 1) return (long long)getGaji(gol)*1;
    if (gol == 2) return (long long)getGaji(gol)*1.25;
    if (gol == 3) return (long long)getGaji(gol)*1.5;

    return 0;
}

long long getTotal(int gol) {
    long long total = 0;

    total += getGaji(gol);
    total += getTunjangan(gol);

    return total;
}

long long getJumlahGaji(List head) {
    long long jumlah = 0;

    Pointer pTemp = head;
    do
    {
        jumlah += getGaji(pTemp->Data.gol);
        pTemp = pTemp->next;
    } while (pTemp != head);
    
    return jumlah;
}

long long getJumlahTunjangan(List head) {
    long long jumlah = 0;

    Pointer pTemp = head;
    do
    {
        jumlah += getTunjangan(pTemp->Data.gol);
        pTemp = pTemp->next;
    } while (pTemp != head);
    
    return jumlah;
}

long long getJumlahTotal(List head) {
    long long jumlah = 0;

    Pointer pTemp = head;
    do
    {
        jumlah += getTotal(pTemp->Data.gol);
        pTemp = pTemp->next;
    } while (pTemp != head);
    
    return jumlah;
}

long long getRata(List head) {
    long long jumlah = 0; int n = 0;

    if (head == nullptr) 
    {
        std::cerr << "Error! List is empty";
        return 0;
    }

    Pointer pTemp = head;
    do
    {
        jumlah += getTotal(pTemp->Data.gol);

        n++;
        pTemp = pTemp->next;
    } while (pTemp != head);
    
    return (long long)jumlah/n;
}

void printTable(List head) {
    if (!head) 
    {
        std::cerr << "\nList is empty!\n";
        return;
    }

    int nomor = 1; Pointer pTraverse = head;

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
    
    do
    {
        std::cout << std::setw(SHORT_WIDTH) << nomor
        << std::setw(LONG_WIDTH) << pTraverse->Data.NIP
        << std::setw(LONG_WIDTH) << pTraverse->Data.nama
        << std::setw(SHORT_WIDTH) << pTraverse->Data.gol
        << std::setw(LONG_WIDTH) << getGaji(pTraverse->Data.gol)
        << std::setw(LONG_WIDTH) << getTunjangan(pTraverse->Data.gol)
        << std::setw(LONG_WIDTH) << getTotal(pTraverse->Data.gol) << "\n";

        pTraverse = pTraverse->next; nomor++;
    } while (pTraverse != head);
    
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    std::cout << std::setw(SHORT_WIDTH + LONG_WIDTH) << "Jumlah: " << std::setw(LONG_WIDTH + SHORT_WIDTH) << " "
    << std::setw(LONG_WIDTH) << getJumlahGaji(pTraverse)
    << std::setw(LONG_WIDTH) << getJumlahTunjangan(pTraverse)
    << std::setw(LONG_WIDTH) << getJumlahTotal(pTraverse) << "\n";
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    std::cout << "Rata-rata Gaji: " << getRata(pTraverse) << "\n"; 
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
    << "3. Hapus data terakhir\n"
    << "0. keluar\n";
}

void runMenu(List& pegawai) {
    int choice = -1;

    do
    {
        printChoices();
        choice = getChoice();

        switch (choice)
        {
        case 1:
            printTable(pegawai);
            break;
        case 2:
        {
            bool found = 0; std::string key = "";

            std::cout << "Masukan setelah NIP: ";
            std::cin >> key; 
            Pointer pSearch = linearSearch(pegawai, found, key);

            if(!found)
            {
                std::cerr << "\nData tidak ditemukan!\n";
                break;
            }

            if (!pegawai && found)
            {
                std::cout << "\nData kosong!\n\nLakukan Insert First\n";
                found = 0;
            } else
            {
                std::cout << "\nDitemukan!\n\nMasukan Data!\n";
            }

            Pointer pNew = createNode();
            insertAfter(pegawai, found, pSearch, pNew);
            break;
        }
        case 3:
            deleteLast(pegawai);

            break;
        
        default:
            std::cout << "Terima kasih sudah menggunakan program ini!";
            break;
        }
    } while (choice != 0);
}

int main() {
    List pegawai;
    initList(pegawai);
    runMenu(pegawai);
}