#include <bits/stdc++.h>

using namespace std;

float f(float x){
    return pow(x, 2) - (3*x) + 2;
}
float df(float x){
    return (2*x) - 3;
}

int main(){

    float x, x0, E = 0.0005, root=0;
    int n, i;

    cout<<"Enter initial guess:";
    cin>>x0;

    cout<<"Enter total number of iteration: ";
    cin>>n;

    for(i=0; i<n; i++){

        x = x0 - f(x0) / df(x0);

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

}
