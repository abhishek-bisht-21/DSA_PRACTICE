bool findPair(int arr[], int size, int n){
    //code
    
sort(arr,arr+size);
   int low=0,high=1;
   while(low<size && high<size)
   {
       if(arr[high]-arr[low]==n && low<high)// Very important
       {
           return true;
       }
       else if(arr[high]-arr[low]>n)
       {
           low++;
       }
       else
       {
           high++;
       }
   }
   return false;
    
}