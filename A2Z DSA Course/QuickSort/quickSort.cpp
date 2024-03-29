#include <bits/stdc++.h> 

int segregateData(vector<int> &arr, int si, int ei, int pivot){

    //swap(arr[p], arr[ei])
    int p = si - 1;
    int itr = si;

    while(itr <= ei){
        if(arr[itr] <= arr[ei]){
            swap(arr[++p], arr[itr]);
        }

        itr++;
    }

    return p;
}

void quickSort(vector<int> &arr, int si, int ei){

    if(si > ei){
        return;
    }

    //int len = (ei-si+1);
    //int pivot = rand() % len + si;

    int pivot = ei;
    int pidx = segregateData(arr,si,ei,pivot);

    quickSort(arr,si,pidx-1); // Left Half
    quickSort(arr,pidx+1,ei); // Right Half 

}

vector<int> quickSort(vector<int> arr)
{
    quickSort(arr,0,arr.size()-1);
    return arr;
}
