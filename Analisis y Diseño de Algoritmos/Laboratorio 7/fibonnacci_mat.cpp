#include <cstdio>
#include <cassert>

using namespace std;

// definir matriz 2x2
struct Matrix2By2 {
   Matrix2By2(int m00 = 0, int m01 = 0, int m10 = 0, int m11 = 0) : m_00(m00), m_01(m01), m_10(m10), m_11(m11) {}

   int m_00;
   int m_01;
   int m_10;
   int m_11;
};

// Definir multiplicación de matrices 2x2
Matrix2By2 MatrixMultiply(const Matrix2By2 &matrix1, const Matrix2By2 &matrix2) {
   return {
         matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
         matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
         matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
         matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11};
}

// Divide y vencerás para calcular la multiplicación de n matrices 2x2
Matrix2By2 MatrixPower(int n) {
    Matrix2By2 matrix;
    if (n == 1) {
        matrix = Matrix2By2(1, 1, 1, 0);
    }else if (n % 2 == 0) {
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    }else if (n % 2 == 1) {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }
    return matrix;
}

// Calcula el n-ésimo número en la secuencia de Fibonacci
int Fibonacci(int n) {
   int result[2] = {1, 1};
   // si n es 1 o 2
   if (n <= 2)
      return result[n - 1];

   Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
   return PowerNMinus2.m_00;
}


int main() {
   int n = 1073741824;
   int sum = Fibonacci(n);
   printf("%d ", sum);
   return 0;
}