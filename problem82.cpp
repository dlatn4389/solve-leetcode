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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* prev = dummyHead;
        ListNode* curr = head;
        if (curr==nullptr) return head;

        while (curr!=nullptr and curr->next!=nullptr) {
            if (curr->val==curr->next->val) {
                while (curr->next!=nullptr and curr->next->val==curr->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummyHead->next;
    }
};

void add(ListNode* head, int x) {
    ListNode* curr = head;
    while (curr->next!=nullptr) {
        curr = curr->next;
    }
    curr->next = new ListNode(x);
}

void print(ListNode* head) {
    ListNode* curr = head;
    while (curr!=nullptr) {
        cout << curr->val << ' ';
        curr = curr->next;
    }
}

int main() {
    ListNode* dummyHead = new ListNode();

    cout << "Input size of list below" << endl;
    int n; cin >> n;

    cout << "Input Elements of list below" << endl;
    while (n--) {
        int x; cin >> x;
        add(dummyHead, x);
    }

    cout << endl;
    cout << "***************print************" << endl;
    Solution sol;
    ListNode* answer = sol.deleteDuplicates(dummyHead->next);
    print(answer);
}

