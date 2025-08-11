/*
	Author: Lior Refael Berkovits
	Reviewed by: Yaniv
	Date: 19/03/2025
*/

#include <iostream> // cout
#include <cassert> // assert
#include <stack> // stack
#include <set> // multiset
#include <queue> // queue
#include <map> // map
#include <cstdio> // cin, cout
#include <string> // string

using namespace std;

/*************************Forward-Declaration****************************/

static bool IsParenthesesBalanced(const char* expression);
static void ArrSort(int arr[], size_t size);
static void PrintInputWords(void);
static void InsertWords(queue<string>& q, map<string, size_t>& m);
static void PrintWords(queue<string>& q, map<string, size_t>& m);

/*******************************Main*************************************/

int main()
{
    int arr[] = {4,3,2,4,5,6,7,12,1};
    size_t size = 9;

    (IsParenthesesBalanced("<(1+2) * 4>{}")) ? cout << "1. Balanced\n" : cout << "1. Not Balanced\n";
	(IsParenthesesBalanced("<(1+2) * 4>{})")) ? cout << "2. Balanced\n" : cout << "2. Not Balanced\n";
	cout << endl;

    ArrSort(arr, size);
	cout << endl;

    PrintInputWords();

    return (0);
}

/*************************Static-Functions*******************************/

static bool IsParenthesesBalanced(const char* expression)
{
    stack<char> stack;
	
	assert(expression);
	
	while('\0' != *expression)
	{
		if('{' == *expression || '(' == *expression || '[' == *expression || '<' == *expression)
		{
			stack.push(*expression);
		}
		else if('}' == *expression || ')' == *expression || ']' == *expression || '>' == *expression)
		{
			if(!stack.empty() && (('}' == *expression && '{' == stack.top())
			                   || (')' == *expression && '(' == stack.top())
			                   || (']' == *expression && '[' == stack.top())
							   || ('>' == *expression && '<' == stack.top())))
			{
				stack.pop();
			}
			else
			{
				return (false);
			}
		}
		
		++expression;
	}

	return (stack.empty());
}

/************************************************************************/

static void ArrSort(int arr[], size_t size)
{
	multiset<int> s1;
	size_t i = 0;

    for(i = 0; i < size; ++i)
	{
		s1.insert(arr[i]);
	}

	i = 0;
	for(multiset<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter)
	{
		arr[i] = *iter;
		cout << *iter;
		++i;
		(i == size) ? cout << endl : cout << ", ";
	}
}

/************************************************************************/

static void PrintInputWords(void)
{
	queue<string> q;
	map<string, size_t> m;

	InsertWords(q, m);
	PrintWords(q, m);
}

static void InsertWords(queue<string>& q, map<string, size_t>& m)
{
	string s("");
	map<string, size_t>::iterator iter;

	while(s != ".")
	{
		getline(cin, s);
	
		if(m.find(s) == m.end())
		{
			q.push(s);
			m.insert(make_pair(s, 1));
		}
		else
		{
			++m[s];
		}
	}
	
	cout << endl;
}

static void PrintWords(queue<string>& q, map<string, size_t>& m)
{
	while(q.size() > 1)
	{
		size_t num = m[q.front()];
		(num == 1) ? cout << "" : cout << num << " x ";
		cout << q.front() << endl;
		q.pop();
	}
}

