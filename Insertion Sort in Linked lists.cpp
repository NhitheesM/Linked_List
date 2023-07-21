// Most Efficient and Most Easy
Node* insertionSortLL(Node *head)
{
    vector<int>v;
    Node*temp = head;
    if(head == NULL or head->next == NULL){
        return head;
    }
    while(temp != NULL){
        v.push_back(temp->data);
        temp = temp->next;
    }
    sort(v.begin(),v.end());
    int i = 0;
    temp = head;
    while(temp != NULL){
        temp->data = v[i++];
        temp = temp->next;
    }
    return head;
}

// Correct method but not efficient

Node* insertionSortLL(Node* head) {
    Node* sorted = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;

        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* search = sorted;
            while (search->next != NULL && current->data > search->next->data) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = nextNode;
    }

    return sorted;
}