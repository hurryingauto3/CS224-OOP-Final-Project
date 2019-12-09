#include <iostream>
#include <cstdlib>
#include "Terrain.hpp"

class Node
{
public:
    Node *next;
    Terrain data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node *head;

    LinkedList();
    ~LinkedList();
    void add(Terrain data);
    void print();
};

LinkedList::LinkedList()
{
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList()
{
    std::cout << "LIST DELETED";
}

void LinkedList::add(Terrain data)
{
    Node *node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void LinkedList::print()
{
    Node *head = this->head;
    int i = 1;
    while (head)
    {
        std::cout << i << ": " << head->data.passable << std::endl;
        head = head->next;
        i++;
    }
}
