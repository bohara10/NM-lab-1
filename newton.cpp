// Newton Raphson Method
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float function(float x)
{
    return sin(x) + x * x + 5 * x - 9;
}

float derivative(float x)
{
    return cos(x) + 2 * x + 5;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << endl;
    float c, x_old, x_new, fx, dx, error;
    c = 1;
    x_new = num;

    cout << "Iteration\tx(old)\t\tf(x) (old)\tf`(x) (old)\tx(new)\t\tError\n";

    do
    {
        x_old = x_new;
        fx = function(x_old);
        dx = derivative(x_old);
        x_new = x_old - (fx / dx);
        error = (x_new - x_old) / x_new;

        if (error < 0)
        {
            error = -error;
        }

        cout << fixed << setprecision(4) << c << "\t\t" << x_old << "\t\t" << fx << "\t\t" << dx << "\t\t" << x_new << "\t\t" << error << "\n";
        c = c + 1;
    } while (error > 0.05);

    cout << endl
         << "Final output: " << fixed << setprecision(2) << x_new;
    return 0;
}