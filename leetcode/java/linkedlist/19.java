/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(n==0 || head==null)
            return head;
        if(n==1 && head.next==null)
            return null;
        
        ListNode fast=head;
        ListNode slow=head;
        while(n-->0)
            fast=fast.next;
        if(fast==null)
            return slow.next;
        while(fast.next!=null)
        {
            fast=fast.next;
            slow=slow.next;
        }
        
        ListNode fwd=slow.next;
        slow.next=fwd.next;
        fwd.next=null;
        
        return head;
    } 
    
}
