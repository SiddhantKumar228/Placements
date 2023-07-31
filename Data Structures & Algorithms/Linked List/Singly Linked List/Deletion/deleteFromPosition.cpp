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

// Inserting node at position
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

// Deleting node from position
void delFromPos(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "Underflow";
        return;
    }

    // Count number of nodes
    int count = 1;
    Node *temp = head;
    while (temp != tail)
    {
        count++;
        temp = temp->next;
    }

    // Position is first
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    // Position is last
    else if (pos == count)
    {
        temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    // Position is mid
    else
    {
        count = 1;
        Node *prev = NULL;
        Node *curr = head;
        Node *next = head->next;
        while (count < pos)
        {
            prev = curr;
            curr = next;
            next = next->next;
            count++;
        }
        prev->next = next;
        curr->next = NULL;
        delete curr;
    }
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
    insertAtPos(head, tail, 6, 87);
    insertAtPos(head, tail, 7, 98);

    cout << "\nOriginal List: ";
    print(head);

    delFromPos(head, tail, 1);
    cout << "\nList After Deletion: ";
    print(head);

    delFromPos(head, tail, 6);
    cout << "\nList After Deletion: ";
    print(head);

    delFromPos(head, tail, 3);
    cout << "\nList After Deletion: ";
    print(head);

    cout << "\nhead = " << head->data;
    cout << "\ntail = " << tail->data;
}