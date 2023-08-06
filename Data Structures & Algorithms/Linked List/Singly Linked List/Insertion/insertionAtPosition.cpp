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

void insertAtPos(Node *&head, Node *&tail, int pos, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    int count = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }

    else if (pos == count + 1)
    {
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        count = 1;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        newNode->next = curr;
        prev->next = newNode;
    }
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

    insertAtPos(head, tail, 1, 11);
    insertAtPos(head, tail, 2, 22);
    insertAtPos(head, tail, 3, 33);
    insertAtPos(head, tail, 4, 44);
    insertAtPos(head, tail, 5, 55);
    print(head);
    cout << "\n";
    insertAtPos(head, tail, 1, 9);
    print(head);
    cout << "\n";
    insertAtPos(head, tail, 7, 77);
    print(head);
    cout << "\n";
    insertAtPos(head, tail, 3, 19);
    print(head);
    cout << "\n";
    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
}