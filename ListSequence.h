#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"
using namespace std;
template <typename T>
class ListSequence : public Sequence<T> {
protected:
    LinkedList<T>* list;
public:
    // Конструкторы
    ListSequence() {
        list = new LinkedList<T>;
    }
    
    ListSequence(T* items, int count) {
        list = new LinkedList<T>(items, count);
    }
    
    ListSequence(Sequence<T>* list) {
        this->list = new LinkedList<T>(((ListSequence<T>*)list)->list);
    }
    
    ListSequence(initializer_list<T> list) {
        this->list = new LinkedList<T>(list);
    }    
    
    ~ListSequence() {
        delete list;
    }
    
    // Декомпозиция
    T& GetFirst() {
        return this->list->GetFirst();
    }

    T& GetLast() {
        return this->list->GetLast();
    }

    T& Get(int index)  {
        return this->list->Get(index);
    }

    Sequence<T>* GetSubSequence(int startIndex, int endIndex) {
        LinkedList<T>* x = this->list->GetSubList(startIndex, endIndex);
        ListSequence<T>* resseq = new ListSequence<T>;
        delete resseq->list;
        resseq->list = x;
        return resseq;
    }

    int GetLength() {
        return this->list->GetLength();
    }
    
    // Операции
    Sequence<T>& Append(T item) {
        list->Append(item);
        return *this;
    }

    Sequence<T>& Prepend(T item) {
        list->Prepend(item);
        return *this;    
    }

    Sequence<T>& InsertAt(T item, int index) {
        list->InsertAt(item, index);
        return *this;    
    }
    
    Sequence<T>* Concat(Sequence<T>* seq) {
        LinkedList<T>* x = this->list->Concat(((ListSequence<T>*)seq)->list);
        ListSequence<T>* resseq = new ListSequence<T>;
        delete resseq->list;
        resseq->list = x;
        return resseq;
    }
};

#endif