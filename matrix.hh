#pragma once

#include <fstream>
#include <vector>

using namespace std;

class Matrix {
public:
  typedef double scalar_t; //< Types of the elements of the matrix

private:
  unsigned size_i, size_j; //< Sizes of the matrix
  vector<vector<scalar_t>/**/> contents; //< Values in the matrix

public:
  /**
  Constructor of an empty matrix of size n x p
  \param n: number of columns
  \param p: number of rows
  */
  Matrix(unsigned n, unsigned p);
  /**
  Return the number of columns in the matrix
  \return number of columns in the matrix
  */
  unsigned get_size_i(void) const;
  /**
  Return the number of rows in the matrix
  \return number of rows in the matrix
  */
  unsigned get_size_j(void) const;
  /**
  Set one value in the matrix
  \param i: column for the new value
  \param j: row for the new value
  \param x: value to input in the matrix
  at the position i x j
  */
  void set(unsigned i, unsigned j, scalar_t x);
  /**
  Return a value from the matrix
  \param i: column.
  \param j: row.
  \return the value contained at i x j.
  */
  scalar_t get(unsigned i, unsigned j) const;

  /**
  Print the Matrix in humain readable format
  */
  void print() const;

  /**
  Export the matrix to file for R scripts
  \param out: open ofstream to write in
  */
  void export_to_file(ofstream& out);
};

/*****************************************************/

/**
Add matrix M1 and M2 and return the result
\param Matrix M1
\param Matrix M2 with the same size as M1
\return Matrix M1+M2 with the same size as M1 and M2
*/
Matrix operator+(const Matrix& M1, const Matrix& M2);


/**
Substract matrix M2 to M1 and return the result
\param Matrix M1
\param Matrix M2 with the same size as M1
\return Matrix M1-M2 with the same size as M1 and M2
*/
Matrix operator-(const Matrix& M1, const Matrix& M2);

/**
Multiply matrix M by the scalar s and return the result
\param scalar_t s
\param Matrix M
\return Matrix s * M with the same size as M
*/
Matrix operator*(Matrix::scalar_t a, const Matrix& M1);

/**
Multiply matrix M1 and M2 and return the result
\param Matrix M1
\param Matrix M2 such that M2.j = M1.i
\return Matrix M1*M2 of size M2.i x M1,j
*/
Matrix operator*(const Matrix& M1, const Matrix& M2);

/**
Transpose matrix M return the result
\param Matrix M
\return Matrix
*/
Matrix transpose(const Matrix& M1);

/**
Create an identity matrix
\param unsigned n, size of the matrix
\return An identity matrix of size n
*/
Matrix id(unsigned n);

/**
Compute the norm of the matrix
\param Matrix M
\return Norm of M
*/
double norm(const Matrix& M1);

/**
Compute the determinant of a matrix
\param Square matrix M
\return Determinant of matrix M
*/
Matrix::scalar_t determinant(const Matrix& M1);

/**
Compute the inverse of a matrix
\param Square matrix M
\return Inverse matrix of M
*/
Matrix inverse(const Matrix& M1);

