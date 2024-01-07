# Implementation of Red Black Tree

## Interface of my dictionary
This is a single map interface, complete with copy constructors, constructors, and destructors. It supports insertion, finding, and deletion of elements in O(log n) time, as expected, and is scalable to large sizes. Just like STL, subscript creates a key with value 0 if not created and just changes or finds the value (it can be changed or used as Lvalue) corresponding to the key. Whereas at() operator will throw an exception and terminate the code if the key does not exist, and insert() will do so if the key does. remove() operator is the STL erase() and will throw an exception if the key does not exist in the structure.

This does not directly support sets, multisets, or multimaps. Instead, for sets, the value can be a boolean datatype, and for multiset, an integer type (number of occurrences), with first addition with value 1 and addition or subtraction of 1 to the value on subsequent insertion or deletion, and deletion of key when the value reaches 0. For multimaps, the value datatype can be a vector of datatypes. These are workarounds for the aforementioned data structures, if needed.

The ordering in the inbuilt Red Black Tree is based on the key alone, as expected. This does not support comparator overloading for key datatype (unlike STL map) and comparisons like ==, < across two different dictionaries. Further, it will not work for partially ordered or unordered datatypes since it is not a hashmap. It requires fully ordered types, preferably integer, floating, string, std::pair or std::tuple datatypes as keys. There are no restrictions on the value datatypes.

The iterators behave slightly differently from STL iterators but are meant to iterate linearly as though it is a vector. They do retain their position after insertion or deletion, although accessing an iterator after the deletion of that node is dangerous. Note that there is no reverse iterator, but we can start from end() and go -- (backward) instead of ++ (forward). It supports jump-across-n-elements (+= and -= operators) too.

The function end() serves as the STL rbegin() and is the largest (by ordering) element in the dictionary, while begin() is the smallest. Once an iterator crosses the bounds of the dictionary, it cannot be used anymore, nor can it reach the dictionary. At that stage, it becomes a null iterator. There is no equivalent of STL end() or rend() from which the iterator can go back to the (largest) element in the dictionary.

```
template <typename T, typename U> 
class dict {
    dict();
    ~dict();
    operator = (dict& Oth); 
    dict(dict& Oth);

    void insert(T key, U val);
    U& at(T key);
    U remove(T key); // return val;
    U& operator [] (T key);
    int size();
    bool empty();
    iterator find(T key);
    iterator begin();
    iterator end();

    class iterator {
        T& key();
        U& val();
        operator ++, --, += (int), -= (int);
        bool isBegin();
        bool isEnd();
        bool isNull(); 
    };
};
```

Run the following command to compile and execute a test code for the red black tree implementation provided. 
```
make
```

## Results on Macbook Air, M1
* Time taken for my dictionary: 26.30236487 seconds
* Time taken for STL map: 47.51094642 seconds

This was over a sample of 10 million (precisely 9999901) entries being inserted once at a random, iterated through, and deleted at the end. The ordering is verified. Further, the execution time is compared with the corresponding time for the STL map, and the above results were observed. In general, this dict is faster.
