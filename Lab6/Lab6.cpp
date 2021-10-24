#include <iostream>
class NodeSC
{
public:
    double data;
    NodeSC* next;
    
    NodeSC(): data(0), next(nullptr) {}
    NodeSC(const double d): data(d), next(nullptr) {  }
    NodeSC(const double d, NodeSC* next): data(d), next(next) {  }
    ~NodeSC();
};
class LinkedList
{
public:
    NodeSC* head;
    LinkedList() : head(nullptr) {}
    LinkedList(NodeSC* head): head(head) {}
    NodeSC* SearchIterative(const double value) const
    {
        NodeSC* current = head;
        while (current != nullptr && current->data != value)
        {
            current = current->next;
        }
        return current;
    }
    
    NodeSC* SearchRecursive(NodeSC* &head, double value)
    {
        if(head == nullptr || head->data == value)
        {
            return head;
        }
        
        return SearchRecursive(head->next, value);
    }
    void InsertIterative(const double value)
    {
        if(head == nullptr)
        {
            head = new NodeSC(value);
        }
        else
        {
            NodeSC* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = new NodeSC(value);
        }
    }
    
    void InsertRecursive(NodeSC* &head, const double value)
    {
        if(head == nullptr)
        {
            head = new NodeSC(value);
        }
        else
        {
            InsertRecursive(head->next, value);
        }
    }
};
int main()
{
    LinkedList* linkedList = new LinkedList();
    linkedList->InsertIterative(1);
    linkedList->InsertIterative(2);
    linkedList->InsertRecursive(linkedList->head, 3);
    linkedList->InsertRecursive(linkedList->head, 4);
    std::cout << linkedList->SearchIterative(1)->data << std::endl;
    std::cout << linkedList->SearchIterative(2)->data << std::endl;
    std::cout << linkedList->SearchIterative(0) << std::endl;
    std::cout << linkedList->SearchRecursive(linkedList->head, 3)->data << 
std::endl;
    std::cout << linkedList->SearchRecursive(linkedList->head, 4)->data << 
std::endl;
    std::cout << linkedList->SearchRecursive(linkedList->head, 0) << std::endl;
    delete linkedList;
    
    LinkedList l;
    l.InsertIterative(1);
    l.InsertIterative(2);
    l.InsertRecursive(l.head, 3);
    l.InsertRecursive(l.head, 4);
    std::cout << l.SearchIterative(1)->data << std::endl;
    std::cout << l.SearchIterative(2)->data << std::endl;
    std::cout << l.SearchIterative(0) << std::endl;
    std::cout << l.SearchRecursive(l.head, 3)->data << std::endl;
    std::cout << l.SearchRecursive(l.head, 4)->data << std::endl;
    std::cout << l.SearchRecursive(l.head, 0) << std::endl;
    
    return 0;
}