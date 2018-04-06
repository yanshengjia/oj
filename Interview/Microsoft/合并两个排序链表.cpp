#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* mergeLists(Node* head1, Node* head2) {
    Node *guard = new Node();
    Node *current = guard;
    
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }
    
    if (head1 != NULL) {
        current->next = head1;
    } else {
        current->next = head2;
    }
    
    return guard->next;
}

void printList(Node* head) {
    while (head != NULL) {
        if (head->next == NULL) {
            cout << head->data << "->null" << endl;
            return;
        }
        cout << head->data << "->";
        head = head -> next;
    }
}

int main() {
    // list1: 1->3->8->null
    Node *a0 = new Node();
    Node *a1 = new Node();
    Node *a2 = new Node();
    a0->data = 1;
    a1->data = 3;
    a2->data = 8;
    a0->next = a1;
    a1->next = a2;
    a2->next = NULL;
    printList(a0);

    // list2: 2->6->6->null
    Node *b0 = new Node();
    Node *b1 = new Node();
    Node *b2 = new Node();
    b0->data = 2;
    b1->data = 6;
    b2->data = 6;
    b0->next = b1;
    b1->next = b2;
    b2->next = NULL;
    printList(b0);

    // merge
    Node *head = mergeLists(a0, b0);

    printList(head);

    return 0;
}



