#ifndef INT_ARRAY_HPP
#define INT_ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>

class Array {
public:
    Array() : len{0}, buf{nullptr} {
    }

    explicit Array(int len) : len{len}, buf{new int[len]} {
    }

    // copy constructor
    Array(const Array& other) : len{other.len}, buf{new int[other.len]} {
        for (int i = 0; i < len; i++) {
            buf[i] = other.buf[i];
        }
    }

    // move constructor
    Array(Array&& other) : Array() {
        std::swap(len, other.len);
        std::swap(buf, other.buf);
    }

    // friend void swap(Array& lhs, Array& rhs) noexcept
    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

    // copy assignment
    Array& operator=(const Array& other) {
        Array copy(other);
        swap(*this, copy);
        return *this;
    }
    
    // move assignment
    Array& operator=(Array&& other) {
        swap(*this, copy);
        return *this;
    }
    // destructor
    ~Array() {
        delete[] buf;
    }

    int length() const {
        return len;
    }

    int& operator[](int index) {
        if (!in_bounds(index)) {
            throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
        }
        return buf[index];
    }

    const int& operator[](int index) const {
        if (!in_bounds(index)) {
            throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
        }
        return buf[index];
    }

    void fill(int val) {
        for (int i = 0; i < len; i++) {
            buf[i] = val;
        }
    }

private:
    int len;
    int* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

inline std::ostream& operator<<(std::ostream& out, const Array& array) {
    std::stringstream temp;
    // We don't want to set formatting flags globally.
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}

inline std::istream& operator>>(std::istream& in, Array& array) {
    for (int i = 0; i < array.length(); ++i) {
        in >> array[i];
    }

    return in;
}

#endif
