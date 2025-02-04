#include <bits/stdc++.h>
using namespace std;

int linearsearch(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4}; 
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = linearsearch(arr,n,3);
    if(index==-1) cout<<"Element not found!";
    else cout<<"Element found at "<<index<<" index";
}