#include "liwanze.h"
#include <iostream>
using namespace std ;
Liwanze::Liwanze() : name(""), loc(ndef) {}

Liwanze::Liwanze(string Name, Region Loc) : name(Name), loc(Loc) {}

Liwanze::~Liwanze() {}

string Liwanze::GenreToString(Region region) const {
    switch (region) {
    case ndef: return "Undefined";
    case amer: return "America";
    case apac: return "Asia-Pacific";
    case emea: return "Europe, Middle East, and Africa";
    default: return "Unknown";
    }
}
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::addNode(const Liwanze& value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void LinkedList::deleteNode(const string& artistName) {
    if (head == nullptr) return; // Empty list

    // If the node to be deleted is the head
    if (head->data.name == artistName) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data.name != artistName) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void LinkedList::printList() const {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Artist: " << temp->data.name << ", Region: " << temp->data.GenreToString(temp->data.loc) << endl;
        temp = temp->next;
    }
}

