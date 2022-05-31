
string firstRepChar(string s)
{
    
    int h[26]={0};
    bool flag=false;
    string res;
    // traverse the string from left to right
    for(int i=0;i<s.length();i++)
    {
        // checking if current element is coming first time or not
        if(h[s[i]-'a']>=1)
        {
            res = s[i];
            flag=true;
            break;
        }
        else
            h[s[i]-'a']++;
    }
    // if there is no repeated character present.
    if(flag==false)
        res = "-1";
        
    return res;    
}