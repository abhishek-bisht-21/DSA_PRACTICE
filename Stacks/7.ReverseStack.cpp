// TC -> N, SC -> N

class Solution{
public:

    void insertAtBottomRecursively(stack<int> &st, int x){
	if(st.empty()){
		st.push(x);
		return;
	}

	int curr = st.top();
	st.pop();
	insertAtBottomRecursively(st,x);
	st.push(curr);
}

    void Reverse(stack<int> &st){
        if(st.empty()){
            return;
        }
        
        int curr = st.top();
        st.pop();
        Reverse(st);
        insertAtBottomRecursively(st,curr);
    }
};