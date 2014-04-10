//
//  Very simple list class for practicing list algorithms, not intended for
//  production.
//
//  Created by Stewart Bracken on 12/4/13.
//  Copyright (c) 2013 Stewart Bracken. All rights reserved.
//

#ifndef InterviewPractice_List_h
#define InterviewPractice_List_h

template <class T>
class List {
    template <class U>
    class Node{
        friend class List<T>;
        T data;
        Node<U>* next;
        Node(U _data):data(_data), next(0){
        }
    };
    typedef Node<T> Node_t;
    Node_t* head;
    Node_t* tail;
public:
    List() : head(0),tail(0) {};
    ~List<T>();
    void insert_back(T data);
    void insert_front(T data);
    //Skip k, then reverse k. Repeat until end.
    void reverse_k(T k);
    void print() const;
};

#endif
