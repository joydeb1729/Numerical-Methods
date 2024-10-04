#include<bits/stdc++.h>

using namespace std;

int main(){
    int n=5, i;

    float sum_lnx=0, sum_lny=0, sum_lnxlny=0, sum_lnx_square=0;
    float a, b, xi, yi, lna;

    cout<<"Enter the values of n: ";
    cin>>n;

    for(i = 0; i<n; i++){
        cout<<"Enter the values of (X"<<i+1<< ",Y"<<i+1<<"): ";
        cin>>xi>>yi;
        sum_lnx+= log(xi);
        sum_lny+=log(yi);
        sum_lnxlny+= (log(xi)*log(yi));
        sum_lnx_square += (log(xi)*log(xi));
    }
    //cout<<sum_x<<" "<<sum_y<<" "<<sum_xy<<" "<<sum_x_square<<endl;

    b = ((n*sum_lnxlny) - (sum_lnx*sum_lny)) / (n*(sum_lnx_square)- (sum_lnx*sum_lnx));

    lna = (sum_lny/n) - (b*(sum_lnx/n));
    a = exp(lna);

    cout<<"y = "<<a<<"x^"<<b<<endl;
}


// X => 1, 2, 3, 4, 5
// Y => 0.5, 2, 4.5, 8, 12.5

// Ans => y=0.5x^2