#include <iostream>
#include<string>

using namespace std;

class Number{
private:
	string str;

public:
	//method to set the value of str
	void get_num(string s){
		str = s;
	}
	//method to take input the str from user
	void input_num(){
		cout << "enter the number" << endl;
		cin >> str;
	}
	//mathod to read the str of the object
	string show_num(){
		return str;
	}
	//operator overloading to sum big integers
	Number operator + (Number b){
		int i, carry, j;
		string result = "";                    //final result is stored in result

		string str1 = str;
		string str2 = b.show_num();

		if(str1.length()>str2.length()){      //making sure str1 is smaller than str2
			swap(str1, str2);
		}

		//reversing the strings
		i = 0;
    	j = str1.length() - 1;
    	char temp;
    	for (i = 0; i < j; i++,j--)
    	{
        	temp = str1[i];
        	str1[i] = str1[j];
        	str1[j] = temp;
    	}   
    	i = 0;
    	j = str2.length() - 1;
    	for (i = 0; i < j; i++,j--)
    	{
        	temp = str2[i];
        	str2[i] = str2[j];
        	str2[j] = temp;
    	}

    	int l1 = str1.length();
    	int l2 = str2.length();

    	//here we are doing the basic method of sum
    	carry = 0;
    	for(i = 0; i < l1 ; i++){
        	int sum = ((str1[i] - '0') +(str2[i] - '0') + carry); 
        	result.push_back(sum%10 + '0'); 
        	carry = sum/10; 
    	}

    	for (i=l1; i < l2 ; i++) 
    	{ 
        	int sum = ((str2[i]-'0')+carry); 
        	result.push_back(sum%10 + '0'); 
        	carry = sum/10; 
    	} 
  
    	if (carry > 0){
    		result.push_back(carry+'0'); 
    	} 
 
    	i = 0;
    	j = result.length() - 1;
    	for (i = 0; i < j; i++,j--)
    	{
        	temp = result[i];
        	result[i] = result[j];
        	result[j] = temp;
    	}

    	Number num;
    	num.get_num(result);
		return num;

	}

};

int main(){
	Number num1, num2, num3;
	num1.get_num("4444444444444444444444444444444444444");
	num2.get_num("11111111111111111111111111111111111111111111");
	num3 = num1 + num2;				//operator overloading called

	cout << "the addition is " << num3.show_num() << endl;
}