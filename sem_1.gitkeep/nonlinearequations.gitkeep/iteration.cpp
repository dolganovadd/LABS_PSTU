/*
Вариант 25 
f(x)=x-2+sin(1/x)
f'(x)=1+cos(1/x)*(-1/sqrt(x))
f''(x)=(2*cos(1/x)-sin(1/x))/pow(x,4)
[1,2]
ф(x) = x + λ(x-2+sin(1/x))
r = max(|f'(a)|, |f'(b)|)
r=max(|1+cos(1/a)*(-1/sqrt(a))|, |1+cos(1/b)*(-1/sqrt(b))|)
r=max(1,54, 0,725)=1,54
f'(x) > 0 => -1/r < λ < 0
берем любое удобное число в диапазоне
 λ = -1/20 = -0.05
*/
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    float x, xPrev;
    double lambda = -0.05; 
    x = 2; 
    xPrev = 0;  
    double eps = 0.000001;

    while (abs(x - xPrev) > eps)
    {
        xPrev = x;
        x = lambda * (x - 2 + sin(1 / x)) + xPrev;
    }
    cout << "x= " << x << endl;
    return 0;
}