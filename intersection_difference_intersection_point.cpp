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
 
// Function to find the intersection point of two linked lists
Node* findIntersection(Node* first, Node* second)
{
    // Take two pointers pointing to the heads of respective lists
    Node *x = first, *y = second;
 
    // advance both pointers until they meet at a common node
    while (x != y)
    {
        // When the first list reaches its end, redirect it to the
        // head of the second list
        if (x == nullptr) {
            x = second;
        }
        else {
            x = x->next;
        }
 
        // When the second list reaches its end, redirect it to the
        // head of the first list
        if (y == nullptr) {
            y = first;
        }
        else {
            y = y->next;
        }
    }
 
    // return the common node
    return x;
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