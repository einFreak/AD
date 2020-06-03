#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class list_element
{
public:
    int val;
    list_element *next;
};


class linked_list
{
private:
    list_element *head; // Zeiger auf den Anfang
    list_element *tail; // Zeiger auf das Ende
    int list_size;

    list_element *Quicksort_List (list_element *q_head, list_element *q_tail);
    list_element *Partition_List(list_element *l_head, list_element *l_tail, list_element **new_head, list_element **new_tail);

public:
    linked_list();
    ~linked_list();
    void Append(int o); // Fügt einen Wert hinzu
    void DeleteList(list_element *first); // Liste entfernen
    void DeleteValue(int o); // Wert entfernen
    void Print(); // Liste ausgeben
    void Quicksort_List();

};

#endif // LINKED_LIST_H
