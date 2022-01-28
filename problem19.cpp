#include <iostream>
#include <algorithm>
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
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        int size = 0;
        ListNode* curr = head;
        while (curr!=nullptr) {
            size++;
            curr = curr->next;
        }

        int target_idx = size-n;
        if (target_idx==0) {
            head = head->next;
            return head;
        }
        ListNode *prev = head;
        for (int i=1; i<target_idx; i++) {
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};

void add(ListNode *head, int n) {
    ListNode* node = new ListNode(n);
    ListNode* curr = head;

    while (curr->next!=nullptr) {
        curr = curr->next;
    }
    curr->next = node;
}

void print(ListNode* head) {
    ListNode* curr = head;
    while (curr!=nullptr) {
        cout << curr->val << ' ';
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode();
    // 원소의 개수
    cout << "Input Number of Element below" << endl;
    int n; cin >> n;
    cout << "Input Element below" << endl;
    for (int i=0; i<n; i++) {
        int in; cin >> in;
        if (i==0) {
            head->val = in;
        }
        else {
            add(head, in);
        }
    }
    cout << "Input target below" << endl;
    int target; cin >> target;
    cout << endl;
    cout << "***********print**************" << endl;
    Solution sol;
    sol.removeNthFromEnd(head, target);
    print(head);
}