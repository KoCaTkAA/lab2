#include <iostream>
#include "Exception.h"
using namespace std;

template <typename T>
class DynamicArray{
    private:
        T* items = nullptr;
        int size = 0;
    public:

        // Конструкторы
        DynamicArray() {
            items = nullptr;
        }

        DynamicArray(int count) {
            if (count < 0) throw SetException(SizeBelowZero);
            try {
                items = new T[count];
            }
            catch (bad_alloc) {
               throw SetException(MemoryAllocateError);
            }
            size = count;
        }

        DynamicArray(T* items, int count) {
            if (count < 0) throw SetException(SizeBelowZero);
            try {
                this->items = new T[count];
            }
            catch (std::bad_alloc) {
                throw SetException(MemoryAllocateError);
            }
            size = count;
            for (int i = 0; i < size; i++) {
                this->items[i] = items[i];
            }
        }

        DynamicArray(DynamicArray<T>* dynamic_array) {
            try {
                items = new T[dynamic_array->GetSize()];
            }
            catch (std::bad_alloc) {
                throw SetException(MemoryAllocateError);
            }
            size = dynamic_array -> size;
            for (int i = 0; i < size; i++) {
                this->items[i] = dynamic_array -> items[i];
            }
        }

        DynamicArray(initializer_list<T> list) :DynamicArray(int(list.size())) {
            int j = 0;
            for (auto i : list) {
                this->items[j] = i;
                j++;
            }
        }

        // Деструктор
        ~DynamicArray() {
            delete[] this->items;
        }

        // Декомпозиция
        T& Get(int index) {
            if (index >= size || index < 0) {
                throw SetException(IndexOutOfRange);
            }
            return items[index];
        }

        int GetSize() {
            return size;
        }

        // Операции
        void Set(int index, T value) {
            if (index >= this->size || index < 0) {
                throw SetException(IndexOutOfRange);
            }
            items[index] = value;
        }

        void Resize(int NewSize) {
            if (NewSize < 0) {
                throw SetException(SizeBelowZero);
            }
            try {
                T* items_cur = new T[NewSize];
                int cpy_num = (NewSize > size ? size : NewSize);
                memcpy(items_cur, items, cpy_num * sizeof(T));
                delete[] items;
                items = items_cur;
                size = NewSize;
            }
            catch (std::bad_alloc) {
                throw SetException(MemoryAllocateError);
            }
        }

        void Append(T item) {
            this->Resize(size + 1);
            this->Set(size - 1, item);
        }

        void Prepend(T item) {
            this->Resize(size + 1);
            memmove(this->items + 1, this->items, (size - 1) * sizeof(T));
            this->Set(0, item);
        }

        void InsertAt(T item, int index) {
            if (index >= this->size || index < 0) {
                throw SetException(IndexOutOfRange);
            }
            this->Resize(size + 1);
            memmove(this->items + (index + 1), this->items + (index), (size - 1 - index) * sizeof(T));
            this->Set(index, item);
        }

        DynamicArray<T>* GetSubArray(int startIndex, int endIndex) {
            if (startIndex >= this->size || startIndex < 0 || endIndex >= this->size || endIndex < 0) {
                throw SetException(IndexOutOfRange);
            }
            if (endIndex < startIndex) {
                throw SetException(NegativeRange);
            }
            DynamicArray<T>* res = new DynamicArray<T>;
            for (int i = startIndex; i <= endIndex; i++) {
                res->Append(this->Get(i));
            }
            return res;
        }

        DynamicArray<T>* Concat(DynamicArray<T>* arr) {
            DynamicArray<T>* res = new DynamicArray<T>;
            for (int i = 0; i < size; i++) {
                res->Append(this->Get(i));
            }
            for (int i = 0; i < arr->GetSize(); i++) {
                res->Append(arr->Get(i));
            }
            return res;
        }

        T& operator[] (int index) {
            return this -> Get(index);
        }





};