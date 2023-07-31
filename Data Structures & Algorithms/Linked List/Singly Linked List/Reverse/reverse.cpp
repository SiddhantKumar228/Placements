#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

// Insert node at position
void insertAtPos(Node *&head, Node *&tail, int pos, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    // Count number of nodes
    int count = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }

    // Position is first
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }

    // Position is last
    else if (pos == count + 1)
    {
        tail->next = newNode;
        tail = newNode;
    }

    // Position is mid
    else
    {
        count = 1;
        temp = head;
        Node *prev = NULL;
        Node *curr = head;
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

// Reversing the list
void reverse(Node *&head, Node *&tail)
{
}

// Print linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Main function
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtPos(head, tail, 1, 12);
    insertAtPos(head, tail, 2, 25);
    insertAtPos(head, tail, 3, 36);
    insertAtPos(head, tail, 4, 48);
    insertAtPos(head, tail, 5, 79);

    cout << "\nOriginal List: ";
    print(head);

    reverse(head, tail);
    cout << "\nReverse List: ";
    print(head);

    cout << "\nhead = " << head->data;
    cout << "\ntail = " << tail->data;
}