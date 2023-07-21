// Create Odd and Even lists .Then Join
Node* segregateOddEven(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* oddHead = nullptr;
    Node* evenHead = nullptr;
    Node* oddTail = nullptr;
    Node* evenTail = nullptr;

    Node* current = head;

    while (current != nullptr) {
        if (current->data % 2 == 1) {
            if (oddHead == nullptr) {
                oddHead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        } else {
            if (evenHead == nullptr) {
                evenHead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }

        current = current->next;
    }

    if (oddHead == nullptr) {
        return evenHead;
    } else {
        oddTail->next = evenHead;
        if (evenTail != nullptr)
            evenTail->next = nullptr;
        return oddHead;
    }
}

// Create Vectors for Odd and Even .Then Store in Linked list

Node * segregateOddEven (Node * head)
{
	Node* temp=head;
	vector<int> odd;
	vector<int> even;
	while(temp!=NULL){
		if((temp->data)%2==1){
			odd.push_back(temp->data); 
		}
		else{
			even.push_back(temp->data);
		}
		temp=temp->next;
	}
	temp=head;
	for(int i=0;i<odd.size();i++){
		temp->data=odd[i];
		temp=temp->next;
	}
	for(int i=0;i<even.size();i++){
		temp->data=even[i];
		temp=temp->next;
	}
	delete odd;
	return head;
}