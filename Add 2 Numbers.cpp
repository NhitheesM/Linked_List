/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* ans=new Node();
    Node* temp=ans;
    
    int carry=0;
    while(num1||num2||carry){
        int sum=carry;
        if(num1){
            sum+=num1->data;
            num1=num1->next;
        }
        if(num2){
            sum+=num2->data;
            num2=num2->next;
        }
        carry=sum/10;
        sum=sum%10;

        temp->next=new Node(sum);
        temp=temp->next;
    }
    return ans->next;
}

