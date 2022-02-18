class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
       int n =  (a ^ b);
       
      int count = 0;
    
        while (n) {
            n &= (n - 1); // Removing RightMost Set Bit
            count++;
        }
    
        return count;
      
        
    }
};