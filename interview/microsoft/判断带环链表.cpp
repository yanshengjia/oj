// Author: Shengjia Yan
// Date: 2018-04-20 Friday
// Email: i@yanshengjia.com
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

bool hasCircle (Node* head) {
    Node *slow, *fast;
    slow = fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) {
            return true;   
        }
    }
    return false;
}