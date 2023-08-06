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

void insertAtEnd(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void delFromEnd(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Underflow";
        return;
    }
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
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
    insertAtEnd(head, tail, 1);
    insertAtEnd(head, tail, 2);
    insertAtEnd(head, tail, 3);
    insertAtEnd(head, tail, 4);
    insertAtEnd(head, tail, 5);
    print(head);
    cout << "\n";
    delFromEnd(head, tail);
    print(head);
    cout << "\n";
    delFromEnd(head, tail);
    print(head);
    cout << "\n";
    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
}