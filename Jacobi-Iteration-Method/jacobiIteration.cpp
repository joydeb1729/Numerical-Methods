#include <bits/stdc++.h>

using namespace std;

float f1(float x2, float x3){
    return (5 - x2 -x3) / 2;
}

float f2(float x1, float x3){
    return (15 - (3*x1) - (2*x3)) / 5;
}

float f3(float x1, float x2){
    return (8 - (2*x1) - x2) / 4;
}


int main(){

    float x1, x2, x3, E = 0.000005;
    int i, n, flag = 0;

    cout<<"Enter x1 , x2 and x3: ";
    cin>>x1>>x2>>x3;

    cout<<"Enter total number of iteration: ";
    cin>>n;

    for(i=0; i<n; i++){

        float temp1 = x1, temp2 = x2, temp3 = x3;

        x1 = f1(temp2, temp3);
        x2 = f2(temp1, temp3);
        x3 = f3(temp1, temp2);

        if(abs((x1-temp1)/x1) <=E && abs((x2-temp2)/x2) <=E &&  abs((x3-temp3)/x3) <= E){
            flag = 1;
            break;
        }
        cout<<"The value of x1 in iteration "<<i+1<<" is = "<<x1<<endl;
        cout<<"The value of x2 in iteration "<<i+1<<" is = "<<x2<<endl;
        cout<<"The value of x3 in iteration "<<i+1<<" is = "<<x3<<endl;
        cout<<endl;
    }

    if(!flag){
        cout<<"The roots are not founded!"<<endl;
    }
    else{
        cout<<endl;
        cout<<"The value of x1 is = "<<x1<<endl;
        cout<<"The value of x2 is = "<<x2<<endl;
        cout<<"The value of x3 is = "<<x3<<endl;
        cout<<"Total number of iteration = "<<i+1<<endl;
        
    }



}