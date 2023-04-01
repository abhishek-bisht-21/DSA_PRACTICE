#include <iostream>
using namespace std;

int sum(int n){
	if(n==1){
		return 1;
	}

	int smallAns = sum(n-1);
	return n+smallAns;
}

int main()
{
	int n = 5;
	int ans = sum(n);
	cout << ans << endl;
	return 0;
}