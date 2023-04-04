#include <iostream>
using namespace std;


int Power(int a, int b){

	// Base Case
	if(b == 0){
		return 1;
	}

	// Recursive Call
	int smallAns = Power(a,b-1);
	// Small Calculation
	int myAns = a * smallAns;
	return myAns;
}

int main(){
	int a = 2;
	int b = 5;
	int Pow = Power(a,b);
	cout << Pow << endl;
	return 0;
}