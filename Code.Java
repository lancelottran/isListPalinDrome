// Definition for singly-linked list:
// class ListNode<T> {
//   ListNode(T x) {
//     value = x;
//   }
//   T value;
//   ListNode<T> next;
// }
//

boolean isListPalindrome(ListNode<Integer> l) {
    ListNode<Integer> head = l;
    ListNode<Integer> fast = l;
    ListNode<Integer> slow = l;
    
    if(l == null || l.next == null)
        return true;
    
    while(fast != null && fast.next != null)
    {
        fast = fast.next.next;
        slow = slow.next;
    }
    

    if(fast != null)
       slow = slow.next;
    
    slow = reverse(slow);
    
    while(slow != null  && head != null)
    {
        if(!slow.value.equals(head.value))
        {
            return false;
        }
        else{
            slow = slow.next;
            head = head.next;
        }
    }
    
    return true;
}

ListNode reverse(ListNode<Integer> mid){
    ListNode<Integer> prev = null;
    ListNode<Integer> next = null;
    ListNode<Integer> curr = mid;
    
    while(curr != null){
        next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }
    
    mid= prev;
    
    return mid;
}
