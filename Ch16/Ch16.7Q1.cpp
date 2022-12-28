#include <cassert>
#include <initializer_list> 
#include <iostream>

class IntArray			//My code is lines 48 and 53-67. All else is copy/paste
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArray() = default;

	IntArray(int length)
		: m_length{ length }
		, m_data{ new int[length] {} }
	{

	}

	IntArray(std::initializer_list<int> list)
		: IntArray(static_cast<int>(list.size()))
	{
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~IntArray()
	{
		delete[] m_data;
	}

	IntArray(const IntArray&) = delete;
	IntArray& operator=(const IntArray& list) = delete;

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	IntArray& operator=(std::initializer_list<int> list);		//Could have just defined the function here

	int getLength() const { return m_length; }
};

IntArray& IntArray::operator=(std::initializer_list<int> list)
{
	delete[] m_data;
	m_length = static_cast<int>(list.size());	//They only reallocated m_data if the new list is of a different size. Their solution:
	m_data = new int[m_length];					//int length{ static_cast<int>(list.size()) }; if (length != m_length) 
												//{delete[] m_data; m_length = length; m_data = new int[length]{};}
	int count{ 0 };
	for (auto element : list)
	{
		m_data[count] = element;	//I get warning C6386 buffer overrun while writing to m_data. Debugging no help
		++count;					//Makes no sense and the code executes correctly anyway?? Their solution doesn't look that
	}								//different to mine so no idea what the warning is about.
	
	return *this;
}

int main()
{
	IntArray array{ 5, 4, 3, 2, 1 };
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}