#include <iostream>

#ifndef vector
#define vector

class Vector {

public:
    Vector();
    ~Vector();

public:
    void clear();
    void shrink_to_fit();
    int* data();
    int capacity();
    void erase(int);
    int size() const;
    void insert(int,int);
    int begin();
    int end();
    bool empty();
    void push_back(int);
    int at(int);
    void pop_back();

private:
    int m_cap;
    int m_size;
    int* m_buf;
};

#endif //vector
