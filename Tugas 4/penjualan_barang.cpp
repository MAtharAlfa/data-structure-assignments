/*
Nama Program : Pengelola Penjualan Barang
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 29/03/2026
Deskripsi    : Program akan mengelola data penjualan barang berikut ➔ Barang (kodeBrg, namaBrg, 
               harga, banyak)
*/

#include <iostream>
#include <string>
#include <iomanip>

struct Barang {
    int kodeBrg;
    std::string namaBrg;
    int harga;
    int Banyak;
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