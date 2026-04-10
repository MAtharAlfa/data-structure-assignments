#include <string>
#include <iostream>

struct Element
{
    std::string member;
    Element* next;
    Element* prev;
};

typedef Element* Pointer;
using List = Pointer;

bool isEmpty(List& tail) {
    if (tail == nullptr) return true;
    
    return false;
}

void createList(List& tail) {
    tail = nullptr;
}

void createElement(Pointer& pNew, std::string value) {
    pNew = new Element;
    
    pNew->member = value;
    pNew->next = nullptr;
}

void insertFirst(List& tail, Pointer pNew) {
    if (tail == nullptr)
    {
        tail = pNew;
        tail->next = tail;
        tail->prev = tail;
    } else if (tail->next == tail) 
    {
        pNew->next = tail;
        pNew->prev = tail;

        tail->next = pNew;
        tail->prev = pNew;
    } else 
    {
        pNew->next = tail->next;
        pNew->prev = tail;

        tail->next->prev = pNew;
        tail->next = pNew;
    }
}

void next (Pointer& current) {
    current = current->next;
}

void previous (Pointer& current) {
    current = current->prev;
}

void printCurrent(List tail, Pointer current) {
    std::cout << "Lagu saat ini : " << current->member << "\n";
}

void traversal(List tail) {
    if (isEmpty(tail))
    {
        std::cerr << "stack kosong";
        return;
    }

    Pointer head = tail->next, pTraverse = head;
    do {
        std::cout << pTraverse->member << "\n";
        pTraverse = pTraverse->next;
    } while (pTraverse != head);
}

int main() {
    List lagu;
    Pointer pNew;

    createList(lagu);

    createElement(pNew, "Indonesia rata");
    insertFirst(lagu, pNew);

    createElement(pNew, "Hymne Unpad");
    insertFirst(lagu, pNew);

    createElement(pNew, "Mars Himatif");
    insertFirst(lagu, pNew);

    createElement(pNew, "Bintang 5");
    insertFirst(lagu, pNew);

    createElement(pNew, "Tabola Bale");
    insertFirst(lagu, pNew);

    Pointer current = lagu;

    int choice = -1;
    do
    {
        std::cout << "=============================\n";
        traversal(lagu);
        std::cout << "=============================\n";
        printCurrent(lagu, current);
        std::cout << "=============================\n";

        std::cout << "Input (1, 2, 0):";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            next(current);
            break;
        case 2:
            previous(current);
            break;
        default:
            break;
        }
    } while (choice != 0);
    

    return 0;
}