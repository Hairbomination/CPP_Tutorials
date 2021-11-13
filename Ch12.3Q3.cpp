#include<iostream>
#include<array>
#include<cassert>

class Stack
{
	std::array<int, 10> array;		//Should be m_array if following naming conventions
	int size{ 0 };					//m_size. Also should be std::size_type (even though they said to use an integer)
									//Their code goes: using container_type = std::array<int, 10>;
public:								//using size_type = container_type::size_type;
	void reset()					//container_type m_array {};
	{								//size_type m_next{ 0 };
		size = 0;
	}
	bool push(const int x)
	{
		if (size < 10)
		{
			array[size] = x;		//Could've used array[size++] here
			++size;
			return true;
		}
		else
			return false;
	}
	int pop()
	{
		assert(size > 0);			//This is about half right. I should revisit the assert tutorial.

		int value{ array[size] };	//Lines 30-34 can apparently be replaced with return array[--size]
		array[size] = 0;			//It isn't necessary to change the value back to 0, just return the value and --size
		--size;						
			return value;			//This is actually returning the wrong value anyway. You just can't tell because
	}								//it never prints. Size points to the next free element. The element I wanted was size-1
	void print()
	{
		std::cout << "( ";
		if (size == 0)				//Unecessary if else statements here. Would still work by deleting lines 38-41
			std::cout << " ";
		else
		{
			for (int count{ 0 }; count < size; ++count)
			{
				std::cout << array[count] << " ";
			}
		}
		std::cout << ")\n";
}
};

int main()				//They provided the entire main function. From here down is copy/pasted. 
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}