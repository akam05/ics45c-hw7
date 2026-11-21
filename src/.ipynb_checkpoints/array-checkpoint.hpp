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

#endif