#include <iostream>
using namespace std;

void printDecreasing(int n){

	// Base Case
	if(n == 0){
		return;
	}

	// Small Work (Printing for Nth Element)
	cout << n << endl;
	// Faith (Expecting it to print All the N-1 Element)
	printDecreasing(n-1);
}

int main(){

	int n = 6;
	printDecreasing(n);
	return 0;
}