#ifndef STACK_H
#define STACK_H

#include "StackNode.h"

using namespace std;

template<class T>
class Stack
{
    StackNode<T> *top;

public:
    Stack()
    {
        top = NULL;
    }

    void Push(T *data)
    {
        StackNode<T> *newNode = new StackNode<T>(data);

        if(top == NULL)
        {
            top = newNode;
        }
        else
        {
            top->Next = newNode;
            newNode->Prev = top;
            top = newNode;
        }
    }

    void Display()
    {
        StackNode<T> *current = top;

        while(current != NULL)
        {
            cout << *(current->Data) << endl;
            current = current->Prev;
        }
    }

    void Pop()
    {
        StackNode<T> *pCurrent = top;
        if(pCurrent == NULL)
            return;

        if(pCurrent->Prev==NULL)
        {
            top = NULL;
        }
        else
        {
            pCurrent->Prev->Next=NULL;
            top = pCurrent->Prev;
        }

        delete pCurrent;
    }

    T * GetTop()
    {
        return top->Data;
    }
    /*T Peak()
    {
        if(top==NULL)
            exit (0);
        else
            return *top->Data;

    }*/
    bool isEmpty()
    {
        return (top==NULL);
    }
};

#endif
