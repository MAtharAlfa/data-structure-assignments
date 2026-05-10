/*
Nama Program : Pengelola Gaji Pegawai Array of Record
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 29/04/2026
Deskripsi    : Program akan menampilkan gaji pegawai sesuai dengan golongan yang didapat dengan menggunakan
               struktur data Stack Linked List
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
    Pegawai data;
    Node* next;
};

typedef Node* Pointer;
typedef Pointer Stack;

Pointer createNode();
Pointer createStack(Stack& list);
long long getGaji(int gol);
long long getTunjangan(int gol);
long long getTotal(int gol);
long long getJumlahGaji(Stack top);
long long getJumlahTunjangan(Stack top);
long long getJumlahTotal(Stack top);
long long getRata(Stack top);
void printTable(Stack top);
int getChoice();
void printChoices();
void runMenu(Stack& pegawai);

Pointer createNode() {
    Pointer pNew = new Node;

    std::cout << "Masukan NIP: ";
    std::cin >> pNew->data.NIP;

    std::cout << "Masukan nama: ";
    std::cin >> pNew->data.nama;

    std::cout << "Masukan Gol: ";
    std::cin >> pNew->data.gol;
    pNew->next = nullptr;

    return pNew;
}

Pointer createStack(Stack& stack) {
    stack = nullptr;

    return stack;
}

void push(Stack& top, Pointer& pNew) {
    if (!top) 
    {
        top = pNew;
    } else 
    {
        pNew->next = top;
        top = pNew;
    }
}

Pointer pop(Stack& top) {
    Pointer pHasil = nullptr;

    if (!top) {
        std::cerr << "List kosong, tidak ada yang dihapus!";
        return nullptr;
    } else if (top->next == nullptr)
    {
        pHasil = top;

        top->next = nullptr;
        top = nullptr;
    } else 
    {
        pHasil = top;
        top = top->next;
        pHasil->next = nullptr;
    }

    return pHasil;
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

long long getJumlahGaji(Stack top) {
    long long jumlah = 0;

    Pointer pTemp = top;
    do
    {
        jumlah += getGaji(pTemp->data.gol);
        pTemp = pTemp->next;
    } while (pTemp != nullptr);
    
    return jumlah;
}

long long getJumlahTunjangan(Stack top) {
    long long jumlah = 0;

    Pointer pTemp = top;
    do
    {
        jumlah += getTunjangan(pTemp->data.gol);
        pTemp = pTemp->next;
    } while (pTemp != nullptr);
    
    return jumlah;
}

long long getJumlahTotal(Stack top) {
    long long jumlah = 0;

    Pointer pTemp = top;
    do
    {
        jumlah += getTotal(pTemp->data.gol);
        pTemp = pTemp->next;
    } while (pTemp != nullptr);
    
    return jumlah;
}

long long getRata(Stack top) {
    long long jumlah = 0; int n = 0;

    if (top == nullptr) 
    {
        std::cerr << "Error! List is empty";
        return 0;
    }

    Pointer pTemp = top;
    do
    {
        jumlah += getTotal(pTemp->data.gol);

        n++;
        pTemp = pTemp->next;
    } while (pTemp != nullptr);
    
    return (long long)jumlah/n;
}

void printTable(Stack top) {
    if (!top) 
    {
        std::cerr << "\nList is empty!\n";
        return;
    }

    int nomor = 1; Pointer pTraverse = top;

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
        << std::setw(LONG_WIDTH) << pTraverse->data.NIP
        << std::setw(LONG_WIDTH) << pTraverse->data.nama
        << std::setw(SHORT_WIDTH) << pTraverse->data.gol
        << std::setw(LONG_WIDTH) << getGaji(pTraverse->data.gol)
        << std::setw(LONG_WIDTH) << getTunjangan(pTraverse->data.gol)
        << std::setw(LONG_WIDTH) << getTotal(pTraverse->data.gol) << "\n";

        pTraverse = pTraverse->next; nomor++;
    } while (pTraverse != nullptr);
    
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    std::cout << std::setw(SHORT_WIDTH + LONG_WIDTH) << "Jumlah: " << std::setw(LONG_WIDTH + SHORT_WIDTH) << " "
    << std::setw(LONG_WIDTH) << getJumlahGaji(top)
    << std::setw(LONG_WIDTH) << getJumlahTunjangan(top)
    << std::setw(LONG_WIDTH) << getJumlahTotal(top) << "\n";
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    std::cout << "Rata-rata Gaji: " << getRata(top) << "\n"; 
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
    << "2. Masukan data ke atas stack\n"
    << "3. Pop data teratas\n"
    << "0. keluar\n";
}

void runMenu(Stack& pegawai) {
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
            Pointer pNew;
            pNew = createNode();
            push(pegawai, pNew);

            break;
        case 3:
            pop(pegawai);

            break;
        
        default:
            std::cout << "Terima kasih sudah menggunakan program ini!";
            break;
        }
    } while (choice != 0);
}

int main() {
    Stack pegawai;
    createStack(pegawai);
    runMenu(pegawai);
}