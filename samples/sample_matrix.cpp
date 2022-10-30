// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "Matrix.h"
//---------------------------------------------------------------------------

void main()
{
  TDynamicMatrix<int> a(5), c(5);
  TDynamicMatrix<int> b(a);


  setlocale(LC_ALL, "Russian");
  std::cout << "Тестирование класс работы с матрицами \n";
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++ )
    {
      a[i][j] =  3;
      b[i][j] = 2;
    }
  c = a + b;
  std::cout << "Matrix a = " << "\n" << a << "\n";
  std::cout << "Matrix b = " << "\n" << b << "\n";
  std::cout << "Matrix c = a + b" << "\n" << c << "\n";
  c = a - b;
  std::cout << "Matrix c = a - b" << "\n" << c << "\n";
  c = a * b;
  std::cout << "Matrix c = a * b" << "\n" << c << "\n";



  TDynamicVector<int> av(5), cv(5);
  TDynamicVector<int> bv(av);

  for (int i = 0; i < 5; i++)
  {
    av[i] = i + 1;
    bv[i] = i + 3;
  }
  cv = av + bv;
  std::cout << "Vector av = " << av << "\n";
  std::cout << "Vector bv = " << bv << "\n";
  std::cout << "Vector av + bv = " << cv << "\n";
  cv = bv - av;
  std::cout << "Vector bv - av = " << cv << "\n";
}
//---------------------------------------------------------------------------
