// ARRAY IMPLEMENTATAION OF STACK
#include<iostream>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;

        Stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int n){
            if(size-top>1) {
                top++;
                arr[top] = n;
            }
            else cout<<"stck is Full"<<endl;
        }

        void pop(){
            if(top>=0){
                top--;
            }
            else cout<<"stack is underflow";
        }
        // return s the top element
        int peek(){
            if(top>=0){
                return arr[top];
            }
            else cout<<"Stack is empty"<<endl;
            return -1;
        }

        bool isEmpty(){
            if(top==-1) return true;
            else return false;
        }

};


int main()
{
    Stack st(10);
    cout<<st.peek()<<endl;
    st.push(12);
    cout<<st.peek()<<endl;

    st.push(13);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.isEmpty();



    return 0;
}