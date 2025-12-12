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
    bool hasCycle(ListNode *head) {
        //Normal Solution
        // unordered_set<ListNode*> visited;
        // while(head!=nullptr){
        //     if(visited.count(head)) return true;
        //     visited.insert(head);
        //     head = head->next;
        // }
        // return false;

        //Floyds cycle detection
        if(!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast-> next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};