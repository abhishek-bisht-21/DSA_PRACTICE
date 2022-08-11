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


void patternPrinting2(int n){
	if(n == 0){
		return;
	}

	for(int i=1;i<=n;i++){
		cout << i << " ";
	}

	cout <<"\n";

	patternPrinting2(n-1); // TRUST the function

	for(int i=1;i<=n;i++){
		cout << i << " ";
	}

	cout <<"\n";
}



int main(){
	patternPrinting2(4);
	return 1;
}