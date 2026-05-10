#include<iostream>
using namespace std;

void fungsi (int a, int &b, int &c) {
    int y = 2;
    b = y+a ;
    c += b;
    a--;
    cout << a << b << c << y << endl;
}

main(){
    int a=1, b=2, c=3, y=4;
    fungsi(b,c,a);
    cout << a << b << c << y << endl;
}       