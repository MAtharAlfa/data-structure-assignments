/*
Nama Program : Pengelola Penjualan Barang
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 29/03/2026
Deskripsi    : Program akan mengelola data penjualan barang berikut ➔ Barang (kodeBrg, namaBrg, 
               harga, banyak)
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

typedef Barang listBarang[100];

int getHighest(const listBarang list, const int size) {
    int highest = INT_MIN;

    for (size_t i = 0; i < size; i++)
    {
        if (list[i].harga > highest)
        {
            highest = list[i].harga;
        }
    }
    
    return highest;
}

int getLowest(const listBarang list, const int size) {
    int lowest = INT_MAX;

    for (size_t i = 0; i < size; i++)
    {
        if (list[i].harga < lowest)
        {
            lowest = list[i].harga;
        }
    }
    
    return lowest;
}

float getMeanPrice(const listBarang list, const int size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += list[i].harga;
    }
    
    return ((float)sum/size);
}

int linearSearch(const listBarang list, const int size, const int key) {
    int i = 0;

    while (i < size)
    {
        if (list[i].kodeBrg == key) return i;
        i++;
    }

    return -1;
}

void bubbleSortByKodeAscending(listBarang list, const int size) {
    bool swapped = false;

    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = 0; j < size-i-1; j++)
        {
            if (list[j].kodeBrg > list[j+1].kodeBrg)
            {
                Barang temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
            swapped = true;
        }
        if (swapped == false) break;
    }
}

void bubbleSortByKodeDescending(listBarang list, const int size) {
    bool swapped = false;

    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = 0; j < size-i-1; j++)
        {
            if (list[j].kodeBrg < list[j+1].kodeBrg)
            {
                Barang temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
            swapped = true;
        }
        if (swapped == false) break;
    }
}

int getJumlah(Barang jumlah) {
    return jumlah.banyak*jumlah.harga;
}

int getSumJumlah(listBarang list, int size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += getJumlah(list[i]);
    }
    
    return sum;
}

void printOutput(listBarang list, int size) {
    std::cout << std::right << std::setfill(' '); // reset to normal state for concistency

    std::cout << "\n" << std::setw(50) << "Daftar Barang PT Informatika\n";

    // bagian atas
    std::cout << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') //75 total width dari setw
    << std::left << std::setw(SHORT_WIDTH) << "NO" 
    << std::setw(MEDIUM_WIDTH) << "KODE" 
    << std::setw(LONG_WIDTH) << "NAMA BARANG" 
    << std::setw(MEDIUM_WIDTH) << "HARGA" 
    << std::setw(MEDIUM_WIDTH) << "BANYAK" 
    << std::setw(LONG_WIDTH) << "JUMLAH"
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n";

    //bagian isi
    for (size_t i = 0; i < size; i++)
    {
        std::cout << std::left << std::setw(SHORT_WIDTH) << i+1 
        << std::right << std::setfill('0') << std::setw(3) << list[i].kodeBrg << std::left << std::setfill(' ') << std::setw(7) << " " //setw 7+3  == setw MEDIUM 
        << std::setw(LONG_WIDTH) << list[i].namaBrg 
        << std::setw(MEDIUM_WIDTH) << list[i].harga 
        << std::setw(MEDIUM_WIDTH) << list[i].banyak 
        << std::setw(LONG_WIDTH) << getJumlah(list[i]) << "\n";
    }
    
    //bagian jumlah total
    std::cout << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n"
    << std::left << std::setw(55) << "JUMLAH TOTAL:" << getSumJumlah(list, size)
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ');

    //bagian catatan
    std::cout << "\n" << "HARGA TERTINGGI: " << std::setw(MEDIUM_WIDTH) << getHighest(list, size) << "\n"
    << "HARGA TERENDAH: " << std::setw(MEDIUM_WIDTH) << getLowest(list, size) << "\n"
    << "RATA-RATA HARGA: " << std::setw(MEDIUM_WIDTH) << getMeanPrice(list, size)
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n";
}

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

int main() {
    std::cout << "Selamat datang di Program Pengelola Penjualan Barang!\n\n";
    Barang foo[2] = {{1, "Buku", 1, 10}, {3, "Tas", 2, 20}};
    int size = 2;
    int input = -1;

    do
    {
        size = sizeof(foo)/sizeof(foo[0]); //update size

        std::cout << "Pilih aksi yang ingin dilakukan:\n"
        << "1. Lihat Tabel\n"
        << "2. Cari Barang berdasarkan Kode\n"
        << "3. Sortir secara Naik\n"
        << "4. Sortir secara Turun\n"
        << "0. Keluar\n\n";

        std::cout << "input: ";
        input = getValueInt(0, 4);

        switch (input)
        {
        case 0:
            std::cout << "\n\nTerima kasih sudah menggunakan program ini!"; 
            break;

        case 1 :
            printOutput(foo, size);
            break;

        case 2 :
        {
            int key = -1; // -1 itu placeholder
            int index = -1;

            std::cout << "Masukan kode barang yang ingin dicari!\n" 
            << "(masukan kode dalam bentuk integer, 013 -> 13)\n" 
            << "input : ";

            key = getValueInt();
            std::cout << "\n"; 

            index = linearSearch(foo, size, key);
            
            if (index != -1) {
                std::cout << "Barang ditemukan di baris ke-" << index+1 << " di dalam tabel di bawah ini:\n";
                printOutput(foo, size);
            } else {
                std::cout << "Barang tidak ditemukan dalam tabel di bawah ini:\n";
                printOutput(foo, size);
            }

            break;
        }
        case 3:
            bubbleSortByKodeAscending(foo, size);
            printOutput(foo, size);
            break;

        case 4:
            bubbleSortByKodeDescending(foo, size);
            printOutput(foo, size);
            break;
        }
    } while (input != 0);
    

    return 0;
}