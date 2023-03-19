class Solution
{
    public:
long long countKdivPairs(int arr[], int n, int k)

    {

        //code here

        unordered_map<int,int>mp;

        long long int cn =0;

        for( int i=0; i<n; i++){

             int temp = arr[i]%k;

            if(mp.find(k-temp) != mp.end()){

                cn += mp[k-temp];

            }

            if(mp.find(temp) != mp.end() && temp ==0){

                cn += mp[temp];

            }

             mp[temp]++;

        }

        return cn;

    }
};