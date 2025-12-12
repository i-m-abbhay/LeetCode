/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    unordered_set<ListNode*> visited;
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        if(visited.count(head)) return true;
        visited.insert(head);
        return hasCycle(head->next);
    }
};