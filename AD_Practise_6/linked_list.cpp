#include "linked_list.h"
#include <iostream>
#include <cstddef>

linked_list::~linked_list() {
    DeleteList(head);
    head=NULL; tail=NULL;
}

linked_list::linked_list() {
    head=NULL;
    tail=NULL;
    list_size = 0;
}

void linked_list::Append(int o) {
    list_element *elem=new list_element;
    elem->val=o;
    elem->next=NULL;
    if (tail==NULL) {
        head=elem;
        tail=elem;
    }
    else {
        tail->next=elem;
        tail=elem;
    }
    list_size++;
}

void linked_list::DeleteList(list_element *first) {
    if (first != NULL) {
            if (first->next != NULL)
                DeleteList(first->next);

    delete first; }
}

void linked_list::DeleteValue(int o) {
    list_element *curr=head, *prev=NULL;
    while (curr!=NULL) {
        if (curr->val==o) {
            if (prev==NULL)
                head=curr->next;
            else
                prev->next=curr->next;

            if (curr==tail)
                tail=prev;

            list_element *h=curr;
            curr=curr->next;
            delete h;
            list_size--;
        }
        else {
            prev=curr;
            curr=curr->next;
        }
    }
}

void linked_list::Print() {
    list_element *curr=head;

    while (curr!=NULL) {
        std::cout<<curr->val<<" ";
        curr=curr->next;
    }
    std::cout<<std::endl;
    std::cout<<"size: "<<list_size<<std::endl;
}


list_element *linked_list::Partition_List(list_element *l_head, list_element *l_tail, list_element **new_head, list_element **new_tail) {
    std::cout<<"Entering PL"<<std::endl;
    list_element *pivot = l_tail;
    list_element *prev  = NULL;
    list_element *cur   = l_head;
    list_element *tail  = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->val < pivot->val)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*new_head) == NULL)
                (*new_head) = cur;

            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            list_element *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot val is the smallest element in the current list,
    // pivot becomes the head
    if ((*new_head) == NULL)
        (*new_head) = pivot;

    // Update newEnd to the current last node
    (*new_tail) = tail;

    // Return the pivot node
    return pivot;
}

list_element *linked_list::Quicksort_List (list_element *q_head, list_element *q_tail) {


    //wenn nur ein Element return bzw sortiert
    if (!q_head || q_head == q_tail)
        return q_head;


    linked_list new_liste;
    //Partition the list
    list_element *pivot = Partition_List(q_head, q_tail, &new_liste.head, &new_liste.tail);

    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (new_liste.head != pivot)
    {
        // Set the node before the pivot node as NULL
        list_element *tmp = new_liste.head;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot
        new_liste.head = Quicksort_List(new_liste.head, tmp);

        // Change next of last node of the left half to pivot
        while (tmp != NULL && tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = pivot;
    }

    // Recur for the list after the pivot element
    pivot->next = Quicksort_List(pivot->next, new_liste.tail);

    q_head = new_liste.head;
    return 0;
}

void linked_list::Quicksort_List () {
    std::cout<<"Entering QS"<<std::endl;
    Quicksort_List(head, tail);
    std::cout<<"Exit QS"<<std::endl;
    return;
}
