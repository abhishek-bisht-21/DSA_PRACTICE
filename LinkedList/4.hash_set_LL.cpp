// 705. Design HashSet

// Approach 1 -> Using vector 
class MyHashSet {
public:
    
    vector<int> m;
    int size = 1e6+1;
    MyHashSet() {
        m.resize(size);
    }
    
    void add(int key) {
        m[key] = 1;
    }
    
    void remove(int key) {
        m[key] = 0;
    }
    
    bool contains(int key) {
        return m[key];
    }
};


// Approach 2 -> using LL

