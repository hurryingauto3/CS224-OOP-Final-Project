#pragma once
#include <iostream>
#include <cstdlib>
#include "Node.hpp"
#include "SDL.h"
class LinkedList
{
private:
    Node *head, *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void addnode(MasterObject *n);
    Node *gethead(); //returns the head of the linked list
    Node *gettail(); //returns the tail of the linked list
    void DelNode();  //deletes the last node
    bool IsEmpty();
    void RenderAll();
    void CollideCheck();
};