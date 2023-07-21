/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    Node *temp=head;
    int n=0;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    int mid=n/2+1;
    n=0;
    temp=head;
    while(temp!=NULL){
        n++;
        if(n==mid){
            return temp;
        }
        
        temp=temp->next;
    }
}

