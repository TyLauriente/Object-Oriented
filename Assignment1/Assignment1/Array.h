#ifndef ARRAY_HEADER_H
#define ARRAY_HEADER_H

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
		return m_data[index];
	}

	int getSize() const
	{
		return m_size;
	}

	void setItem(int index, T value)
	{
		m_data[index] = value;
	}
private:
	T* m_data;
	int m_size;
};

#endif // !ARRAY_HEADER_H
