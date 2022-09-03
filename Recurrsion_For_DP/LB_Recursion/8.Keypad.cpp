// Possible Words From Phone Digits

class Solution
{
    public:
    
    
    void solve(string digit,int idx,string mapping[], string output, vector<string> &ans){
        
        // Base Case
        if(idx >= digit.length()){
            ans.push_back(output);
            return;
        }
        
        
        int num = digit[idx] - '0';
        string value = mapping[num];
        
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digit,idx+1,mapping,output,ans);
            output.pop_back();
        }
        
        
        
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        
        vector<string> ans;
        string output;
        int idx = 0;
        string digits = "";
        for(int i=0;i<N;i++){
            
            string s = to_string(a[i]);
            digits += s;
        }
        
      
        string mapping[10] = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,idx,mapping,output,ans);
        return ans;
       
    }
};