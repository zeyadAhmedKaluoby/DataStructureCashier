#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    public:
        T *Data;
        Node *Next, *Prev;

        Node(T *data)
        {
            Data = data;
            Next = Prev = NULL;
        }
};

#endif // NODE_H
