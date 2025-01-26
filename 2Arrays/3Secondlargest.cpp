#include <bits/stdc++.h>
using namespace std;

int largestelement(int arr[],int n){
    int secondl=0;
    int largest=0;
    for(int i=0;i<n;i++){
        if(arr[i]>largest) largest = arr[i];
    }
    return largest;
}

int main(){
    int arr[] = {1,5,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int largest = largestelement(arr,n);
    cout<<"Largest element in this array is "<<largest;
}