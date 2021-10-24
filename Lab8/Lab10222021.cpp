#include <iostream>

class Node
{
public:
    Node* prev = nullptr;
    Node* next = nullptr;
    double data = 0;
    int repeatedTimes = 0;

    Node(){}
    Node(const double d): data(d){}
    Node(const double d, const int repeatedTimes): data(d), repeatedTimes(repeatedTimes){}
    Node(const double d, Node* prev): prev(prev), data(d){}
    Node(const double d, Node* prev, Node* next): prev(prev), next(next), data(d){}

    void Remove() const
    {
        if(prev != nullptr)
        {
            prev->next = next;
        }
        
        if(next != nullptr)
        {
            next->prev = prev;
        }
        
        delete this;
    }
};

class DoubleChainedList
{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    DoubleChainedList(Node* head)
    {
        if (head == nullptr) return;
        
        Node* temp = head;
        this->head = tail = new Node(temp->data);
        temp = temp->next;
        while (temp != nullptr)
        {
            InsertEnd(temp->data);
            temp = temp->next;
        }
    }

    DoubleChainedList(const double d)
    {
        head = tail = new Node(d);
    }
    
    DoubleChainedList(const double headValue, const double tailValue)
    {
        head = new Node(headValue);
        tail = new Node(tailValue, head);
        head->next = tail;
    }

    void InsertEnd(const double d)
    {
        if(head == tail)
        {
            head->next = new Node(d, head);
            tail = head->next;
        }
        else
        {
            tail->next = new Node(d, tail);
            tail = tail->next;
        }
    }

    void RemoveDuplicatesUnsorted() const
    {
        Node* headTemp = head;
        Node* tailTemp = tail;
        while (headTemp != nullptr)
        {
            while (tailTemp != nullptr)
            {
                if(tailTemp != headTemp && tailTemp->data == headTemp->data)
                {
                    tailTemp = tailTemp->prev;
                    tailTemp->next->Remove();
                }
                else
                {
                    tailTemp = tailTemp->prev;
                }
            }
            headTemp = headTemp->next;
            tailTemp = tail;
        }
    }
    
    void RemoveDuplicatesSorted() const
    {
        for (Node* temp = head; temp != nullptr; temp = temp->next)
        {
            if(temp->next != nullptr && temp->data == temp->next->data)
            {
                temp->Remove();
            }
        }
    }

    DoubleChainedList GetRepetitionCount()
    {
        const DoubleChainedList tempList = DoubleChainedList(*this);
        tempList.Print();
        tempList.RemoveDuplicatesUnsorted();
        for (Node* i = tempList.head; i != nullptr; i = i->next)
        {
            for (Node* j = head; j != nullptr; j = j->next)
            {
                if(i->data == j->data)
                {
                    i->repeatedTimes++;
                }
            }
        }
        tempList.Print2();
    }

    void Print() const
    {
        for (Node* temp = head; temp != nullptr; temp = temp->next)
        {
            std::cout << temp->data << std::endl;
        }
    }

    void Print2() const
    {
        for (Node* temp = head; temp != nullptr; temp = temp->next)
        {
            std::cout << temp->data << ", " << temp->repeatedTimes << std::endl;
        }
    }
};


int main()
{
    DoubleChainedList dll = DoubleChainedList(1);
    dll.InsertEnd(2);
    dll.InsertEnd(4);
    dll.InsertEnd(3);
    dll.InsertEnd(2);
    dll.InsertEnd(4);
    dll.InsertEnd(4);
    
    return 0;
}
