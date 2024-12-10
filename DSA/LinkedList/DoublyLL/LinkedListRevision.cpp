#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

public:
    Node(int x, Node *nextNode, Node *prevNode) // constructor with both data and next node
    {
        val = x;
        next = nextNode;
        prev = prevNode;
    }
    Node(int x)
    {
        val = x;
        next = nullptr;
        prev = nullptr;
    }
};
// function to insert a new node in the nexted list
void addNode(Node *&head, int val)
{
    Node *new_Node = new Node(val);

    if (head == nullptr) {
        // If the list is empty, the new node points to itself (circular list)
        new_Node->next = new_Node;
        new_Node->prev = new_Node;
        head = new_Node;
    } else {
        // Otherwise, find the last node and insert the new node after it
        Node *tail = head;
        while (tail->next != head) {
            tail = tail->next; // Move to the last node (before the head)
        }
        // Insert the new node
        new_Node->next = head;
        new_Node->prev = tail;
        tail->next = new_Node;
        head->prev = new_Node; // Make head's previous point to the new node
    }
}

void printForwardList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
}
int length_of_LL(Node *head)
{
    if (head == nullptr) 
        return 0; // If the list is empty, the length is 0.

    Node *traverseNode = head;
    int length = 1; // Start with 1 because we are at the head.

    while (traverseNode->next != head) {
        traverseNode = traverseNode->next;
        length++;
    }

    return length;
}

void printBackwardList(Node *head)
{
    Node *traverseNode = head;
    while (head != nullptr)
    {
        head = head->next;
    }
}

void deleteHead(Node *head)
{
    Node *traverseNode = head;
    head = head->next;
    delete traverseNode;
}

void deleteNode(Node *head, int nodeVal)
{ // head node and val that the node containing which is to be deleted, assuming all values are unique
    if (head->val == nodeVal)
    {
        deleteHead(head);
        return;
    }
    Node *traverseNode = head;
    // check if its the head node or not
    while (traverseNode->next->val != nodeVal && traverseNode->next != nullptr)
    {
        traverseNode = traverseNode->next;
    }
    traverseNode->next = traverseNode->next->next;
    traverseNode = traverseNode->next;
    delete traverseNode;
}

int main()
{
    // head of the list
    Node *head = new Node(5);
    addNode(head, 10);
    addNode(head, 11);
    addNode(head, 12);
    // printForwardList(head);
    cout << endl
         << "Length of LL: ";
    int length = length_of_LL(head);
    cout << length;
    // cout<<endl;
    // deleteNode(head,5);
    // printBackwardList(head);

    return 0;
};