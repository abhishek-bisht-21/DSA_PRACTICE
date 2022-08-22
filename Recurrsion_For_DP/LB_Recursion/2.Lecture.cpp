#include <bits/stdc++.h>
using namespace std;


// Reverse String
void reverseString(string &str, int s, int e){

	if(s > e){
		return;
	}

	swap(str[s],str[e]);

	reverseString(str,s+1,e-1);
}


int main(){

	string str = "DOG";
	int len = str.length();
	cout << "Before Reversing the string: " << str << endl;
	reverseString(str,0,len-1);
	cout << "After Reversing the string: " << str << endl;






	return 1;

}