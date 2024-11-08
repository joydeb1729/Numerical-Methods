#include<bits/stdc++.h>

using namespace std;

int main(){
    int n=5, i;

    float sum_x=0, sum_y=0, sum_xy=0, sum_x_square=0;
    float a, b, xi, yi;

    cout<<"Enter the values of n: ";
    cin>>n;

    for(i = 0; i<n; i++){
        cout<<"Enter the values of (X"<<i+1<< ",Y"<<i+1<<"): ";
        cin>>xi>>yi;
        sum_x+=xi;
        sum_y+=yi;
        sum_xy+= (xi*yi);
        sum_x_square += (xi*xi);
    }
    //cout<<sum_x<<" "<<sum_y<<" "<<sum_xy<<" "<<sum_x_square<<endl;

    b = ((n*sum_xy) - (sum_x*sum_y)) / (n*(sum_x_square)- (sum_x*sum_x));

    a = (sum_y/n) - (b*(sum_x/n));

    cout<<"y = "<<a<<" + "<<b<<"x"<<endl;
}



//  X => 1, 2, 3, 4, 5 
//  Y => 3, 4, 5, 6, 8

// Ans => y=1.6+1.2x