#include <iostream>
using namespace std;

void checkValidInput()
{
    if (cin.fail()) throw "Invalid data: number required";
}

void checkValidParamN(int n)
{
    if(n < 4) throw "Invalid data: n must be bigger than 4";
}

void checkValidParamsAB(double a, double b)
{
    if (b < a) throw "Invalid data: b must be bigger than a";
}

void checkValidParamStep(double step)
{
    if (step <= 0) throw "Invalid data: step must be bigger than 0";
}

double calculate(int n, double x)
{
    double sum = 0;
    double mlt = 1;
    bool flagZero = false;
    if (x <= 0)
    {
        for (int i = 0; i <= n - 1; i++)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                if (x == (i - j))
                {
                    flagZero = true;
                    i = n - 1;
                    j = n - 1;
                }
                else
                {
                    sum += 1.0 / (x - i + j);
                }
            }
        }
        if (flagZero == true)
        {
            return flagZero;
            flagZero = false;
        }
        else
        {
            return sum;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            mlt *= 1.0 / x - 1.0 / i;
        }
        return mlt;
    }
}

int main()
{
    double a, b, step;
    int n;
    try
    {
        cout << "Input n >= 4, n: ";
        cin >> n;
        checkValidInput();
        checkValidParamN(n);
        cout << "Input A; B: ";
        cin >> a >> b;
        checkValidInput();
        checkValidParamsAB(a,b);
        cout << "Input step > 0, step: ";
        cin >> step;
        checkValidInput();
        checkValidParamStep(step);
        for (double x = a; x <= b; x += step)
        {
            if (calculate(n, x) == true) cout << "x = " << x << "\t" << "Division by zero" << endl;
            else cout << "x = " << x << "\t" << "y = " << calculate(n, x) << endl;
        }
    }
    catch (const char* ex)
    {
        cout << ex << endl;
        return -1;
    }
    catch (...)
    {
        cout << "Unknown error" << endl;
        return -2;
    }
}