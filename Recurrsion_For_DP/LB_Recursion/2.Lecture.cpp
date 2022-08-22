#include <bits/stdc++.h>
using namespace std;


// Reverse String
void reverseString(string &str, int s, int e){

	if(s > e){
		return;
	}

	swap(str[s],str[e]);

	reverseString(str,s+1,e-1);
}


// Check Palindrome
bool checkPalindrome(string str, int s, int e){
	
	if(s == e){
		return true;
	}

	if(str[s] != str[e]){
		return false;
	}

	bool res = checkPalindrome(str,s+1,e-1);

	return res; 

}


int main(){

	string str = "DOG";
	int len = str.length();
	cout << "Before Reversing the string: " << str << endl;
	reverseString(str,0,len-1);
	cout << "After Reversing the string: " << str << endl;

	string s = "naman";
	cout << "Check Palindome : "<< boolalpha << checkPalindrome(s,0,s.length()-1) << endl;






	return 1;

}