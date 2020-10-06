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
	//method to do multiplication of big integers
	void number_multiply(Number num1, Number num2){
		int i, j;
		string str1 = num1.show_num();
		string str2 = num2.show_num();

    	int len1 = str1.size(); 
    	int len2 = str2.size(); 

    	string result = "";						//result will store the final result
    	for(i=0; i < (len2 + len1); i++){		//and its maximum length is len1 + len2
    		result.push_back('0');
    	}
    
    	int i_s1 = 0;  							//these help us to understand the position of result
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
            	carry = sum/10;
            	result[i_s1 + i_s2] = (sum % 10 + '0'); 
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

    	str = result;

	}

};

int main(){
	Number num1, num2, num3;
	num1.get_num("46464434434343436");
	num2.get_num("22216678989");
	num3.number_multiply(num1, num2);

	cout << "the multiplication is " << num3.show_num() << endl;
}