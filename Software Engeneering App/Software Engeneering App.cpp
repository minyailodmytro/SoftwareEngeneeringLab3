#include <iostream>
#include <limits>
using namespace std;

int main()
{

    double m, n, step;
    int x;
    double sum = 0;
    double mlt = 1;
    int flagZero = 0; // checks division by zero
    do
    {
        cout << "Input n>=4, n=";
        cin >> n;
        if (cin.fail() || n < 4)
        {
            cout << "ERROR! Illegal n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail() || n < 4);
    do
    {
        cout << "Input A; B: ";
        cin >> a >> b;
        if (cin.fail() || a > b) {
            cout << "ERROR! A and B must be numbers and B must be bigger than A!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (cin.fail() || a > b);
    do
    {
        cout << "Input step>0, step=";
        cin >> step;
        if (cin.fail() || step <= 0) cout << "ERROR! Step must be a number and bigger than zero" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (cin.fail() || step <= 0);
    for (double x = a; x <= b; x += step)
    {
        sum = 0;
        mlt = 1;
        if (x <= 0)
        {
            for (int i = 0; i <= n - 1; i++)
            {
                for (int j = 0; j <= n - 1; j++)
                {
                    if (x == (i - j))
                    {
                        flagZero = 1;
                        i = n - 1;
                        j = n - 1;
                    }
                    else
                    {
                        sum += 1.0 / (x - i + j);
                    }
                }
            }
            if (flagZero == 1)
            {
                cout << "x=" << x << "; " << "ERROR! Illegal x: division by zero" << endl;
                flagZero = 0;
            }
            else
            {
                cout << "x=" << x << "; " << "sum=" << sum << endl;
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                mlt *= 1.0 / x - 1.0 / i;
            }
            cout << "x=" << x << "; " << "mlt=" << mlt << endl;
        }
    }
    return 0;
}