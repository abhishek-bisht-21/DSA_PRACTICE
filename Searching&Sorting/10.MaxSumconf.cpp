// GFG

/*

arr -> a b c d e
sum = a+b+c+d+e

S0 -> 0a+1b+2c+3d+4e
S1 -> 0e+1a+2b+3c+4d
S2 -> 0d+1e+2a+3b+4c
S3 -> 0c+1d+2e+3a+4b
S4 -> 0b+1c+2d+3e+4a

Si+1 = Si + Sum - n*arr[n-i-1]


*/

int max_sum(int A[],int N)
{
//Your code here

int sum = 0;
int allSum = 0;
for(int i=0;i<N;i++){
    sum+=A[i];
    allSum+=A[i]*i;
}

int maxSum = allSum;
int csum = allSum;
for(int i = 0;i<N;i++){
     csum = csum + sum - N*A[N-i-1];
    
    if(csum >= maxSum){
        maxSum = csum;
    }
}

return maxSum;

}