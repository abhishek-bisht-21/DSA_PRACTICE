class Solution{
    public:
    
    class marks{
        public:
            
            int phy=0;
            int chem=0;
            int math=0;
            
            marks(){
                
            }
            
            marks(int phy , int chem, int math){
                this->phy = phy;
                this->chem = chem;
                this->math = math;
            }
    };
    
    class compare{
      public:
        bool operator()(marks &a, marks &b){
            if(a.phy != b.phy){
                return a.phy<b.phy;
            }else if(a.chem != b.chem){
                return a.chem > b.chem;
            }else{
                return a.math<b.math;
            }
        }
    };
    
    void customSort (int phy[], int chem[], int math[], int N)
    {
        // your code here
        int n = N;
        vector<marks> arr;
        for(int i=0;i<n;i++){
            marks m = {phy[i], chem[i], math[i]};
            arr.push_back(m);
        }
        
        sort(arr.begin(), arr.end(),compare());
        
        for(int i=0;i<n;i++){
            phy[i] = arr[i].phy;
            chem[i] = arr[i].chem;
            math[i] = arr[i].math;
        }
    } 
};