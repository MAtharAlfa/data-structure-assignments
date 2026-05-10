#include <iostream>
#include <iomanip>

struct Data {
    std::string NIP;
    std::string nama;
    int golongan;
};

struct Node {
    Data pegawai;
    Node* next;
};

typedef Node* Pointer;
typedef Pointer List;
    
const int GAJI[3] = {3000000, 4000000, 5000000};


void createList(List& head) {
    head = nullptr;
}

void createElement(Pointer& pNew) {
    pNew = new Node;
    
    pNew->next = nullptr;
    std::cout << "Masukan NIP anda:\n input: ";
    std::cin >> pNew->pegawai.NIP;

    std::cout << "Masukan nama anda:\n input: ";
    std::cin >> pNew->pegawai.nama;
    
    std::cout << "Masukan golongan anda:\n input: ";
    std::cin >> pNew->pegawai.golongan;
}

void insertFirst(List& head, Pointer& pNew) {
    if (!head) // head == nullptr
    {
        head = pNew;
    } else 
    {
        pNew->next = head;
        head = pNew;
    }
}

Pointer searching(List head, std::string key, bool& found) {
    found = 0;
    Pointer pSearch = head;

    while (pSearch != nullptr && !found) //!found == found == 0
    {
        if (pSearch->pegawai.NIP == key)
        {
            found = 1;
            return pSearch;
        }
        
        pSearch = pSearch->next;
    }

    return nullptr;
}

void insertBefore(List& head, Pointer& pNew, std::string NIP) {
    if (!head)
    {
        insertFirst(head, pNew);
    } else 
    {
        bool found = 0;
        Pointer pSearch = searching(head, NIP, found);
        Pointer pHelp = head;
        
        if (!found)
        {
        std::cout << "no found";
            insertFirst(head, pNew);
        } else if (head == pSearch) 
        {
            insertFirst(head, pNew);
        } else 
        {
        std::cout << "found";

            while (pHelp->next != pSearch)
            {
                std::cout << pHelp->pegawai.nama;
                pHelp = pHelp->next;
            }
            
            pNew->next = pSearch;
            pHelp->next = pNew;
        }
    }
}

float cariRata(List head) {
    Pointer pHelp = head;
    int n = 0;
    int jumlah = 0;

    while (pHelp != nullptr)
    {
        n++;
        jumlah += GAJI[pHelp->pegawai.golongan-1];
            
        pHelp = pHelp->next;
    }
    
    if(n == 0) return 0;
    return (float)jumlah/n;
}

void print(List head) {
    if (!head) //head == nullptr
    {
        std::cout << "List kosong";
        return;
    } else
    {
        Pointer pHelp = head;
        int nomor = 1;

        std::cout << "\nDaftar Gaji pegawai PT.IF UNPAD\n";
        // std::cout << "---------------------------------------------\n";
        std::cout << std::setfill('-') << std::setw(46) << "\n" << std::setfill(' '); //outputnya ekivalen kode di atas 45'-' dan satu '\n' == 46 karakter
        do
        {
            std::cout << std::setw(5) << nomor 
            << std::setw(10) << pHelp->pegawai.NIP
            << std::setw(10) << pHelp->pegawai.nama 
            << std::setw(5) << pHelp->pegawai.golongan
            << std::setw(10) << GAJI[pHelp->pegawai.golongan - 1] << "\n"; //bentuk baris

            pHelp = pHelp->next;
            nomor++;
        } while (pHelp != nullptr);
        std::cout << "---------------------------------------------\n";
        std::cout << "Rata-rata gaji: " << std::setprecision(2) << std::fixed << cariRata(head);
    }
}

int main() {
    List pegawai;
    Pointer pNew;

    createList(pegawai);
    createElement(pNew);
    insertBefore(pegawai, pNew, "1");
    createElement(pNew);
    insertBefore(pegawai, pNew, "4");
    createElement(pNew);
    insertBefore(pegawai, pNew, "5");
    createElement(pNew);
    insertBefore(pegawai, pNew, "1");

    print(pegawai);
}