#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b ,c;
    double discr;
    double x1, x2;

    cin >> a >> b >> c;

    if ( a == 0 && b == 0)
        return 0;
        
    else if ( a == 0 && b != 0 && c != 0)
    {
        x1 = (c * (-1)) / b;
        cout << x1;
    }

    else if (b == 0 && c == 0)
    {
        cout << 0;
        return 0;
    }

    else if (b == 0 && c != 0)
    {
        if ((c = (c * (-1)) / a) >= 0)
        {    
            x1 = sqrt(c);
            x2 = -x1;
            cout << x1 << " " << x2;
        }
        else 
            return 0;
    }
    
    else if ( b != 0 && c == 0)
    {
        x1 = 0;
        x2 = -b / a;
        cout << x1 << " " << x2;
    }
    
    else if ((discr = pow(b, 2) - (4 * a * c)) >= 0)
    {
        x1 = (-b + sqrt(discr)) / (2 * a);
        x2 = (-b - sqrt(discr)) / (2 * a);
        
        if (discr == 0)
        {
            cout << x1;
        }
        else
            cout << x1 << " " << x2;
    }

    return 0;
}