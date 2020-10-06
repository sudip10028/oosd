#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << "no of ordered partition: ";
	cout << pow(2, n-1);
    return 0;
}
