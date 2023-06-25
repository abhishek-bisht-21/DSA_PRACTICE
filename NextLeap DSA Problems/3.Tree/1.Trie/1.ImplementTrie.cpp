class Trie {

public:
    struct Node{
        Node *links[26];
        bool flag = false;
        bool containsKey(char ch){
            return (links[ch - 'a'] != NULL);
        }


        void put(char ch, Node* node){
	    // New Character = its Reference trie.
            links[ch - 'a'] = node;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        void setEnd(){
            flag = true;
        }

        bool isEnd(){
            return flag;
        }

    };

    Node* root;    

    Trie() {
        root = new Node();
    }
    
    // tc-> O(len of word)
    void insert(string word) {
	// Dummy variable node which initially points to the root.
        Node* node = root;
	  // We need to insert every character.
        // We are checking that a character(word[i]) exist in our Trie 
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
		// If character doesnot exist.
		// Put the reference trie against that character.
                node->put(word[i], new Node());
            }

            // Moves to the reference Trie.
            node = node->get(word[i]);
        }
	// Node will be standing at the last reference trie.
        node->setEnd();
    }
    
    // tc -> O(len)
    bool search(string word) {
        Node* node = root;

        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }

            node=node->get(word[i]);
        }

        return node->isEnd();
    }
    
    // tc-> O(len)
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }

        return true;
    }
};