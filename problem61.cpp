#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getSize(ListNode* head) {
        int size = 0;
        ListNode* curr = head;
        while (curr!=nullptr) {
            size++;
            curr = curr->next;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head or !head->next) return head;

        int size = getSize(head);
        k %= size;

        while (k--) {
            ListNode* prev = nullptr;
            ListNode* curr = head;

            while (curr->next!=nullptr) {
                prev = curr;
                curr = prev->next;
            }
            prev->next = curr->next;
            curr->next = head;
            head = curr;
        }
        return head;
    }
};

