# Implementation of Red Black Tree

## Interface of STL Map
This is a single map interface.

```
class dict<T, U> {
    dict();
    ~dict();
    operator = (dict& Oth); 
    dict(dict& Oth);

    void insert(T key, U val);
    U& at(T key);
    U remove(T key); // Return val
    U& operator [] (T key); // Subscript
    int size();
    bool empty();
    iterator find(T key);
    iterator begin();
    iterator end();

    class iterator {
        T& key();
        U& val();
        operator ++, --, += (int), -= (int);
        isBegin();
        isEnd();
        isNull();
    }; // ONLY FORWARD ITERATOR. END = LAST ELEMENT IN DICT
};

Run the following command to compile and execute a test code for the red black tree implementation provided.
```
make
```

## Results on Macbook Air, M1
Time taken for my dictionary: 26.30236487

Time taken for STL map: 47.51094642
