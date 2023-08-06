#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

void insertAtBeg(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void delFromBeg(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "UnderFlow";
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtBeg(head, tail, 5);
    insertAtBeg(head, tail, 4);
    insertAtBeg(head, tail, 3);
    insertAtBeg(head, tail, 2);
    insertAtBeg(head, tail, 1);
    print(head);
    cout << "\n";
    delFromBeg(head, tail);
    print(head);
    cout << "\n";
    delFromBeg(head, tail);
    print(head);
    cout << "\n";
    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
}