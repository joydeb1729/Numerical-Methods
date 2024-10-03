#include<bits/stdc++.h>

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


int main(){

    int i, j;

    float values[3][4];
    string eq1, eq2, eq3;

    cout << "Enter the first equation (a1x1 + b1x2 + c1x3 = d1): ";
    getline(cin, eq1);
    cout << "Enter the second equation (a2x1+b2x2 + c2x3 = d2): ";
    getline(cin, eq2);
    cout << "Enter the third equation (a3x1 + b3x2 + c34x3 = d3): ";
    getline(cin, eq3);

    extractEquation(eq1, values[0][0], values[0][1], values[0][2], values[0][3]);
    extractEquation(eq2, values[1][0], values[1][1], values[1][2], values[1][3]);
    extractEquation(eq3, values[2][0], values[2][1], values[2][2], values[2][3]);

    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            cout<<values[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    float pivot, temp1, temp2;
    for(i=0; i<3; i++){
        pivot = values[i][i];
        if(i==0){
            temp1 = pivot/values[1][i];
            temp2 = pivot/values[2][i];
            for(j=0; j<4; j++){
                values[i+1][j] = values[i][j] - (temp1*values[i+1][j]);
                values[i+2][j] = values[i][j] - (temp2*values[i+2][j]);
            }
        }
        else if(i==1){
            temp2 = pivot/values[2][i];
            for(j=0; j<4; j++){
                values[i+1][j] = values[i][j] - (temp2*values[i+1][j]);
            }
        }

        for(int k=0; k<3; k++){
        for(int l=0; l<4; l++){
            cout<<values[k][l]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    }

    float x1, x2, x3;

    x3 = values[2][3] / values[2][2];
    x2 = (values[1][3] - (x3 * values[1][2])) / values[1][1];
    x1 = (values[0][3] - (x3*values[0][2]) - (x2*values[0][1])) / values[0][0];

    cout<<"x1 = "<<x1<<", "<<"x2 = "<<x2<<", "<<"x3 = "<<x3<<endl;

}

/*

2x1 + 4x2 - 6x3 = -8
x1 + 3x2 + x3 = 10
2x1 - 4x2 - 2x3 = -12


*/