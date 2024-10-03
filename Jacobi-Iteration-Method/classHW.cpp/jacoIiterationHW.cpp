#include <bits/stdc++.h>

using namespace std;

// Built in function
/*

void extractEquation1(string equation, int &a, int &b, int &c, int &d) {
    equation = regex_replace(equation, regex("x1"), "");
    equation = regex_replace(equation, regex("x2"), "");
    equation = regex_replace(equation, regex("x3"), "");
    equation = regex_replace(equation, regex("\\+"), " ");
    equation = regex_replace(equation, regex("="), " ");
    
    stringstream ss(equation);
    ss >> a >> b >> c >> d;
}

*/

// My function
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

            i++; //not taking the integer after x.

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

int main() {
    float x1, x2, x3, E = 0.005;
    int i, n, flag = 0;

    float a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
    string eq1, eq2, eq3;

    cout << "Enter the first equation (a1x1 + b1x2 + c1x3 = d1): ";
    getline(cin, eq1);
    cout << "Enter the second equation (a2x1+b2x2 + c2x3 = d2): ";
    getline(cin, eq2);
    cout << "Enter the third equation (a3x1 + b3x2 + c34x3 = d3): ";
    getline(cin, eq3);

    extractEquation(eq1, a1, b1, c1, d1);
    extractEquation(eq2, a2, b2, c2, d2);
    extractEquation(eq3, a3, b3, c3, d3);

/*
    cout<<a1<<" "<<b1<<" "<<c1<<" "<<d1<<endl;
    cout<<a2<<" "<<b2<<" "<<c2<<" "<<d2<<endl;
    cout<<a3<<" "<<b3<<" "<<c3<<" "<<d3<<endl;

    return 0;

*/
    x1 = 0, x2 = 0, x3 = 0, n = 200;

    for (i = 0; i < n; i++) {
        float new_x1, new_x2, new_x3;

        new_x1 = (d1 - (b1 * x2) - (c1 * x3)) / a1;
        new_x2 = (d2 - (a2 * x1) - (c2 * x3)) / b2;
        new_x3 = (d3 - (a3 * x1) - (b3 * x2)) / c3;

        if (abs((new_x1 - x1)) <= E && abs((new_x2 - x2)) <= E && abs((new_x3 - x3)) <= E) {
            flag = 1;
            break;
        }

        x1 = new_x1;
        x2 = new_x2;
        x3 = new_x3;

        cout << "The value of x1 in iteration " << i + 1 << " is = " << x1 << endl;
        cout << "The value of x2 in iteration " << i + 1 << " is = " << x2 << endl;
        cout << "The value of x3 in iteration " << i + 1 << " is = " << x3 << endl;
        cout << endl;
    }

    if (!flag) {
        cout << "The root is not found!" << endl;
    } else {
        cout << "The value of x1 = " << x1 << endl;
        cout << "The value of x2 = " << x2 << endl;
        cout << "The value of x3 = " << x3 << endl;
        cout << "Total number of iterations = " << i + 1 << endl;
        cout << endl;
    }

    return 0;
}

/*

// Equaions from lab test
2x1 + x2 + x3 = 5
3x1 + 5x2 + 2x3 = 15        ans => 1, 2, 1
2x1 + x2 + 4x3 = 8      

// My random equations
2.098x1 + x2 - 5.89x3 = 5.907
-3x1 - 5.789x2 + 2.897x3 = -15.896
2x1 - x2 + 4x3 = -8.979


*/
 
 