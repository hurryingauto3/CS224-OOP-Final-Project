#include <iostream>

#include "LinkedList.hpp"

void LinkedList::addnode(MasterObject *n)
{

    Node *tmp = new Node;
    tmp->data = n;
    tmp->next = nullptr;
    tmp->prev = nullptr;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
}
Node *LinkedList::gethead()
{
    return head;
}

Node *LinkedList::gettail()
{
    return tail;
}
void LinkedList::DelNode()
{
    if (!(this->IsEmpty()))
    {

        Node *tmp = tail;
        if (tmp->prev == NULL)
        {
            tail = head = NULL;
            delete tmp;
            tmp = nullptr;
        }
        else if (tmp->prev != NULL)
        {
            tail = tail->prev;
            tail->next = NULL;
            //tmp = nullptr;
            delete tmp;
            tmp = nullptr;
        }
    }
}

bool LinkedList::IsEmpty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LinkedList::RenderAll()
{
    Node *tmp = this->head;

    while (tmp != nullptr)
    {
        tmp->data->obj_render();
        tmp = tmp->next;
    }
}