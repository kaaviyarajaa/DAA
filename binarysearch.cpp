#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[],int left,int right,int val){
    while(left<=right){
        int mid;
        mid=left+(right-1)/2;
        if(arr[mid]==val){
             return mid;
        }
        if(arr[mid]<val){
            left=mid-1;
        }
        else{
            right=mid+1;
        }
 }
    return -1;
}
int main(void){
int arr[]={2,3,4,8,9};
int val=8;
int n=sizeof(arr)/sizeof(arr[0]);
int result=binarysearch(arr,0,n-1,val);
if(result==-1){
    cout << "Element is not present in array";
}
else{
    cout << "Element is present at index " << result;
}
    return 0;
}
