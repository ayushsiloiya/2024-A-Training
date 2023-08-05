class Solution {
public:
    int count=0;
    void merge(vector<int>& arr,int s,int mid,int e){
        int arr2[e-s+1];
        int i=s,j=mid+1,k;
         while(i<=mid && j<=e){
            if(arr[i]>(long)2*arr[j]){
                count+=(mid-i+1);
                j++;
            }else{
                i++;
            }
        }
        i=s,j=mid+1,k=0;
        while(i<=mid && j<=e){
            if(arr[i]<=arr[j]){
                arr2[k++]=arr[i++];
            }else{
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
    void mergesort(vector<int> &arr,int s,int e){
        if(s<e){
            int mid=(s+e)/2;
            mergesort(arr,s,mid);
            mergesort(arr,mid+1,e);
            merge(arr,s,mid,e);
        }
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        return count;
    }
};