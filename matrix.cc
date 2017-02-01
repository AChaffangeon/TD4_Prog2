#include <iostream>
#include <iomanip>

#include <string>
#include <cmath>
#include <cassert>
#include <cstdlib>

#include <vector>
#include <cstdio>


#include "matrix.hh"

using namespace std;

Matrix::Matrix(unsigned n, unsigned p) {
  size_i = n;
  size_j = p;
  assert(1 <= size_i);
  assert(1 <= size_j);

  contents = vector<vector<scalar_t>/**/>(size_i);
  for (unsigned i = 0; i < size_i; i++)
    contents.at(i) = vector<scalar_t>(size_j, 0.0);	// Initialization to 0.0
}

unsigned Matrix::get_size_i() const {
  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);
  return 0;
}

unsigned Matrix::get_size_j() const {
  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);
  return 0;
}

void Matrix::set(unsigned i, unsigned j, scalar_t x) {
  assert(0 <= i && i < size_i);
  assert(0 <= j && j < size_j);
  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);
}

Matrix::scalar_t Matrix::get(unsigned i, unsigned j) const {
  assert(0 <= i && i < size_i);
  assert(0 <= j && j < size_j);
  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);
  return 0;
}

void Matrix::print() const {
  for (unsigned i = 0; i < size_i; i++) {
    for (unsigned j = 0; j < size_j; j++) {
      cout << setprecision(2) << setw(8) << contents.at(i).at(j);
    }
    cout << endl;
  }
  cout << "___________________________" << endl;
}

void Matrix::export_to_file(ofstream& out) {
  out << "Writing into a file" << endl;
  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);
}

/*****************************************************/

Matrix id(unsigned n) {
  unsigned size = n;
  Matrix M(size, size);
  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);
  return M;
}

double norm(const Matrix& M1) {
  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);

  return 0;
}

static Matrix submatrix(const Matrix& M1, unsigned a, unsigned b) {	//Note it is static!
  unsigned size_i = M1.get_size_i();
  unsigned size_j = M1.get_size_j();
  assert (0 <= a && a < size_i);
  assert (0 <= b && b < size_j);
  assert(size_i >= 2);
  assert(size_j >= 2);

  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);
  return id(1);
}

static int toggle(unsigned i) {		//Note it is static!
  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);

  return 0;
}

Matrix::scalar_t determinant(const Matrix& M1) {
  unsigned size_i = M1.get_size_i();
  unsigned size_j = M1.get_size_j();
  assert(size_i == size_j);

  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);
  return 0;
}


/************************************/

Matrix operator+(const Matrix& M1,const Matrix& M2)
{
  //test assertion on size
  assert(M1.get_size_i()==M2.get_size_i() && M1.get_size_i()==M2.get_size_i());

  //let a new matrix
  Matrix ret(M1.get_size_i(),M1.get_size_j());

  //calc coeff
  for(unsigned int i=0; i<M1.get_size_i();i++)
    {
      for(unsigned int j=0; j<M1.get_size_j();j++)
	{
	  ret.set(i,j,M1.get(i,j)+M2.get(i,j));
	}
    }
  return ret;
}




Matrix operator-(const Matrix& M1,const Matrix& M2)
{
  return M1*(-1*M2);
}


Matrix operator*(Matrix::scalar_t a,const Matrix& M2)
{
  //let a new matrix
  Matrix ret(M2.get_size_i(),M2.get_size_j());
  
  //calc coeff
  for(unsigned int i=0; i<M2.get_size_i();i++)
    {
      for(unsigned int j=0; j<M2.get_size_j();j++)
	{
	  ret.set(i,j,a*M2.get(i,j));
	}
    }
  return ret;
}

Matrix operator*(const Matrix& M1,const Matrix& M2)
{
  //test assertion on size
  assert(M1.get_size_j()==M2.get_size_i());

  //let a new matrix
  Matrix ret(M1.get_size_i(),M1.get_size_j());

  //calc coeff
  for(unsigned int i=0; i<M1.get_size_i();i++)
    {
      for(unsigned int j=0; j<M2.get_size_j();j++)
	{
	  Matrix::scalar_t sum=0;//we assume neutra for + in scalar monoid is 0;
	  for(unsigned int k=0;k<M2.get_size_i();k++)
	    {
	      sum+=(M1.get(i,k)+M2.get(k,j));
	    }
	  ret.set(i,j,sum);
	}
    }
return ret;
}

/***********************************/

Matrix transpose(const Matrix& M1) {
  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);
  return id(1);
}

Matrix inverse(const Matrix& M1) {
  unsigned size_i = M1.get_size_i();
  unsigned size_j = M1.get_size_j();
  assert(size_i == size_j);

  // TODO
  cerr << "The function has yet to be implemented" << endl;
  assert(false);

  return id(1);
}



