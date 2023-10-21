#include <iostream>
#include <iomanip>

struct Matrix {
  float* p;
  int m;
  int n;

  Matrix(int m, int n)
  {
    this->m = m;
    this->n = n;
    p = new float[m * n];

    for (int i = 0; i < m * n; i++)
        std::cin >> p[i];
  }

  Matrix(int a, int b, int m, int n)
  {
    this->m = m;
    this->n = n;
    p = new float[m * n];

    for (int i = 0; i < m * n; i++)
      p[i] = a + i > b ? a : a + i;
  }

  void add(Matrix& mat) {
    if (m != mat.m || n != mat.n)
      return;
    for (int i = 0; i < m * n; i++)
      p[i] += mat.p[i];
  }

  void sub(Matrix& mat) {
    if (m != mat.m || n != mat.n)
      return;
    for (int i = 0; i < m * n; i++)
      p[i] -= mat.p[i];
  }

  void mult(Matrix& mat) {
    float *np;
    int nn;

    if (n != mat.m)
      return;

    nn = mat.n;
    np = new float[m * nn];

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < nn; j++) {
        np[(i * n) + j] = 0;
        for (int k = 0; k < mat.m; k++)
          np[(i * n) + j] += p[(i * n) + k] * mat.p[(k * n) + j];
      }
    }

    n = nn;
    delete[] p;
    p = np;
  }

  void transpose() {
    float *np;
    int nm;

    np = new float[n * m];
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        np[(i * n) + j] = p[(j * n) + i];
    nm = m;
    m = n;
    n = nm;
    delete[] p;
    p = np;
  }

  void print() {
    for (int i = 0; i < n; i++) {
      std::cout << std::setprecision(4);
      std::cout << std::setw(4);
      for (int j = 0; j < m; j++)
        std::cout << p[(i * n) + j] << ((j == m - 1) ? "\n" : " ");
    }
    std::cout << std::endl;
  }

  ~Matrix() {
    delete[] p;
  }
};

int main()
{
  Matrix mat1(2, 2);
  Matrix mat2(1, 4, 2, 2);
  Matrix mat3(0, 11, 4, 3);

  std::cout << "mat" << std::endl;
  mat1.print();
  mat2.print();
  std::cout << "add" << std::endl;
  mat1.add(mat2);
  mat1.print();
  std::cout << "sub" << std::endl;
  mat1.sub(mat2);
  mat1.print();
  std::cout << "mult" << std::endl;
  mat1.print();
  mat2.print();
  mat3.print();
  mat1.mult(mat2);
  mat1.print();
  mat3.mult(mat1);
  mat3.print();
  std::cout << "transpose" << std::endl;
  mat1.print();
  mat1.transpose();
  mat1.print();
  std::cout << "transpose" << std::endl;
  mat3.print();
  mat3.transpose();
  mat3.print();
  return 0;
}
