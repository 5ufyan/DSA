#include "list_node.h"

// template class declaration
template <class T>
class DList {
private:
    list_node<T>* first, *current ;
    int size = 0;
public:
    DList();
    ~DList();
    bool add(T el);
    bool insert(T el, T after_el);
    bool remove(T el);
    bool clear();
    int getSize();
    T get(int loc);
};

// template class definition
template <class T>
DList<T>::DList() {
    first = current = NULL;

}

template <class T>
DList<T>::~DList() {
    list_node<T>* temp = first;
    while (temp != NULL)
    {
        first = temp->next;
        delete temp;
        temp = first;
    }
}

template <class T>
bool DList<T>::add(T el) {


    list_node<T>* temp = new list_node<T>;
    temp->data = el;
    if (first == NULL)
    {
        temp->prev = NULL;
        first = temp;
        current = temp;
    }
    else
    {
        current->next = temp;
        temp->prev = current;
        current = temp;
    }
    size++;
    return true;
}

template <class T>
bool DList<T>::insert(T el, T after_el) {
    list_node<T>* temp;
    temp = first;
    while (temp != NULL)
    {
        if (temp->data == after_el)
        {
            list_node<T>* newNode = new list_node<T>;
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next!=NULL)
            {
                newNode->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->data = el;
            size++;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template <class T>
bool DList<T>::remove(T el) {
    list_node<T>* temp = first;
    list_node<T>* newNode = NULL;


    while (temp != NULL && temp->data != el) {
        newNode = temp;
        temp = temp->next;
    }


    if (temp != NULL) {

        if (temp == first) {
            first = temp->next;
        }

        else {
            newNode->next = temp->next;
        }
        delete temp;
        size--;
        return true;
    }
    return false;
}

template <class T>
bool DList<T>::clear() {
    list_node<T>* temp = first;
    while (temp != NULL)
    {
        first = temp->next;
        delete temp;
        temp = first;
    }
    size = 0;
    return true;
}

template <class T>
int DList<T>::getSize() {
    return size;
}

template <class T>
T DList<T>::get(int loc) 
{ 
    int i=0;

    list_node<T>* tmp = first;

    while (i < loc && tmp != NULL) {

        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL)

        throw 100;

    return tmp->data;
    

}

