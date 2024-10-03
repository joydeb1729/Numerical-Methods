#include <bits/stdc++.h>

using namespace std;


void extractEquation(string equation, float &a, float &b, float &c, float &d){

    int length = equation.length();
    string temp = "";
    int j = 0;
    float arr[4];
    bool isNegative = false;

    // for finding a, b, c
    for(int i=0; i<length; i++){
        
        if((equation[i] >= '0' && equation[i] <= '9') || equation[i] == '.' ){
            temp += equation[i];
        }

        else if(equation[i] == '-'){
            isNegative = true;
        }

        else if(equation[i] == 'x' || equation[i] == 'X'){
            
            if(temp.empty()){
                temp = "1";     // 1 as default co efficient
            }

            arr[j] = stof(temp); // string to float

            if(isNegative){
                arr[j] *= -1;
            }

            i+=2; //not taking the integer after x.

            // reset part
            j++;
            temp = "";
            isNegative = false;
        }
        
    }

    //for finding d
    if(!temp.empty()){
        arr[3] = stof(temp);
        if(isNegative){
            arr[3] *= -1;
        }
    }

    a = arr[0];
    b = arr[1];
    c = arr[2];
    d = arr[3];
}


float f(float x, float a, float b, float c, float d){
    return (a * pow(x, 3) + b * pow(x, 2) + (c*x) - d);
}

float df(float x, float a, float b, float c){
    return ( 3*a* pow(x, 2) + (2*b*x) + c);
}


int main(){

    float x, x0, E = 0.0005, root=0;
    int n , i;

    float a, b, c, d;
    string eq;

    cout << "Enter the equation (ax^3 + bx^2 + cx = d): ";
    getline(cin, eq);

    extractEquation(eq, a, b, c, d);

    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;


    x0 = 0, n =30;

    for(i=0; i<n; i++){

        x = x0 - f(x0, a, b, c, d) / df(x0, a, b, c);

        if(abs((x-x0)/x) <=E){
            root = x;
            break;
        }
        else{
            x0 = x;
        }

        cout<<"The value of x in iteration "<<i+1<<" is = "<<x<<endl;
    }

    cout << "\nProbable answer: " << root << "\nTotal iterations: " << i+1 << endl;


    return 0;
}

/*

ax^3 + bx^2 + cx = d
2x^3 - 3x^2 + 4x = 5 => ans = 1.3711
x^3 + 0x^2 - 2x = 5  => ans = 2.0945

*/
