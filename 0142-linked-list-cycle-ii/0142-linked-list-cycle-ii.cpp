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
        map<ListNode*, int> mp;
        ListNode * curr = head;
        int idx =0;
        while(curr != nullptr){
            if( mp.find(curr)!=mp.end()){
                return curr;
            }
            mp.insert(pair<ListNode*, int> (curr, idx));
            idx++;
            curr = curr->next;
        }
        return curr;
        
    }
};