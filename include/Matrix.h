#pragma once
#include "Vector.h"


const int MAX_MATRIX_SIZE = 10000;


template<class T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T>>
{
	using::TDynamicVector<TDynamicVector<T>>::pMem;
	using::TDynamicVector<TDynamicVector<T>>::sz;

public:
	TDynamicMatrix(size_t s);
	TDynamicMatrix(const TDynamicMatrix<T>& m);
	~TDynamicMatrix();

	using TDynamicVector<TDynamicVector<T>>::operator[];

	bool operator==(const TDynamicMatrix& m) const noexcept;
	bool operator!=(const TDynamicMatrix& m) const noexcept;
	
	TDynamicMatrix<T> operator+(const TDynamicMatrix<T>& m);
	TDynamicMatrix<T> operator-(const TDynamicMatrix<T>& m);
	TDynamicMatrix<T> operator*(const TDynamicMatrix<T>& m);
};

template<class T>
inline TDynamicMatrix<T>::TDynamicMatrix(size_t s = 1): TDynamicVector<TDynamicVector<T>> (s)
{
	if ((s < 1) || (s > MAX_MATRIX_SIZE))
		throw "Error";

	this->sz = s;
	if (this->pMem != nullptr)
		delete[] this->pMem;

	this->pMem = new TDynamicVector<T>[this->sz];
	for (int i = 0; i < sz; i++)
		this->pMem[i] = TDynamicVector<T>(sz);
}

template<class T>
inline TDynamicMatrix<T>::TDynamicMatrix(const TDynamicMatrix<T>& m)
{
	if (m.sz == 0)
		this->pMem = 0;
	if (m.sz > 0)
		this->sz = m.sz;

	this->pMem = new TDynamicVector<T>[sz];
	for (int i = 0; i < sz; i++)
		this->pMem[i] = m.pMem[i];
}

template<class T>
inline TDynamicMatrix<T>::~TDynamicMatrix()
{
}

template<class T>
inline bool TDynamicMatrix<T>::operator==(const TDynamicMatrix<T>& m) const noexcept
{
	if (sz != m.sz)
		return false;

	for (int i = 0; i < sz; i++)
	{
		if (pMem[i] != m.pMem[i])
			return false;
	}

	return true;
}

template<class T>
inline bool TDynamicMatrix<T>::operator!=(const TDynamicMatrix<T>& m) const noexcept
{
	if (sz == m.sz)
	{
		for (int i = 0; i < sz; i++)
		{
			if (pMem[i] != m.pMem[i])
				return true;
		}
		return false;
	}

	return true;
}

template<class T>
inline TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const TDynamicMatrix<T>& m)
{
	if (sz != m.sz)
		throw "Error";

	TDynamicMatrix<T> res(sz);
	for (int i = 0; i < sz; i++)
		res.pMem[i] = pMem[i] + m.pMem[i];

	return res;
}

template<class T>
inline TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const TDynamicMatrix<T>& m)
{
	if (sz != m.sz)
		throw "Error";

	TDynamicMatrix<T> res(sz);
	for (int i = 0; i < sz; i++)
		res.pMem[i] = pMem[i] - m.pMem[i];

	return res;
}

template<class T>
inline TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const TDynamicMatrix<T>& m)
{
	if (sz != m.sz)
		throw "Error";

	TDynamicMatrix<T> res(sz);
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
		{
			T sum = 0;
			for (int k = 0; k < sz; k++)
				sum += pMem[i][k] * m.pMem[k][j];

			res.pMem[i][j] = sum;
		}

	return res;
}

template<class T>
std::ostream& operator <<(std::ostream& ostr, TDynamicMatrix<T>& p)
{
	for (size_t i = 0; i < p.GetSize(); i++)
	{
		auto v = p[i];
		for (size_t j = 0; j < p.GetSize(); j++)
		{
			ostr << p[i][j] << "\t";
		}
		ostr << "\n";
	}

	return ostr;
}

template<class T>
std::istream& operator >>(std::istream& istr, TDynamicMatrix<T>& p)
{
	size_t s;
	istr >> s;
	TSquareMatrix<T> istr(s);
	for (size_t i = 0; i < s; i++)
		for (size_t j = 0; j < s; j++)
			istr >> istr[i][j];
	p = istrmatrix;
	return istr;
}