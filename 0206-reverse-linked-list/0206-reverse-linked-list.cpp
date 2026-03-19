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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head; // 1* 2 3 4 5
        ListNode* prev = nullptr; // null
        while(curr!=nullptr){
            ListNode* next = curr->next; // 2
            curr->next = prev; //
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
