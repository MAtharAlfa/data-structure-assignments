#include <iostream>

const int maxElement = 255;
struct StackArray{
    char data[maxElement];
    int top;
};

StackArray s;

void createStack(StackArray& s) {
    s.top = -1;
}

char peek(StackArray S) {
    return s.data[s.top];
}

bool isEmpty(StackArray S) {
    if (s.top < 0)
    {
        return true;
    } else {
        return false;
    }
}

void push(StackArray &s, char newElement) {
    if (s.top == maxElement - 1)
    {
        /* code */
    }
    
}