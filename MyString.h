#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include"MyIterator.h"
using namespace std;
class MyString
{
private:
	char* _p;
	size_t _length;
	size_t _capacity;

public: // typedef
	typedef MyIterator<char> iterator;
	typedef MyIterator<const char> const_iterator;
	typedef reverse_MyIterator<char> reverse_iterator;
	typedef reverse_MyIterator<const char> const_reverse_iterator;
	typedef reverse_MyIterator<const char> const_reverse_iterator;

public: //Constructor and destroyer and operator =
	static const size_t npos = -1;
	MyString();
	MyString(const MyString& str);
	MyString(const MyString& str, size_t pos, size_t npos);
	MyString(const char* s);
	MyString(const char* str, size_t n);
	MyString(size_t n, char c);
	MyString(iterator first, iterator last);
	~MyString();
	MyString& operator=(const MyString& s);
	MyString& operator=(const char* s);
	MyString& operator=(char c);


public: //Iterator
	iterator begin();
	iterator end();

	const_iterator cbegin();
	const_iterator cend();

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator crbegin();
	const_reverse_iterator crend();

public: //Capacity:
	size_t size() const;
	size_t length() const;
	size_t max_size() const;
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t capacity() const;
	void reserve(size_t n = npos);
	void clear();
	bool empty() const;
	void shrink_to_fit();


public: //Element access
	char& operator[](size_t pos);
	const char& operator[](size_t pos) const;

	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;


public: //Modifiers
	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);

	MyString& append(const MyString& str);
	MyString& append(const MyString& str, size_t subpos, size_t sublen);
	MyString& append(const char* s);
	MyString& append(const char* s, size_t n);
	MyString& append(size_t n, char c);
	MyString& append(iterator first, iterator last);

	void push_back(char c);

	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_t subpos, size_t sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, size_t n);
	MyString& assign(size_t n, char c);
	MyString& assign(iterator first, iterator last);

	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);
	void insert(iterator p, size_t n, char c);
	iterator insert(iterator p, char c);
	void insert(iterator p, iterator first, iterator last);

	MyString& erase(size_t pos = npos, size_t len = npos);
	iterator erase(iterator p);
	iterator erase(iterator first, iterator last);

	MyString& replace(size_t pos, size_t len, const MyString& str);
	MyString& replace(iterator i1, iterator i2, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(iterator i1, iterator i2, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(iterator i1, iterator i2, const char* s, size_t n);
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	MyString& replace(iterator i1, iterator i2, size_t n, char c);
	MyString& replace(iterator i1, iterator i2, iterator first, iterator last);

	void swap(MyString& str);

	void pop_back();


public: //String operations
	const char* c_str() const;
	const char* data() const;

	allocator<char>get_allocator() const;

	size_t copy(char* s, size_t len, size_t pos = npos) const;

	size_t find(const MyString& str, size_t pos = npos) const;
	size_t find(const char* s, size_t pos = npos) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = npos) const;

	size_t rfind(const MyString& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;

	MyString substr(size_t pos = npos, size_t len = npos) const;

	size_t find_first_of(const MyString& b, size_t pos = npos) const;
	size_t find_first_of(const char* s, size_t pos = npos) const;
	size_t find_first_of(const char* s, size_t pos, size_t n);
	size_t find_first_of(char c, size_t pos = npos) const;

	size_t find_last_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;

	size_t find_first_not_of(const MyString& str, size_t pos = npos) const;
	size_t find_first_not_of(const char* s, size_t pos = npos) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = npos) const;

	size_t find_last_not_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;

	int compare(const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;



public: //Non-member function overloads
	friend MyString operator+ (const MyString& lhs, const MyString& rhs);
	friend MyString operator+ (const MyString& lhs, const char* rhs);
	friend MyString operator+ (const char* lhs, const MyString& rhs);
	friend MyString operator+ (const MyString& lhs, char rhs);
	friend MyString operator+ (char lhs, const MyString& rhs);

	friend bool operator== (const MyString& lhs, const MyString& rhs);
	friend bool operator== (const char* lhs, const MyString& rhs);
	friend bool operator== (const MyString& lhs, const char* rhs);
	friend bool operator!= (const MyString& lhs, const MyString& rhs);
	friend bool operator!= (const char* lhs, const MyString& rhs);
	friend bool operator!= (const MyString& lhs, const char* rhs);
	friend bool operator<  (const MyString& lhs, const MyString& rhs);
	friend bool operator<  (const char* lhs, const MyString& rhs);
	friend bool operator<  (const MyString& lhs, const char* rhs);
	friend bool operator<=  (const MyString& lhs, const MyString& rhs);
	friend bool operator<=  (const char* lhs, const MyString& rhs);
	friend bool operator<=  (const MyString& lhs, const char* rhs);
	friend bool operator>  (const MyString& lhs, const MyString& rhs);
	friend bool operator>  (const char* lhs, const MyString& rhs);
	friend bool operator>  (const MyString& lhs, const char* rhs);
	friend bool operator>=  (const MyString& lhs, const MyString& rhs);
	friend bool operator>=  (const char* lhs, const MyString& rhs);
	friend bool operator>=  (const MyString& lhs, const char* rhs);

	friend void swap(MyString& x, MyString& y);

	friend istream& operator>>(istream& is, MyString& str);
	friend ostream& operator<<(ostream& os, const  MyString& str);

	friend istream& getline(istream& is, MyString& str, char delim);
	friend istream& getline(istream& is, MyString& str);
};