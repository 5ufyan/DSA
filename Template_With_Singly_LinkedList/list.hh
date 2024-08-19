#include "list_node.h"

// template class declaration
template <class T>
class List {
private:
    list_node<T>* start, * end;
    int size = 0;
public:
    List();
    ~List();
    bool add(T el);
    bool insert(T el, T after_el);
    bool remove(T el);
    bool clear();
    int getSize();
    T get(int loc);
};

// template class definition
template <class T>
List<T>::List() {
    start = end = NULL;

}

template <class T>
List<T>::~List() {
    list_node<T>* temp = start;
    while (temp != NULL)
    {
        start = temp->next;
        delete temp;
        temp = start;
    }
}

template <class T>
bool List<T>::add(T el) {


    list_node<T>* temp = new list_node<T>;
    temp->data = el;
    if (start == NULL)
    {
        temp->next = NULL;
        start = temp;
        end = temp;
    }
    else
    {
        temp->next = NULL;
        end->next = temp;
        end = temp;
    }
    size++;
    return true;
}

template <class T>
bool List<T>::insert(T el, T after_el) {
    list_node<T>* temp;
    temp = start;
    while (temp != NULL)
    {
        if (temp->data == after_el)
        {
            list_node<T>* newNode = new list_node<T>;
            newNode->next = temp->next;
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
bool List<T>::remove(T el) {
    list_node<T>* temp = start;
    list_node<T>* newNode = NULL;


    while (temp != NULL && temp->data != el) {
        newNode = temp;
        temp = temp->next;
    }


    if (temp != NULL) {

        if (temp == start) {
            start = temp->next;
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
bool List<T>::clear() {
    list_node<T>* temp = start;
    while (temp != NULL)
    {
        start = temp->next;
        delete temp;
        temp = start;
    }
    size = 0;
    return true;
}

template <class T>
int List<T>::getSize() {
    return size;
}

template <class T>
T List<T>::get(int loc) 
{ 
    int i=0;

    list_node<T>* tmp = start;

    while (i < loc && tmp != NULL) {

        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL)

        throw 100;

    return tmp->data;
    

}

