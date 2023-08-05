// ARRAY IMPLEMENTATAION OF queue
#include<iostream>
using namespace std;

class Queue{
    public:
        int *arr;
        int qfront;
        int rear;
        int size;

        Queue(){
            size = 100001;
            arr = new int[size];
            qfront = 0;
            rear = 0;
        }


        void enqueue(int d) {
            if(rear==size){
                cout<<"Queue is full"<<endl;
                return;
            }
            else {
                arr[rear] = d;
                rear++; 
            }
        }

        bool isEmpty(){
            return rear==qfront;
        }

        int dequeue(){
            if(isEmpty()) {
                return -1;
            }
            else{
                int ans = arr[qfront];
                arr[qfront] = -1;
                qfront++;
                if(qfront == rear){
                    qfront=0;
                    rear=0;
                }
                return ans;
            }
        }

        int front(){
            if(qfront==rear){
                return -1;
            }
            return arr[qfront];
        }

};


int main()
{
    Queue q;
    
    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;
    q.enqueue(12);
    cout<<q.front()<<endl;

    q.enqueue(13);
    q.dequeue();
    cout<<q.front()<<endl;
    cout<<q.isEmpty();



    return 0;
}