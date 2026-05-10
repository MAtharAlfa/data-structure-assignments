#include <iostream>
#include <string>

struct Element
{
    char member;
    Element* next;
};

typedef Element* Pointer; //first element

typedef Pointer Stack; //head or top

char peek(Stack top) {
    return top->member;
}

bool isEmpty(Stack top) {
    if (top == nullptr)
    {
        return true;
    } else {
        return false;
    }
}

void createStack(Stack& top) {
    top = nullptr;
}

void createElement(Pointer& newElement, char datum) {
    newElement = new Element;
    newElement->member = datum;
    newElement->next = nullptr;
}

void push(Stack& top, Pointer newElement) {
    if (isEmpty(top))
    {
        top = newElement;
    } else {
        newElement->next = top;
        top = newElement;
    }
}

void pop (Stack& top, Pointer& pDel) {
    if (isEmpty(top))
    {
        std::cout << "Stack Underflow";
        pDel = nullptr;
    } else if (top->next == nullptr) {
        pDel = top;
        top = nullptr;
        delete pDel;
    } else {
        pDel = top;
        top = top->next;
        pDel->next = nullptr;
        delete pDel;
    }
}

void traversal(Stack& top) {
    Pointer pHelp = top;

    if (isEmpty(top))
    {
        std::cout << "Stack is empty";
    } else {
        std::cout << "Top\n^\n|\n";
        do
        {
            std::cout << pHelp->member;
            pHelp = pHelp->next;

        } while (pHelp != nullptr);
    }
}

int main(){
    Pointer newElement, pDel;
    Stack top;
    std::string kata;

    createStack(top);

    std::cout << "input: ";
    getline(std::cin, kata);

    for (size_t i = 0; i < kata.size(); i++)
    {
        createElement(newElement, kata.at(i));
        push(top, newElement);
    }

    std::cout << "\n";
    
    traversal(top);

    return 0;
}
