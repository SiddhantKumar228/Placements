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

void insert(Node *&head, Node *&tail, int val)
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
    tail->next = head;
}

void print(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insert(head, tail, 1);
    insert(head, tail, 3);
    insert(head, tail, 5);
    insert(head, tail, 7);
    print(head, tail);

    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
    cout << "\nTail Next = " << tail->next->data;
}