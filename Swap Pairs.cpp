Node* pairsSwap(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* dummy = new Node(0);
    dummy->next = head;
    Node* current = dummy;

    while (current->next != nullptr && current->next->next != nullptr) {
        Node* firstNode = current->next;
        Node* secondNode = current->next->next;

        // Swapping nodes
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;
        current->next = secondNode;

        // Move the current pointer two steps forward
        current = current->next->next;
    }

    Node* newHead = dummy->next;
    delete dummy;

    return newHead;
}