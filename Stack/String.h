#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class String
{
	char* data;
	int size;
	int getLength(const char*) const;
	bool isValidIndex(const int) const;
	int countSpaceAndTab() const;
	void copyString(char* dest, char* src);
	int strcmp(const String& s2)const;
	void strcpy(String& x) const;
	void setNumber(const long long int);
	void setDouble(const double num);
public:
	String();
	String(const char c);
	String(const char*);
	String(const String&);
	String(String&& other);
	String& operator = (const String&);
	String& operator = (String&&);
	~String();
	void input();
	void shrink();
	char& operator [](const int index);
	const char& operator [](const int index) const;
	bool operator !()const;
	int getLength() const;
	int getSize() const;
	void display() const;
	int find(const String& subStr, const int start = 0)const;
	void insert(const int index, const  String& subStr);
	void remove(const int, const int count = 1);
	int replace(const String& old, const  String& newSubStr);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void resize(const int);
	int operator == (const String& s2) const;
	String left(const int count);
	String right(const int count);
	String operator +(const String& s2);
	String operator +=(const String& s2);
	String& operator = (const double num);
	String& operator = (const long long int num);
	String operator()(const String& delim);


	explicit operator long long int() const;
	explicit operator double() const;
	explicit operator bool() const;

};
istream& operator >> (istream&, String&);
ostream& operator <<(ostream&, const String&);

#endif