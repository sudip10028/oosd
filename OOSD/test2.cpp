#include <iostream>

using namespace std;

int** addMatrix(int** a, int** b, int n){
	int i, j;
    int** c;
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
            c[i][j] = a[i][j]+b[i][j];
        }
    }
    return c;
}

int main()
{
    int** a = {{1,3,2},{12,172,23},{14,51,19}};
    int** b = {{1,3,2},{12,172,23},{14,51,19}};
    int c[3][3];
    int i, max, n, j;
    n = 3;
    c = addMatrix(a, b, n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<c[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}