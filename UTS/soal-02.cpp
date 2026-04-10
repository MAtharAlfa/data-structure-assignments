#include <string>
#include <iostream>

struct Element
{
    char member;
    Element* next;
};

typedef Element* Pointer;
using List = Pointer;

bool isEmpty(List& top) {
    if (top == nullptr) return true;
    
    return false;
}

char peek(List top) {
    if (isEmpty(top)) 
    {
        std::cerr << "list kosong";
        return '\0';
    }

    return top->member;
}

void createStack(List& top) {
    top = nullptr;
}

void createElement(Pointer& pNew, char value) {
    pNew = new Element;
    
    pNew->member = value;
    pNew->next = nullptr;
}

void push(List& top, Pointer pNew) {
    if (isEmpty(top))
    {
        top = pNew;
    } else {
        pNew->next = top;
        top = pNew;
    }
}

Pointer pop(List& top) 
{
    if(peek(top) == 'U' || peek(top) == 'E' ||peek(top) == 'A') std::cout << peek(top);

    if (isEmpty(top))
    {
        std::cerr << "stack kosong";
        return nullptr;
    } else if (top->next == nullptr)
    {
        Pointer pDel = top;
        top = nullptr;

        return pDel;
    } else 
    {
        Pointer pDel = top;
        top = top->next;

        return pDel;
    }
}

void traversal(List top) {
    if (isEmpty(top))
    {
        std::cerr << "stack kosong";
        return;
    }

    Pointer pTraverse = top;
    while (pTraverse != nullptr)
    {
        std::cout << pTraverse->member;
        pTraverse = pTraverse->next;
    }
}

int main() {
    List stack, printStack;
    Pointer pNew;

    std::string value = "LUCENTRA";

    createStack(stack);

    for (int i = 0; i < value.size(); i++)
    {
        createElement(pNew, value.at(i));
        push(stack, pNew);
    }
    // traversal(stack);


    Pointer pTemp = nullptr;
    pTemp = pop(stack);
    push(printStack, pTemp);

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);

    pop(stack);
    pop(stack);


    // traversal(printStack);

    return 0;
}