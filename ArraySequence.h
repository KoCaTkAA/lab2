#include "DynamicArray.h"
#include "Sequence.h"
using namespace std;

template <typename T>
class ArraySequence : public Sequence<T> {
protected:
    DynamicArray<T>* array;

public:
    // Конструкторы

    ArraySequence() {
        array = new DynamicArray<T>();
    }

    ArraySequence(T* items, int count) {
        array = new DynamicArray<T>(items, count)
    }
    
    ArraySequence(Sequence<T>* array) {
        this->array = new DynamicArray<T>(((ArraySequence<T>*)array)->array);
    }
    
    ArraySequence(initializer_list<T> list) {
        this->array = new DynamicArray<T>(list);
    }
    
    // Деструктор
    ~ArraySequence() {
        delete array;
    }
    
    // Декомпозиция
    T& GetFirst() override {
        return array->Get(0);
    }
    
    T& GetLast() override {
        return array->Get(array->GetSize() - 1);
    }
    
    T& Get(int index) override {
        return array->Get(index);
    }
    
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        if (startIndex < 0 || endIndex >= array->GetSize() || startIndex > endIndex) {
            throw IndexOutOfRange();
        }
        
        ArraySequence<T>* subsequence = new ArraySequence<T>();
        for (int i = startIndex; i <= endIndex; ++i) {
            subsequence->Append(items->Get(i));
        }
        return subsequence;
    }
    
    int GetLength() override {
        return array->GetSize();
    }
    
    // Операции
    void Append(T item) override {
        arraySequence *res = Instance();
        res->array->Append(item);
        return res;
    }

    void Prepend(T item) override {
        array->Prepend(item);
    }
    
    void InsertAt(T item, int index) override {
        array->InsertAt(item, index);
    }
    
    Sequence<T>* Concat(Sequence<T>* seq)  {
        DynamicArray<T>* x = this->array->Concat(((ArraySequence<T>*)seq)->array);
        ArraySequence<T>* resseq = new ArraySequence<T>;
        delete resseq->array;
        resseq->array = x;
        return resseq;
    }
    
    // Функциональные операции
};