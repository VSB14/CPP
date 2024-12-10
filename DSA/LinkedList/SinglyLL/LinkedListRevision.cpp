#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *link;

public:
    Node(int x, Node *next) //constructor with both data and next node
    {
        val = x;
        link = next;
    }
    Node(int x)
    {
        val = x;
        link = nullptr;
    }
};
// function to insert a new node in the linked list
void addNode(Node *head, int val)
{

    Node *new_Node = new Node(val);
    //we require to fit the new node at the end of the list
    while(head->link != nullptr){
        head = head->link;
    }
    head->link = new_Node;
}
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->link;
    }
}

void deleteHead(Node *head){
    Node *traverseNode = head;
    head = head->link;
    delete traverseNode;
}

void deleteNode(Node *head, int nodeVal){ //head node and val that the node containing which is to be deleted, assuming all values are unique
    if(head->val == nodeVal){
        deleteHead(head);
        return;
    }
    Node *traverseNode = head;
    //check if its the head node or not
    while (traverseNode->link->val != nodeVal && traverseNode->link != nullptr)
    {
        traverseNode = traverseNode->link;
    }
    traverseNode->link = traverseNode->link->link;
    traverseNode = traverseNode->link;
    delete traverseNode;
    

}

int main()
{
    // head of the list
    Node *head = new Node(5);
    addNode(head, 10);
    addNode(head, 11);
    addNode(head, 12);
    printList(head);
    cout<<endl;
    deleteNode(head,5);
    printList(head);

    return 0;
};