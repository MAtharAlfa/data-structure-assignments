/*
Nama Program : Program Pelihat Address Pointer serta Nilainya
Nama         : Muhammad Athar Alfarisi
NPM          : 140810250005
Tanggal Buat : 29/03/2026
Deskripsi    : Program akan print setiap address dan nilai yang ada
*/

#include <iostream>
using namespace std;

typedef int* larik;

void printLarikPointer(larik a, int n){    //Mencetak data larik  {4,5,2} 
    cout <<"\nPencetakan Data alamat array dengan pointer" <<endl; 
    cout << "Alamat variabel pointer a          : " << &a << endl;
    cout << "Isi pointer a (alamat array) (sama): " << a << endl;
    cout << "Nilai pertama array (*a)           : " << *a << endl;

    cout <<"------------------------------------------------------------"<<endl; 

    for (int* p = a; p < a+n; p++) { 
        cout << "Alamat pointer p                : " << &p << endl;
        cout << "Data array (alamat elemen)      : p = " << p << endl;
        cout << "Nilai yang ditunjuk *p = " << *p << endl; 
    } 
} 

void printLarikPointer1(larik a, int n){    //Mencetak data larik  {4,5,2} 
   cout <<"\nPencetakan alamat array dan data dengan dereference" <<endl; 
   cout <<"---------------------------------------------------------------------" << endl; 
    for(int i = 0; i < n; i++) { 
        cout << "Index ke-" << i << endl;
        cout << "Alamat Data ke-" << (i+1) << "    : "<< &(a[i]) <<endl; 
        cout << "Dengan pointer aritmatika (a+i) : " << (a + i) << endl;
        cout << "Nilai Data ke-" << (i+1) <<  "    : " << a[i] << endl;
        cout << "Derefrence data ke-" << (i+1) << " = "<< *(a + i) <<endl; 
   } 
}

int main() {
    int arr[] = {4, 5, 2};
    int n = 3;

    cout << "Alamat array (arr)                 : " << arr << endl;
    cout << "Alamat variabel array (&arr) (sama): " << &arr << endl;

    printLarikPointer(arr, n);
    printLarikPointer1(arr, n);

    return 0;
}