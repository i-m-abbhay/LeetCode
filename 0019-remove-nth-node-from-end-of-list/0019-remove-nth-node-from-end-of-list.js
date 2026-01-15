/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    let curr=head;
    let totalNodes = 0;
    while(curr!==null){
        totalNodes++;
        curr=curr.next;
    }
    if(n===totalNodes){
        return head.next;
    }
    curr = head;
    for(let i = 0; i<totalNodes-n-1; i++){
        curr= curr.next;
    }
    curr.next = curr.next.next
    return head;
};