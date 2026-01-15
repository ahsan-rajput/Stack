#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
	T* data;
	int capacity;
	int top;
	void reSize(int newSize)
	{
		T* temp = new T[newSize];
		for (int i = 0; i < top; i++)
		{
			temp[i] = data[i];
		}
		int tempTop = top;
		this->~Stack();
		data = temp;
		capacity = newSize;
		top = tempTop;
	}

public:
	Stack()
	{
		capacity = 0;
		data = nullptr;
		top = 0;
	}

	~Stack()
	{
		if (!data)
			return;
		delete[] data;
		data = nullptr;
		top = 0;
		capacity = 0; 
	}

	void push(T val)
	{
		if (isFull())
			reSize(capacity == 0 ? 1 : capacity * 2);
		data[top++] = val;
	}

	T pop()
	{
		if (isEmpty())
			exit(0);
		T val = data[--top];
		if (top > 0 && top == capacity / 4)
			reSize(capacity / 2);
		return val;
	}

	T stackTop()
	{
		if (isEmpty())
			exit(0);
		return data[top - 1];
	}

	bool isFull()
	{
		return top == capacity;
	}

	bool isEmpty()
	{
		return top == 0;
	}

	int getCapacity()
	{
		return capacity;
	}

	int getNumberOfElements()
	{
		return top;
	}

};



#endif
// Added for test.