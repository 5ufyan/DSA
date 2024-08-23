#include <iostream>
#include <cstddef>

// template class declaration
template <class T>
class Array{
private:
    int size, index;
    T *arr;
public:
    Array(int size);
    ~Array();
    bool insert(int loc, T el);
    bool add(T el);
    int del(T el);
    int search(T el);
    void clear();
    int getSize();
    T get(int index);
};

// template class definition
template <class T>
Array<T>::Array(int size){
    this->size=size;
    index=-1;
    arr=new T[size];
}

template <class T>
Array<T>::~Array(){
    delete []arr;
    index=-1;
    size=0;
}

template <class T>
bool Array<T>::insert(int loc, T el){
    if( arr!=NULL && loc>=0 && loc<=index && index!=size-1 ){
        //shift right all elements from loc to index
        for(int i=index;i>=loc;--i){
            arr[i+1]=arr[i];
        }
        arr[loc]=el;
        ++index;
        return true;
    }else{
        return false;
    }
}

template <class T>
bool Array<T>::add(T el){
    if( arr!=NULL && index!=size-1 ){
        arr[++index]=el;
        return true;
    }else{
        return false;
    }
}

template <class T>
int Array<T>::del(T el){
    if( arr!=NULL ){
        int loc=search(el);
        if( loc!=-1 ){
            for(int i=loc;i<=index;i++){
                arr[i]=arr[i+1];
            }
            --index;
            return true;
        }
        return false;
    }
}

template <class T>
int Array<T>::search(T el){
    for(int i=0;i<=index;++i){
        if( arr[i]==el ){
            return i;
        }
    }
    return -1;
}

template <class T>
void Array<T>::clear(){
    index=-1;
}

template <class T>
int Array<T>::getSize(){
    return size;
}

template <class T>
T Array<T>::get(int loc){
    if( loc>index ){
        throw loc;
    }
    return arr[loc];
}
