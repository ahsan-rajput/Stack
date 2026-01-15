#include<iostream>
using  namespace std;
#include"String.h"
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const char c)
{
	size = 2;
	data = new char[size] {c, '\0'};
}
String::String(const char* s) :String()
{
	if (getLength(s) == 0)
		return;
	size = getLength(s) + 1;
	data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = s[i];
	}
}

String::String(const String& x) :String()
{
	if (x.data == nullptr)
		return;
	size = x.size;
	data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = x.data[i];
	}
}

String::String(String&& other)
{
	data = other.data;
	size = other.size;
	other.data = nullptr;
	other.size = 0;
}

String::~String()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

void String::input()
{
	data = new char[1] {'\0'};
	char ch;
	int count = 0;
	size = 1;
	while ((ch = cin.get()) != '\n')
	{
		if (count + 1 == size)
			resize(size * 2);
		data[count] = ch;
		count++;
		data[count] = '\0';

	}
}
void String::shrink()
{
	resize(getLength() + 1);
}
char& String::operator [](const int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
const char& String:: operator [](const int index) const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
bool String::operator !()const
{
	if ((data == nullptr) || (data[0] == '\0'))
	{
		return true;
	}
	return false;
}
int String::getLength() const
{
	if (data == nullptr)
	{
		return 0;
	}
	int counter = 0;
	while (data[counter] != '\0')
	{
		counter++;
	}
	return counter;
}
int String::getSize() const
{
	return size;
}
void String::display() const
{
	if (size == 0)
		return;
	cout << data;
}
int String::find(const String& subStr, const int start) const
{
	if (isValidIndex(start))
	{
		int y = getLength() - subStr.getLength();
		for (int i = start; i <= y; i++)
		{
			bool isMatched = true;
			for (int j = 0; j < subStr.getLength(); j++)
			{
				if (data[i + j] != subStr.data[j])
				{
					isMatched = false;
				}
			}
			if (isMatched)
			{
				return i;
			}
		}
		return -1;
	}
	cout << "Inappropriate index";
	exit(0);
}
void String::insert(const int index, const  String& subStr)
{
	if (isValidIndex(index))
	{
		if (getLength() + subStr.getLength() >= size)
		{
			resize(getLength() + subStr.getLength() + 1);
		}
		String temp;
		strcpy(temp);
		data = data + index;
		subStr.strcpy(*this);
		data = data + subStr.getLength();
		temp.data = temp.data + index;
		temp.strcpy(*this);
		temp.data = temp.data - index;
		data = data - (index + subStr.getLength());
	}
	else
	{
		cout << "Inappropriate index.";
		exit(0);
	}
}
void String::remove(const int index, const int count)
{
	if ((isValidIndex(index)) && (count <= getLength() - index) && (count >= 0))
	{
		copyString(&data[index], &data[index + count]);
	}
	else
	{
		cout << "Invalid Input.";
		exit(0);
	}
}

void String::trimLeft()
{
	int newSize = getLength() + 1 - countSpaceAndTab();
	reverse();
	resize(newSize);
	reverse();
}

void String::trimRight()
{
	reverse();
	int newSize = getLength() + 1 - countSpaceAndTab();
	reverse();
	resize(newSize);
}
void String::trim()
{
	trimLeft();
	trimRight();
}


bool String::isValidIndex(const int x) const
{
	return (x >= 0 && x < size);
};


void String::resize(const int newSize)
{
	if (newSize <= 0)
	{
		this->~String();
		return;
	}
	char* temp = new char[newSize];
	if (newSize < size)
		data[newSize - 1] = '\0';
	copyString(temp, data);
	this->~String();
	data = temp;
	size = newSize;
}

int String::strcmp(const String& s2) const
{
	int smallStrLen;
	smallStrLen = getLength() < s2.getLength() ? getLength() : s2.getLength();
	for (int counter = 0; counter <= smallStrLen; counter++)
	{
		if (data[counter] > s2.data[counter])
		{
			return 1;
		}
		if (data[counter] < s2.data[counter])
		{
			return -1;
		}
	}
	return 0;

}
int String::operator == (const String& s2) const
{
	return strcmp(s2);
}
void String::reverse()
{
	char temp;
	for (int counter = 0; counter <= (getLength() - 1) / 2; counter++)
	{
		temp = data[counter];
		data[counter] = data[(getLength() - (1 + counter))];
		data[(getLength() - (1 + counter))] = temp;
	}
}
void String::makeLower()
{
	for (int counter = 0; counter < getLength(); counter++)
	{
		if (data[counter] >= 'A' && data[counter] <= 'Z')
		{
			data[counter] = data[counter] + 32;
		}
	}
}
void String::makeUpper()
{
	for (int counter = 0; counter < getLength(); counter++)
	{
		if (data[counter] >= 'a' && data[counter] <= 'z')
		{
			data[counter] = data[counter] - 32;
		}
	}
}

int String::countSpaceAndTab() const
{
	int counter = 0;
	while (data[counter] == 32 || data[counter] == 9)
	{
		counter++;
	}
	return counter;
}
String:: operator long long int() const
{
	int count = 0;
	long long int  answer = 0;
	do
	{
		answer = answer * 10 + (data[count] - '0');
		count++;
	} while (data[count] != '\0');
	return answer;
}

String String::operator +(const String& s2)
{
	String x;
	x.resize(getLength() + s2.getLength() + 1);
	strcpy(x);
	x.data = x.data + getLength();
	s2.strcpy(x);
	x.data = x.data - getLength();
	return x;
}
void String::strcpy(String& x) const
{
	int sizeOfX = x.size;
	int copyCond = sizeOfX - 1 < getLength() ? sizeOfX - 1 : getLength();
	int counter = 0;
	while (counter < copyCond)
	{
		x.data[counter] = data[counter];
		counter++;
	}
	x.data[counter] = '\0';
}


int String::getLength(const char* x) const
{
	int counter = 0;
	while (x[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

String String::operator +=(const String& s2)// '''
{
	size = getLength() + s2.getLength() + 1;
	resize(size);
	char* temp = data;
	data = data + getLength();
	s2.strcpy(*this);
	data = temp;
	return *this;
}

String::operator double() const
{
	if (data != nullptr)
	{
		bool isNegative = false;
		int count = 0;
		if (data[0] == '-')
		{
			isNegative = true;
			count++;
		}
		bool decimalFlag = false;
		double answer = 0, div = 10;
		while (data[count] != '\0')
		{
			if (data[count] == '.')
			{
				decimalFlag = true;
				count++;
			}
			if (!decimalFlag)
			{
				answer = answer * 10 + (data[count] - '0');
			}
			else
			{
				answer = answer + (data[count] - '0') / div;
				div = div * 10;
			}
			count++;

		}	return isNegative ? -answer : answer;
	}
}

String String::left(const int count)
{
	if (count <= 0)
		return String();
	int len = getLength();
	if (count >= len)
	{
		String s{ *this };
		this->~String();
		return s;
	}
	char temp = data[count];
	data[count] = '\0';
	String s{ data };
	data[count] = temp;
	copyString(&data[0], &data[count]);
	return s;
}

String String::right(const int count)
{
	reverse();
	String temp{ left(count) };
	temp.reverse();
	reverse();
	return temp;
}

void String::setNumber(const long long int num)
{
	this->~String();
	long long int num1 = num;
	int counter = 0;
	while (num1)
	{
		num1 = num1 / 10;
		counter++;
	}
	num1 = num;
	size = num < 0 ? counter + 2 : counter + 1;
	if (num1 == 0)
		size++;
	num1 = num < 0 ? -1 * num : num;
	resize(size);
	data[size - 1] = '\0';
	for (int i = size - 2; i >= 0; i--)
	{
		data[i] = (num1 % 10) + 48;
		num1 = num1 / 10;
	}
	if (num < 0)
	{
		data[0] = '-';
	}
}

int String::replace(const String& old, const  String& newSubStr)
{
	int i = 0, lengthOfOldStr = old.getLength(), lengthOfNewStr = newSubStr.getLength(), index, noOfOccurances = 0;
	while (data[i + (lengthOfOldStr - 1)] != '\0')
	{
		index = find(old);
		if (index != -1)
		{
			noOfOccurances++;
			if (lengthOfNewStr > lengthOfOldStr)
			{
				resize(getLength() + (lengthOfNewStr - lengthOfOldStr) + 1);
				for (i = size - 1; i >= index + lengthOfOldStr; i--)
				{
					data[i] = data[i - (lengthOfNewStr - lengthOfOldStr)];
				}
			}
			if (lengthOfNewStr >= lengthOfOldStr)
			{
				char temp = data[index + lengthOfNewStr];
				copyString(&data[index], newSubStr.data);
				data[index + lengthOfNewStr] = temp;
			}
			else
			{
				copyString(&data[index], newSubStr.data);
				copyString(&data[index + lengthOfNewStr], &data[index + lengthOfOldStr]);
			}

		}
		i++;
	}
	return noOfOccurances;
}


void String::copyString(char* dest, char* src)
{
	int i = 0;
	if (src)
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
}

String& String::operator = (const String& x)
{
	if (this == &x)
		return *this;
	this->~String();
	if (x.data == nullptr)
		return *this;
	size = x.size;
	data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = x.data[i];
	}
}

String& String::operator = (const long long int num)
{
	this->~String();
	setNumber(num);
	return *this;
}

String& String:: operator = (const double num)
{
	this->~String();
	setDouble(num);
	return *this;
}


String& String :: operator = (String&& x)
{
	if (this != &x)
	{
		this->~String();
		data = x.data;
		size = x.size;
		x.size = 0;
		x.data = nullptr;
	}
	return *this;
}

void String::setDouble(const double num)
{

	int precision = 6;
	setNumber((long long int)num);
	double fractionalPart = num - (long long int)num;
	if (fractionalPart < 0.0)
	{
		fractionalPart *= -1;
	}
	if (fractionalPart > 0.0)
	{
		*this += ".";
		String fraction;
		fraction.resize(7);
		int i = 0;
		for (; i < precision; i++)
		{
			fractionalPart *= 10;
			int digit = (int)fractionalPart;
			fraction[i] = (digit + 48);
			fractionalPart -= digit;
		}
		fraction[i] = '\0';
		*this += fraction;
	}

}

istream& operator >> (istream& in, String& ref)
{
	ref.resize(1);
	ref[0] = '\0';
	char ch;
	int count = 0;
	while ((ch = in.get()) != '\n')
	{
		if (count + 1 == ref.getSize())
			ref.resize(ref.getSize() * 2);
		ref[count] = ch;
		count++;
		ref[count] = '\0';

	}
	return in;
}
ostream& operator << (ostream& out, const String& ref)
{
	if (ref.getSize() == 0)
	{
		return out;
	}
	out << &ref[0];
	return out;
}

String String :: operator ()(const String& delim) // 4
{
	String temp;
	int i = 0;
	int curentIndex = 0;
	int firstIndex = getSize() + 1;
	while (i < delim.getSize() - 1)
	{
		curentIndex = find(delim.data[i]);
		if (curentIndex < firstIndex && curentIndex != -1)
		{
			firstIndex = curentIndex;
		}
		i++;
	}

	if (firstIndex == getSize() + 1)
	{
		temp = *this;
		this->~String();
	}
	else if (firstIndex == 0)
	{
		remove(0, 1);
	}
	else if (firstIndex > 0)
	{
		temp = left(firstIndex);
		remove(0, 1);
	}

	return temp;
}

String::operator bool() const
{
	if ((data == nullptr) || (data[0] == '\0'))
	{
		return false;
	}
	return true;
}














// Previous One
//void String::strcpy(String& x) const
//{
//	if (x.data == nullptr)
//	{
//		x.data = new char[size];
//		x.size = size;
//	}
//	int sizeOfX = x.size;
//	int copyCond = sizeOfX - 1 < getLength() ? sizeOfX - 1 : getLength();
//	int counter = 0;
//	while (counter < copyCond)
//	{
//		x.data[counter] = data[counter];
//		counter++;
//	}
//	x.data[counter] = '\0';
//}
