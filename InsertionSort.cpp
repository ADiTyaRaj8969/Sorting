#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int size){
  for(int i = 0 ;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return;
}
void InsertionSort(int arr[],int n){
  for(int i = 0;i<n;i++){
    int key = arr[i];
    int j = i-1;
    while(key<arr[j]){
        arr[j+1]= arr[j];
        j = j-1;

    }
    arr[j+1]=key;
  }
}
int main(){
    int arr[]= {4,6,9,90,67,25,21,14,};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original Array:- ";
    printArray(arr,size);
    cout<<"Sorted Array:- ";
    InsertionSort(arr,size);
    printArray(arr,size);
    return 0;
}