/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //without using floyd's double pointer approach
        //TC -> O(N)
        // map<ListNode*, int> mp;
        // ListNode * curr = head;
        // int idx =0;
        // while(curr != nullptr){
        //     if( mp.find(curr)!=mp.end()){
        //         return curr;
        //     }
        //     mp.insert(pair<ListNode*, int> (curr, idx));
        //     idx++;
        //     curr = curr->next;
        // }
        // return curr;

        if (!head || !head->next) return nullptr;

        // Phase A: detect if a cycle exists (find meeting point)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;           // +1 step
            fast = fast->next->next;     // +2 steps
            if (slow == fast) {          // cycle detected
                // Phase B: find the entry point of the cycle
                ListNode* p1 = head;
                ListNode* p2 = slow;     // meeting point
                while (p1 != p2) {
                    p1 = p1->next;       // both move +1
                    p2 = p2->next;
                }
                return p1;               // cycle entry
            }
        }
        return nullptr; // no cycle
    }
};