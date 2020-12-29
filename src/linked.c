/**
 * singly linked list library
 * 
 * 
 * 
 * 
 *
 * 
 * 
 * 
 * 
 * Sourced from "Algorithms Made Easy"
 */
#include <stdlib.h>


typedef struct ListNode {
    int data;
    struct list_node * next;
} list_node;


/**
 * prints a linked list, started at the given "head" node
 *
 */
void print_ll(list_node * head) {
    list_node *current = head;
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
int ll_len(list_node * head) {
    list_node *current = head;
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


list_node * ll_create(int data) {
    list_node * new_node = (list_node *)malloc(sizeof(list_node));
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
list_node * ll_insert_front(list_node * head, int data) {
    
    // create and initialize the new node
    list_node * new_node = ll_create(data);

    // if the head node is valid (not NULL) place it second in line
    // behind the newly created node
    if (head != NULL) {
        new_node->next = head;
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
list_node * ll_delete_front(list_node * head) {
    list_node * temp = head;
    head = head->next;
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
list_node * ll_insert_end(list_node * head, int data) {

    // create and initialize the new node
    list_node * new_node = ll_create(data);

    if (head == NULL) {
        return new_node;
    }

    list_node * current = head;

    while(1) {
        if (current->next == NULL) {
            current->next = new_node;
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
list_node * ll_delete_end(list_node * head) {

    list_node * new_end;
    list_node * end = head;

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
list_node * ll_insert_pos(list_node * head, int data, int pos) {
    
    // pos <= 1: insert at the front of the linked list
    if (pos <= 1) {
        return ll_insert_front(head, data);
    }

    list_node * new_node = ll_create(data);

    list_node * prev = head;

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
            // insert the new node after "prev" - the calculated 
            // previous node based on the given position, pos
            new_node->next = prev->next;
            prev->next = new_node;
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
list_node * ll_delete_pos(list_node * head, int pos) {

    if (pos <= 1) {
        return ll_delete_front(head);
    }

    list_node * prev;
    list_node * del = head;

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
            prev->next = del->next;
            free(del);
            return head;
        }

        prev = del;
        del = del->next;
    }
}