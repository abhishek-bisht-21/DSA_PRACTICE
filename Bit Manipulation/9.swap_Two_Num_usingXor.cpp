class Solution{   
public:
    pair<int, int> get(int a, int b){
        //complete the function here
        
         a = a^b;
         b = a^b;
         a = a^b;
        
        pair<int,int> p = make_pair(a,b);
        return p;
        
    }
};