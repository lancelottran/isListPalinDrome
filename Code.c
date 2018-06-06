//
// Definition for singly-linked list:
// typedef struct list_##name {
//   type value;
//   struct list_##name *next;
// } list_##name;
//
// list_##name *alloc_list_##name(type v) {
//   list_##name *l = calloc(1, sizeof(list_##name));
//   l->value = v;
//   return l;
// }
//
//
void reverse(list_integer ** l){
    list_integer * next;
    list_integer * prev;
    list_integer * curr = *l;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    *l = prev;
}

bool compare(list_integer * l1, list_integer * l2){
    while(l2){    
        if(l1->value == l2->value){            
            l1 = l1->next;
            l2 = l2->next;
        }
        else{
            printf("%d %d", l1->value, l2->value);   
            return false;
        }
    }
    

    return true;
}

bool isListPalindrome(list_integer * l) {
    list_integer * slow = l;
    list_integer * fast = l;
    list_integer * head = l;
    
    if(l == NULL || l->next == NULL)
        return true;
    
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    if(fast != NULL){
        slow = slow->next;
    }
    
    reverse(&slow);
    
    bool res = compare(head, slow);
    
    return res;
}
