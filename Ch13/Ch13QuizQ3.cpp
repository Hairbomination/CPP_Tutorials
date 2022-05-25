#include <iostream>
#include <cassert>		//Weird. If I put cstddef before cassert I get an error message at line 14 saying identifier assert is undefined.
#include <cstddef>

class IntArray
{
private:
	int* m_array{nullptr};
	int m_size{ 0 };

public:
	IntArray(int size)
	{
		assert(size > 0);	//Theirs: assert(length > 0 && "IntArray length should be a positive integer");
			
		m_array = new int[static_cast<std::size_t>(size)]{};	//They didn't use the static cast this time. No idea why
		m_size = size;
	}
	
	IntArray(const IntArray& copy)
	{
		deepCopy(copy);		//They didn't call another function here. The copy is done within the constructor.
	}

	~IntArray()
	{
		delete[] m_array;
		m_array = nullptr;	//Unnecessary 
	}

	int& operator[](const int index);
	void deepCopy(const IntArray& copy);
	IntArray& operator=(const IntArray& copy);

	
	friend std::ostream& operator<<(std::ostream& out, const IntArray& array)
	{
		for (int index{ 0 }; index < array.m_size; ++index)
		{
			out << array.m_array[index] << " ";
		}
		return out;
	}
};

int& IntArray::operator[](const int index)
{
	assert(index >= 0 && index < m_size);

	return m_array[index];
}

void IntArray::deepCopy(const IntArray& copy)
{
	delete[] m_array;		//This doesn't seem necessary? Possibly because they put this code in the copy constructor so there wouldn't be anything in m_array?
	m_size = copy.m_size;

	if (copy.m_array)
	{
		m_array = new int[static_cast<std::size_t>(m_size)];
		for (int i{ 0 }; i < m_size; ++i)
			m_array[i] = copy.m_array[i];
	}
	else
		m_array = nullptr;
}

IntArray& IntArray::operator=(const IntArray& copy)
{
	if (this != &copy)		//They repeated the code from the copy constructor here. I prefer this version (which I copied from them anyway)
	{
		deepCopy(copy);
	}
	return *this;
}

IntArray fillArray()		//Copy paste from here down
{							//The existence of this function is pure assholery
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors. I didn't write this comment
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	return 0;
}