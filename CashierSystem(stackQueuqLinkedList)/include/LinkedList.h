#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

using namespace std;

template<class T>
class LinkedList
{
    Node<T> *head, *tail;
    int ListCounter;

public:
    LinkedList()
    {
        head = tail = NULL;
        ListCounter=0;
    }
    int getListCounter()
    {
        return ListCounter;
    }
//    void Add(Node *newNode);

    void Add(T *data)
    {
        Node<T> *newNode = new Node<T>(data);

        if(head == NULL)
        {
            head = tail = newNode;
            ListCounter++;
        }
        else
        {
            tail->Next = newNode;
            newNode->Prev = tail;
            tail = newNode;
            ListCounter++;
        }
    }

    /*void Display()
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            cout << *(current->Data) << endl;
            current = current->Next;
        }
    }*/

    void Delete(T *data)
    {
        Node<T> *pDelete = Search(data);

        if(pDelete == NULL)
            return;

        if(pDelete == head)
        {
            if(pDelete == tail) // if(head->Next == NULL)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->Next;
                head->Prev = NULL;
            }
        }
        else if(pDelete == tail)
        {
            tail = tail->Prev;
            tail->Next = NULL;
        }
        else
        {
            pDelete->Prev->Next = pDelete->Next; // A->Next = B
            pDelete->Next->Prev = pDelete->Prev; // B->Prev = A
        }

        delete pDelete;
        ListCounter--;
    }

    void InsertAfter(T *afterData, T *newData)
    {
        Node<T> *newAdded = new Node<T>(newData);
        Node<T> *myPrev = Search(afterData);
        if(myPrev==NULL)
        {
            return;
        }
        if(myPrev==tail)
        {
            myPrev->Next=newAdded;
            newAdded->Prev=myPrev;
            tail=newAdded;
            ListCounter++;
        }
        else{
            newAdded->Next=myPrev->Next;
            myPrev->Next->Prev=newAdded;
            myPrev->Next=newAdded;
            newAdded->Prev=myPrev;
            ListCounter++;
        }
    }

    T FirstElement()
    {
        if(head !=NULL)
        return *head->Data;
            return NULL;
    }

    void DeleteByIndex(int index)
    {
        Node<T> *pDelete = head;
        int counter = 0;
        if(index<0)
            {
                //cout<<"invalid index.";
                //cout<<endl;
                return;
            }
        while(counter!=index)
        {
            pDelete=pDelete->Next;
            counter++;
            if(pDelete->Next==NULL)
            {
                //cout<<"invalid index.";
                //cout<<endl;
                return;
            }
        }
        if(pDelete == NULL)
            return;

        if(pDelete == head)
        {
            if(pDelete == tail) // if(head->Next == NULL)
            {
                head = tail = NULL;
            }
            else
            {
                head = head->Next;
                head->Prev = NULL;
            }
        }
        else if(pDelete == tail)
        {
            tail = tail->Prev;
            tail->Next = NULL;
        }
        else
        {
            pDelete->Prev->Next = pDelete->Next;
            pDelete->Next->Prev = pDelete->Prev;
        }
        delete pDelete;
        ListCounter--;
    }

    void BubbleSort()
    {
        Node<T> *pSort=head;
        Node<T> *pComp=pSort->Next;
        for(int counter = 0;counter<(ListCounter)-1;counter++)
        {
            pSort=head;
            pComp=pSort->Next;
            while(pComp)
            {
                if(*pSort->Data > *pComp->Data)
                {
                    T *temp=NULL;
                    temp=pSort->Data;
                    pSort->Data=pComp->Data;
                    pComp->Data=temp;
                }
                pComp=pComp->Next;
                pSort=pSort->Next;
            }
        }

    }
    void SelectionSort()
    {
        Node<T> *pSort=head;
        Node<T> *pComp=pSort->Next;
        while(pSort->Next!=NULL)
        {
            pComp=pSort->Next;
            while(pComp)
            {
                if(*pSort->Data > *pComp->Data)
                {
                    T *temp=NULL;
                    temp=pSort->Data;
                    pSort->Data=pComp->Data;
                    pComp->Data=temp;
                }
                pComp=pComp->Next;
            }
            pSort=pSort->Next;
        }
    }
    int BinarySearch(T searched)
    {
        int Min = 0, Max = ListCounter-1;
        Node<T> *pMiddle = head;
        while(Min<=Max)
        {
            pMiddle=head;
            int Mid = (Max + Min)/2;
            for(int i=0;i<Mid;i++)
            {
                pMiddle=pMiddle->Next;
            }
            if(searched==(*pMiddle->Data))
            {
                return Mid;
            }
            else if(searched>(*pMiddle->Data))
            {
                Min = Mid + 1;
            }
            else //if(searched<(*pMiddle->Data))
            {
                Max = Mid - 1;
            }
        }
        return -1;
    }

    void Reverse()
    {
        Node<T> *temp = NULL;
        Node<T> *current = head;

        /* swap next and prev for all nodes of
        doubly linked list */
        while (current != NULL)
        {
            temp = current->Prev;
            current->Prev = current->Next;
            current->Next = temp;
            current = current->Prev;
        }

        /* Before changing the head, check for the cases like empty
            list and list with only one node */
        if(temp != NULL )
            head = temp->Prev;
    }
  /*  int Size(){
             int count=0;
             Node<T> *current = head;

             while(current != NULL){
              count++;
              current=current->Next;
             }
             return count;
            }*/

             T *getElementByIndex(int index){

      Node<T> *  pDelete=head;
        int counter = 0;
        if(index<0)
            {
               // cout<<"invalid index.";
              //  cout<<endl;
              //  exit(0);
            }
        while(counter!=index)
        {
            pDelete=pDelete->Next;
            counter++;
            if(pDelete==NULL)
            {
//                cout<<"invalid index.";
              //  cout<<endl;
             //   exit(0);
            }
        }

        return pDelete->Data;
    }


     void getElementandSet(int index ,T value){

      Node<T> *  pDelete=head;
        int counter = 0;
        if(index<0)
            {
//                cout<<"invalid index.";
             //   cout<<endl;
             //   exit(0);
            }
        while(counter!=index)
        {
            pDelete=pDelete->Next;
            counter++;
            if(pDelete==NULL)
            {
             //   cout<<"invalid index.";
             //   cout<<endl;
             //   exit(0);
            }
        }

        *pDelete->Data=value;
    }


private:
    Node<T>* Search(T *data)
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            if(current->Data == data)
                return current;

            current = current->Next;
        }

        return NULL;
    }
};

#endif // LINKEDLIST_H
