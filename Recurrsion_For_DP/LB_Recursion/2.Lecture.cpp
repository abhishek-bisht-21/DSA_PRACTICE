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


// Check Palindrome
bool checkPalindrome(string str, int s, int e){
	
	if(s == e){
		return true;
	}

	if(str[s] != str[e]){
		return false;
	}

	bool res = checkPalindrome(str,s+1,e-1);

	return res; 

}

// Calculating Power

int power(int a, int b){
	
	if(b == 0){
		return 1;
	}

	int small_ans = power(a,b-1);
	int myans = a * small_ans;
	return myans;
}



int powerOptimised(int a, int b){
	
	if(b == 0){
		return 1;
	}

	int small_ans = powerOptimised(a,b/2);
	int myans = small_ans * small_ans;
	if(b % 2 != 0){
		myans = a *  myans;
	}
	return myans;
}


// Bubble Sort

void BubbleSort(int arr[], int n){

	int i,j;

	for(i=0;i<n;i++){
		bool isSwapped = false;
		for(j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				isSwapped = true;
			}
		}

		// Array is Already Sorted
		if(isSwapped == false){
			break;
		}
	}
}


// Bubble Sort Using Recursion

void BubbleSortRecursive(int arr[], int n){

	// Base Case
	if(n == 0 or n == 1){
		return;
	}

	// Solve for the Largest Element
	for(int i = 0; i < n-1; i++)
	{
		if(arr[i] > arr[i+1]){
			swap(arr[i], arr[i+1]);
		}
	}

	BubbleSortRecursive(arr,n-1);
	

}

int main(){

	// string str = "DOG";
	// int len = str.length();
	// cout << "Before Reversing the string: " << str << endl;
	// reverseString(str,0,len-1);
	// cout << "After Reversing the string: " << str << endl;

	// string s = "naman";
	// cout << "Check Palindome : "<< boolalpha << checkPalindrome(s,0,s.length()-1) << endl;

	// int a = 2;
	// int b = 5;
	// cout << "Calculate " << a << "^"<< b << " = " << power(a,b) << endl;
	// cout << "Calculate " << a << "^"<< b << " = " << powerOptimised(a,b) << endl;

	int arr[] = {10,1,7,6,14,9};
	int n = sizeof(arr)/sizeof(int);

	cout << "Array Before Bubble Sort: " << endl;
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	BubbleSortRecursive(arr,n);


	cout << "Array Before Bubble Sort: " << endl;
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;





	return 1;

}