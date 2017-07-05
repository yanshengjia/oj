/*
一个环状有序链表，有头指针，里面存储的元素按升序排列(除去环的交接点，即头部元素和尾部元素)。使用C/C++实现一个算法，将新元素插入到当前链表中，不破坏原有链表的各种约束。
Created by sjyan @2017-06-23
*/

#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    bool isHead;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
        this->isHead = false;
    }
};

// insert a new element to the linked list
int insert(ListNode *head, ListNode *newone) {    
    // head->head
    if (head->next->isHead == true) {
        head->next = newone;
        newone->next = head;
        return 0;
    }

    ListNode *p = head->next;
    ListNode *q = p->next;
    ListNode *last = p;
    
    // head->newone->p1->...
    if (p->val > newone->val) {
        head->next = newone;
        newone->next = p;
        return 0;
    }
    
    // head->p1->p2->...->pn->head
    while (q->isHead != true) {
        if (p->val <= newone->val && newone->val <= q->val) {
            p->next = newone;
            newone->next = q;
            return 0;
        }
        last = q;
        p = p->next;
        q = q->next;
    }
    
    // head->...->last->newone->haed
    // head->p->head
    if (last->val < newone->val) {
        last->next = newone;
        newone->next = head;
        return 0;
    }
    return 0;
}

// print linked list
void print(ListNode *head) {
    cout<<"head->";
    ListNode *p = head->next;
    
    while(p->isHead != true) {
        cout<<p->val<<"->";
        p = p->next;
    }

    cout<<"head"<<endl;
}

int main() {
    // case 1: head->2->4->6->head, newone = 3
    ListNode *head = new ListNode(0);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(4);
    ListNode *p3 = new ListNode(6);
    ListNode *newone = new ListNode(5);
    head->isHead = true;
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = head;
    
    // case 2: head->head, newone = 3
    // ListNode *head = new ListNode(0);
    // ListNode *newone = new ListNode(3);
    // head->isHead = true;
    // head->next = head;
    
    // case 3: head->1->head, newone = 3
    // ListNode *head = new ListNode(0);
    // ListNode *p1 = new ListNode(1);
    // ListNode *newone = new ListNode(3);
    // head->isHead = true;
    // head->next = p1;
    // p1->next = head;

    // case 4: head->4->head, newone = 3
    // ListNode *head = new ListNode(0);
    // ListNode *p1 = new ListNode(4);
    // ListNode *newone = new ListNode(3);
    // head->isHead = true;
    // head->next = p1;
    // p1->next = head;

    // insert
    print(head);
    insert(head, newone);
    print(head);
    
    return 0;
}