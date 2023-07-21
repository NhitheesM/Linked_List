Node* addNodes(Node* head, int n, int m) {
    Node* dummy=head;
	int ntemp=0;
	int mtemp=0;
	int sum=0;

	while(dummy!=NULL){
		if(mtemp==m){
			sum+=dummy->data;
			ntemp++;
			if(ntemp==n){
				Node* sumNode=new Node(sum);
				sumNode->next=dummy->next;
				dummy->next=sumNode;
				ntemp=0;
				mtemp=0;
			}
				
		}
		else{
			mtemp++;
		}
		dummy=dummy->next;
	}
	return head;
}