#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int size){
  for(int i = 0 ;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return;
}
void BubbleSort(int arr[],int n){
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
  }
}
int main(){
    int arr[]= {4,6,9,90,67,25,21,14,};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original Array:- ";
    printArray(arr,size);
    cout<<"Sorted Array:- ";
    BubbleSort(arr,size);
    printArray(arr,size);
    return 0;
}