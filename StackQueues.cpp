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
			if(st.top() == '('){ // In btw the closing and openning there is no other element present
				ans = true; // hence it is a duplicate bracket as it is not containing anything useful in it.
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

   return ans;
}


// ______________________________________________________ BALANCED BRACKETS______________________________________________________________




void balancedBrackets(string s){
   stack<char>st;
  for(int i=0;i<s.length();i++)
  {
      char ch=s[i];
      if(ch=='('||ch=='{'||ch=='[')
      {
          st.push(ch);
      }else
      if(ch==')')
      {
          if(st.size()==0||st.top()!='(')
          {
              cout<<"false";return ;   
          }else
          {
              st.pop();
          }
      }else
      if(ch=='}')
      {
          if(st.size()==0||st.top()!='{')
          {
              cout<<"false";return ;
          }else
          {
              st.pop();
          }
      }else
      if(ch==']')
      {
          if(st.size()==0||st.top()!='[')
          {
              cout<<"false";return ;
          }else
          {
              st.pop();
          }
      }
  }

  // We are checking if our closing brackets are not less than openning brackets.
  if(st.size()==0)
  {
      cout<<"true";
  }else
  {
      cout<<"false";
  }
}

// _____________________________________________________________ NEXT GREATER ELEMENT IN RIGHT___________________________________________


vector<int> solve(vector<int>arr)
{

  stack<int> st;
  vector<int> ans(arr.size(),0);

  int n = arr.size();

  st.push(arr[n-1]); // Initially we are pushing the right most element in the stack
  ans[n-1] = -1;  // The last element doesnot have any element on its right therefore we are storing -1 for it.

  for(int i=n-2;i >= 0;i--){ // Accessing the array from right to left

       // Till the time current array element is greater than stack's top element and stack is not empty.
       // Keep popping the element out of the stack.	
      while(st.size()>0&&st.top()<=arr[i]) 
       {
           st.pop();
       }

       // 2 possible conditions can be if it has popped out all the elements of the stack it means that on its 
       // right no bigger element than it exist therefore put -1, indicating no bigger element is on its right.
       if(st.size()==0)
       {
           ans[i]=-1;
       }
       // st.size !=0 . Therefore element at the stack top is its next greater element on right.
       else{
           ans[i]=st.top();
       }

       // In the end always push the current element in the stack. To check its chances to become next greater element on right for someone.
       st.push(arr[i]);

  }  

  return ans;

}


// ____________________________________________________ STOCK SPAN_____________________________________________________________

/* Very similar to last question, its actually NEXT GREATER ON LEFT.

Two possible Conditions are :
1) Before Today higher price not availble --> Currindex + 1
2) Before Today higher price is available --> Currindex - higherData_index

We have to store index and not the value inside the stack. cause we have to store either the index + 1 or the diference btw indices


*/


vector<int> solve(vector<int>arr)
{
  //write your code here

  int n=arr.size();
  vector<int>span(n,0);
  stack<int>st;
  st.push(0);
  span[0]=1;
  for(int i=1;i<n;i++)
  {
      while(st.size()>0&&arr[st.top()]<=arr[i])
      {
          st.pop();
      }
      if(st.size()==0)
      {
          span[i]=i+1;
      }else
      {
          span[i]=i-st.top();
      }
      st.push(i);
  }
  return span;
}