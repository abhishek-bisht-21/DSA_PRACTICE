class Solution{
    public:
    
    typedef long long ll;
    ll ksmallest(ll a[], ll n, ll k){
        
       
        priority_queue<ll> pq;
        
        for(int i=0;i<n;i++){
            pq.push(a[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
       
       return pq.top();
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
       ll elek1 = ksmallest(A,N,K1);
        ll elek2 = ksmallest(A,N,K2);
        
        ll sum = 0;
        for(int i=0;i<N;i++){
            if(elek1 < A[i] && A[i] < elek2){
                sum+=A[i];
            }
        }
        
        return sum;
        
    }
};