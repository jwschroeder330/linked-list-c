/**
 * doubly linked lists
 * 
 * 
 * 
 * 
 * 
 */
#include <stdlib.h>


typedef struct DListNode {
    int data;
    d_list_node * next;
    d_list_node * prev;
} d_list_node;



/**
 * prints a linked list, started at the given "head" node
 *
 */
void print_d_ll(d_list_node * head) {
    d_list_node *current = head;
    while(1) {
        if(current == NULL) {
            break;
        }
        printf("\n%d", current->data);
        current = current->next;
    }
}


/**
 * calculates the number of nodes in a linked list starting
 * from the given "head" node
 * 
 * time complexity: O(n)
 * 
 * 
 */
int d_ll_len(d_list_node * head) {
    d_list_node *current = head;
    int count = 0;
    while(1) {
        if (current == NULL) {
            break;
        }
        count ++;
        current = current->next;
    }
    return count;
}


d_list_node * d_ll_create(int data) {
    d_list_node * new_node = (d_list_node *)malloc(sizeof(d_list_node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


/**
 * initialize a new node, and point it at the existing head node
 * 
 * returns the new node as the new head node
 * 
 * time complexity: O(1)
 * 
 * space complexity: O(1)
 *
 */
d_list_node * ll_insert_front(d_list_node * head, int data) {
    
    // create and initialize the new node
    d_list_node * new_node = d_ll_create(data);

    // if the head node is valid (not NULL) place it second in line
    // behind the newly created node
    if (head != NULL) {
        new_node->next = head;
        head->prev = new_node;
    }
    return new_node;
}

/**
 * 
 * time complexity: O(n)
 * 
 * space complexity: O(1)
 * 
 * 
 */
d_list_node * d_ll_delete_front(d_list_node * head) {
    d_list_node * temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}


/**
 * 
 * 
 * time complexity: O(n)
 * 
 * space complexity: O(1)
 * 
 * 
 */ 
d_list_node * d_ll_insert_end(d_list_node * head, int data) {

    // create and initialize the new node
    d_list_node * new_node = d_ll_create(data);

    if (head == NULL) {
        return new_node;
    }

    d_list_node * current = head;

    while(1) {
        if (current->next == NULL) {
            current->next = new_node;
            new_node->prev = current;
            break;
        }
        current = current->next;
    }

    return head;
}


/**
 * 
 * time complexity: O(n)
 * 
 * space complexity: O(1)
 * 
 * 
 */
d_list_node * d_ll_delete_end(d_list_node * head) {

    d_list_node * new_end;
    d_list_node * end = head;

    while(1) {
        if (end == NULL) {
            break;
        }
        new_end = end;
        end = end->next;
    }

    new_end->next = NULL;
    free(end);
    return head;
}



/**
 * 
 * 
 * time complexity: O(n)
 * 
 * @note in the worst case, we may need to insert at the end
 * 
 * space complexity: O(1)
 * 
 * 
 */
d_list_node * ll_insert_pos(d_list_node * head, int data, int pos) {
    
    // pos <= 1: insert at the front of the linked list
    if (pos <= 1) {
        return d_ll_insert_front(head, data);
    }

    d_list_node * new_node = d_ll_create(data);

    d_list_node * prev = head;
    d_list_node * next;

    while(1) {
        // elements in the linked list should not be NULL
        // if we find one during this loop, return NULL to signify 
        // there has been an error
        if (prev == NULL) {
            return NULL;
        }
        
        // when pos = 0 we have reached the desired location to 
        // insert the new_node
        if (pos == 0) {
            
            // "prev" may be the last member in the linked list
            // "next" may not actually exist
            next = prev->next;
            if (next != NULL) {
                next->prev = new_node;
            }
            // set the new node to point to the new next node
            new_node->next = next;
            
            // set the now-previous node to point at the new node
            prev->next = new_node;
            new_node->prev = prev;  // and vice-versa

            return head;
        }

        // continue iterating "prev" forward until pos == 0
        prev = prev->next;
        pos --;
    }
}

/**
 * 
 * time complexity: O(n)
 * space complexity: O(1)
 * 
 * 
 */
d_list_node * d_ll_delete_pos(d_list_node * head, int pos) {

    if (pos <= 1) {
        return d_ll_delete_front(head);
    }

    d_list_node * prev;
    d_list_node * del = head;
    d_list_node * next;

    while(1) {
        // elements in the linked list should not be NULL
        // if we find one during this loop, return NULL to signify 
        // there has been an error
        if (del == NULL) {
            return NULL;
        }
        
        // when pos = 0 we have reached the desired location to 
        // delete the existing node
        if (pos == 0) {
            next = del->next;
            prev->next = next;
            if (next != NULL) {
                next->prev = prev;
            }
            free(del);
            return head;
        }

        prev = del;
        del = del->next;
    }
}

