
// Remove minimum number of elements

class Solution{
  public:
    int minRemove(int a[], int b[], int n, int m) {
        int elementsRemoved = 0;
        
        unordered_map<int, int> amap; // Element, Freq
        for(int i=0;i<n;i++){
            amap[a[i]]++;
        }
        
        unordered_map<int, int> bmap; // Element, Freq
        for(int i=0;i<m;i++){
            bmap[b[i]]++;
        }
        

        for(auto x: amap){
		// Finding Common Elements in Array A and B
            if(bmap.find(x.first) != bmap.end()){
		    // Which ever element is common and has less freq will be removed.
                int freq_to_rem = x.second > bmap[x.first] ? bmap[x.first] : x.second;
                elementsRemoved+=freq_to_rem;
            }
        }
        
        return elementsRemoved;
    }
};