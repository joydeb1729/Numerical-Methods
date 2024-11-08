#include <bits/stdc++.h>

using namespace std;

void extractEquation(string equation, float coefficients[])
{
    int length = equation.length();
    string temp = "";
    bool isNegative = false;

    int idx = 0;

    for (int i = 0; i < length; i++)
    {
        if ((equation[i] >= '0' && equation[i] <= '9') || equation[i] == '.')
        {
            temp += equation[i];
        }
        else if (equation[i] == '-')
        {
            isNegative = true;
        }
        else if (equation[i] == 'x' || equation[i] == 'X')
        {
            if (temp.empty())
            {
                temp = "1";
            }
            float value = stof(temp);
            if (isNegative)
            {
                value *= -1;
            }
            coefficients[idx++] = value;
            i++;
            temp = "";
            isNegative = false;
        }
    }

    if (!temp.empty())
    {
        float value = stof(temp);
        if (isNegative)
        {
            value *= -1;
        }
        coefficients[idx] = value;
    }
}

int main()
{
    int n;

    cout << "Enter the number of unknowns: ";
    cin >> n;
    cin.ignore();

    float values[n][n+1];
    string equation;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter equation " << i+1 << " (a" << i+1 << "x1 + b" << i+1 << "x2 + ... = d" << i+1 << "): ";
        getline(cin, equation);

        float coefficients[n + 1];
        extractEquation(equation, coefficients);

        for (int j = 0; j <= n; j++)
        {
            values[i][j] = coefficients[j];
        }
    }

    cout << "\nInitial Equations (Coefficients & Constants only):" << endl;
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l <= n; l++)
        {
            cout << values[k][l] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        // Making the pivot element 1 (for simplifying)
        float pivot = values[i][i];
        for (int j = 0; j <= n; j++)
        {
            values[i][j] /= pivot;
        }

        // Making other elements in the column 0
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                float factor = values[k][i];
                for (int j = 0; j <= n; j++)
                {
                    values[k][j] -= factor * values[i][j];
                }
            }
        }

        cout << "Equations after step " << i + 1 << " (Coefficients & Constants only):\n";
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l <= n; l++)
            {
                cout << values[k][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << values[i][n] << endl;
    }

    return 0;
}

/*

2x1 + 4x2 - 6x3 = -8
x1 + 3x2 + x3 = 10
2x1 - 4x2 - 2x3 = -12

*/
