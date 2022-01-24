




// _________________________________________________________________Display Array____________________________________________________________________________



void display(int arr[], int idx, int n){

    if (idx == n)
        return;

    cout << arr[idx] << endl;
    display(arr, idx + 1, n);
}


// _____________________________________________________________Display Array In Reverse________________________________________________

void display(int arr[], int idx, int n){

    if (idx == n)
        return;

    display(arr, idx + 1, n);
    cout << arr[idx] << endl;
}



// ___________________________________________________________ Max in the Array__________________________________________________________________

int max(int arr[], int idx, int n){

    if (idx == n - 1)
        return arr[idx];

    int a = max(arr, idx + 1, n);
    if (a > arr[idx])
        return a;
    else
        return arr[idx];
}


// _________________________________________________________________First Index_________________________________________________________


int firstIndex(int arr[], int idx, int x, int n){

    if (idx == n)
        return -1;

    if (arr[idx] == x){
        return idx;
    }else{
        int a = firstIndex(arr, idx + 1, x, n);
        return a;
    }
}


// ________________________________________________________________ Last Index____________________________________________________________

int lastIndex(int arr[], int idx, int x, int n){
    if (idx == n)
        return -1;

    int a = lastIndex(arr, idx + 1, x, n);

    if (a != -1)
        return a;

    if (arr[idx] == x)
        return idx;
    else
        return -1;
}


// _________________________________________________________________All Indices Of Array_____________________________________________________


vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{
  if (idx == arr.size())
  {
    vector<int> base(count, 0);
    return base;
  }

  if (arr[idx] == data)
    count++;
  vector<int> ans = allIndex(arr, idx + 1, data, count);
  if (arr[idx] == data)
    ans[count - 1] = idx;

  return ans;
}