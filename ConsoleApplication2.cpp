#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

double f(double x) {
    return pow(sin(x), 2) - x / 5 - 1;
}  
double df(double x) { 
    return 2*sin(x)*cos(x) - 1/5; 
} 
   
int main() {
    double EPS;
    vector <double> rez;
    double  a = -4, b = 0, h;
    cout << "Enter the step h: "; cin >> h;
    cout << "Enter the inaccuracy EPS: "; cin >> EPS;
    for (double x = a; x < b; x += h) {
        if (f(x) * f(x + h) < 0)
        {
            double a1 = x, b1=x+h;
            while (fabs(a1 - b1) > EPS) { 
                b1 = a1;
                a1 = b1 - f(b1) / df(b1); 
            }
            if (!rez.size())
            {
                rez.push_back(round(a1 / EPS) * EPS);
            }
            else {
                bool same = false;
                for (int i = 0; i < rez.size(); i++)
                {
                    if (rez[i] == round(a1 / EPS) * EPS)
                    {
                       same++; i = rez.size(); 
                    }

                }
                if (!same)
                {
                    rez.push_back(round(a1 / EPS) * EPS);
                }
            }
            
        }
    }
       for ( double x : rez)
       {
                cout <<"x = " << x<<'\t';
                cout << "f(x) = " << f(x) << '\n';
       }
}