#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int size){
  for(int i = 0 ;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return;
}
void selectionSort(int arr[],int n){
  for(int i = 0;i<n;i++){
    int min_index = i;
    for(int j=i+1;j<n;j++){
        if(arr[min_index]>arr[j]){
            min_index = j;
        }
    }
    swap(arr[i],arr[min_index]);
  }
}
int main(){
    int arr[]= {4,6,9,90,67,25,21,14,};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original Array:- ";
    printArray(arr,size);
    cout<<"Sorted Array:- ";
    selectionSort(arr,size);
    printArray(arr,size);
    return 0;
}