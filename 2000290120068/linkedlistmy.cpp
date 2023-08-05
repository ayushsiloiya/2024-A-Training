#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL;
    while (data != -7)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cin >> data;
    }
    return head;
}
void inputathead(node *&head)
{
    int a;
    cin >> a;
    node *n = new node(a);
    n->next = head;
    head = n;
}
void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int lenghtnode(node* &head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

int intersection(node* &head1, node * &head2)
{
    int l1 = lenghtnode(head1);
    int l2 = lenghtnode(head2);
    int t = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        t = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        t = -(l1 - l2);
        ptr1 = head2;
        ptr2 = head1;
    }
    while (t)
    {
        ptr1=ptr1->next;
        if (ptr1==NULL)
        {
            return -1;
        }
        
        t--;
    }
    while (ptr1!=NULL && ptr2!=NULL)
    {
        if (ptr1==ptr2)
        {
            return ptr1->data; 
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        
    }
    
}
int main()
{
    node *head1;
    cout << "Enter The First Linkedlist And To End It Enter -7 :\n";
    head1 = takeinput();
    node *head2;
    cout << "Enter The Second Linkedlist And To End It Enter -7 :\n";
    head2 = takeinput();
    display(head1);
    display(head2);
    intersection(head1, head2);
    display(head1);
    display(head2);

    // cout<<"Enter The Element at head: \n";
    // inputathead(head);
    // display(head);
    // cout<<"Deletion At head :\n";
    // deleteathead(head);
    // display(head);

    return 0;
}