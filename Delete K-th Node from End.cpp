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

Node* removeKthNode(Node* head, int K)
{
    if(head==NULL){
        return NULL;
    }
    int n=0;
    Node* temp=head;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    int NodePos=n-K;
    temp=head;
    if(NodePos==0){
        head=head->next;
        delete(temp);
    }
    int i=0;
    while(temp!=NULL){
        i++;
        if(i==NodePos){
            Node* prev=temp;
            Node* pos=temp->next;
            prev->next=pos->next;
            pos->next=NULL;
            delete(pos);
        }
        temp=temp->next;
    }
    return head;
}
