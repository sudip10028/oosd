#include <iostream>

using namespace std;

double difference(double n,double mid) 
{ 
    if (n > (mid*mid*mid)) 
        return (n-(mid*mid*mid)); 
    else
        return ((mid*mid*mid) - n); 
} 

double cubicRoot(double n) 
{ 
    double start = 0, end = n; 
    double e = 0.0000001; 
  
    while (true) 
    { 
        double mid = (start + end)/2; 
        double error = difference(n, mid); 
        if (error <= e) 
            return mid; 
        if ((mid*mid*mid) > n) 
            end = mid; 
        else
            start = mid; 
    } 
} 

int main() 
{ 
    double n; 
    cin >> n;
    cout << cubicRoot(n);
    return 0; 
} 