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
Matrix(int rows, int cols) : rows(rows), cols(cols), data {rows}
{
    for (int i =0; i < rows; i++) 
    {
        data[i] = Array<T>(cols);
    }
}

template <typename T>
Array<T>& operator[](int row);

template <typename T>
const Array<T>& operator[](int row) const;

template <typename T>
int num_rows() const;

template <typename T>
int num_cols() const;

template <typename T>
void fill(const T& val);

template <typename T>
template <typename Fn>
void fill_with_fn(Fn fn);

#endif