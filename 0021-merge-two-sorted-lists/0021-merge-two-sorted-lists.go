/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func min(a, b int) int{
    if a<b{
        return a
    }
    return b
}
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    if list1==nil && list2 == nil { return nil}
    
    dummy:= &ListNode{}
    curr:= dummy

    l1ptr := list1
    l2ptr := list2
    
    for l1ptr!=nil && l2ptr!=nil{
        if l1ptr.Val < l2ptr.Val {
            curr.Next=l1ptr
            l1ptr=l1ptr.Next
        } else {
            curr.Next = l2ptr
            l2ptr=l2ptr.Next
        }
        curr = curr.Next
    }
    if l1ptr!=nil{
        curr.Next = l1ptr
    } else {
        curr.Next = l2ptr
    }

    return dummy.Next
}