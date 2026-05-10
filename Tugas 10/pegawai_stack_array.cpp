/*
Nama Program : Pengelola Gaji Pegawai Array of Record
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 29/04/2026
Deskripsi    : Program akan menampilkan gaji pegawai sesuai dengan golongan yang didapat dengan menggunakan
               struktur data Stack Array
*/

const int MAX_ELEMENT = 255;
const int SHORT_WIDTH = 5;
const int long LONG_WIDTH = 15;

#include <iostream>
#include <iomanip>

struct Pegawai {
    std::string NIP;
    std::string nama;
    int gol;
};

struct Stack {
    Pegawai data[MAX_ELEMENT];
    int top;
};

bool checkFound(bool found);
Pegawai createNewElement();
void createStack(Stack& S);
long long getGaji(int gol);
long long getTunjangan(int gol);
long long getTotal(int gol);
long long getJumlahGaji(Stack S);
long long getJumlahTunjangan(Stack S);
long long getJumlahTotal(Stack S);
long long getRata(Stack S);
void printTable(Stack S);
int getChoice();
void printChoices();
void runMenu(Stack& pegawai);

Pegawai createNewElement() {
    Pegawai pNew;

    std::cout << "Masukan NIP: ";
    std::cin >> pNew.NIP;

    std::cout << "Masukan nama: ";
    std::cin >> pNew.nama;

    std::cout << "Masukan Gol: ";
    std::cin >> pNew.gol;

    return pNew;
}

void createStack(Stack& stack) {
    stack.top = -1;
}

void push(Stack& S, Pegawai& pNew) {
    if (S.top == MAX_ELEMENT - 1)
    {
        std::cerr << "Stack sudah penuh!" << std::endl;
        return;
    } else
    {
        S.top++;
        S.data[S.top] = pNew;
    }
}

void pop(Stack& S, Pegawai& pHasil) {
    if (S.top < 0)
    {
        std::cerr << "Stack sudah kosong!" << std::endl;
        return;
    } else 
    {
        pHasil = S.data[S.top];
        S.top--;
    }
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

long long getJumlahGaji(Stack S) {
    long long jumlah = 0;

    int cBantu = S.top;
    
    while (cBantu >= 0)
    {
        jumlah += getGaji(S.data[cBantu].gol);
        cBantu--;
    }
    
    return jumlah;
}

long long getJumlahTunjangan(Stack S) {
    long long jumlah = 0;

    int cBantu = S.top;
    
    while (cBantu >= 0)
    {
        jumlah += getTunjangan(S.data[cBantu].gol);
        cBantu--;
    }
    
    return jumlah;
}

long long getJumlahTotal(Stack S) {
    long long jumlah = 0;

    int cBantu = S.top;
    
    while (cBantu >= 0)
    {
        jumlah += getGaji(S.data[cBantu].gol);
        cBantu--;
    }
    
    return jumlah;
}

long long getRata(Stack S) {
    long long jumlah = 0; int n = 0;

    if (S.top < 0) 
    {
        std::cerr << "Error! List is empty";
        return 0;
    }

    int cBantu = S.top;
    while (cBantu >= 0) 
    {
        jumlah += getTotal(S.data[cBantu].gol);

        n++;
        cBantu--;
    }
    
    return (long long)jumlah/n;
}

void printTable(Stack S) {
    if (S.top < 0) 
    {
        std::cerr << "\nList is empty!\n";
        return;
    }

    int nomor = 1; int cBantu = S.top;

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
    
    while (cBantu >=0)
    {
        std::cout << std::setw(SHORT_WIDTH) << nomor
        << std::setw(LONG_WIDTH) << S.data[cBantu].NIP
        << std::setw(LONG_WIDTH) << S.data[cBantu].nama
        << std::setw(SHORT_WIDTH) << S.data[cBantu].gol
        << std::setw(LONG_WIDTH) << getGaji(S.data[cBantu].gol)
        << std::setw(LONG_WIDTH) << getTunjangan(S.data[cBantu].gol)
        << std::setw(LONG_WIDTH) << getTotal(S.data[cBantu].gol) << "\n";

        cBantu--; nomor++;
    }
    
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    std::cout << std::setw(SHORT_WIDTH + LONG_WIDTH) << "Jumlah: " << std::setw(LONG_WIDTH + SHORT_WIDTH) << " "
    << std::setw(LONG_WIDTH) << getJumlahGaji(S)
    << std::setw(LONG_WIDTH) << getJumlahTunjangan(S)
    << std::setw(LONG_WIDTH) << getJumlahTotal(S) << "\n";
    std::cout << std::setfill('-') << std::setw(90) << " " << std::setfill(' ') << "\n";
    std::cout << "Rata-rata Gaji: " << getRata(S) << "\n"; 
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
        {
            Pegawai pNew;
            pNew = createNewElement();
            push(pegawai, pNew);

            break;
        }
        case 3:
        {
            Pegawai pHasil;
            pop(pegawai, pHasil);

            break;
        }
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