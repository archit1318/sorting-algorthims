#include<bits/stdc++.h>
using namespace std;
void merge(int*arr,int s,int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int a1[len1];
    int a2[len2];
    int k=s;
    for(int i=0;i<len1;i++)a1[i]=arr[k++];
    k=mid+1;
    for(int i=0;i<len2;i++)a2[i]=arr[k++];
    k=s;
    int index1=0; int index2=0;
    while(index1<len1 && index2<len2){
        if(a1[index1]<a2[index2]){
            arr[k++]=a1[index1++];
        }else{
            arr[k++]=a2[index2++];
        }
    }
    while(index1<len1){
        arr[k++]=a1[index1++];
    }
    while(index2<len2){
        arr[k++]=a2[index2++];
    }
}
void mergeSort(int *arr,int s,int e){
    if(s>=e)return;
    int mid =(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    int n; cin>>n;  
    int arr[n];
    for(auto i=0;i<n;i++)cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(auto x:arr)cout<<x<<"  ";

}