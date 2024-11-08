#include <bits/stdc++.h>
using namespace std;

void extractPolynomialEquation(string equation, float coefficients[], int n)
{
    int length = equation.length();
    string temp = "";
    bool isNegative = false;

    for (int i = 0; i < length; i++)
    {
        if ((equation[i] >= '0' && equation[i] <= '9') || equation[i] == '.')
        {
            temp += equation[i];
        }
        else if (equation[i] == '-')
        {
            isNegative = true;
        }
        else if (equation[i] == 'x' || equation[i] == 'X' || equation[i] == 'y' || equation[i] == 'Y')
        {
            if (temp.empty()) temp = "1";  // Default coefficient = 1

            float value = stof(temp);
            if (isNegative) value *= -1;  // Adjust sign

            int x_power = 0, y_power = 0;

            // Extracting x power
            if (equation[i] == 'x' || equation[i] == 'X')
            {
                i++;
                if (i < length && equation[i] == '^')
                {
                    i++;
                    string powerStr = "";
                    while (i < length && isdigit(equation[i]))
                    {
                        powerStr += equation[i];
                        i++;
                    }
                    x_power = stoi(powerStr);
                }
                else
                {
                    x_power = 1;
                }
            }

            // Extracting y power
            if (equation[i] == 'y' || equation[i] == 'Y')
            {
                i++;
                if (i < length && equation[i] == '^')
                {
                    i++;
                    string powerStr = "";
                    while (i < length && isdigit(equation[i]))
                    {
                        powerStr += equation[i];
                        i++;
                    }
                    i--;
                    y_power = stoi(powerStr);
                }
                else
                {
                    y_power = 1;
                }
            }

            if (y_power == 0)  // Pure x term
            {
                coefficients[x_power] += value;
            }
            else if (x_power == 0)  // Pure y term
            {
                coefficients[n + y_power] += value;
            }
            else  // Mixed x^i y^j term
            {
                int index = (n * 2) + (x_power * n) + y_power;
                coefficients[index] += value;
            }

            temp = "";
            isNegative = false;
        }
        else if (equation[i] == '+')
        {
            isNegative = false;
        }
    }

    // Storing constant in coefficients[0]
    if (!temp.empty())
    {
        float value = stof(temp);
        if (isNegative) value *= -1;
        coefficients[0] += value; 
    }
}

int main()
{
    int n;
    cout << "Enter the maximum degree of the polynomial: ";
    cin >> n;

    string equation;
    cout << "Enter the polynomial equation (ax^m y^n + bx^p + cy^q + ... + d): ";
    cin.ignore();
    getline(cin, equation);

    int coeffSize = 2 * n + (n * n);  // to store all x,y,xy terms 
    float coefficients[coeffSize] = {0};

    extractPolynomialEquation(equation, coefficients, n);

    cout << "\nThe extracted coefficients are:" << endl;
    for (int i = 1; i <= n; i++)
    {
        if(coefficients[i])
        cout << "Coefficient of x^" << i << ": " << coefficients[i] << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if(coefficients[n + i])
        cout << "Coefficient of y^" << i << ": " << coefficients[n + i] << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(i+j>n) continue;

            if(coefficients[2 * n + i * n + j])
            cout << "Coefficient of x^" << i << " y^" << j << ": " << coefficients[2 * n + i * n + j] << endl;
        }
    }
     cout << "Coefficient of constant term : " << coefficients[0] << endl;

    return 0;
}


/*
n=5

9x^3y^2 + 7x^2y^3 + 7xy + 8.6x^5 + 8x^2  - 97y^4 - 78y^3 + 67x + 76y + 100

*/