#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char arr[5];
    cin >> setw(5) >> arr;
    int i, max, n;
    n = 10;
    for(i=0;i<5;i++){
    	cout << arr[i] << endl;
    }
    return 0;
}