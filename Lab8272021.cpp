#include <iostream>
#include <string>

bool isEven(int i)
{
    if (i % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEvenV2(int i)
{
    return i % 2 == 0 ? true : false;
}

std::string MonthToString(float i)
{
    if (i == 1)
    {
        return "January";
    }
    else if (i == 2)
    {
        return "February";
    }
    else if (i == 3)
    {
        return "March";
    }
    else if (i == 4)
    {
        return "April";
    }
    else if (i == 5)
    {
        return "May";
    }
    else if (i == 6)
    {
        return "June";
    }
    else if (i == 7)
    {
        return "July";
    }
    else if (i == 8)
    {
        return "August";
    }
    else if (i == 9)
    {
        return "September";
    }
    else if (i == 10)
    {
        return "October";
    }
    else if (i == 11)
    {
        return "November";
    }
    else if (i == 12)
    {
        return "December";
    }
    else
    {
        return "Invalid Input";
    }
}

std::string MonthToStringV2(int i)
{
    switch (i)
    {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Invalid Input";
    }
}

float x1(float n)
{
    float value = 0;
    for (float i = 1; i <= n; i++)
    {
        value += i / (i + 1);
    }

    return value;
}

float x1v2(float n)
{
    float value = 0;
    float i = 1;
    while (i <= n)
    {
        value += i / (i + 1);
        i++;
    }

    return value;
}

float x2(float n)
{
    float value = 0;
    for (float i = 1; i <= n; i++)
    {
        float temp = 0;
        for(float j = i; j <= n; j++)
        {
            temp += i * j;
        }

        value += temp;
    }

    return value;
}

float x2v2(float n)
{
    float value = 0;
    float i = 1;
    while(i <= n)
    {
        float temp = 0;
        float j = i;
        while (j <= n)
        {
            temp += i * j;
            j++;
        }

        value += temp;
        i++;
    }

    return value;
}

float x3(float n)
{
    float value = 0;
    for (float i = 1; i <= n; i++)
    {
        float temp = 0;
        for(float j = 1; j <= n; j++)
        {
            float temp2 = 0;
            for(float k = 1; k <= n; k++)
            {
                temp2 += 1 / sqrtf(i + j + k);
            }
            temp += temp2;
        }
        value += temp;
    }

    return value;
}

float x3v2(float n)
{
    float value = 0;
    float i = 1;
    while (i <= n)
    {
        float temp = 0;
        float j = 1;
        while (j <= n)
        {
            float temp2 = 0;
            float k = 1;
            while (k <= n)
            {
                temp2 += 1 / sqrtf(i + j + k);
                k++;
            }
            temp += temp2;
            j++;
        }
        value += temp;
        i++;
    }

    return value;
}

float x4(float n)
{
    float value = 1;
    
    for (float i = 1; i <= n; i++)
    {
        float temp = 0;
        for (float j = 1; j <= n; j++)
        {
            temp += j;
        }
        value *= i * temp;
    }

    return value;
}

float x4v2(float n)
{
    float value = 1;
    float i = 1;
    while (i <= n)
    {
        float temp = 0;
        float j = 1;
        while (j <= n)
        {
            temp += j;
            j++;
        }
        value *= i * temp;
        i++;
    }

    return value;
}

float x5(float n)
{
    float value = 0;
    
    for (float i = 1; i <= n; i++)
    {
        if(!isEven(i))
        {
            value += 4;
        }
        else
        {
            value += 9;
        }
    }

    return value;
}

float x5v2(float n)
{
    float value = 0;
    float i = 1;
    while (i <= n)
    {
        if(!isEven(i))
        {
            value += 4;
        }
        else
        {
            value += 9;
        }
        i++;
    }

    return value;
}

float x6(float (*f)(float), float n)
{
    float value = 0;
    
    for (float i = 1; i <= n; i++)
    {
        value += f(i);
    }

    return value;
}

float x7(float (*f)(float), float n)
{
    float value = 0;
    
    for (float i = 1; i <= n; i++)
    {
        value *= f(i);
    }

    return value;
}

float x9(float n, float m)
{
    float value = 0;
    
    for (float i = 1; i <= n; i++)
    {
        float temp = 0;
        for(float j = 1; j <= m; j++)
        {
            temp *= sqrtf(i) * j * j;
        }
        value += temp;
    }

    return value;
}

float x10(float a, float n)
{
    float value = 0;
    
    for (float i = 1; i <= n; i++)
    {
        value += a * i * i;
    }

    return sqrtf(value);
}

float main()
{
    std::cout << "Exercise 1" << std::endl;
    std::cout << (isEven(0) ? "True" : "False") << std::endl;
    std::cout << (isEven(1) ? "True" : "False") << std::endl;
    std::cout << (isEvenV2(0) ? "True" : "False") << std::endl;
    std::cout << (isEvenV2(1) ? "True" : "False") << std::endl;
    std::cout << std::endl;
    
    std::cout << "Exercise 2" << std::endl;
    std::cout << MonthToString(1) << std::endl;
    std::cout << MonthToString(2) << std::endl;
    std::cout << MonthToString(3) << std::endl;
    std::cout << MonthToString(4) << std::endl;
    std::cout << MonthToString(5) << std::endl;
    std::cout << MonthToString(6) << std::endl;
    std::cout << MonthToString(7) << std::endl;
    std::cout << MonthToString(8) << std::endl;
    std::cout << MonthToString(9) << std::endl;
    std::cout << MonthToString(10) << std::endl;
    std::cout << MonthToString(11) << std::endl;
    std::cout << MonthToString(12) << std::endl;
    std::cout << MonthToString(0) << std::endl;
    std::cout << MonthToStringV2(1) << std::endl;
    std::cout << MonthToStringV2(2) << std::endl;
    std::cout << MonthToStringV2(3) << std::endl;
    std::cout << MonthToStringV2(4) << std::endl;
    std::cout << MonthToStringV2(5) << std::endl;
    std::cout << MonthToStringV2(6) << std::endl;
    std::cout << MonthToStringV2(7) << std::endl;
    std::cout << MonthToStringV2(8) << std::endl;
    std::cout << MonthToStringV2(9) << std::endl;
    std::cout << MonthToStringV2(10) << std::endl;
    std::cout << MonthToStringV2(11) << std::endl;
    std::cout << MonthToStringV2(12) << std::endl;
    std::cout << MonthToStringV2(0) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Exercise 1.1" << std::endl;
    std::cout << x1(10) << std::endl;
    std::cout << x1(100) << std::endl;
    std::cout << x1(1000) << std::endl;
    std::cout << x1v2(10) << std::endl;
    std::cout << x1v2(100) << std::endl;
    std::cout << x1v2(1000) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Exercise 1.2" << std::endl;
    std::cout << x2(10) << std::endl;
    std::cout << x2(100) << std::endl;
    std::cout << x2(1000) << std::endl;
    std::cout << x2v2(10) << std::endl;
    std::cout << x2v2(100) << std::endl;
    std::cout << x2v2(1000) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Exercise 1.3" << std::endl;
    std::cout << x3(10) << std::endl;
    std::cout << x3(100) << std::endl;
    std::cout << x3(1000) << std::endl;
    std::cout << x3v2(10) << std::endl;
    std::cout << x3v2(100) << std::endl;
    std::cout << x3v2(1000) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Exercise 1.4" << std::endl;
    std::cout << x4(10) << std::endl;
    std::cout << x4(100) << std::endl;
    std::cout << x4(1000) << std::endl;
    std::cout << x4v2(10) << std::endl;
    std::cout << x4v2(100) << std::endl;
    std::cout << x4v2(1000) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Exercise 1.5" << std::endl;
    std::cout << x5(10) << std::endl;
    std::cout << x5(100) << std::endl;
    std::cout << x5(1000) << std::endl;
    std::cout << x5v2(10) << std::endl;
    std::cout << x5v2(100) << std::endl;
    std::cout << x5v2(1000) << std::endl;
    std::cout << std::endl;
    
    return 0;
}
