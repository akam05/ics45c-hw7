#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

#include "array.hpp"

template <typename T>
class Matrix {
public:
    Matrix();
    Matrix(int rows, int cols);

    Array<T>& operator[](int row);
    const Array<T>& operator[](int row) const;

    int num_rows() const;
    int num_cols() const;

    void fill(const T& val);

    template <typename Fn>
    void fill_with_fn(Fn fn);

private:
    int rows, cols;
    Array<Array<T>> data;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix);

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix);

// ... definitions follow
template <typename T>
Matrix<T>::Matrix() : rows{0}, cols{0}, data{} 
{
}

template <typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols), data {rows}
{
    for (int i =0; i < rows; i++) 
    {
        data[i] = Array<T>(cols);
    }
}

template <typename T>
Array<T>& Matrix<T>::operator[](int row) {
    return data[row];
}

template <typename T>
const Array<T>& Matrix<T>::operator[](int row) const {
    return data[row];
}

template <typename T>
int Matrix<T>::num_rows() const {
    return rows;   
}
template <typename T>
int Matrix<T>::num_cols() const {
    return cols;
}

template <typename T>
void Matrix<T>::fill(const T& val) {
    for (int i = 0; i < rows; i++) {
        data[i].fill(val);
    }
}

template <typename T>
template <typename Fn>
void Matrix<T>::fill_with_fn(Fn fn) {
    for (int i = 0; i <rows; i++) {
        data[i].fill_with_fn(fn);
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
std::stringstream temp;
    // We don't want to set formatting flags globally.
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}
    
template <typename T>
std::istream& operator>>(std::istream& in, Array<T>& array) {
    for (int i = 0; i < array.length(); ++i) {
        in >> array[i];
    }

    return in;
}
#endif