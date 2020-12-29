/**
 * circular linked lists
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */


/**
 * doubly linked lists
 * 
 * 
 * 
 * 
 * 
 */
#include <stdlib.h>


typedef struct CListNode {
    int data;
    c_list_node * next;
    c_list_node * prev;
} c_list_node;



/**
 * prints a linked list, started at the given "head" node
 *
 */
void print_c_ll(c_list_node * head) {
    c_list_node *current = head;
    while(1) {
        printf("\n%d", current->data);
        current = current->next;
        if(&current == &head) {
            break;
        }
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
int c_ll_len(c_list_node * head) {
    if (head == NULL) {
        return 0;
    }
    c_list_node *current = head;
    int count = 0;
    while(1) {
        count ++;
        current = current->next;
        if (&current == &head) {
            break;
        }
    }
    return count;
}


c_list_node * c_ll_create(int data) {
    c_list_node * new_node = (c_list_node *)malloc(sizeof(c_list_node));
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
c_list_node * ll_insert_front(c_list_node * head, int data) {
    
    // create and initialize the new node
    c_list_node * new_node = c_ll_create(data);

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
c_list_node * c_ll_delete_front(c_list_node * head) {
    c_list_node * temp = head;
    head = head->next;
    head->prev = temp->prev;
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
c_list_node * c_ll_insert_end(c_list_node * head, int data) {

    // create and initialize the new node
    c_list_node * new_node = c_ll_create(data);

    if (head == NULL) {
        return new_node;
    }

    c_list_node * current = head;

    while(1) {
        current = current->next;
        if (&current->next == &head) {
            current->next = new_node;
            new_node->prev = current;
            break;
        }
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
c_list_node * c_ll_delete_end(c_list_node * head) {
    c_list_node * new_end;
    c_list_node * end = head;

    while(1) {
        new_end = end;
        end = end->next;
        if (&(end->next) == &head) {
            break;
        }
    }
    new_end->next = head;
    head->prev = new_end;
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
c_list_node * ll_insert_pos(c_list_node * head, int data, int pos) {
    
    // pos <= 1: insert at the front of the linked list
    if (pos <= 1) {
        return c_ll_insert_front(head, data);
    }

    c_list_node * new_node = c_ll_create(data);

    c_list_node * prev = head;
    c_list_node * next;

    while(1) {
        // return NULL (error) if we are going around in circles...
        if (&prev == &head) {
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
c_list_node * c_ll_delete_pos(c_list_node * head, int pos) {

    if (pos <= 1) {
        return c_ll_delete_front(head);
    }

    c_list_node * prev;
    c_list_node * del = head;
    c_list_node * next;

    while(1) {
        // ensure we are not going in circles ...
        if (&del == &head) {
            perror("c_ll_delete_pos: infinite search for position discovered, exiting now");
            exit(EXIT_FAILURE);
        }
        
        // when pos = 0 we have reached the desired location to 
        // delete the existing node
        if (pos == 0) {
            next = del->next;
            prev->next = next;
            next->prev = prev;
            free(del);
            return head;
        }
        prev = del;
        del = del->next;
    }
}
