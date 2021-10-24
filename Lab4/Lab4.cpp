#include <iostream>
#include <math.h>

class Array
{
#pragma region Lab9102021
protected:
    double* a;
    int n;
public:
    Array()
    {
        this->n = 0;
        this->a = new double[0];
    }

    Array(int size)
    {
        this->n = size;
        this->a = new double[size];
    }
    
    Array(int size, double defaultValue)
    {
        this->n = size;
        this->a = new double[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = defaultValue;
        }
    }

    Array(const Array& array)
    {
        this->n = array.n;
        this->a = new double[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = array.a[i];
        }
    }

    ~Array()
    {
        delete[] a;
    }

    int GetSize() const
    {
        return n;
    }

    void InsertBeginning(const double value)
    {
        double* b = new double[++n]{ value };
        
        for(int i = 0; i < n - 1; i++)
        {
            b[i + 1] = a[i];
        }

        this->a = b;
    }

    void InsertEnd(const double value)
    {
        double* b = new double[++n];
        b[n - 1] = value;
        
        for(int i = 0; i < n - 1; i++)
        {
            b[i] = a[i];
        }
        
        this->a = b;
    }
    
    void RemoveBeginning()
    {
        double* b = new double[--n];
        
        for(int i = 0; i < n; i++)
        {
            b[i] = a[i + 1];
        }

        this->a = b;
    }

    void RemoveEnd()
    {
        double* b = new double[--n];
        
        for(int i = 0; i < n; i++)
        {
            b[i] = a[i];
        }

        this->a = b;
    }

    void Invert()
    {
        for (int i = 0; i < n / 2; i++)
        {
            const double temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
    }

    double Maximum() const
    {
        double result = a[0];
        for(int i = 1; i < n; i++)
        {
            if(a[i] > result)
            {
                result = a[i];
            }
        }

        return result;
    }
    
    double Minimum() const
    {
        double result = a[0];
        for(int i = 1; i < n; i++)
        {
            if(a[i] < result)
            {
                result = a[i];
            }
        }

        return result;
    }

    double Average() const
    {
        double total = 0;
        for(int i = 0; i < n; i++)
        {
            total += a[i];
        }

        return total / n;
    }

    Array& operator +(const Array& addingValues) const
    {
        Array result = Array(n + addingValues.n);
        for (int i = 0; i < n; i++)
        {
            result.a[i] = a[i];
        }
        
        for (int i = 0; i < addingValues.n; i++)
        {
            result.a[n + i] = addingValues.a[i];
        }
        
        std::cout << "Size:" << result.n << std::endl;

        return result;
    }
    
    Array& operator *(const double value) const
    {
        Array result = Array(n);
        for(int i = 0; i < n; i++)
        {
            result.a[i] = a[i] * value;
        }

        return result;
    }
#pragma endregion Lab9102021
    
#pragma region Lab9172021
    bool Search1(double x) const
    {
        for (int i = 0; i < n; i++)
        {
            if(a[i] == x)
            {
                return true;
            }
        }
        return false;
    }
    
    bool Search2(double x) const
    {
        int i = 0;
        while (i < n)
        {
            if(a[i] == x)
            {
                return true;
            }
            i++;
        }
        return false;
    }
    
    bool Search3(double x) const
    {
        int i = 0;
        do
        {
            if(a[i] == x)
            {
                return true;
            }
            i++;
        } while (i < n);
        return false;
    }

    bool Search4(double x) const
    {
        Array inner = Array(*this);
        if(inner.n > 0)
        {
            if(inner.a[0] == x)
            {
                return true;
            }
            inner.RemoveBeginning();
            return inner.Search4(x);
        }
        return false;
    }

    bool IsAllEven1() const
    {
        for(int i = 0; i < n; i++)
        {
            if(!IsEven(a[i]))
            {
                return false;
            }
        }
        return true;
    }
    
    bool IsAllEven2() const
    {
        int i = 0;
        while (i < n)
        {
            if(!IsEven(a[i]))
            {
                return false;
            }
            i++;
        }
        return true;
    }
    
    bool IsAllEven3() const
    {
        int i = 0;
        do
        {
            if(!IsEven(a[i]))
            {
                return false;
            }
            i++;
        } while (i < n);
        return true;
    }
    
    bool IsAllEven4() const
    {
        Array inner = Array(*this);
        if(inner.n > 0)
        {
            if(!IsEven(inner.a[0]))
            {
                return false;
            }
            inner.RemoveBeginning();
            return inner.IsAllEven4();
        }
        return true;
    }

    bool IsEven(double x) const
    {
        return !(x - floor(x / 2) * 2);
    }

    Array& IndexesOf(double x)
    {
        Array result;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == x)
            {
                result.InsertEnd(i);
            }
        }
        return result;
    }

    void SwapAll(double from, double to)
    {
        for(int i = 0; i < n; i++)
        {
            if(a[i] == from)
            {
                a[i] = to;
            }
        }
    }

    void RemoveAll(double x)
    {
        Array temp;
        for (int i = 0; i < n; i++)
        {
            if(a[i] != x)
            {
                temp.InsertEnd(a[i]);
            }
        }
        
        this->a = temp.a;
        this->n = temp.n;
    }

    static void Print(Array a)
    {
        for(int i = 0; i < a.n; i++)
        {
            std::cout << a.a[i] << std::endl;
        }
    }
    
#pragma endregion Lab9172021
};

int main()
{
    Array a = Array(3, 2);
    a.InsertBeginning(1);
    a.InsertEnd(3);
    std::cout << "Search1(1): " << a.Search1(1) << std::endl;
    std::cout << "Search1(3): " << a.Search1(3) << std::endl;
    std::cout << "Search1(4): " << a.Search1(4) << std::endl;
    std::cout << "Search2(1): " << a.Search2(1) << std::endl;
    std::cout << "Search2(3): " << a.Search2(3) << std::endl;
    std::cout << "Search2(4): " << a.Search2(4) << std::endl;
    std::cout << "Search3(1): " << a.Search3(1) << std::endl;
    std::cout << "Search3(3): " << a.Search3(3) << std::endl;
    std::cout << "Search3(4): " << a.Search3(4) << std::endl;
    std::cout << "Search4(1): " << a.Search4(1) << std::endl;
    std::cout << "Search4(3): " << a.Search4(3) << std::endl;
    std::cout << "Search4(4): " << a.Search4(4) << std::endl;

    Array b = Array(3, 2);
    std::cout << "IsAllEven1: " << b.IsAllEven1() << std::endl;
    std::cout << "IsAllEven2: " << b.IsAllEven2() << std::endl;
    std::cout << "IsAllEven3: " << b.IsAllEven3() << std::endl;
    std::cout << "IsAllEven4: " << b.IsAllEven4() << std::endl;
    b.InsertBeginning(3);
    std::cout << "IsAllEven1: " << b.IsAllEven1() << std::endl;
    std::cout << "IsAllEven2: " << b.IsAllEven2() << std::endl;
    std::cout << "IsAllEven3: " << b.IsAllEven3() << std::endl;
    std::cout << "IsAllEven4: " << b.IsAllEven4() << std::endl;

    Array c;
    c.InsertEnd(0);
    c.InsertEnd(1);
    c.InsertEnd(2);
    c.InsertEnd(0);
    Array indexes = c.IndexesOf(0);
    std::cout << "Indexes: " << std::endl;
    Array::Print(indexes);

    c.SwapAll(0, 3);
    std::cout << "SwapAll(0 to 3): " << std::endl;
    Array::Print(c);
    
    c.RemoveAll(3);
    std::cout << "RemoveAll(3): " << std::endl;
    Array::Print(c);
    return 0;
}
