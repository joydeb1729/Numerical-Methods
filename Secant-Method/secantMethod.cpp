#include <bits/stdc++.h>

using namespace std;

float f(float x){
    return pow(x,2) - (4*x) - 10;
}

int main(){

    float x1, x2, x3, E = 0.0005, root=0;
    int n, i;

    cout<<"Enter x1 and x2: ";
    cin>>x1>>x2;

    cout<<"Enter total number of iteration: ";
    cin>>n;


    for(i=0; i<n; i++){

        x3 = x2 - (f(x2)*(x2-x1))/(f(x2)-f(x1));

        if(abs((x3-x2)/x3) <= E){
            root = x3;
            break;
        }
        else{
            x1 = x2;
            x2 = x3;
        }

        cout<<"The value of x3 in iteration "<<i+1<<" is = "<<x3<<endl;

    }

    cout << "\nProbable answer: " << root << "\nTotal iterations: " << i+1 << endl;

}