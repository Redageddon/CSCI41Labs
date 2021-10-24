#include <iostream>

class Array
{
private:
    double* a;
    int n;
public:
    Array()
    {
        this->n = 1;
        this->a = new double[n];
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

    static void TestAllFunctions()
    {
        Array a = Array(3, 3);
        for (int i = 0; i < a.n; i++)
        {
            std::cout << a.a[i] << std::endl;
        }
        std::cout << std::endl << "GetSize:" << std::endl;
        std::cout << a.GetSize() << std::endl << "________________________" << std::endl;
        
        a.a[0] = 0;
        a.a[1] = 1;
        a.a[2] = 2;
        
        for (int i = 0; i < a.n; i++)
        {
            std::cout << a.a[i] << std::endl;
        }
        std::cout << std::endl << "Invert:" << std::endl;

        a.Invert();
        for (int i = 0; i < a.n; i++)
        {
            std::cout << a.a[i] << std::endl;
        }
        std::cout << std::endl << "Remove Beginning:" << std::endl;
        
        a.RemoveBeginning();
        for (int i = 0; i < a.n; i++)
        {
            std::cout << a.a[i] << std::endl;
        }
        std::cout << std::endl << "RemoveEnd:" << std::endl;;
        
        a.RemoveEnd();
        for (int i = 0; i < a.n; i++)
        {
            std::cout << a.a[i] << std::endl;
        }
        std::cout << std::endl << "InsertBeginning(0);" << std::endl;

        a.InsertBeginning(0);
        for (int i = 0; i < a.n; i++)
        {
            std::cout << a.a[i] << std::endl;
        }
        std::cout << std::endl << "InsertEnd(2):" << std::endl;
        
        a.InsertEnd(2);
        for (int i = 0; i < a.n; i++)
        {
            std::cout << a.a[i] << std::endl;
        }
        std::cout << std::endl << "Maximum:" << std::endl;;

        std::cout << a.Maximum() << std::endl << "Minimum:" << std::endl;
        
        std::cout << a.Minimum() << std::endl << "Average:" << std::endl;
        
        std::cout << a.Average() << std::endl << "Array + Array:" << std::endl;
        
        Array b = a + a;
        for (int i = 0; i < b.n; i++)
        {
            std::cout << b.a[i] << std::endl;
        }
        std::cout << std::endl << "Array * 3:" << std::endl;
        Array c = a * 3;
        for (int i = 0; i < c.n; i++)
        {
            std::cout << c.a[i] << std::endl;
        }
    }
};


int main()
{
    Array::TestAllFunctions();
    return 0;
}
