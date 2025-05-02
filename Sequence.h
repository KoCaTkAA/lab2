#ifndef SEQUENCE_H
#define SEQUENCE_H

template <typename T>
class Sequence {
public:
    virtual ~Sequence() = default;
    
    // Декомпозиция
    virtual T& GetFirst() = 0;
    virtual T& GetLast() = 0;
    virtual T& Get(int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;
    
    // Операции
    virtual Sequence<T>& Append(T item) = 0;
    virtual Sequence<T>& Prepend(T item) = 0;
    virtual Sequence<T>& InsertAt(T item, int index) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
    
    // Map-reduce (попробуем реализовать)
    /*
    virtual Sequence<T>* Where(bool (*predicate)(T)) = 0;
    virtual Sequence<T>* Map(T (*function)(T)) = 0;
    template <typename U>
    virtual U Reduce(U (*function)(U, T), U initialValue) = 0;
    virtual Sequence<T>* Zip(Sequence<T>* other, T (*function)(T, T)) = 0;
    virtual pair<Sequence<T>*, Sequence<T>*> Unzip(bool (*predicate)(T)) = 0;
    */
};

#endif