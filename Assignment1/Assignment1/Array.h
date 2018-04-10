#ifndef ARRAY_HEADER_H
#define ARRAY_HEADER_H

#include<iostream>

template <typename T>
class Array
{
public:
	Array(int size = 10)
		: m_size(size)
		, m_data(new T[size])
	{}

	~Array()
	{
		delete m_data;
	}

	T& GetItem(int index) const
	{
		if (index < 0 || index > m_size)
		{
			std::cout << "*ERROR AT CLASS Array - Function GetItem(int index)" << std::endl;
			std::cout << "INDEX OUT OF BOUNDS*" << std::endl;
			return *m_data;
		}
		else
			return m_data[index];
	}

	int getSize() const
	{
		return m_size;
	}

	void setItem(int index, T value)
	{
		if (index < 0 || index > m_size)
		{
			std::cout << "*ERROR AT CLASS Array - Function setItem(int index, T value)" << std::endl;
			std::cout << "INDEX OUT OF BOUNDS*" << std::endl;
		}
		else
			m_data[index] = value;
	}
private:
	T* m_data;
	int m_size;
};

#endif // !ARRAY_HEADER_H
