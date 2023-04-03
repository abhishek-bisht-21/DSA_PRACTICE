#include <iostream>
using namespace std;


int factorial(int n){

	// Base Case
	if(n == 0){
		return 1;
	}

	int smallAns = factorial(n-1);
	int myAns = n * smallAns;
	return myAns;
}

int main(){
	int n = 5;
	int fact = factorial(n);
	cout << fact << endl;
	return 0;
}