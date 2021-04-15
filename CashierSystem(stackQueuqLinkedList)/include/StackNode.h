#ifndef STACKNODE_H
#define STACKNODE_H

template<class T>
class StackNode
{
    public:
        T *Data;
        StackNode *Next, *Prev;

        StackNode(T *data)
        {
            Data = data;
            Next = Prev = NULL;
        }
};

#endif
