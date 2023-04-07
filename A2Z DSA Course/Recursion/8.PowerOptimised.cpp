#include <iostream>
using namespace std;


int powerOptimised(int a, int b){

	if(b == 0){
		return 1;
	}

	int smallAns = powerOptimised(a , b/2);
	int myAns = smallAns * smallAns;
	if(b % 2 == 1){
		myAns *= a; 
	}

	return myAns;
}

int main(){

	int a = 2;
	int b = 5;
	int ans = powerOptimised(a,b);
	cout << ans << endl;
	return 0;
}

