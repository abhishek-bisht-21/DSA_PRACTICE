class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int counter = 0;
        while(N != 0){
            int rsbm = N & -N;
            N -= rsbm;
            counter++;
            
        }
        
        return counter;
    }
};