#include <iostream>
#include <fstream>


#include "matrix.hh"

using namespace std;

int main() {
  ofstream file;
  // Open the file script.r to write into it
  file.open("script.r");
  // Write a line into the file
  file << "print('#Test de la librairie Matrice')" << endl;


  int n = 3;
  Matrix M(n, n);
  M.export_to_file(file);

  // See example at http://www.math.cornell.edu/~andreim/Lec17.pdf

  M.set(0, 0, 0.0);
  M.set(1, 0, -2.0);
  M.set(2, 0, 4.0);
  M.set(0, 1, 1.0);
  M.set(1, 1, 3.0);
  M.set(2, 1, 0.0);
  M.set(0, 2, 2.0);
  M.set(1, 2, -1.0);
  M.set(2, 2, 1.0);

  Matrix MM = inverse(M);

  /**************************
  Matrix M:

       0       1       2
      -2       3      -1
       4       0       1

  Determinant: -26

  Matrix MM:

   -0.12   0.038    0.27
   0.077    0.31    0.15
    0.46   -0.15  -0.077

  **************************/

  M.print();
  cout << determinant(M) << endl;;
  MM.print();

  cout << norm((M * MM) - id(n)) << " " <<  norm((MM * M) - id(n)) << endl;


  // Do not forget to properly close the file
  file.close();
}
