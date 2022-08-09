#include <iostream>
using namespace std;


int sumDigits(int num){
	if(num % 10 == 0){
		return 0;
	}	
	int smallAns = num % 10;
	return smallAns + sumDigits(num/10);
}

int fact(int n){

	if(n == 0){
		return 1;
	}

	return n * fact(n-1);
}

int main(){

	int n = 5;
	int num = 3124;
	cout << "Factorial of " << n << " is " << fact(n) << endl;
	cout << "Sum of digits of " << num << " is " << sumDigits(num) << endl;


	return 0;
}