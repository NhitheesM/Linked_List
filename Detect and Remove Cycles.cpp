/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where ‘N’ is the number of nodes in the list.   
*/

#include <set>
Node *removeLoop(Node *head)
{
    // LookUp table to store the visited nodes.
    set<Node *> lookUp;

    Node *prev = nullptr;
    Node *cur = head;

    while (cur != nullptr){

        if (lookUp.find(cur) != lookUp.end()){
            //  We reached some earlier node again thus we found a cycle
            prev->next = nullptr;
            return head;
        }
        else{
            // Add the node to hastset of already seen nodes
            lookUp.insert(cur);
            prev = cur;
        }

        cur = cur->next;
    }

    // We didn't found any Cycle
    return head;
}