#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

using namespace std;

template<class T>
class Queue
{
    Node<T> *head, *tail;
    int Counter;
public:
    Queue()
    {
        Counter =0;
        head = tail = NULL;
    }


    void Enqueue(T *data)
    {
        Node<T> *newNode = new Node<T>(data);

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->Next = newNode;
            newNode->Prev = tail;
            tail = newNode;
        }
        Counter++;
    }

    void Display()
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            cout <<"this is Q"<< (current->Data->GetName()) << endl;
            current = current->Next;
        }
    }

    void Dequeue()
    {
        Node<T> *pCurrent = head;
        if(head == NULL)
            return;
        if(pCurrent == tail)
        {
            head = tail = NULL;
        }
        else
        {
            pCurrent->Next->Prev=NULL;
            head = pCurrent->Next;
        }
        Counter--;
        delete pCurrent;
    }
    T * GetDequeue()
    {
        return head->Data;
    }
    bool isHasData()
    {
        if(tail==NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }


    int GetSize(){
        return Counter;
    }
};

#endif
