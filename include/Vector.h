#pragma once
#include <iostream>


const int MAX_VECTOR_SIZE = 100000000;


template <typename T>
class TDynamicVector
{
protected:
	size_t sz;
	T* pMem;

public:
	TDynamicVector(size_t s = 1);
	TDynamicVector(T* arr, size_t s);
	TDynamicVector(const TDynamicVector<T>& v);
	TDynamicVector(TDynamicVector<T>&& v) noexcept;
	~TDynamicVector();
	TDynamicVector<T>& operator=(const TDynamicVector<T>& v);
	TDynamicVector<T>& operator=(TDynamicVector<T>&& v) noexcept;

	size_t GetSize() const noexcept;

	T& operator[](size_t ind);
	const T& operator[](size_t ind) const;

	T& At(size_t ind);
	const T& At(size_t ind) const;

	bool operator==(const TDynamicVector<T>& v) const noexcept;
	bool operator!=(const TDynamicVector<T>& v) const noexcept;

	TDynamicVector<T> operator+(T val);
	TDynamicVector<T> operator-(double val);
	TDynamicVector<T> operator*(double val);

	TDynamicVector<T> operator+(const TDynamicVector<T>& v);
	TDynamicVector<T> operator-(const TDynamicVector<T>& v);
	T operator*(const TDynamicVector<T>& v);

	friend std::istream& operator>>(std::istream& istr, TDynamicVector& v)
	{
		for (int i = 0; i < v.sz; i++)
			istr >> v.pMem[i];
		return istr;
	}

	friend std::ostream& operator<<(std::ostream& ostr, const TDynamicVector& v)
	{
		for (int i = 0; i < v.sz; i++)
			ostr << v.pMem[i] << ' ';
		return ostr;
	}
};

template<typename T>
inline TDynamicVector<T>::TDynamicVector(size_t s)
{
	if ((s < 1) || (s > MAX_VECTOR_SIZE))
		throw "Error";

	sz = s;
	pMem = new T[sz];

	for (int i = 0; i < sz; i++)
	{
		pMem[i] = {};
	}
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(T* arr, size_t s)
{
	if ((s < 1) or (arr == nullptr))
		throw "Error";

	sz = s;
	pMem = new T[sz];

	for (int i = 0; i < sz; i++)
		pMem[i] = arr[i];
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(const TDynamicVector<T>& v)
{
	if (v.pMem == nullptr)
	{
		sz = 0;
		pMem = nullptr;
	}
	else
	{
		sz = v.sz;
		pMem = new T[sz];

		for (int i = 0; i < sz; i++)
			pMem[i] = v.pMem[i];
	}
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(TDynamicVector<T>&& v) noexcept
{
	sz = v.sz;
	pMem = v.pMem;
	v.sz = 0;
	v.pMem = nullptr;
}

template<typename T>
inline TDynamicVector<T>::~TDynamicVector()
{
	if (pMem != nullptr)
	{
		delete[] pMem;
		sz = 0;
	}
}

template<typename T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(const TDynamicVector<T>& v)
{
	if (this != &v)
	{
			delete[] pMem;

			sz = v.sz;
			if (sz != 0)
			{
				pMem = new T[sz];
				for (int i = 0; i < sz; i++)
					pMem[i] = v.pMem[i];
			}
			else
			{
				pMem = nullptr;
			}
			return *this;
		
	}

	return *this;
}

template<typename T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(TDynamicVector<T>&& v) noexcept
{
	if (this != &v)
	{
		if (pMem != nullptr)
			delete[] pMem;

		sz = v.sz;
		pMem = v.pMem;

		v.sz = 0;
		v.pMem = nullptr;
	}

	return *this;
}

template<typename T>
inline size_t TDynamicVector<T>::GetSize() const noexcept
{
	return sz;
}

template<typename T>
inline T& TDynamicVector<T>::operator[](size_t ind)
{
	if ((ind >= 0) && (ind < sz))
	{
		return pMem[ind];
	}
	else
		throw "Error";
}

template<typename T>
inline const T& TDynamicVector<T>::operator[](size_t ind) const
{
	if (ind >= 0) && (ind < sz)
	{
		return pMem[ind];
	}
	else
		throw "Error";
}

template<typename T>
inline T& TDynamicVector<T>::At(size_t ind)
{
	if (pMem == nullptr)
		throw "Error";

	if ((ind < 0) || (ind >= sz))
	{
		throw "Error";
	}
	else
		return pMem[ind];
}

template<typename T>
inline const T& TDynamicVector<T>::At(size_t ind) const
{
	if (pMem == nullptr)
		throw "Error";

	if ((ind < 0) || (ind >= sz))
	{
		throw "Error";
	}
	else
		return pMem[ind];
}

template<typename T>
inline bool TDynamicVector<T>::operator==(const TDynamicVector<T>& v) const noexcept
{
	if (sz != v.sz)
		return false;

	for (int i = 0; i < sz; i++)
	{
		if (pMem[i] != v.pMem[i])
			return false;
	}

	return true;
}

template<typename T>
inline bool TDynamicVector<T>::operator!=(const TDynamicVector<T>& v) const noexcept
{
	if (sz == v.sz)
	{
		for (int i = 0; i < sz; i++)
		{
			if (pMem[i] != v.pMem[i])
				return true;
		}
		return false;
	}
	return true;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(T val)
{
	TDynamicVector res(*this);
	
	for (int i = 0; i < sz; i++)
		res.pMem[i] += val;

	return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator-(double val)
{
	TDynamicVector res(*this);

	for (int i = 0; i < sz; i++)
		res.pMem[i] -= val;

	return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator*(double val)
{
	TDynamicVector res(*this);

	for (int i = 0; i < sz; i++)
		res.pMem[i] *= val;

	return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(const TDynamicVector<T>& v)
{
	if (sz != v.sz)
		throw "Error";

	TDynamicVector res(*this);

	for (int i = 0; i < sz; i++)
		res.pMem[i] += v.pMem[i];

	return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator-(const TDynamicVector<T>& v)
{
	if (sz != v.sz)
		throw "Error";

	TDynamicVector res(*this);

	for (int i = 0; i < sz; i++)
		res.pMem[i] -= v.pMem[i];

	return res;
}

template<typename T>
inline T TDynamicVector<T>::operator*(const TDynamicVector<T>& v) 
{
	if (sz != v.sz)
		throw "Error";

	T res = 0;

	for (int i = 0; i < sz; i++)
		res += pMem[i] * v.pMem[i];

	return res;
}
