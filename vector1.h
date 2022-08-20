#include <iostream>
#include <exception>
#include "vector.hpp"

Vector::Vector() {
    m_cap = 1;
    m_size = 0;
    m_buf = new int[m_cap];
}

Vector::~Vector() {
    delete[] m_buf;
}

void Vector::push_back(int elem) {
    if (m_cap == m_size) {
        m_cap *= 2;
        int* tmp = new int[m_cap];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = m_buf[i];
        }
        delete[] m_buf;
        m_buf = tmp;
    }
    m_buf[m_size] = elem;
    ++m_size;
}

int Vector::capacity() {
    return m_cap;
}

int Vector::size() const {
    return m_size;
}

void Vector::pop_back() {
    m_size--;
}

void Vector::clear() {
    m_size = 0;
    m_cap = 1;
    delete[] m_buf;
    m_buf = nullptr;
}

bool Vector::empty() {
    if (m_size == 0) {
        std::cout << "vector is empty" << std::endl;
        return true;
    }
    else {
        std::cout << "vector is not empty" << std::endl;
        return false;
    }
}

int* Vector::data() {
    return m_buf;
}

int Vector::at(int index) {
    if (index >= m_size || index < 0) {
        throw std::out_of_range("out of range");
    }
      if (index < m_size && index >= 0) {
        return m_buf[index];
    }

}

int Vector::begin() {
    int index = m_buf[0];
    return index;
}

int Vector::end() {
    int index = m_buf[--m_size];
    return index;
}

void Vector::erase(int index) {
    if (index < m_size && index >= 0) {
        for (int i = index; i < m_size; ++i) {
            m_buf[i] = m_buf[i+1];
        }
        --m_size;
    }
    else
        throw std::out_of_range("out of range");
}

void Vector::shrink_to_fit() {
    if (m_size == m_cap) {
        return;
    }
    int* tmp = new int[m_size];
    for (int i = 0; i < m_size; ++i) {
        tmp[i] = m_buf[i];
    }
    delete[] m_buf;
    m_buf = tmp;
    m_cap = m_size;
    tmp = nullptr;
}

void Vector::insert(int index, int elem) {
    if (m_size < m_cap) {
        for (int i = m_size; i > index; --i) {
            m_buf[i] = m_buf[i-1];
        }
        m_buf[index] = elem;
    }
    else {
        m_cap *= 2;
        int* tmp = new int[m_cap];
        for (int i = 0; i < index; ++i) {
            tmp[i] = m_buf[i];
        }
        tmp[index] = elem;
        for (int i = 0; i < m_size; ++i) {
            tmp[i + 1] = m_buf[i];
        }
        delete[] m_buf;
        m_buf = tmp;
        tmp = nullptr;
    }
    ++m_size;
}
