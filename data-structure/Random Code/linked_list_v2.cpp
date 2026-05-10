#include <iostream>

struct Element {
    char chara;
    int code;
};

struct Node {
    Element member;
    Node* next;
};

typedef Node* Pointer;
typedef Pointer List;

void createList(List& head) {
    head = nullptr;
}

void createElement(Pointer& pNew) {
    pNew = new Node;

    std::cout << "Masukan char: ";
    std::cin >> pNew->member.chara;
    std::cout << "Masukan kode int: ";
    std::cin >> pNew->member.code;
    pNew->next = nullptr;
}

bool isEmpty(List& head) {
    return (head == nullptr);
}

void insertFirst(List& head, Pointer pNew) {
    if (isEmpty(head))
    {
        head = pNew;
    } else 
    {
        pNew->next = head;
        head = pNew;
    }
}

void deleteFirst (List& head, Pointer& pHapus) {
    if (isEmpty(head))
    {
        std::cout << "List kosong";
        return;
    } else if (head->next == nullptr)
    {
        pHapus = head;
        head = nullptr;
    } else 
    {
        pHapus = head;
        head = head->next;
    }
}

void traversal(List head) {
    Pointer pHelp = head;

    do
    {
        std::cout << "hasil: " << pHelp->member.chara << " " << pHelp->member.code << "\n";
        pHelp = pHelp->next;
    } while (pHelp != nullptr);
}

int main() {
    List list;
    Pointer pHelp;

    createList(list);

    createElement(pHelp);
    insertFirst(list, pHelp);
    
    createElement(pHelp);
    insertFirst(list, pHelp);

    createElement(pHelp);
    insertFirst(list, pHelp);

    deleteFirst(list, pHelp);

    traversal(list);
}