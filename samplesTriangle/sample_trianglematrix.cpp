#include <iostream>
#include "TriangleMatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TTriangleMatrix<int> mat1(2);
  std::cin >> mat1;
  TTriangleMatrix<int> mat2(2);
  std::cin >> mat2;
  TTriangleMatrix<int> res = mat1 + mat2;
  std::cout << res;
}