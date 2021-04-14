#include <iostream>
using namespace std;
 
// A Linked List Node
struct Node
{
    int data;
    Node* next;
};
 
// Utility function to create a new node with the given data and
// pushes it onto the list's front
void push(Node*& headRef, int data)
{
    // create a new linked list node from the heap
    Node* newNode = new Node;
 
    newNode->data = data;
    newNode->next = headRef;
    headRef = newNode;
}
 
// Utility function to find the total number of nodes in a linked list
int size(Node* head)
{
    int nodes = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        nodes++;
    }
    return nodes;
}
 
// Function to find the intersection point of two linked lists.
// Assume that the first list contains `k` nodes more than the second list
Node* findIntersection(Node* first, Node* second, int k)
{
    // advance the bigger list by `k` nodes
    for (int i = 0; i < k && first; i++) {
        first = first->next;
    }
 
    // simultaneously move both lists at the same speed until they meet
    while (first && second)
    {
        // if both lists meet any node, then that node is the intersection point
        if (first == second) {
            return first;
        }
 
        // advance both lists by one node
        first = first->next;
        second = second->next;
    }
 
    // return null if both lists don't meet
    return nullptr;
}
 
// Function to find the intersection point of two linked lists
Node* findIntersection(Node* first, Node* second)
{
    // get the difference in the number of nodes in both lists
    int diff = size(first) - size(second);
 
    // if the first list has a smaller number of nodes, exchange both lists
    if (diff < 0) {
        swap(first, second);
    }
 
    // find and return the intersection node
    return findIntersection(first, second, abs(diff));
}
 
int main()
{
    // construct the first linked list (1 —> 2 —> 3 —> 4 —> 5 —> null)
    Node* first = nullptr;
    for (int i = 7; i > 0; i--) {
        push(first, i);
    }
 
    // construct the second linked list (1 —> 2 —> 3 —> null)
    Node* second = nullptr;
    for (int i = 3; i > 0; i--) {
        push(second, i);
    }
 
    // link tail of the second list to the fourth node of the first list
    second->next->next->next = first->next->next->next;
 
    Node* addr = findIntersection(first, second);
    if (addr) {
        cout << "The intersection point is " << addr->data << endl;
    }
    else {
        cout << "The lists do not intersect." << endl;
    }
 
    return 0;
}