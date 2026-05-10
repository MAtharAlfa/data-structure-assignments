#include <iostream>
#include <iomanip>

const int GAJI[3] = {3000000, 4000000, 5000000};

struct Data {
    std::string NIP;
    std::string Nama;
    int Gol;
};

struct Node {
    Data pegawai;
    Node* next;
};

typedef Node* Pointer;
typedef Pointer List;

void insertFirst(List& head, Pointer& pNew) {
    if (!head) //== head == nullptr
    {
        head = pNew;
    } else
    {
        pNew->next = head;
        head = pNew;
    }
}

Pointer searching(List head, std::string key, bool& found) {
    found = false;
    Pointer pSearch = head;

    if (!head) // head == nullptr
    {
        std::cout << "list kosong";
        return nullptr;
    } else 
    {
        do
        {
            if (pSearch->pegawai.NIP == key)
            {
                found = true;
                return pSearch;
            }
            
            pSearch = pSearch->next;
        } while (pSearch != nullptr && !found); // found == 0   
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
        Pointer pHelp = head; //precSearch | A->B
        Pointer pSearch = searching(head, NIP, found); //pSearch itu hasil searching

        if (found == 0) //!found
        {
            insertFirst(head, pNew);
        } else if (pSearch == head)
        {
            insertFirst(head, pNew);
        } else
        {
            while (pHelp->next != pSearch)
            {
                pHelp = pHelp->next;
            }
                                  //A->B
            pNew->next = pSearch; //A->B && pNew->B
            pHelp->next = pNew; // A->pNew->B
        }
    }
}

float cariRata(List head) {
    Pointer pHelp = head;
    int totalAngka = 0;
    int totaljumlah = 0;

    while (pHelp != nullptr)
    {
        totalAngka++;
        totaljumlah += GAJI[pHelp->pegawai.Gol - 1];

        pHelp = pHelp->next;
    }
    
    if (head == nullptr) return 0;
    return (float)totaljumlah/totalAngka;
}

void print(List head) {
    if (!head) //head == nullptr
    {
        std::cout << "List kosong!";
        return;
    } else 
    {
        Pointer pHelp = head;
        int nomor = 1;

        std::cout << "\nDaftar Pegawai PT.IF UNPAD\n";
        std::cout << std::setw(46) << std::setfill('-') << "\n" << std::setfill(' ');
        
        std::cout << std::setw(5) << "Nomor"
        << std::setw(10) << "NIP"
        << std::setw(10) << "Nama"
        << std::setw(5) << "Gol"
        << std::setw(10) << "Gaji" << "\n";
        
        std::cout << std::setw(46) << std::setfill('-') << "\n" << std::setfill(' ');

        
        do
        {            
            std::cout << std::setw(5) << nomor
            << std::setw(10) << pHelp->pegawai.NIP
            << std::setw(10) << pHelp->pegawai.Nama
            << std::setw(5) << pHelp->pegawai.Gol
            << std::setw(10) << GAJI[pHelp->pegawai.Gol - 1] << "\n";

            nomor++;
            pHelp = pHelp->next;
        } while (pHelp != nullptr);
        
        std::cout << std::setw(46) << std::setfill('-') << "\n" << std::setfill(' ');
        std::cout << std::fixed << std::setprecision(2) << "Rata-rata gaji: " << cariRata(head);
    }
}

void createElement(Pointer& pNew) {
    pNew = new Node;

    pNew->next = nullptr;
    std::cout << "Masukan NIP:\ninput: ";
    std::cin >> pNew->pegawai.NIP;

    std::cout << "Masukan Nama:\ninput: ";
    std::cin >> pNew->pegawai.Nama;

    std::cout << "Masukan Gol:\ninput: ";
    std::cin >> pNew->pegawai.Gol;
}

int main() {
    List pegawai = nullptr;
    Pointer pNew;

    createElement(pNew);
    insertBefore(pegawai, pNew, "12004");
    
    createElement(pNew);
    insertBefore(pegawai, pNew, "12001");

    createElement(pNew);
    insertBefore(pegawai, pNew, "12005");

    print(pegawai);
}

//12004 -> 12001 -> 12005
//12004 -> 12001 -> 12005

//1
// 12005

//2
// 12001 -> 12005

//3
// 12001 -> 12004 -> 12005