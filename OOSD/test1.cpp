#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {1,3,2,72,72,23,14,51,19,88};
    int i, j, max, n, temp;
    n = 10;
    max = -100;
    for(i=0;i<n-1;i++){
    	for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    
    return 0;
}