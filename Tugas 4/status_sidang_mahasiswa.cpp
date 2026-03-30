/*
Nama Program : Pengelola Status Sidang
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 29/03/2026
Deskripsi    : Program akan mengelola data sidang untuk menentukan nilai dan status kelulusan dari mahasiswa. 
*/

const int SHORT_WIDTH = 5;
const int MEDIUM_WIDTH = 10;
const int LONG_WIDTH = 20; // for UI setw

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

struct Waktu { 
    int jam; 
    int menit; 
    int detik; 
};

struct Mahasiswa { 
   std::string npm;            
   std::string nama;            
   int nilaiPenguji1; 
   int nilaiPenguji2; 
   int nilaiPenguji3;
   float nilaiAkhir;
   char hurufMutu;
   Waktu  mulai;             
   Waktu  selesai;
   Waktu lama;
   std::string status;
};

typedef Mahasiswa listSidang[100];

Waktu getLamaSidang (Mahasiswa tersidang) {
    if (tersidang.selesai.detik < tersidang.mulai.detik)
    {
        tersidang.selesai.detik += 60;
        tersidang.selesai.menit--;
    }

    tersidang.lama.detik = tersidang.selesai.detik - tersidang.mulai.detik;

    if (tersidang.selesai.menit < tersidang.mulai.menit)
    {
        tersidang.selesai.menit += 60;
        tersidang.selesai.jam--;
    }

    tersidang.lama.menit = tersidang.selesai.menit - tersidang.mulai.menit;

    if (tersidang.selesai.jam < tersidang.mulai.jam)
    {
        tersidang.selesai.jam += 24;
    }

    tersidang.lama.jam = tersidang.selesai.jam - tersidang.mulai.jam;

    return tersidang.lama;
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

Waktu getValueWaktu(Waktu jam) {
    std::cout << "Masukan Jam: \ninput: ";
    jam.jam = getValueInt(0, 23);

    std::cout << "Masukan Menit: \ninput: ";
    jam.menit = getValueInt(0, 59);

    std::cout << "Masukan Detik: \ninput: ";
    jam.detik = getValueInt(0, 59);

    return jam;
}

float getNilaiAkhir (Mahasiswa tersidang) {
    return (float)(tersidang.nilaiPenguji1+tersidang.nilaiPenguji2+tersidang.nilaiPenguji3)/3;
}

std::string getStatusKelulusan (Mahasiswa tersidang) {
    if (tersidang.nilaiAkhir >= 68) return "Lulus";
    
    return "Gagal";
}

char getHurufMutu(Mahasiswa tersidang) {
    if (tersidang.nilaiAkhir >= 0 && tersidang.nilaiAkhir < 55)
    {
        return 'D';
    } else if (tersidang.nilaiAkhir >=55 && tersidang.nilaiAkhir < 68)
    {
        return 'C';
    } else if (tersidang.nilaiAkhir >=68 && tersidang.nilaiAkhir < 80) 
    {
        return 'B';
    } else if (tersidang.nilaiAkhir >=80 && tersidang.nilaiAkhir <= 100) 
    {
        return 'A';
    } else 
    {
        return '\0'; // error
    }
}

Mahasiswa getValueMahasiswa(Mahasiswa tersidang) {
    std::cout << "Masukan NPM: \ninput: ";
    std::cin.ignore();
    std::getline(std::cin, tersidang.npm);

    std::cout << "Masukan Nama: \ninput: ";
    std::getline(std::cin, tersidang.nama);

    std::cout << "Masukan Nilai Penguji 1: \ninput: ";
    tersidang.nilaiPenguji1 = getValueInt(0, 100);

    std::cout << "Masukan Nilai Penguji 2: \ninput: ";
    tersidang.nilaiPenguji2 = getValueInt(0, 100);

    std::cout << "Masukan Nilai Penguji 3: \ninput: ";
    tersidang.nilaiPenguji3 = getValueInt(0, 100);

    std::cout << "Masukan Waktu Mulai Sidang!\n";
    tersidang.mulai = getValueWaktu(tersidang.mulai);

    std::cout << "Masukan Waktu Selesai Sidang!\ninput: ";
    tersidang.selesai = getValueWaktu(tersidang.selesai);

    tersidang.hurufMutu = getHurufMutu(tersidang);
    tersidang.status = getStatusKelulusan(tersidang);
    tersidang.lama = getLamaSidang(tersidang);
    tersidang.nilaiAkhir = getNilaiAkhir(tersidang);

    return tersidang;
}

int getHighest(const Mahasiswa arr[], const int size) {
    int highest = INT_MIN;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i].nilaiAkhir > highest)
        {
            highest = arr[i].nilaiAkhir;
        }
    }
    
    return highest;
}

int getLowest(const Mahasiswa arr[], const int size) {
    int lowest = INT_MAX;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i].nilaiAkhir < lowest)
        {
            lowest = arr[i].nilaiAkhir;
        }
    }
    
    return lowest;
}

float getMeanScore(const Mahasiswa arr[], const int size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i].nilaiAkhir;
    }
    
    return ((float)sum/size);
}

int linearSearch(const Mahasiswa arr[], const int size, const std::string key) {
    int i = 0;

    while (i < size)
    {
        if (arr[i].npm == key) return i;
        i++;
    }

    return -1;
}

void bubbleSortNilaiAscending(Mahasiswa arr[], const int size) {
    bool swapped = false;

    for (size_t i = 0; i < size-1; i++)
    {
        for (size_t j = 0; j < size-i-1; j++)
        {
            if (arr[j].nilaiAkhir > arr[j+1].nilaiAkhir)
            {
                Mahasiswa temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            swapped = true;
        }
        if (swapped == false) break;
    }
}

void selectionSortNilaiDescending(Mahasiswa arr[], const int size) {
    for (size_t i = 0; i < size-1; i++)
    {
        int highestIndex = 0;
        for (size_t j = i+1; j < size; j++)
        {
            if (arr[j].nilaiAkhir > arr[highestIndex].nilaiAkhir)
            {
                highestIndex = j;
            }
        }
        if (highestIndex != i)
        {
            Mahasiswa temp = arr[i];
            arr[i] = arr[highestIndex];
            arr[highestIndex] = temp;
        }
    }
}

std::string printWaktu(Waktu jam) {
    std::ostringstream temp;

    temp << std::setfill('0') << std::setw(2) << jam.jam <<  ":" << std::setw(2) << jam.menit << ":" << std::setw(2) << jam.detik << std::setfill(' ');  

    std::string result = temp.str();

    return result;
}

void printOutput(Mahasiswa arr[], int size) {
    std::cout << std::right << std::setfill(' '); // reset to normal state for concistency

    std::cout << "\n" << std::setw(50) << "Daftar Nilai Sidang dan Lama Sidang Mahasiswa Program Studi TI\n";

    // bagian atas
    std::cout << std::setfill('-') << std::setw(175) << " \n" << std::setfill(' ') //175 total width dari setw
    << std::left << std::setw(SHORT_WIDTH) << "No" 
    << std::setw(MEDIUM_WIDTH) << "NPM" 
    << std::setw(LONG_WIDTH) << "Nama Mahasiswa" 
    << std::setw(MEDIUM_WIDTH) << "Nilai 1" 
    << std::setw(MEDIUM_WIDTH) << "Nilai 2" 
    << std::setw(MEDIUM_WIDTH) << "Nilai 3"
    << std::setw(LONG_WIDTH) << "Nilai Akhir" 
    << std::setw(LONG_WIDTH) << "Huruf Mutu" 
    << std::setw(LONG_WIDTH) << "Mulai"
    << std::setw(LONG_WIDTH) << "Selesai" 
    << std::setw(LONG_WIDTH) << "Lama" << std::setw(MEDIUM_WIDTH) << "Status"   
    << std::setfill('-') << std::setw(175) << " \n" << std::setfill(' ') << "\n";
    //bagian isi
    for (size_t i = 0; i < size; i++)
    {
        std::string mulai = printWaktu(arr[i].mulai);
        std::string selesai = printWaktu(arr[i].selesai);
        std::string lama = printWaktu(arr[i].lama);

        std::cout << std::left << std::setw(SHORT_WIDTH) << i+1 
        << std::setw(MEDIUM_WIDTH) << arr[i].npm 
        << std::setw(LONG_WIDTH) << arr[i].nama 
        << std::setw(MEDIUM_WIDTH) << arr[i].nilaiPenguji1 
        << std::setw(MEDIUM_WIDTH) << arr[i].nilaiPenguji2 
        << std::setw(MEDIUM_WIDTH) << arr[i].nilaiPenguji3
        << std::setw(LONG_WIDTH) << getNilaiAkhir(arr[i]) 
        << std::setw(LONG_WIDTH) << getHurufMutu(arr[i]) 
        << std::setw(LONG_WIDTH) << mulai 
        << std::setw(LONG_WIDTH) << selesai 
        << std::setw(LONG_WIDTH) << lama 
        << std::setw(MEDIUM_WIDTH) << getStatusKelulusan(arr[i]) << "\n";
    }

    //bagian catatan
    std::cout << std::setfill('-') << std::setw(175) << " \n" << std::setfill(' ') 
    << "\n" << "Nilai Akhir Tertinggi: " << std::setw(MEDIUM_WIDTH) << getHighest(arr, size) << "\n"
    << "Nilai Akhir Terendah: " << std::setw(MEDIUM_WIDTH) << getLowest(arr, size) << "\n"
    << "Nilai Akhir Rata-Rata: " << std::setw(MEDIUM_WIDTH) << getMeanScore(arr, size)
    << std::setfill('-') << std::setw(175) << " \n" << std::setfill(' ') << "\n";
}

int main() {
    std::cout << "Selamat datang di Program Pengelola Status Sidang Mahasiswa!\n\n";
    int size = 0;
    
    std::cout << "Masukan total data yang ingin dimasukan!\ninput: ";
    size = getValueInt(0);
    Mahasiswa foo[size];

    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Mahasiswa " << i+1 << "\n";
        foo[i] = getValueMahasiswa(foo[i]);

        std::cout << '\n';
    }
    

    int input = -1;

    do
    {
        size = sizeof(foo)/sizeof(foo[0]); //update size

        std::cout << "Pilih aksi yang ingin dilakukan:\n"
        << "1. Lihat Tabel\n"
        << "2. Cari Mahasiswa berdasarkan Kode\n"
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
            std::string key = "";
            int index = -1;

            std::cout << "Masukan NPM mahasiswa yang ingin dicari!\n" 
            << "(masukan kode dalam bentuk integer, eg. 13)\n" 
            << "input : ";

            std::cin.ignore();
            getline(std::cin, key);
            std::cout << "\n"; 

            index = linearSearch(foo, size, key);
            
            if (index != -1) {
                std::cout << "Mahasiswa ditemukan di baris ke-" << index+1 << " di dalam tabel di bawah ini:\n";
                printOutput(foo, size);
            } else {
                std::cout << "Mahasiswa tidak ditemukan dalam tabel di bawah ini:\n";
                printOutput(foo, size);
            }
        }
            break;
        case 3 :
            bubbleSortNilaiAscending(foo, size);
            printOutput(foo,size);
            break;

        case 4 :
            selectionSortNilaiDescending(foo, size);
            printOutput(foo,size);
            break;
        }
        
    } while (input != 0);
    

    return 0;
}