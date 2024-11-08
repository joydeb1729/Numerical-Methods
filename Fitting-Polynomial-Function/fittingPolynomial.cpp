#include<bits/stdc++.h>

using namespace std;

int main(){
    int n=5, i, j;

    cout<<"Enter the values of n: ";
    cin>>n;

    float sum_x[n]={0}, sum_yx[n]={0};
    float xi, yi;
    float matrix[n-1][n];

    for(i = 0; i<n; i++){
        cout<<"Enter the values of (X"<<i+1<< ",Y"<<i+1<<"): ";
        cin>>xi>>yi;

        for(j=0; j<n; j++){
            sum_x[j] += pow(xi, j+1);
        }
        for(j=0; j<n; j++){
            sum_yx[j]+= (yi * pow(xi,j));
        }
    }

    
    for(i=0; i<n-1; i++){
        for(j=0; j<n; j++){
            if(i==0 && j==0){
                matrix[i][j] = n;
            }
            else if(j==n-1){
                matrix[i][j] = sum_yx[i];
            }
            else{
                matrix[i][j] = sum_x[i+j-1];
            }
        }
    }

    cout<<"The Augmented matrix from the values: \n";
    for(i=0; i<n-1; i++){
        for(j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // Using Gauss-Jordan to solve the Augmented Matrix
    for (int i = 0; i < n - 1; i++)
    {
        float pivot = matrix[i][i];
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] /= pivot;
        }

        for (int k = 0; k < n - 1; k++)
        {
            if (k != i)
            {
                float factor = matrix[k][i];
                for (int j = 0; j < n; j++)
                {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
        cout << "Equations after step " << i + 1 << " (Coefficients & Constants only):\n";
        for (int k = 0; k < n-1; k++)
        {
            for (int l = 0; l < n; l++)
            {
                cout << matrix[k][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

     cout <<" Final Equation : y = ";
    for (int i = 0; i < n - 1; i++)
    {
        if(i==0){
            cout<<matrix[i][n-1]<<" + ";
        }
        else if(i==1){
            cout<<matrix[i][n-1]<<"x + ";
        }
        else if(i==n-2){
            cout<<matrix[i][n-1]<<"x^"<<n-2<<endl;
        }
        else
        cout<<matrix[i][n-1]<<"x^"<<i+1<<" + ";
    }

    return 0;
}
    




//  X => 1, 2, 3, 4 
//  Y => 6, 11, 18, 27

// a1=3, a2=2, a3=1; 