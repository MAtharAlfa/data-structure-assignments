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

int getHighest(const Barang arr[], const int size) {
    int highest = INT_MIN;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i].harga > highest)
        {
            highest = arr[i].harga;
        }
    }
    
    return highest;
}

int getLowest(const Barang arr[], const int size) {
    int lowest = INT_MAX;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i].harga < lowest)
        {
            lowest = arr[i].harga;
        }
    }
    
    return lowest;
}

float getMeanPrice(const Barang arr[], const int size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i].harga;
    }
    
    return ((float)sum/size);
}

int linearSearch(const Barang arr[], const int size, const int key) {
    int i = 0;

    while (i < size && arr[i].kodeBrg != key)
    {
        i++;
    }

    if (i == key) return i;

    return -1;
}

void bubbleSortByKodeAscending(Barang arr[], const int size) {
    bool swapped = false;

    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = 0; j < size-i-1; j++)
        {
            if (arr[j].kodeBrg > arr[j+1].kodeBrg)
            {
                Barang temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            swapped = true;
        }
        if (swapped == false) break;
    }
}

int getJumlah(Barang jumlah) {
    return jumlah.banyak*jumlah.harga;
}

int getSumJumlah(Barang arr[], int size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += getJumlah(arr[i]);
    }
    
    return sum;
}

void printOutput(Barang arr[], int size) {
    std::cout << "\n" << std::setw(50) << "Daftar Barang PT Informatika\n";

    // bagian atas
    std::cout << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') //75 total width dari setw
    << std::left << std::setw(SHORT_WIDTH) << "NO" << std::setw(MEDIUM_WIDTH) << "KODE" << std::setw(LONG_WIDTH) << "NAMA BARANG" 
    << std::setw(MEDIUM_WIDTH) << "HARGA" << std::setw(MEDIUM_WIDTH) << "BANYAK" << std::setw(LONG_WIDTH) << "JUMLAH"
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n";

    //bagian isi
    for (size_t i = 0; i < size; i++)
    {
        std::cout << std::left << std::setw(SHORT_WIDTH) << i+1 
        << std::right << std::setfill('0') << std::setw(3) << arr[i].kodeBrg << std::left << std::setfill(' ') << std::setw(7) << " " //setw 7+3  == setw MEDIUM 
        << std::setw(LONG_WIDTH) << arr[i].namaBrg 
        << std::setw(MEDIUM_WIDTH) << arr[i].harga 
        << std::setw(MEDIUM_WIDTH) << arr[i].banyak 
        << std::setw(LONG_WIDTH) << getJumlah(arr[i]) << "\n";
    }
    
    //bagian jumlah total
    std::cout << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n"
    << std::left << std::setw(55) << "JUMLAH TOTAL:" << getSumJumlah(arr, size)
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ');

    //bagian catatan
    std::cout << "\n" << "HARGA TERTINGGI: " << getHighest(arr, size) << "\n"
    << "HARGA TERENDAH: " << getHighest(arr, size) << "\n"
    << "RATA-RATA HARGA: " << getHighest(arr, size)
    << std::setfill('-') << std::setw(75) << " \n" << std::setfill(' ') << "\n";
}

int main() {
    Barang foo[2] = {{1, "Buku", 1000, 10}, {3, "Tas", 10000, 20}};

    printOutput(foo, 2);

    return 0;
}