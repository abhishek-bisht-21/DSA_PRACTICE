// Array Subset of another array

string isSubset(int a1[], int a2[], int n, int m) {
    
   unordered_map<int,int> um;
    for(int i=0;i<n;i++)um[a1[i]]++;
    for(int i=0;i<m;i++)
    {
        if(um[a2[i]]>0)um[a2[i]]--;
        else return "No";
    }
    return "Yes"; 
}