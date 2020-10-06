#include <iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2;
    int i,j;
    cout << "give first input:";
    cin >> str1;
    cout << "give second input:";
    cin >> str2;

    int len1 = str1.size(); 
    int len2 = str2.size(); 

    string result = "";                  
    for(i=0; i < (len2 + len1); i++){       
        result.push_back('0');
    }
    
    int i_s1 = 0;                         
    int i_s2 = 0;  
      
    for (i = len1-1; i >= 0; i--) 
    { 
        int carry = 0; 
        int n1 = str1[i] - '0'; 
   
        i_s2 = 0;  
                 
        for (j=len2-1; j>=0; j--) 
        { 
            int n2 = str2[j] - '0'; 
            int sum = n1*n2 + (result[i_s1 + i_s2] - '0') + carry; 
            carry = sum/7;
            result[i_s1 + i_s2] = (sum % 7 + '0'); 
            i_s2++; 
        } 

            if (carry > 0){
                result[i_s1 + i_s2] = ((result[i_s1 + i_s2]-'0') + carry) + '0';
            } 

            i_s1++; 
        } 
  

        i = result.length() - 1; 
        while (i>=0 && (result[i]-'0') == 0){
            i--;
        } 
        result = result.substr(0, i+1);

        i = 0;
        j = result.length() - 1;
        char temp;
        for (i = 0; i < j; i++,j--)
        {
            temp = result[i];
            result[i] = result[j];
            result[j] = temp;
        }
        cout << "the result is: ";
        cout << result;
    return 0;
}