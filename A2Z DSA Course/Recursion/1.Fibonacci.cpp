class Solution {
  public:
    long long int nthFibonacci(long long int n){
        
        // Base Case
        if(n <= 1){
            return n;
        }
        
        // Recursive Call
        long long int fibo1 = nthFibonacci(n-1);
        long long int fibo2 = nthFibonacci(n-2);
        
        // Small Calculation
        long long int res = fibo1+fibo2;
        
        return res;
        
    }
};