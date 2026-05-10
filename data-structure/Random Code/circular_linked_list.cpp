#include <iostream>

struct Element {
    char member;
    Element* next;
};

using Pointer = Element*;
typedef Pointer CircularList;

void createList(CircularList& list) {
    list = nullptr;
}

void createElement(Pointer& pNew) {
    pNew = new Element;

    std::cin >> pNew->member;
    pNew->next = nullptr;
}

bool isEmpty(CircularList tail) {
    if (tail == nullptr) return true;

    return false;
}

void insertFirst(CircularList& tail, Pointer pNew) {
    if(isEmpty(tail)) 
    {
        tail = pNew;
        tail->next = tail;
    } else {
        pNew->next = tail->next;
        tail->next = pNew;
    }
}

void insertLast (CircularList& tail, Pointer pNew) {
    if (isEmpty(tail))
    {
        tail = pNew;
        tail->next = tail;
    } else {
        pNew->next = tail->next;
        tail->next = pNew;
        tail = tail->next;
    }
}

void deleteFirst(CircularList& tail) {
    if (isEmpty(tail))
    {
        std::cout << "empty list\n";
        return;
    } else if (tail->next == tail)
    {
        delete tail;
        tail = nullptr;
    } else 
    {
        Pointer pDel = tail->next;

        tail->next = pDel->next;

        delete pDel;
        pDel = nullptr;
    }
}

void deleteLast(CircularList& tail) {
    if (isEmpty(tail))
    {
        std::cout << "empty list\n";
        return;
    } else if (tail->next == tail)
    {
        delete tail;
        tail = nullptr;
    } else 
    {
        Pointer precLast = tail, pDel = nullptr;

        while (precLast->next != tail)
        {
            precLast = precLast->next;
        }
        
        pDel = tail;

        tail = precLast;
        tail->next = pDel->next;

        delete pDel;

        precLast = nullptr;
        pDel = nullptr;
    }
}

void traversal(CircularList& tail) {
    if (isEmpty(tail))
    {
        std::cout << "empty list\n";
        return;
    }

    Pointer head = tail->next, pTraverse = head;
    
    do
    {
        std::cout << pTraverse->member;
        pTraverse = pTraverse->next;
    } while (pTraverse != head);
}

Pointer linearSearch(CircularList tail, char key) {
    if (isEmpty(tail)) 
    {
        std::cerr << "empty list\n";
        return nullptr;
    }

    Pointer head = tail->next, pFind = head;

    do
    {
        if (pFind->member == key)
        {
            return pFind;
        }
        
        pFind = pFind->next;
    } while (pFind != head);
    
    return nullptr;
}

#include <iostream>

// Assume all your functions are already declared above:
// insertFirst, insertLast, deleteFirst, deleteLast, traversal, linearSearch

void printMenu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Insert First\n";
    std::cout << "2. Insert Last\n";
    std::cout << "3. Delete First\n";
    std::cout << "4. Delete Last\n";
    std::cout << "5. Traverse\n";
    std::cout << "6. Search\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    CircularList tail = nullptr;
    int choice;
    char value;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {

        case 1: {
            std::cout << "Enter char: ";
            std::cin >> value;
            insertFirst(tail, createElement(value));
            break;
        }

        case 2: {
            std::cout << "Enter char: ";
            std::cin >> value;
            insertLast(tail, createElement(value));
            break;
        }

        case 3:
            deleteFirst(tail);
            break;

        case 4:
            deleteLast(tail);
            break;

        case 5:
            traversal(tail);
            std::cout << "\n";
            break;

        case 6: {
            std::cout << "Enter char to search: ";
            std::cin >> value;

            Pointer found = linearSearch(tail, value);

            if (found != nullptr) {
                std::cout << "Found: " << found->member << "\n";
            } else {
                std::cout << "Not found\n";
            }
            break;
        }

        case 0:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}