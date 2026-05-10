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
    if (isEmpty(top))
    {
        std::cerr << "stack kosong";
        return nullptr;
    } else if (top->next == nullptr)
    {
        Pointer pDel = top;
        top = nullptr;
        pDel->next = nullptr;

        return pDel;
    } else 
    {
        Pointer pDel = top;
        top = top->next;
        pDel->next = nullptr;

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
    List stack, store;
    Pointer pNew;

    std::string value = "LUCENTRA";

    createStack(stack);
    createStack(store);

    for (int i = 0; i < value.size(); i++)
    {
        createElement(pNew, value.at(i));
        push(stack, pNew);
    }
    traversal(stack); std::cout << "\n";



    for (size_t i = 0; i < value.length(); i++)
    {
        Pointer pStore = pop(stack);

        if (pStore->member == 'U' || pStore->member == 'A' || pStore->member == 'E')
        {
            push(store, pStore);

            std::cout << "\n";
        }
    }

    traversal(store);

    return 0;
}