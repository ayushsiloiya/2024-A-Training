int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int s=0,e=n-1,st=-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]==x){
			st=mid;
			e=mid-1;
		}else if(arr[mid]>x){
			e=mid-1;
		}else{
			s=mid+1;
		}
	}
	if(st==-1) return 0;
	int count=1;
	for(int i=st+1;i<n;i++){
		if(arr[i]==x) count++;
	}
	return count;
}
