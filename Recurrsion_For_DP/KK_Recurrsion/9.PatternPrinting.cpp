#include <bits/stdc++.h>
using namespace std;


void patternPrinting(int n){
	if(n == 0){
		return;
	}

	patternPrinting(n-1); // TRUST the function
	for(int i=1;i<=n;i++){
		cout << i << " ";
	}

	cout <<"\n";
}


int main(){
	patternPrinting(5);
	return 1;
}