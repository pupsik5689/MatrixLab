#pragma once
#include "Vector.h"
const int MAX_MATRIX_SIZE = 10000;
template <class T>
class TTriangleMatrix : public TDynamicVector<TDynamicVector<T>>
{
  using::TDynamicVector<TDynamicVector<T>>::pMem;
  using::TDynamicVector<TDynamicVector<T>>::sz;
public:
  TTriangleMatrix(int s);
  TTriangleMatrix(const TTriangleMatrix<T>& m) noexcept;
  TTriangleMatrix(TTriangleMatrix<T>&& m);

  bool operator==(const TTriangleMatrix<T>& m) const noexcept;
  bool operator!=(const TTriangleMatrix<T>& m) const noexcept;

  using::TDynamicVector<TDynamicVector<T>>::operator[];

  TTriangleMatrix<T> operator+(const TTriangleMatrix<T>& m);
  TTriangleMatrix<T> operator-(const TTriangleMatrix<T>& m);
  TTriangleMatrix<T> operator*(const TTriangleMatrix<T>& m);

  TTriangleMatrix<T> operator=(TTriangleMatrix<T>&& m);
  TTriangleMatrix<T> operator=(const TTriangleMatrix<T>& m);
};

template<class T>
inline TTriangleMatrix<T>::TTriangleMatrix(int s) : TDynamicVector<TDynamicVector<T>>(s)
{
  if ((s < 1) || (s > MAX_MATRIX_SIZE))
    throw "Error";
  sz = s;
  for (int i = 0; i < sz; i++)
    pMem[i] = TDynamicVector<T>(i + 1);
}

template<class T>
inline TTriangleMatrix<T>::TTriangleMatrix(const TTriangleMatrix<T>& m) noexcept
{
  if (m.pMem == nullptr)
  {
    pMem = nullptr;
    sz = 0;
  }
  else
  {
    sz = m.sz;
    pMem = new TDynamicVector<T>[sz];
    for (int i = 0; i < sz; i++)
      pMem[i] = m.pMem[i];
  }
}

template<class T>
inline TTriangleMatrix<T>::TTriangleMatrix(TTriangleMatrix<T>&& m)
{
  pMem = m.pMem;
  sz = m.sz;
  m.pMem = nullptr;
  m.sz = 0;
}

template<class T>
inline bool TTriangleMatrix<T>::operator==(const TTriangleMatrix<T>& m) const noexcept
{
  return TDynamicVector<TDynamicVector<T>>::operator ==(m);
}

template<class T>
inline bool TTriangleMatrix<T>::operator!=(const TTriangleMatrix<T>& m) const noexcept
{
  return TDynamicVector<TDynamicVector<T>>::operator !=(m);
}

template<class T>
inline TTriangleMatrix<T> TTriangleMatrix<T>::operator+(const TTriangleMatrix<T>& m)
{
  if (sz != m.sz)
    throw "Error";

  TTriangleMatrix<T> res(sz);
  for (int i = 0; i < sz; i++)
    res.pMem[i] = pMem[i] + m.pMem[i];
  return res;
}

template<class T>
inline TTriangleMatrix<T> TTriangleMatrix<T>::operator-(const TTriangleMatrix<T>& m)
{
  if (sz != m.sz)
    throw "Error";

  TTriangleMatrix<T> res(sz);
  for (int i = 0; i < sz; i++)
    res.pMem[i] = pMem[i] - m.pMem[i];
  return res;
}

template<class T>
inline TTriangleMatrix<T> TTriangleMatrix<T>::operator*(const TTriangleMatrix<T>& m)
{
  if (sz != m.sz)
    throw "Error";

  TTriangleMatrix<int> res(sz);
  for (int i = 0; i < sz; i++)
    for (int j = 0; j <= i; j++)
    {
      T sum = 0;
      for (int k = j; k <= i; k++)
        sum += pMem[i][k] * m.pMem[k][j];
      res.pMem[i][j] = sum;
    }
  return res;
}

template<class T>
inline TTriangleMatrix<T> TTriangleMatrix<T>::operator=(TTriangleMatrix<T>&& m)
{
  if (this == &m)
    return *this;

  if (pMem != nullptr)
    delete[] pMem;

  pMem = m.pMem;
  sz = m.sz;
  m.pMem = nullptr;
  m.sz = 0;

  return *this;
}

template<class T>
inline TTriangleMatrix<T> TTriangleMatrix<T>::operator=(const TTriangleMatrix<T>& m)
{
  if (this == &m)
    return *this;

  sz = m.sz;
  if (pMem != nullptr)
    delete[] pMem;

  pMem = new TDynamicVector<T>[sz];
  for (int i = 0; i < m.sz; i++)
    pMem[i] = m.pMem[i];

  return *this;
}

template<class T>
std::ostream& operator <<(std::ostream& ostr, TTriangleMatrix<T>& m)
{
  for (int i = 0; i < m.GetSize(); i++)
  {
    for (int j = 0; j <= i; j++)
    {
      ostr << m[i][j] << ' ';
    }
    ostr << "\n";
  }
  return ostr;
}

template<class T>
std::istream& operator >>(std::istream& istr, TTriangleMatrix<T>& m)
{
  for (int i = 0; i < m.GetSize(); i++)
  {
    for (int j = 0; j < i + 1; j++)
      istr >> m[i][j];
  }

  return istr;
}