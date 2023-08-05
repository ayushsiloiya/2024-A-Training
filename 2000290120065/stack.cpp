// LL IMPLEMENTATAION OF STACK
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int d){
            this->data=d;
            this->next=NULL;
        }
};

class Stack{
    public:
        Node *top;

        Stack(){
            top = NULL;
        }

        void push(int d){
            //creating the new node-will be allocated in heap memory
            Node* temp = new Node(d);

            // checking if memory is allocated in heap or not 
            if(!temp){
                cout<<"Stack Overflow"<<endl;
                return;
            }
    
            temp->data = d;
            temp->next = top;
            top = temp;
            
        }

        void pop(){
            Node* temp;
            if(top==NULL){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            temp = top;
            top = top->next;
            free(temp);
        }

        bool isEmpty(){
            return top==NULL;
        }
        // return s the top element
        int peek(){
            if(!isEmpty()) return top->data;
            cout<<"stack is empty";
            return -1;
        }


};


int main()
{
    Stack st;

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