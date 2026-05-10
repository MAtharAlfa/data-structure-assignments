#include <iostream>

struct Element {
    char member;
    Element* next;
};

typedef Element* Pointer;
using Stack = Pointer;

