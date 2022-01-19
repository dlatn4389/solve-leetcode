#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode(-1);

        bool carry = false;
        while (l1 != nullptr and l2 != nullptr) {
            int sum = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            //cout << "test0: " << sum << endl;

            if (carry) {
                sum += 1;
                carry = false;
            }
            if (sum>=10) {
                carry = true;
                sum -= 10;
            }
            ListNode *curr = answer;

            while (curr->next!=nullptr) {
                curr = curr->next;
            }
            if (curr->val!=-1) {
                curr->next = new ListNode(sum);
            }
            else {
                curr->val = sum;
            }
        }

        if (l1==nullptr and l2!=nullptr) {
            while (l2!=nullptr) {
                int sum = l2->val + carry;
                l2 = l2->next;
                carry = false;
                if (sum>=10) {
                    carry = true;
                    sum -= 10;
                }

                ListNode *curr = answer;
                while (curr->next!=nullptr) {
                    curr = curr->next;
                }
                curr->next = new ListNode(sum);
            }
        }
        if (l2==nullptr and l1!= nullptr) {
            while (l1!=nullptr) {
                int sum = l1->val + carry;
                //cout << "test: " << sum << endl;
                l1 = l1->next;
                carry = false;
                if (sum>=10) {
                    carry = true;
                    sum -= 10;
                }

                ListNode* curr = answer;
                while (curr->next!=nullptr) {
                    curr = curr->next;
                }
                curr->next = new ListNode(sum);
            }
        }

        if (carry) {
            ListNode* curr = answer;
            while (curr->next!=nullptr) {
                curr = curr->next;
            }
            curr -> next = new ListNode(1);
        }
        return answer;
    }
};

int main() {
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    Solution s;

    ListNode* answer = s.addTwoNumbers(l1, l2);

    while (answer!=nullptr) {
        cout << answer -> val << endl;
        answer = answer -> next;
    }
}
