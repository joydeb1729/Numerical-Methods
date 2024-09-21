#include <bits/stdc++.h>

using namespace std;

float func(float x) {
    return pow(x, 2) - x - 2;
}

int main() {
    
    float x1, x2, x0;
    int n;

    cout << "Enter x1 and x2 :" << endl;
    cin >> x1 >> x2;

    cout << "Enter total number of iterations: " << endl;
    cin >> n;

    float fx0, fx1, root = 0, target; 
    target = 0.00005;

    int count = 0;
    for (int i = 0; i < n; i++) {

        x0 = x1 - (func(x1) * (x2 - x1)) / (func(x2) - func(x1));

        fx0 = func(x0);
        fx1 = func(x1);

        if (abs(fx0) <= target) {
            root = x0;
            count = i + 1;  
            break;
        }

 
        if (fx0 * fx1 < 0) {
            x2 = x0;
        } else {
            x1 = x0;
        }

        //root = x0;
        cout<<"The value of x0 in iteration "<<i+1<<" is = "<<x0<<endl;
        count = i + 1;
    }

    cout << "\nProbable answer: " << root << "\nTotal iterations: " << count << endl;

    return 0;
}
