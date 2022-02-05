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
    ListNode* swapPairs(ListNode *head) {
        if (head==nullptr) {
            return head;
        }
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;

        ListNode* prev = dummyHead;
        ListNode* curr = prev->next;
        ListNode* next = curr->next;

        while (next!=nullptr) {
            prev->next = next;
            curr->next = next->next;
            next->next = curr;

            prev = prev->next->next;
            if (prev==nullptr) break;
            curr = prev->next;
            if (curr==nullptr) break;
            next = curr->next;
        }
        return dummyHead->next;
    }
};

void add(ListNode* head, int value) {
    ListNode* curr = head;
    while (curr->next!=nullptr) {
        curr = curr->next;
    }
    ListNode* next = new ListNode(value);
    curr->next = next;
}

void print(ListNode* head) {
    ListNode* curr = head;
    while (curr!=nullptr) {
        cout << curr->val << ' ';
        curr = curr->next;
    }
}

int main() {
    ListNode* l = new ListNode();

    cout << "Input Number of Element below" << endl;
    int n; cin >> n;
    cout << "Input Element below" << endl;
    for (int i=0; i<n; i++) {
        int in; cin >> in;
        if (i==0) {
            l->val = in;
        }
        else {
            add(l, in);
        }
    }

    cout << endl;
    cout << "***********print**************" << endl;
    Solution sol;
    print(sol.swapPairs(l));
}