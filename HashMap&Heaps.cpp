#include <bits/stdc++.h>
using namespace std;



// ________________________________________________ HIGHEST FREQUENCY CHARACTER___________________________________________________________



#include <bits/stdc++.h>
using namespace std;
int main() {

  string str;
  cin >> str;

  unordered_map<char, int> fmap;
  for (int i = 0; i < str.size(); i++) {
    fmap[str[i]]++;
  }

  int maxcount = 0;
  char ch;

  for (pair<char, int>  m : fmap) {
    if (m.second > maxcount)
    {
      maxcount = m.second;
      ch = m.first;
    }
  }
  cout << ch;
}


// ____________________________________________________Get Common Elements - 1___________________________________________________

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n1,n2;
  cin >> n1;
  int arr1[n1];
  
  for (int i = 0; i < n1; i++) {
    cin>>arr1[i];
    mp[arr1[i]]++;
  }
  cin >> n2;
  int arr2[n2];
  for (int i = 0; i < n2; i++) {
    cin >> arr2[i];
    
    // write your code here
    if(mp.find(arr2[i]) != mp.end()){
      cout << arr[i];
    }
    mp.erase(arr2[i]);
    
    }
  }
}


// ________________________________________________________Get Common Elements - 2_________________________________________________

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	//write your code here
	int n,m;
	cin >> n;
	int arr1[n];
	unordered_map<int,int> mp
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp[arr1[i]]++;
	}

	cin >> m;
	int arr2[m];
	for(int i=0;i<m;i++){
		cin >> arr[i];

		if(mp[arr2[i]] != 0 and mp.find(arr2[i]) != mp.end()){
			cout <<  arr2[i] << endl;
			mp[arr2[i]]--;
		}
		
	}

	
}

// ______________________________________________ LONGEST CONSECUTIVE SEQUENCE__________________________________________________________________


/*
STEP 1 : Create a Hashmap of int and bool.
STEP 2 : Run a loop over the vector and for each ele set itself as starting point of its
         sequence. Mark it as true.
STEP 3: Run another loop and check for every ele if any num smaller than that exist in 
        the map, if yes then set that as false. As it cannot be the starting point anymore.

STEP 4 : Now for every True value, calculate its consecutive length and update the max
         consecutive length.  
*/


void longestConsecutive(vector<int> &num) {
        
    unordered_map<int,bool>mp;
    for (int i=0;i<num.size();i++){
        mp[num[i]]=true;
    }
    for (int i=0;i<num.size();i++){
        if(mp.find(num[i]-1)!=mp.end()){
            mp[num[i]]=false;
        }
    }
        
      int msp = 0;
      int ml = 0;
      for (int val : num) {
         if(mp[val] ==true){
            int tsp = val;
            int tl = 1;

            while(mp.find(tsp + tl)!=mp.end()){
               tl++;
            }

            if(tl > ml){
               ml = tl;
               msp = tsp;
            }
         }
      }

      for(int i = 0; i < ml; i++){
         cout<<msp + i<<endl;
      }
        
    }



    //____________________________________________________________K Largest Elements______________________________________________


    // priority_queue<int, vector<int>,greater<int>> pqm; //min heap
   // priority_queue<int, vector<int>> pq;  //max heap


   class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int,vector<int>, greater<int>> pqm;
        vector<int> ans;
        
         for(int i=0;i<k;i++){
         pqm.push(arr[i]);
     }

     for(int i=k;i<n;i++){

         if(pqm.top() < arr[i]){
             pqm.pop();
             pqm.push(arr[i]);
         }

     }

     for(int i=0;i<k;i++){
         ans.push_back(pqm.top()) ;
         pqm.pop();
     }
     
    reverse(ans.begin(),ans.end());
    
    return ans;
    }
};


// _______________________________________________________________Sort K-sorted Array_________________________________________________

// SC -> O(K)
// TC -> (nlogk)

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int k;
	cin >> k;

	// We have created a funnel(Priority queue) like thing of k size.
	// We each time move 1 move ahead and remove the top ele as it is smallest and add the next element in the priorityqueue
	priority_queue<int,vector<int>,greater<int>> p;
	for(int i=0;i<=k;i++){
		p.push(arr[i]);
	}
	for(int i=k+1;i<n;i++){
		cout << p.top() << endl;
		p.pop();
		p.push(arr[i]);
	}
	while(p.size()>0){
		cout << p.top()<< endl;
		p.pop();
	}

}




//______________________________________________ CHECK IF AN ARRAY IS K SORTED OR NOT GFG____________________________________________

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k)
    {
        //code here.
        vector<int> v(arr,arr+n);
        sort(v.begin(),v.end());
        unordered_map<int,int> m; // value and index
        
        for(int i=0;i<n;i++){
            m[v[i]] = i; // value vs Sortedindex (sorted order)
        }
        
        for(int i=0;i<n;i++){
		// The diff the between the Sorted Index and Original Index should be less than K in order to be called as K sorted
            if(abs(m[arr[i]] - i) > k){ 
                return "No";
            }
        }
        
        
        return "Yes";
    }
};


// ________________________________________________________Median Priority Queue____________________________________________________

class MedianPriorityQueue {
    public:

    // Smaller elements will be on this side.(But queue is maxHeap). So we know largest amongst smaller ele.	
    priority_queue <int> left; 
    // Larger Elements will be on this side. (But queue is minHeap). So that we know smaller amongst the largest.
    priority_queue <int, vector<int>, greater<int>> right; 

    // This is because we can easily make swaps, whenever required.
    
    void push(int val) {
        if(size() == 0) {
            left.push(val);
        }
        else if(left.size() > 0 && val <= left.top()) {
            left.push(val);
        }
        else {
            right.push(val);
        }
        
        // balance. The gap between left and right pq shouldn't go beyond 2. If it does then balance it out.
        if(left.size() + 2 == right.size()) { // left is small
            left.push(right.top());
            right.pop();
        }
        else if(right.size() + 2 == left.size()) { // right is small
            right.push(left.top());
            left.pop();
        }
    }
    
    int pop() {
        if(size() == 0) {
            cout<<"Underflow"<<endl;
            return -1;
        }
        
        if(left.size() >= right.size()) {
            int top = left.top();
            left.pop();
            return top;
        }
        else {
            int top = right.top();
            right.pop();
            return top;
        }
    }
    
    // queue whose size will be more at any given point in time that queue's top will contain "MEDIAN ELEMENT"
    int top() {
        if(size() == 0) {
            cout<<"Underflow"<<endl;
            return -1;
        }
        
        if(left.size() >= right.size()) {
            return left.top();
        }
        else {
            return right.top();
        }
    }
    
    int size() {
        return left.size() + right.size();
    }
};


// ______________________________________________________Merge K Sorted Lists______________________________________________

// TC : O(nlogk)
// SC : O(k)

vector<int>mergeKSortedLists(vector<vector<int>>&lists) {
    
    vector<int> rv;
 
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
 
    for (int i = 0; i < lists.size(); i++)
        pq.push({ lists[i][0], { i, 0 } });
 
    while (pq.empty() == false) {
        ppi curr = pq.top();
        pq.pop();
 
        int arrayNumber = curr.second.first;
        int idx = curr.second.second;
 
        rv.push_back(curr.first);
 
        if (idx + 1 < lists[arrayNumber].size())
            pq.push({ lists[arrayNumber][idx + 1], { arrayNumber, idx + 1 } });
    }
 
    return rv;
}