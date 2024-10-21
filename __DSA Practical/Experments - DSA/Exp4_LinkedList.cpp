#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Value delete is : " << this->data << endl;
    }
};

void displayLinkedList(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void displayReversedLinkedList(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    displayReversedLinkedList(temp->next);
    cout << temp->data << " ";
    return;
}

void insertAtHead(Node *&head, int d)
{
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtEnd(Node *&head, int d)
{
    if (head == NULL)
    {
        insertAtHead(head, d);
        return;
    }
    Node *newNode = new Node(d);

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void deleteByPosition(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }

    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int i = 1;
        while (i < pos && curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
            ++i;
        }

        if (curr == NULL)
        {
            cout << "Position out of bounds." << endl;
            return;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    return;
}

void deleteByValue(Node *&head, int val)
{
    if (head == NULL)
    {
        cout << "Underflow!" << endl;
        return;
    }

    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL && curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Position out of bounds." << endl;
        return;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return;
}

int countNumberOfNodes(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        ++count;
        temp = temp->next;
    }

    return count;
}

int main()
{
    Node *head = NULL;

    // insertAtHead(head, 50);
    // insertAtHead(head, 40);
    // insertAtHead(head, 30);
    // insertAtHead(head, 20);
    // insertAtHead(head, 10);

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    cout << "Displaying linked list : ";
    displayLinkedList(head);
    int cnt = countNumberOfNodes(head);
    cout << "Number of Nodes = " << cnt << endl;
    cout << "Displaying reversed linked list : ";
    displayReversedLinkedList(head);

    // deletion
    //  deleteByPosition(head, 2);
    //  cout << "After Deletion by Position: ";
    //  displayLinkedList(head);
    //  deleteByValue(head, 50);
    //  cout << "After Deletion by Value: ";
    //  displayLinkedList(head);

    return 0;
}
