#include <bits/stdc++.h>
using namespace std;


void countZeros(int n, int &c){
	if(n == 0){
		return;
	
	}

	if(n%10 == 0){
		c++;
	}

	countZeros(n/10,c);
}

int main(){

	int n = 1000;
	int c = 0;
	countZeros(n,c);
	cout << "Count Number of Zeros in: " << n << " are " << c;
	return 0;
}