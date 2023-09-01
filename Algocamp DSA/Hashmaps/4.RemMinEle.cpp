
// Remove minimum number of elements

class Solution{
  public:
    int minRemove(int a[], int b[], int n, int m) {
        int elementsRemoved = 0;
        
        unordered_map<int, int> amap;
        for(int i=0;i<n;i++){
            amap[a[i]]++;
        }
        
        unordered_map<int, int> bmap;
        for(int i=0;i<m;i++){
            bmap[b[i]]++;
        }
        

        for(auto x: amap){
            if(bmap.find(x.first) != bmap.end()){
                int freq_to_rem = x.second > bmap[x.first] ? bmap[x.first] : x.second;
                elementsRemoved+=freq_to_rem;
            }
        }
        
        return elementsRemoved;
    }
};