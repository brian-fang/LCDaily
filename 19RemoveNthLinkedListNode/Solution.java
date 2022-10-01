

public class Solution {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }

        static ListNode build(int[] arr) {
            if(arr.length == 0) return null;
            ListNode head = new ListNode(arr[0]), cur = head;
            for(int i = 1; i < arr.length; i++) {
                cur.next = new ListNode(arr[i]);
                cur = cur.next;
            }
            return head;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            ListNode cur = this;
            sb.append('[');
            while(cur != null) {
                sb.append(cur.val);
                if(cur.next != null) sb.append(',');
                cur = cur.next;
            }
            sb.append(']');
            return sb.toString();
        }
    }





    public static ListNode removeNth(ListNode head, int n) {
        // use dummy to simplify corner cases
        ListNode dummy = new ListNode(0, head), slow = dummy, fast = head;

        for(int i = 0; i < n; i++) fast = fast.next; // appropriate spacing between slow and fast
        // so that when fast becomes null, slow is the node before the one to be removed

        while(fast != null) {
            slow = slow.next;
            fast = fast.next;
        }

        // slow is now the node before the one to be removed
        slow.next = slow.next.next;

        return dummy.next;
    }


    public static void main(String[] argv) {
        
        ListNode lst = ListNode.build(new int[] {1,2,3,4,5});

        System.out.println(lst);

        removeNth(lst, 3);

        System.out.println(lst);

    }
}
