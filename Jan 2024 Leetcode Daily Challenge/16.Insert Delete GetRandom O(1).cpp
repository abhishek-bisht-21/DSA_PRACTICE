// 380. Insert Delete GetRandom O(1)

#include <bits/stdc++.h>
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int>m;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(m.find(val) != m.end()){
            return false;
        }
        v.push_back(val);
        m[val] = v.size()-1;
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()){
            return false;
        }
        
        // m[v.size()-1] = m[val];
        int rmidx = m[val];
       
        int lastidx = v.size()-1;
        int lastidxvalue = v[v.size()-1];
        
        swap(v[rmidx], v[lastidx]);
        v.pop_back();
        // m[v[m[val]]] = m[val];
        m[lastidxvalue] = rmidx;
//         m.erase(val);
         m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
         return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */