#include <iostream>

class Stack
{
    double* s;
    int capacity;
    int size;
public:
    Stack() : s(new double[5]), capacity(5), size(0) {}
    
    Stack(const int capacity) : s(new double[capacity]), capacity(capacity), size(0) {}
    
    ~Stack()
    {
        delete[] s;
    }
    
    bool IsFull() const
    {
        return capacity == size;
    }
    
    bool IsEmpty() const
    {
        return size == 0;
    }

    double Pop()
    {
        if(IsEmpty())
        {
            std::cout << "Stack is empty, nothing to pop" << std::endl;
            return 0;
        }
        return s[--size];
    }
    
    double Top() const
    {
        return s[size];
    }
    
    void Push(const double value)
    {
        if(IsFull())
        {
            std::cout << "Stack is full, cannot push new element: " << value << std::endl;
        }
        else
        {
            s[size++] = value;
        }
    }
    
    void Display() const
    {
        if(IsEmpty())
        {
            std::cout << "Nothing to display, stack is empty" << std::endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                std::cout << "Element " << i << ": " << s[size - i - 1] << std::endl;
            }
        }
    }
};

class Queue
{
    int front, rear;
    int size;
    int capacity;
    double* q;
public:
    Queue() : size(0), capacity(5), q(new double[5]) {}
    
    Queue(const int capacity) : size(0), capacity(capacity), q(new double[capacity]) {}
    
    ~Queue()
    {
        delete[] q;
    }
    
    bool IsFull() const
    {
        return capacity == size;
    }
    
    bool IsEmpty() const
    {
        return size == 0;
    }

    void Enqueue(double value)
    {
        if(IsFull())
        {
            std::cout << "Queue is full, cannot push new element: " << value << std::endl;
        }
        else if (IsEmpty())
        {
            front = rear = q[size++] = value;
        }
        else
        {
            rear = q[size++] = value;
        }
    }

    double Dequeue()
    {
        if(IsEmpty())
        {
            std::cout << "Queue is empty, nothing to dequeue" << std::endl;
            return 0;
        }
        const double temp = front;
        
        for (int i = 0; i < size - 1; i++)
        {
            q[i] = q[i + 1];
        }
        
        size--;
        front = q[0];
        return temp;
    }

    double Front()
    {
        return front;
    }

    double Rear()
    {
        return rear;
    }

    void DisplayQueue()
    {
        if(IsEmpty())
        {
            std::cout << "Nothing to display, queue is empty" << std::endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                std::cout << "Element " << i << ": " << q[i] << std::endl;
            }
        }
    }
    
    void DisplayAll()
    {
        for (int i = 0; i < capacity; i++)
        {
            std::cout << "Element " << i << ": " << q[i] << std::endl;
        }
    }
};

int main()
{
    Stack s = Stack(3);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Display();
    std::cout << "Pop: " << s.Pop() << std::endl;
    std::cout << "Pop: " << s.Pop() << std::endl;
    std::cout << "Pop: " << s.Pop() << std::endl;
    s.Pop();
    s.Display();

    std::cout << std::endl;

    Queue q = Queue(3);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.DisplayQueue();
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    q.Dequeue();
    q.DisplayQueue();
    return 0;
}
