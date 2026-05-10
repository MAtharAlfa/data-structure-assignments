#include <iostream>
using namespace std;

typedef int* larik;

void printLarikPointer(larik a, int n) {
    cout << "\n=== Informasi Array & Pointer ===" << endl;
    cout << "Alamat variabel pointer a        : " << &a << endl;
    cout << "Isi pointer a (alamat array)     : " << a << endl;
    cout << "Nilai pertama (*a)               : " << *a << endl;

    cout << "\n--- Iterasi dengan pointer ---" << endl;
    for (int* p = a; p < a + n; p++) {
        cout << "Alamat pointer p                : " << &p << endl;
        cout << "Isi p (alamat elemen)           : " << p << endl;
        cout << "Nilai yang ditunjuk (*p)        : " << *p << endl;
        cout << "-----------------------------" << endl;
    }
}

void printLarikPointer1(larik a, int n) {
    cout << "\n=== Informasi Elemen Array ===" << endl;
    cout << "Alamat variabel pointer a        : " << &a << endl;
    cout << "Isi pointer a (alamat array)     : " << a << endl;

    cout << "\n--- Iterasi dengan indeks ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Index ke-" << i << endl;
        cout << "Alamat elemen a[" << i << "]     : " << &a[i] << endl;
        cout << "Dengan pointer (a+i)             : " << (a + i) << endl;
        cout << "Nilai a[" << i << "]             : " << a[i] << endl;
        cout << "Dengan dereference *(a+i)        : " << *(a + i) << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2};
    int n = 3;

    cout << "Alamat array (arr)               : " << arr << endl;
    cout << "Alamat variabel array (&arr)     : " << &arr << endl;

    printLarikPointer(arr, n);
    printLarikPointer1(arr, n);

    return 0;
}