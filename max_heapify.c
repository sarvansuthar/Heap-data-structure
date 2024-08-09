#include<stdio.h>
#include<math.h>
// void max_heapify(int arr[],int ind,int n);
// void build_max_heap(int arr[],int n);
void max_heapify(int arr[],int ind,int n){//this ind is based on 1th indexing.
    int l=2*ind-1;
    int r=2*ind;
    int largest;
    if(l<n && arr[ind-1]<arr[l]){
        largest=l;
    }
    else{
        largest=ind-1;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest==ind-1){
        return ;
    }
    int temp=arr[ind-1];
    arr[ind-1]=arr[largest];
    arr[largest]=temp;
    return max_heapify(arr,largest+1,n);
}
void build_max_heap(int arr[],int n){
    for(int i=floor(n/2);i>=1;i--){ //this i is 1th based index.
        max_heapify(arr,i,n);
    }
    return ;
}
void heap_sort(int arr[],int n){
    for(int i=n;i>=1;i--){
        printf("%d ",arr[0]);
        int temp=arr[0];
        arr[0]=arr[n-1];
        arr[n-1]=temp;
        max_heapify(arr,1,n-1);
        n--;
    }

}


int main(){
    int arr[10]= {4,1,3,2,16,9,10,14,8,7};
    // max_heapify(arr,1,10);
    build_max_heap(arr,10);
    // for(int i=0;i<10;i++){
    //     printf("%d ",arr[i]);
    // }
    heap_sort(arr,10);

}