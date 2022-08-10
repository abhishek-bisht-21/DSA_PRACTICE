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



int main(){

	int n = 1221;
	std::cout << "Is  " << n << " a palindrome " << boolalpha << isPalindrome(n);
	return 0;
}