#include <bits/stdc++.h>

using namespace std;

float func(float x)
{
    return pow(x, 2) - 4 * x - 10;
}

int main()
{

    float x1, x2, x0;
    int n;

    cout << "Enter x1 and x2 :" << endl;
    cin >> x1 >> x2;

    cout << "Enter total number of iterations: " << endl;
    cin >> n;

    float fx0, fx1, root = 0, target;
    target = 0.0005;

    int count = 0;
    for (int i = 0; i < n; i++)
    {

        x0 = (x1 + x2) / 2;

        fx0 = func(x0);
        fx1 = func(x1);

        if (abs(fx0) <= target)
        { // Root found with sufficient accuracy
            root = x0;
            count = i + 1;
            break;
        }

        // Update the interval for the next iteration
        if (fx0 * fx1 < 0)
        {
            x2 = x0;
        }
        else
        { // We assume fx0 * fx2 < 0 since other cases are handled
            x1 = x0;
        }
        cout<<"The value of x0 in iteration "<<i+1<<" is = "<<x0<<endl;;

        // Update the root to be the latest x0, even if not exact
        // root = x0;
        count = i + 1; // Increment count of iterations
    }

    cout << "\nProbable answer: " << root << "\nTotal iterations: " << count << endl;

    return 0;
}
