#include<iostream>
using namespace std;
#include"Stack.h"
#include"String.h"
int main()
{






	// Reverse using 1 stack 

	//int temp,temp1;
	//Stack<int> s,a1;
	//s.push(1);
	//s.push(9);
	//s.push(2);
	//s.push(3);
	//s.push(1);
	//s.display();
	//int n = s.getNumberOfElements();
	//for (int i = 0; i < n-1; i++)
	//{
	//	temp = s.stackTop();
	//	s.pop();
	//	while (s.getNumberOfElements()!=i)
	//	{
	//		temp1 = s.stackTop();
	//		a1.push(temp1);
	//		s.pop();
	//	}
	//	s.push(temp);
	//	while (!a1.isEmpty())
	//	{
	//		temp1 = a1.stackTop();
	//		s.push(temp1);
	//		a1.pop();
	//	}
	//}
	//s.display();








	// ASCENDING ORDER

	/*Stack<int> s,ad1;
	int min,temp;
	s.push(1);
	s.push(9);
	s.push(2);
	s.push(3);
	s.push(1);
	s.display();
	int n = s.getNumberOfElements();
	for (int i = 0; i < n - 1; i++)
	{
		min=s.stackTop();
		s.pop();
		while (s.getNumberOfElements() != i)
		{
			temp = s.stackTop();
			if (temp < min)
			{
				ad1.push(min);
				min = temp;
				s.pop();
			}
			else
			{
				ad1.push(temp);
				s.pop();
			}
		}
		s.push(min);
		while (!ad1.isEmpty())
		{
			temp = ad1.stackTop();
			s.push(temp);
			ad1.pop();
		}

	}
	s.display();*/



	/*String s{"DSA IS TOUGH"},temp;
	Stack<String> s1;
	cout << s;
	for (int i = 0; i < s.getLength(); i++)
	{
		while (s[i] != ' ' && i < s.getLength())
		{
			temp += s[i];
			i++;
		}

		s1.push(temp);
		temp.~String();
	}
	s.~String();
	while (!s1.isEmpty())
	{
		s += s1.stackTop();
		s += " ";
		s1.pop();
	}*/










	/*Stack<int> s1, s2;
	int temp;
	int n = s1.getNumberOfElements();
	for (int i = 0; i < n; i++)
	{
		while (s1.getNumberOfElements() != 1)
		{
			s2.push(s1.stackTop());
			s1.pop();
		}
		temp = s1.stackTop();
		s1.pop();

		while (s2.getNumberOfElements() != i)
		{
			s1.push(s2.stackTop());
			s2.pop();
		}
		s2.push(temp);
	}

	s2.display();*/







	/*string s{""};
	int n = s.size();
	if (s.size() % 3)
		return -1;
	n = n / 3;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != 'a')
			return -1;
		else if (s[i+n] != 'b')
			return -1;
		else if (s[i+2*n] != 'c')
			return -1;
	}
	return 1;*/















	//// Copy without other stack

	






	// ASCENDING ORDER.

	













	/*Stack<char> s;
	string p{ "aaabbb" };
	int i = 0;
	while (p[i] == 'a')
	{
		s.push('a');
		i++;
	}
	if (p[i] != 'b')
		return -1;
	if (s.getNumberOfElements() == p.size() - i)
	{
		for (; i < p.size(); i++)
		{
			if (p[i] == 'b')
				s.pop();
			else
				return -1;
		}
		return s.isEmpty();
	}
	return -1;*/
}

// 1.

//Stack<int> s;
//string p{ "ab" };
//int n = p.size();
//for (int i = 0; i < n / 2; i++)
//{
//	if (p[i] == 'a')
//		s.push('a');
//}
//
//for (int i = n / 2; i < n; i++)
//{
//	if (p[i] == 'b')
//		s.pop();
//}
//return s.isEmpty();




//String s;
//for (int i = 0, j = s.getSize() - 1; i < j; i++, j--)
//{
//	if (s[i] != s[j])
//		return -1;
//}
//return 1;






















































