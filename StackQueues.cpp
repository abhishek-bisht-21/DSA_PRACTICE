#include <bits/stdc++.h>
using namespace std;



// ___________________________________________________________ DUPLICATE BRACKETS________________________________________________

// The main idea to find duplicate bracket is keep pushing the expressions of a string in the stack, till the time we 
// get a closing bracket and now check if anything new is contained btw that closing bracket and openning bracket.
// Keep popping till we get a openning bracket, if it contained some elements btw closing and openning it means that
// it is a genuine bracket and we return false that it doesn't contain a duplicate bracket.


bool duplicateBrackets(string str){

	stack<char> st;
	bool ans  = false;
	for(int i=0;i<str.length();i++){
		char ch = str[i];
		if(ch == ')'){
			if(st.top() == '('){
				ans = true;
			}else{
				while(st.top() != '('){ // pop till we dont get a openning bracket
					st.pop();
				}
				st.pop(); // to remove the openning bracket as well
			}
		}else{
			st.push(ch);
		}
	}
}

// ______________________________________________________ BALANCED BRACKETS______________________________________________________________



int main(){

}