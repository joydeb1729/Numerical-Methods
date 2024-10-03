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
                temp = "1"; 
            }

            arr[j] = stof(temp);

            if(isNegative){
                arr[j] *= -1;
            }

            i++;

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
    float x1, x2, x3, E = 0.000005;
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


    x1 = 0, x2 = 0, x3 = 0, n = 20;

    for (i = 0; i < n; i++) {

        float prev_x1 = x1, prev_x2 = x2, prev_x3 = x3;

        x1 = (d1 - (b1 * x2) - (c1 * x3)) / a1;
        x2 = (d2 - (a2 * x1) - (c2 * x3)) / b2;
        x3 = (d3 - (a3 * x1) - (b3 * x2)) / c3;

        if (abs((x1 - prev_x1)) <= E && abs((x2 - prev_x2)) <= E && abs((x3 - prev_x3)) <= E) {
            flag = 1;
            break;
        }

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

*/
 
 