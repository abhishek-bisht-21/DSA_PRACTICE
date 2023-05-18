class Solution {
    public:
    pair<int, int> swapNumbers(int a, int b) {
        // Your code goes here
        a = a + b;
        b = a - b;
        a = a - b;

        pair<int, int> p(a,b);
        return p;
    }
}