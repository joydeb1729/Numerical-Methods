#include <bits/stdc++.h>

using namespace std;

void extractFunction(string equation, float coefficients[])
{
    int length = equation.length();
    string temp = "";
    bool isNegative = false;

    int idx = 0;

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
        else if (equation[i] == '=' )
        {
            if (temp.empty())
            {
                temp = "1";
            }
            float value = stof(temp);
            if (isNegative)
            {
                value *= -1;
            }
            coefficients[idx++] = value;
            i++;
            temp = "";
            isNegative = false;
        }
    }

    if (!temp.empty())
    {
        float value = stof(temp);
        if (isNegative)
        {
            value *= -1;
        }
        coefficients[idx] = value;
    }
}


void extractPolynomialEquation(string equation, float coefficients[], int degree)
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
        else if (equation[i] == 'x' || equation[i] == 'X')
        {
            if (temp.empty())
            {
                temp = "1";
            }
            float value = stof(temp);
            if (isNegative)
            {
                value *= -1;
            }
            i++;
            if (equation[i] == '^')
            {
                i++;
                string powerStr = "";
                while (i < length && (equation[i] >= '0' && equation[i] <= '9'))
                {
                    powerStr += equation[i];
                    i++;
                }
                i--; 
                int power = stoi(powerStr);
                coefficients[degree - power] = value;
            }
            else
            {
                coefficients[degree - 1] = value;
            }

            temp = "";
            isNegative = false;
        }
        else if (equation[i] == '+')
        {
            isNegative = false;
        }
    }

    if (!temp.empty())
    {
        float value = stof(temp);
        if (isNegative)
        {
            value *= -1;
        }
        coefficients[degree] = value;
    }
}

int main()
{
    int degree, i;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    string equation, functionStr;
    cout << "Enter the polynomial equation (ax^n + bx^n-1 + .... + px^2 + qx + r): ";
    cin.ignore();
    getline(cin, equation);

    float h = 0, start=0, endPoint=0, prevY=0, currrentY=0;
    cout << "Enter the value of h: ";
    cin>>h;

    cout << "Enter function value [ y(k) = c ]: ";
    cin.ignore();
    getline(cin, functionStr);

    cout << "Enter the value of final pont: ";
    cin>>endPoint;


    float coefficients[degree + 1] = {0}, funcVal[2];

    extractPolynomialEquation(equation, coefficients, degree);
    extractFunction(functionStr, funcVal);
    start=funcVal[0], prevY=funcVal[0], currrentY=funcVal[1];


    cout << "\nThe extracted coefficients are:" << endl;
    for (int i = 0; i <= degree; i++)
    {
        cout << "Coefficient of x^" << degree - i << ": " << coefficients[i] << endl;
    }
    cout<<endl;
    //cout<<"Start = "<<start<<", End = "<<endPoint<<", h = "<<h<<", Previous Y = "<<prevY<<", Current Y = "<<currrentY<<endl;



    //Euler Method Part =>

    cout<<"y("<<start<<") = "<<currrentY<<endl;

    while(start<endPoint){
        prevY = currrentY;
        float temp = 0;
        for(i=0; i<=degree; i++){
            temp+= (coefficients[i] * pow(start, (degree - i)) );
        }
        currrentY = prevY + h*(temp);
        cout<<"y("<<start+h<<") = "<<currrentY<<endl;
        start+=h;
    }


    return 0;
}

/* 

3x^2 + 1
h=0.5/0.25
y(1) = 2
final=2

*/

