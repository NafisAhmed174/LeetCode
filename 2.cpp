/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* root = new ListNode(0);
        auto it1 = l1, it2 = l2, it = root;
        while(1){
            if(it1 != NULL && it2 != NULL){
                int now = it1->val + it2->val + carry;
                carry = now / 10;
                int dig = now % 10;
                it->next = new ListNode(dig);
                it = it->next;
                it1 = it1->next;
                it2 = it2->next;
            }
            else if(it1 != NULL){
                int now = it1->val + carry;
                carry = now / 10;
                int dig = now % 10;
                it->next = new ListNode(dig);
                it = it->next;
                it1 = it1->next;
            }
            else if(it2 != NULL){
                int now = it2->val + carry;
                carry = now / 10;
                int dig = now % 10;
                it->next = new ListNode(dig);
                it = it->next;
                it2 = it2->next;
            }
            else if(carry){
                int dig = carry;
                it->next = new ListNode(dig);
                break;
            }else{
                break;
            }
        }
        root = root->next;
        return root;
    }
};