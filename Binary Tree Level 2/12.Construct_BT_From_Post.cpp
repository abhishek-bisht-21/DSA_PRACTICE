// Construct Binary Search Tree From LevelOrder Traversal


class levelPair
{
public:
    Node *par = nullptr; // Parent == par
    int lb = -(int)1e8;
    int rb = (int)1e8;

    levelPair()
    {
    }

    levelPair(Node *par, int lb, int rb)
    {
        this->par = par;
        this->lb = lb; // left boundary
        this->rb = rb; // right boundary
    }
};

//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    // Code here
    
    int idx = 0;
    queue<levelPair *> que;
    que.push(new levelPair());
    Node *root = nullptr;

    while (que.size() != 0 && idx < n)
    {
        levelPair *rp = que.front(); // rp -> removed Pair	
        que.pop();

	// If it is not in any range, simply continue
        if (arr[idx] < rp->lb || arr[idx] > rp->rb)
            continue;

	// Create a node otherwise.
        Node *node = new Node(arr[idx++]);
	// This is for root node.
        if (rp->par == nullptr)
            root = node;
	// Now decide whose child will this node will become
        else
        {
            if (node->data < rp->par->data)
                rp->par->left = node;
            else
                rp->par->right = node;
        }

        que.push(new levelPair(node, rp->lb, node->data));
        que.push(new levelPair(node, node->data, rp->rb));
    }

    return root;
}