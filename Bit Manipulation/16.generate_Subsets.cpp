
#include <iostream>
using namespace std;

//  Generate All Subsets Using Bitmasking
void filterChars(char *a, int no){
	// a-> "abc" no = 5 --> Output: ac

	int i=0;
	while(no){

		(no&1)?cout<<a[i]:cout<<"";
		i++;
		no = no>>1;
	}

	cout<<endl;
}

void generateSubsets(char *a){
	//  Generate a range of numbers btw 0 to 2^n-1
	int n = strlen(a);
	int range = (1<<n) - 1;

	for(int i=0;i<=range;i++){
		filterChars(a,i);
	}
}