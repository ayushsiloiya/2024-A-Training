class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int count=0;
    void merge(long long arr[],long long s,long long mid,long long e){
        long long int arr2[e-s+1];
        long long int i=s,j=mid+1,k=0;
        while(i<=mid && j<=e){
            if(arr[i]<=arr[j]){
                arr2[k++]=arr[i++];
            }else{
                count+=(mid-i+1);
                arr2[k++]=arr[j++];
            }
        }
        while(i<=mid){
            arr2[k++]=arr[i++];
        }
        while(j<=e){
            arr2[k++]=arr[j++];
        }
        for(i=0;i<e-s+1;i++){
            arr[s+i]=arr2[i];
        }
    }
    void mergesort(long long arr[],long long s,long long e){
        if(s<e){
            long long mid=(s+e)/2;
            mergesort(arr,s,mid);
            mergesort(arr,mid+1,e);
            merge(arr,s,mid,e);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergesort(arr,0,N-1);
        return count;
    }

};