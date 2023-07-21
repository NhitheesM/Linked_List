#include <bits/stdc++.h> 
/**********************************************************************

    Following is the class structure of the Node class for reference:

    class Node{
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };


********************************************************************/
Node* Merge(Node* left,Node* right){
    Node* ans=new Node(0);
    Node* curr=ans;

    while(left!=NULL && right!=NULL){
        if(left->data<=right->data){
            curr->next=left;
            left=left->next;
            curr=curr->next;
        }
        else{
            curr->next=right;
            right=right->next;
            curr=curr->next;
        }
    }
    while(left!=NULL){
        curr->next=left;
        left=left->next;
        curr=curr->next;
    }
    while(right!=NULL){
        curr->next=right;
        right=right->next;
        curr=curr->next;
    }
    return ans->next;
}

Node* FindMiddle(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=(fast->next)->next;
    }
    return slow;

} 

Node *MergeSorting(Node *head){
    if(head->next==NULL){
        return head;
    }
    Node* LeftStart= head;
    Node* Mid=FindMiddle(LeftStart);
    Node* RightStart=Mid->next;
    Mid->next=NULL;
    
    Node *LeftSorted=MergeSorting(LeftStart);
    Node *RightSorted=MergeSorting(RightStart);
    Node *Merged= Merge(LeftSorted,RightSorted);
    return Merged;
}

Node *sortLL(Node *head){
    head=MergeSorting(head);
    return head;

}