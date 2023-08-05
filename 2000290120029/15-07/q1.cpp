//User function template for C++

class Solution
{
    public:
    int curr=0;
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        if(curr==(sizeOfStack/2)){
            s.pop();
            return;
        }
        int x=s.top();
        s.pop();
        curr++;
        deleteMid(s,sizeOfStack);
        s.push(x);
        // code here.. 
    }
};