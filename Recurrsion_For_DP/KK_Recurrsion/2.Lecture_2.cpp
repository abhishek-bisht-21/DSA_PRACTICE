#include <iostream>
using namespace std;

// Infinite Recurrsion -> Stackoverflow
void printn(int n){
	if(n == 0){
		return;
	}

	cout << n << endl;
	printn(n--);
}

// Finite Recursion
void printn(int n){
	if(n == 0){
		return;
	}

	cout << n << endl;
	printn(--n);
}



int main(){
	return 0;
}