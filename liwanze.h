#ifndef LIWANZE_H
#define LIWANZE_H
#include<string>
using namespace std ;

class Liwanze {
public:
    enum Region {
        ndef, amer, apac, emea
    };

    Liwanze();
    Liwanze(string Name, Region Loc);
    ~Liwanze();

    string GenreToString(Region) const;

    string name;
    Region loc;
};
struct Node {
    Liwanze data;
    Node* next;

    Node(const Liwanze& val) : data(val), next(nullptr) {}
};
class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void addNode(const Liwanze& value);
    void deleteNode(const string& artistName);
    void printList() const;


private:
    Node* head;
};
#endif // LIWANZE_H
