#include <iostream>

double f(double* a, double* b, int n, int m)
{
    double value = 0;
    for(int i = 0; i < n; i++)
    {
        double temp = 0;
        for(int j = 0; j < m; j++)
        {
            temp = a[i] * b[j];
        }
        value += temp;
    }

    return value;
}

void f(double* a, double* b, int n, int m, double* result)
{
    for(int i = 0; i < n; i++)
    {
        double temp = 0;
        for(int j = 0; j < m; j++)
        {
            temp = a[i] * b[j];
        }
        *result += temp;
    }
}

void f(double* a, double* b, int n, int m, double& result)
{
    for(int i = 0; i < n; i++)
    {
        double temp = 0;
        for(int j = 0; j < m; j++)
        {
            temp = a[i] * b[j];
        }
        result += temp;
    }
}

double GetMax(double* x, int n)
{
    double result = x[0];
    for(int i = 1; i <= n; i++)
    {
        if(x[i] > result)
        {
            result = x[i];
        }
    }

    return result;
}

void GetMax(double* x, int n, double* vmax)
{
    *vmax = x[0];
    for(int i = 1; i <= n; i++)
    {
        if(x[i] > *vmax)
        {
            *vmax = x[i];
        }
    }
}

void GetMax(double* x, int n, double& vmax)
{
    vmax = x[0];
    for(int i = 1; i <= n; i++)
    {
        if(x[i] > vmax)
        {
            vmax = x[i];
        }
    }
}

struct SPoint3D
{
    int x;
    int y;
    int z;

    double Distance(SPoint3D point1, SPoint3D point2) const
    {
        return sqrt(
            (point2.x - point1.x) * (point2.x - point1.x) +
            (point2.y - point1.y) * (point2.y - point1.y) +
            (point2.z - point1.z) * (point2.z - point1.z));
    }
    
    double DistanceFromOrigin(const SPoint3D point) const
    {
        const SPoint3D origin = SPoint3D();
        return Distance(point, origin);
    }

    void Add(SPoint3D point)
    {
        x += point.x;
        y += point.y;
        z += point.z;
    }

    void Subtract(SPoint3D point)
    {
        x -= point.x;
        y -= point.y;
        z -= point.z;
    }
};

class CPoint3D
{
    int x;
    int y;
    int z;
public:
    CPoint3D()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    
    CPoint3D(const int x, const int y, const int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    CPoint3D(const CPoint3D& destination)
    {
        this->x = destination.x;
        this->y = destination.y;
        this->z = destination.z;
    }
    
    int GetX() const
    {
        return x;
    }

    void SetX(const int value)
    {
        this->x = value;
    }
    
    int GetY() const
    {
        return y;
    }
    
    void SetY(const int value)
    {
        this->y = value;
    }
    
    int GetZ() const
    {
        return z;
    }

    void SetZ(const int value)
    {
        this->z = value;
    }

    double Distance(const CPoint3D& point1, const CPoint3D& point2) const
    {
        return sqrt(
            (point2.x - point1.x) * (point2.x - point1.x) +
            (point2.y - point1.y) * (point2.y - point1.y) +
            (point2.z - point1.z) * (point2.z - point1.z));
    }
    
    double DistanceFromOrigin(const CPoint3D& point) const
    {
        const CPoint3D origin;
        return Distance(point, origin);
    }

    CPoint3D& operator +(const CPoint3D& point1) const
    {
        CPoint3D result = CPoint3D(point1.x + x, point1.y + y, point1.z + z);
        return result;
    }

    CPoint3D& operator -(const CPoint3D& point1) const
    {
        CPoint3D result = CPoint3D(point1.x - x, point1.y - y, point1.z - z);
        return result;
    }
};

int main()
{
    const int n = 3;
    const int m = 3;
    double* a = new double[n] { 1, 2, 3 }; 
    double* b = new double[m] { 4, 5, 6 };

    std::cout << f(a, b, n, m) << std::endl;

    double* result = new double(0);
    f(a, b, n, m, result);
    std::cout << *result << std::endl;

    double result2;
    f(a, b, n, m, &result2);
    std::cout << result2 << std::endl;

    std::cout << std::endl;
    
    std::cout << GetMax(a, n) << std::endl;
    
    double* vmax = new double(0);
    GetMax(a, n, vmax);
    std::cout << *vmax << std::endl;
    
    double vmax2 = 0;
    GetMax(a, n, vmax2);
    std::cout << vmax2 << std::endl;
    
    return 0;
}
