#include <bits/stdc++.h>
using namespace std;




/**
 * Recursive function to find reverse of any number
 */
int Reverse(int num)
{
    /* Find number of digits in num */
    int digit = (int)log10(num);
    
    /* Recursion base condition */
    if(num == 0)
        return 0;

    return ((num%10 * pow(10, digit)) + Reverse(num/10));
}


bool isPalindrome(int num)
{
    /* 
     * Check if the given number is equal to 
     * its reverse.
     */
    if(num == Reverse(num))
    {
        return 1;
    }
    
    return 0;
}

bool isPalindromeString(string str, int s, int e){
	if(s <= e){
		return true;
	}else{
		return ((str[s] == str[e]) && isPalindromeString(str,s+1,e-1));
	}
}


int main(){

	int n = 1221;
	string str = "malyalam";
	int e = 7;
	int s = 0;
	//std::cout << "Is  " << n << " a palindrome " << boolalpha << isPalindrome(n);
	std::cout << "Is  " << str << " a palindrome " << boolalpha << isPalindromeString(str,s,e);

	return 0;
}