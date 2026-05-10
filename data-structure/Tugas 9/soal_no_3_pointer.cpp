#include<iostream>
using namespace std;

//anggap alamat awal m=ff06 hex

main() {
    int m=1;
    int *p = &m;
    int& r = m;
    r++;
    int * q = p + 2;
    int n = (*p) ++;
    n += 2;
    cout << m << " " << &m << " " << r << " " << &r << endl;
    cout << *p << " " << p << " " << n << " " << q << endl;
}