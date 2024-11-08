#include<bits/stdc++.h>

using namespace std;

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

float f(float x){
    return 1/(1+x);
}
float f1(int degree, float coefficients[], float x0){

    float temp=0;
    int i;

    for(i=0; i<=degree; i++){
            temp+= (coefficients[i] * pow(x0, (degree - i)) );
        }
}

float solveByTrapezoidal(float y[], float h, int maxIndex){
    int i;
    float sum=0;

    for(i=0; i<maxIndex; i++){

        for(i=0; i<maxIndex; i++){
            if(i==0 || i==(maxIndex-1)){
                sum+=y[i];
            }
            else{
                sum+= 2*(y[i]);
            }
        }
    }

    return sum * (h/2);
}
float solveBySimson38(float y[], float h, int maxIndex){
    int i;
    float sum=0;

    for(i=0; i<maxIndex; i++){

        for(i=0; i<maxIndex; i++){
            if(i==0 || i==(maxIndex-1)){
                sum+=y[i];
            }
            else if(i%3==0){
                sum+= 2*(y[i]);
            }
            else{
                sum+= 3*(y[i]);
            }
        }
    }

    return sum * (3*h/8);
}



int main(){
    
    int n, i;
    float h, x0, xn;
    

    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    string equation, functionStr;
    cout << "Enter the polynomial equation (ax^n + bx^n-1 + .... + px^2 + qx + r): ";
    cin.ignore();
    getline(cin, equation);

    float coefficients[degree + 1] = {0};

    extractPolynomialEquation(equation, coefficients, degree);
    

    cout<<"Enter the lower limit : ";
    cin>>x0;
    cout<<"Enter the higher limit : ";
    cin>>xn;
    cout<<"Enter the value of h : ";
    cin>>h;

    int maxIndex = (xn-x0)/h + 1;

    float y[maxIndex];

    for(i=0; i<maxIndex; i++){
        y[i] = f(x0 + (i*h));
    }

    for(i=0; i<maxIndex; i++){
        cout<<"y"<<i<<" = "<<y[i]<<" ";
    }
    cout<<endl;

    cout<<"Solution by Simpson 3/8 Rule : I = "<<solveBySimson38(y,h,maxIndex)<<endl;

    return 0;
}



//  X0 = 0
//  Xn = 1
//  h = 0.125

// Simpson 1/3 = h/3 [y0 + 4(y1 + y3 + y5 + ...) + 2(y2 + y4 + y6)+ yn]
// Simpson 3/8 = 3h/8 [y0 + 3(y1 + y2 + y5 + ...) + 2(y3 + y6 + ....)+ yn]