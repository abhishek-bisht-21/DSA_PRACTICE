// 535. Encode and Decode TinyURL

class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string, string> m;
    string encode(string longUrl) {
        string rs = "";
        rs += ((char)((long)rand()*100));
        
        while(m.find(rs) != m.end()){
            rs += ((char)((long)rand()*100));
        }
        
        m[rs] = longUrl;
        
        return rs;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};
