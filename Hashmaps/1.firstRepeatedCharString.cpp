
// Find first repeated character

string firstRepChar(string s)
{
   //code here.
   string ans="";
   unordered_map<char,int>m;
   int mini=INT_MAX;
   for(int i=0;i<s.length();i++){
       
       if(m[s[i]]!=0){
           
           if(mini>i){
               mini=i;
               ans=s[i];
           }
       }
       m[s[i]]++;
   }
   if(mini==INT_MAX){
       return "-1";
   }
   return ans;
}