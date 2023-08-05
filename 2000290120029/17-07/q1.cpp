class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    list<char> l;
		    int arr[26]={0};
		    string ans;
		    for(int i=0;i<A.length();i++){
		        arr[A[i]-'a']++;
		        
		        if(arr[A[i]-'a']==1){
		            l.push_back(A[i]);
		        }
		        
		        if(arr[A[i]-'a']>1){
		            l.remove(A[i]);
		        }
		        
		        if(!l.empty()){
		            ans+=*(l.begin());
		        }else{
		            ans+='#';
		        }
		    }
		    return ans;
		}

};