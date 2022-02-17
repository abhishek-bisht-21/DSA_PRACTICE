class Solution
{
    public:
    vector<string> graycode(int n)
    {
        //code here
        if(n == 1){
            vector<string> bres;
            bres.push_back("0");
            bres.push_back("1");
            return bres;
        
        }
        
        vector<string> rres = graycode(n-1);
        vector<string> mres;
        
        for(int i=0;i<rres.size();i++){
            string r = rres.at(i);
            mres.push_back("0" + r);
        }
        
        for(int i=rres.size()-1;i>=0;i--){
            string r = rres.at(i);
            mres.push_back("1" + r);
        }
        
        return mres;
    }
};