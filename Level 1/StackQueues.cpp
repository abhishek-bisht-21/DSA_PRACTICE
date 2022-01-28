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

      if(st.size()==0) //Before Today Higher price stock didn't exist
      {
          span[i]=i+1;
      }else    // Before Today higher price stock was present. Therefore we wanted to calculate its span.
      {
          span[i]=i-st.top();
      }
      st.push(i);
  }
  return span;
}


//_______________________________________________________Largest Area Histogram________________________________________________________

/*

Next Smaller Element on right uski Right boundary hai. And Next smaller element on left uski left boundary hai.
The difference btw right boundary and left boundary is going to give us the width of our rectangale.

Area = Width * Height.

Right boundary -> Next Smaller Element on Right.  (Access the Array from Right to Left)
Left Boundary -> Next Smaller element on left.  (Access the array from Left to Right)

In the Right And Left Boundary we are going to store the index of the next smaller element on right/left. Then only we will
get to know the width.

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> rightBoundary(n,0); // nse on right
        stack<int> st1;
        st1.push(n-1);
        rightBoundary[n-1] = n;
        for(int i=n-2;i>=0;i--){
            
            while(st1.size() > 0 and heights[st1.top()] >= heights[i]){
                st1.pop();
            }
            if(st1.size() == 0){
                rightBoundary[i] = n;
            } else{
                rightBoundary[i] = st1.top();
            }
            
            st1.push(i);
        }
        
        
        
        vector<int> leftBoundary(n,0); // nse on left
        stack<int> st2;
        st2.push(0);
        leftBoundary[0] = -1;
        
        for(int i=1;i<n;i++){
            while(st2.size() > 0 and heights[st2.top()] >= heights[i]){
                st2.pop();
            }
            if(st2.size() == 0){
                leftBoundary[i] = -1;
            } else{
                leftBoundary[i] = st2.top();
            }
            
            st2.push(i);
        }
        
        
        int maxArea = 0;
        for(int i=0;i<n;i++){
            
            int width = rightBoundary[i] - leftBoundary[i]  - 1;
            int area = width * heights[i];
            
            if(maxArea < area){
                maxArea = area;
            }
        }
        
        return maxArea;
    }
};


// __________________________________________________________Infix Evaluation_______________________________________________________

/*

1) Push Operand into the stack.
2) Push Openning Bracket in the stack.
3) Closing bracket is encounter pop till we get openning bracket.
4) When an operator comes, then operators having equal or greater priority would be popped from the stack.


*/


#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int pre(char ch){
    if(ch == '*'){
        return 2;
    }else if(ch == '/'){
        return 2;
    }else if(ch == '+'){
        return 1;
    }else{
        return 1;
    }
}

int operation(int v1, int v2, char ch){
    if(ch == '*'){
        return v1 * v2;
    }else if(ch == '/'){
        return v1 / v2;
    }else if(ch == '+'){
        return v1 + v2;
    }else{
        return v1 - v2;
    }
}

int main(){
    string str;
    getline(cin, str);
    stack<int> is;
    stack<char> cs;
    
    for(int i = 0; i < str.length(); i++){
        char ch = str.at(i);
        
        if(isdigit(ch)){
            is.push(ch - '0');
        }else if(ch == '('){
            cs.push(ch);
        }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(cs.size() > 0 && cs.top() != '(' && pre(ch) <= pre(cs.top())){
                int v2 = is.top();
                is.pop();
                int v1 = is.top();
                is.pop();
                char op = cs.top();
                cs.pop();
                
                int ans = operation(v1, v2, op);
                is.push(ans);
            }
            cs.push(ch);
        }else if(ch == ')'){
            while(cs.size() > 0 && cs.top() != '('){
                int v2 = is.top();
                is.pop();
                int v1 = is.top();
                is.pop();
                char op = cs.top();
                cs.pop();
                
                int ans = operation(v1, v2, op);
                is.push(ans);
            }
            if(cs.size() > 0){
                cs.pop();
            }
        }
    }
    while(cs.size() > 0){
        int v2 = is.top();
        is.pop();
        int v1 = is.top();
        is.pop();
        char op = cs.top();
        cs.pop();
        
        int ans = operation(v1, v2, op);
        is.push(ans);
    }
    
    int ans = is.top();
    is.pop();
    cout << ans;
    
    return 0;
}


// -______________________________________________________________56. Merge Intervals____________________________________________


class Solution {
public:
    
   static bool compare(const vector<int> v1 , const vector<int> v2){
    return v1[0]<v2[0];
}
    
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort( arr.begin(), arr.end() ,compare); // sorting on basis of start index
   
    stack<vector<int>> st;
   
    for(int i = 0; i < arr.size() ; i++){


        vector<int> meeting = arr[i];
        int sp = meeting[0];
        int ep = meeting[1];
       
        if(st.size() == 0){
            st.push(meeting);
        }
        else{
	    
            vector<int> lastmeeting = st.top();
            st.pop();
	    // Before pushing the next interval in the stack just check if the upcoming meeting intervals
	    // start time is less than last meetings end time then Merge the two intervals.
	    // Who so evers end time will be more will be taken in the mergedInterval
            if(lastmeeting[1] >= sp ){
                vector<int> mergedmeeting{
                  lastmeeting[0] , max(lastmeeting[1] ,ep)
                };
               
                st.push(mergedmeeting);
            }
            else{
		// If the upcoming interval cannot be merged then push the lastmeeting and newmeeting back into the stack.
                st.push(lastmeeting);
                st.push(meeting);
            }
        }
    }
        
        vector<vector<int>> ans;
        
        while(st.size() > 0){
            ans.push_back(st.top()); st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// ______________________________________________________155. Min Stack____________________________________________________

/*
Take help of two stacks. One is Min stack and other is Regular stack.
first push the element in both min and reg stack.
From the 2nd element onwards, first check if the top of min stack is greater than current element then 
only push inside the minstack, otherwise dont. Whereas in regular stack keep pushing every element.

If we want Top Return the top of regular stack and if we want min return the top of minStack

*/


class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};



// _______________________________________The Celebrity Problem___________________________________________________________

/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a 
celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means 
ith person knows jth person. Here M[i][i] will always be 0.Note: Follow 0 based indexing.

*/


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        // code here 
        
          // if a celebrity is there print it''s index (not position), if there is not then print "none"
        stack<int> st;
        for(int i = 0; i < n; i++){
           st.push(i);
        }

        while(st.size() > 1){
           // Each time we are popping out two elements and checking who can be potential celebrity.		
           int i = st.top(); st.pop();
           int j = st.top(); st.pop();

           if(arr[i][j] == 1){ // It means that i knows j. Therefore i cannot be a celebrity. j can be a potential celebrity
               st.push(j);
           } else {   // arr[i][j] != 1. Therefore i is a celebrity(potential)
            st.push(i);
           }
        }

        int pot = st.top(); st.pop();
        bool flag = true;
	// Now we are checking if anyone doesnot know our potential celebrity or our celebrity knows someone
	// In both those cases potential is not a celebrity
        for(int i = 0; i < n; i++){
           if(i != pot){
              if(arr[i][pot] == 0 || arr[pot][i] == 1){
                 flag = false;
                 break;
              }
           }
        }

        if(flag){
          return pot;
        } else {
           return -1;
        }
}

};


// ______________________________________________________Stack To Queue Adapter - Add Efficient______________________________



/*
	Add should be O(1)
*/


class StackToQueueAdapter{
    public:
    stack<int> mainS;
    stack<int> helperS;
    
    int size(){
        return mainS.size();
    }
    
    void add(int data){
        mainS.push(data);
    }

    int peek(){
        if (mainS.size() == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        while(mainS.size()>1){
            int t = mainS.top();
            mainS.pop();
            helperS.push(t);
        }
        int rem = mainS.top();
        mainS.pop();
        helperS.push(rem);
        while(helperS.size()>0){
            int t = helperS.top();
            helperS.pop();
            mainS.push(t);
        }
        return rem;
    }

    int remove(){
        if (mainS.size() == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }

	// Storing all the elements above front element in Helper queue.
        while(mainS.size()>1){
            int t = mainS.top();
            mainS.pop();
            helperS.push(t);
        }
	// Found the Element to removed cause in queue element is removed in FIFO fashion(from the front)
        int rem = mainS.top();
        mainS.pop();
	
	// copying back data into main stack
        while(helperS.size()>0){
            int t = helperS.top();
            helperS.pop();
            mainS.push(t);
        }
        return rem;
    }
};

// ___________________________________________Stack To Queue Adapter - Remove Efficient________________________________



class StackToQueueAdapter {
public:
  stack <int> mainS;
  stack <int> helperS;

  int size() {
    return mainS.size();
  }

  void add(int val) {

    // To Maintain FIFO. We wanted the oldest entered element to stay at the top therefore first copying whole data into helper stack	  
    while (mainS.size() > 0) {
      helperS.push(mainS.top());
      mainS.pop();
    }

    // New element placed at the bottom of the Mainstack	
    mainS.push(val);

    // copying back all the data back into the MainStack	
    while (helperS.size() > 0) {
      mainS.push(helperS.top());
      helperS.pop();

    }
  }

  int Remove() {
    if (mainS.size() == 0) {
      cout << "Queue underflow" << endl;
      return -1;
    }
    int tr = mainS.top();

    mainS.pop();

    return tr;
  }

  int peek() {
    if (mainS.size() == 0) {
      cout << "Queue underflow" << endl;
      return -1;
    }
    return mainS.top();
  }
};


// ____________________________________________Queue To Stack Adapter - Pop Efficient________________________________________________

class QueueToStackAdapter{
    public:
    queue<int> mainQ;
    queue<int> helperQ;
    
    int size(){
        return mainQ.size();
    }
    
    void push(int data){
        if(mainQ.size()==0){
            mainQ.push(data);
            return;
        }
        while(mainQ.size()>0){
            int f = mainQ.front();
            mainQ.pop();
            helperQ.push(f);
        }
        mainQ.push(data);
        while(helperQ.size()>0){
            int f = helperQ.front();
            helperQ.pop();
            mainQ.push(f);
        }
    }

    int top(){
        int rem = mainQ.front();
        return rem;
    }

    int pop(){
        int rem = mainQ.front();
        mainQ.pop();
        return rem;
    }
};


// ______________________________________________Queue To Stack Adapter - Push Efficient_________________________________


class QueueToStackAdapter{
    public:
    queue<int> mainQ;
    queue<int> helperQ;
    
    int size(){
        return mainQ.size();
    }
    
    void push(int data){
        mainQ.push(data);
    }

    int top(){
        if (mainQ.size() == 0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        while(mainQ.size()>1){
            int f = mainQ.front();
            mainQ.pop();
            helperQ.push(f);
        }
        int rem = mainQ.front();
        mainQ.pop();
        helperQ.push(rem);
        while(helperQ.size()>0){
            int f = helperQ.front();
            helperQ.pop();
            mainQ.push(f);
        }
        return rem;
    }

    int pop(){
        if (mainQ.size() == 0){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        while(mainQ.size()>1){
            int f = mainQ.front();
            mainQ.pop();
            helperQ.push(f);
        }
        int rem = mainQ.front();
        mainQ.pop();
        while(helperQ.size()>0){
            int f = helperQ.front();
            helperQ.pop();
            mainQ.push(f);
        }
        return rem;
    }
};

// ________________________________________Number following a pattern________________________________________________

