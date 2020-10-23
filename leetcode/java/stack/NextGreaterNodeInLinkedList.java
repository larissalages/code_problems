/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 *
 * Problem : https://leetcode.com/problems/next-greater-node-in-linked-list/
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */
class NextGreaterNodeInLinkedList {
    public int[] nextLargerNodes(ListNode head) {
        ArrayList<Integer> data = new ArrayList<>();
        while(head != null) {
            data.add(head.val);
            head = head.next;
        }
        int[] out = new int[data.size()];
        
        Stack<Integer> indexStack = new Stack<>();
        for (int i=0; i<data.size(); i++) {
            while ( (!indexStack.isEmpty()) && (data.get(indexStack.peek()) < data.get(i)) )
                out[indexStack.pop()] = data.get(i);

            indexStack.push(i);
        }
        return out;
    }
}