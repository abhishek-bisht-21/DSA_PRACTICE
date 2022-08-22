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

// Calculating Power

int power(int a, int b){
	
	if(b == 0){
		return 1;
	}

	int small_ans = power(a,b-1);
	int myans = a * small_ans;
	return myans;
}



int powerOptimised(int a, int b){
	
	if(b == 0){
		return 1;
	}

	int small_ans = powerOptimised(a,b/2);
	int myans = small_ans * small_ans;
	if(b % 2 != 0){
		myans = a *  myans;
	}
	return myans;
}

int main(){

	// string str = "DOG";
	// int len = str.length();
	// cout << "Before Reversing the string: " << str << endl;
	// reverseString(str,0,len-1);
	// cout << "After Reversing the string: " << str << endl;

	// string s = "naman";
	// cout << "Check Palindome : "<< boolalpha << checkPalindrome(s,0,s.length()-1) << endl;

	int a = 2;
	int b = 5;
	cout << "Calculate " << a << "^"<< b << " = " << power(a,b) << endl;
	cout << "Calculate " << a << "^"<< b << " = " << powerOptimised(a,b) << endl;







	return 1;

}