class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {

        // Save the Head next in temp pointer.
        node* temp = head->next;
        // first make the connection of new Node with temp node
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {

        // Check if Exists in the map or not
        if (m.find(key_) != m.end()) {

            // Get its address from the Map
            node* resnode = m[key_];
            int res = resnode->val;
            // Erase the entry from the Map
            m.erase(key_);
            // Delete Node and Add it next to Head coz its Recently Used
            deletenode(resnode);
            addnode(resnode);
            // Enter in the Map with its new Address
            m[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {

        // If the Key Already exist in the Map.
        if(m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }

        // If Capacity if Full, Then delete the Least Recently used.
        if(m.size() == cap) {
          // Tails prev is Least Recently used.  
          m.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        
        // Add the node next to Head and Enter the new Address of the Node in Map
        addnode(new node(key_, value));
        m[key_] = head->next; 
    }
};