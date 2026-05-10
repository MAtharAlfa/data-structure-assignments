#include <iostream>
using namespace std;

typedef int LarikInt[20];

void inputData(LarikInt &A, int &n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Masukan data integer ke-" << i+1 << "\n"; 
        cin >> A[i];
    }
}

void cetakData(LarikInt A, const int n) {
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int deleteArr(LarikInt &A, int &n, int x) {
    bool found = false;
    int lokasi = 0;
    
    // for (lokasi; lokasi < n; lokasi++)
    // {
    //     if (A[lokasi] == x)
    //     {
    //         A[lokasi] = 0;
    //         found = true;
    //         break;
    //     }
    // }  

// terserah pake while atau for
    while (lokasi < n)
    {
        if (A[lokasi] == x)
        {
            A[lokasi] = 0;
            found = true;
            break;
        }

        lokasi++;
    }
    

    if (found)
    {
        for (int i = lokasi; i < n-1; i++)
        {
            A[i] = A[i+1];
        }

        n--;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    LarikInt larik;
    int size;
    cout << "Masukan ukuran larik:\n"; cin >> size;

    inputData(larik, size);
    deleteArr(larik, size, 1);
    cetakData(larik, size);
}