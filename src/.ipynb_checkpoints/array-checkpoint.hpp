#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

// Forward declaration for friend functions
template <typename T>
class Array;

template <typename T>
void swap(Array<T>& lhs, Array<T>& rhs) noexcept;

template <typename T>
class Array {
public:
    Array();
    explicit Array(int len);

    Array(const Array& other);
    Array(Array&& other) noexcept;

    friend void swap<>(Array<T>& lhs, Array<T>& rhs) noexcept;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    ~Array();

    int length() const;

    T& operator[](int index);
    const T& operator[](int index) const;

    void fill(const T& val);

    template <typename Fn>
    void fill_with_fn(Fn fn);

private:
    int len;
    T* buf;

    bool in_bounds(int index) const;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array);

template <typename T>
std::istream& operator>>(std::istream& in, Array<T>& array);

// ... definitions follow, each preceded by template <typename T>
template <typename T>
Array<T>::Array() : len{0}, buf{nullptr} {
}

template <typename T>
Array<T>::Array(int len) : len{len}, buf{new int[len]} {
}

// copy constructor
template <typename T>
Array<T>::Array(const Array& other) : len{other.len}, buf{new int[other.len]} {
    for (int i = 0; i < len; i++) {
        buf[i] = other.buf[i];
    }
}

// move constructor
template <typename T>
Array<T>::Array(Array&& other) : Array() {
    std::swap(len, other.len);
    std::swap(buf, other.buf);
}

// friend void swap(Array& lhs, Array& rhs) noexcept
template <typename T>
friend void Array<T>::swap(Array& lhs, Array& rhs) noexcept {
    std::swap(lhs.len, rhs.len);
    std::swap(lhs.buf, rhs.buf);
}

// copy assignment
template <typename T>
Array& Array<T>::operator=(const Array& other) {
    Array copy(other);
    swap(*this, copy);
    return *this;
}

// move assignment
template <typename T>
Array& Array<T>::operator=(Array&& other) {
    if (this != &other) {
        Array temp;
        swap(*this, other); 
        swap(other, temp);
    }
    return *this;
}

// destructor
template <typename T>
Array<T>::~Array() {
    delete[] buf;
}

template <typename T>
int Array<T>::length() const {
    return len;
}

template <typename T>
int Array<T>::length() const {
        return len;
    }

template <typename T>
int& Array<T>::operator[](int index) {
    if (!in_bounds(index)) {
        throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
    }
    return buf[index];
}

template <typename T>
const int& Array<T>::operator[](int index) const {
    if (!in_bounds(index)) {
        throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
    }
    return buf[index];
}

template <typename T>
void Array<T>::fill(int val) {
    for (int i = 0; i < len; i++) {
        buf[i] = val;
    }
}

#endif