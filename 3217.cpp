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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* root = new ListNode(0);
        
        set<int> st(nums.begin(), nums.end());
        
        ListNode* ptr = head;
        ListNode* ptr2 = root;
        
        while(ptr != nullptr){
            int now = ptr -> val;
            if(!st.count(now)){
                ptr2 -> next = new ListNode(now);
                ptr2 = ptr2 -> next;
            }
            ptr = ptr->next;
        }
        root = root -> next;
        return root;
    }
};