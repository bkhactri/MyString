#include"MyString.h"
//CONSTRUCTOR and DESTROYER and OPERATOR =
MyString::MyString()
{
	this->_length = 0;
	this->_capacity = 15;
	this->_p = new char[1];
	this->_p[0] = NULL;
}
MyString::MyString(const MyString& str)
{
	this->_length = strlen(str._p);
	this->_capacity = str._capacity;
	this->_p = new char[_length + 1];
	for (int i = 0; i < _length; i++)
	{
		this->_p[i] = str._p[i];
	}
	this->_p[_length] = NULL;
}
MyString::MyString(const MyString& str, size_t pos, size_t npos)
{
	this->_length = strlen(str._p);
	this->_capacity = _length;
	this->_p = new char[int(npos) + 1];
	for (int i = 0; i < int(npos); i++)
	{
		if (int(pos + i) < strlen(str._p))
		{
			this->_p[i] = str._p[pos + i];
		}
		else break;
	}
	this->_p[int(npos)] = NULL;
}
MyString::MyString(const char* s)
{
	this->_length = strlen(s);
	this->_capacity = _length;
	this->_p = new char[_length + 1];
	for (int i = 0; i < _length; i++)
	{
		this->_p[i] = s[i];
	}
	this->_p[_length] = NULL;
}
MyString::MyString(const char* s, size_t n)
{
	this->_length = strlen(s);
	this->_capacity = int(n);
	this->_p = new char[int(n) + 1];
	for (int i = 0; i < int(n); i++)
	{
		this->_p[i] = s[i];
	}
	this->_p[int(n)] = NULL;
}
MyString::MyString(size_t n, char c)
{
	this->_length = int(n);
	this->_capacity = _length;
	this->_p = new char[int(n) + 1];
	for (int i = 0; i < int(n); i++)
	{
		this->_p[i] = c;
	}
	this->_p[int(n)] = NULL;
}

MyString::~MyString()
{
	delete[] _p;
}

MyString& MyString::operator=(const MyString& str) 
{
	if (this->_p != NULL) delete[] this->_p;
	this->MyString::MyString(str);
	return *this;
}
MyString& MyString::operator=(const char* s) 
{
	if (this->_p != NULL) delete[] this->_p;
	this->MyString::MyString(s);
	return *this;
}
MyString& MyString::operator=(char c) 
{
	return *this;
}

//CAPACITY
size_t MyString::size() const
{
	return  strlen(this->_p);
}
size_t MyString::length() const
{
	return  strlen(this->_p);
}
size_t MyString::max_size() const
{
	size_t max;
	return max = -1;
}
void MyString::resize(size_t n)
{
	if (n <= _length)
	{
		this->_p[n] = NULL;
	}
	else
	{
		char* str = new char[_length + 1];
		for (int i = 0; i < _length; i++)
		{
			str[i] = _p[i];
		}
		_p = new char[n + 1];
		for (int i = 0; i < n; i++)
		{
			if (i < _length) 
			{
				_p[i] = str[i];
			}
			else
			{
				_p[i] = NULL;
			}
		}
		_p[n] = NULL;
	}
}
void MyString::resize(size_t n, char c)
{
	if (n <= _length)
	{
		this->_p[n] = NULL;
	}
	else
	{
		char* str = new char[_length + 1];
		for (int i = 0; i < _length; i++)
		{
			str[i] = _p[i];
		}
		_p = new char[n + 1];
		for (int i = 0; i < n; i++)
		{
			if (i < _length)
			{
				_p[i] = str[i];
			}
			else
			{
				_p[i] = c;
			}
		}
		_p[n] = NULL;
	}
}
size_t MyString::capacity() const
{
	if (this->_capacity <= 15)
	{
		return  15;
	}
	else
	{
		return  15 + ((_capacity / 15)) * 16;
	}
}
void MyString::reserve(size_t n)
{
	if (n >= this->_capacity)
	{
		this->_capacity += 16;
	}
}
void MyString::clear()
{
	this->MyString::MyString();
}
bool MyString::empty() const
{
	if (this->size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void MyString::shrink_to_fit()
{
	int size = _capacity = _length = this->size();
	char* s = new char[size];
	for (int i = 0; i < size; i++)
	{
		s[i] = _p[i];
	}
	_p = new char[size];
	for (int i = 0; i < size; i++)
	{
		_p[i] = s[i];
	}
	_p[size] = NULL;
	delete[] s;
}


//ELEMENT ACCESS
char& MyString::operator[](size_t pos) 
{
	char c;
	if (pos >= strlen(this->_p)) 
	{
		return c = NULL;
	}
	return this->_p[pos];
}
const char& MyString::operator[](size_t pos) const 
{
	char c;
	if (pos >= strlen(this->_p))
	{
		return c = NULL;
	}
	return this->_p[pos];
}
char& MyString::at(size_t pos) {
	try
	{
		if (pos >= strlen(this->_p))
		{
			throw  (1);
		}
		else
		{
			return this->_p[pos];
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (at) function." << endl;
		exit(-1073740791);
	}
}
const char& MyString::at(size_t pos) const {
	try
	{
		if (pos >= strlen(this->_p))
		{
			throw  (1);
		}
		else
		{
			return this->_p[pos];
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (at) function." << endl;
		exit(-1073740791);
	}
}
char& MyString::back() 
{
	char c;
	if (strlen(this->_p) == 0) 
	{
		return c = NULL;
	}
	else
	{
		return this->_p[strlen(this->_p) - 1];
	}
}
const char& MyString::back() const 
{
	char c;
	if (strlen(this->_p) == 0)
	{
		return c = NULL;
	}
	else
	{
		return this->_p[strlen(this->_p) - 1];
	}
}
char& MyString::front() 
{
	char c;
	if (strlen(this->_p) == 0)
	{
		return c = NULL;
	}
	else
	{
		return this->_p[0];
	}
}
const char& MyString::front() const 
{
	char c;
	if (strlen(this->_p) == 0) 
	{
		return c = NULL;
	}
	else
	{
		return this->_p[0];
	}
}



//MODIFIERS
MyString& MyString::operator+=(const MyString& str)
{
	*this = *this + str;
	return *this;
}
MyString& MyString::operator+=(const char* str) 
{
	*this = *this + str;
	return *this;
}
MyString& MyString::operator+=(char c) 
{
	*this = *this + c;
	return *this;
}

MyString& MyString::append(const MyString& str) 
{
	*this += str;
	return *this;
}
MyString& MyString::append(const MyString& str, size_t subpos, size_t sublen) 
{
	try
	{
		if (subpos > str.size())
		{
			throw  (4);
		}
		else {
			if (subpos + sublen < sublen)
				for (size_t i = subpos; i < strlen(str._p); i++)
				{
					*this += str._p[i];
				}
			else 
			{
				if (subpos + sublen < strlen(str._p))
				{
					for (size_t i = subpos; i < subpos + sublen; i++)
					{
						*this += str._p[i];
					}
				}
				else
				{
					for (size_t i = subpos; i < strlen(str._p); i++)
					{
						*this += str._p[i];
					}
				}
			}
		}
		return *this;
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (append) function." << endl;
		exit(-1073740791);
	}
}
MyString& MyString::append(const char* str) 
{
	*this += str;
	return *this;
}
MyString& MyString::append(const char* str, size_t n) 
{
	try
	{
		if (n > strlen(str))
		{
			throw  (4);
		}
		else {
			for (size_t i = 0; i < n; i++)
			{
				*this += str[i];
			}
			return *this;
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (append) function." << endl;
		exit(-1073740791);
	}
}
MyString& MyString::append(size_t n, char c) 
{
	try
	{
		if (strlen(this->_p) + n < n)
		{
			throw  (4);
		}
		else {
			for (size_t i = 0; i < n; i++)
			{
				*this += c;
			}
			return *this;
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (append) function." << endl;
		exit(-1073740791);
	}
}

void MyString::push_back(char c) 
{
	*this += c;
}

MyString& MyString::assign(const MyString& str) 
{
	*this = str;
	return *this;
}
MyString& MyString::assign(const MyString& str, size_t subpos, size_t sublen) 
{
	MyString strTemp(str, subpos, sublen);
	*this = strTemp;
	return *this;
}
MyString& MyString::assign(const char* s) 
{
	MyString str(s);
	*this = str;
	return *this;
}
MyString& MyString::assign(const char* s, size_t n) 
{
	MyString str(s, n);
	*this = str;
	return *this;
}
MyString& MyString::assign(size_t n, char c) 
{
	MyString str(n, c);
	*this = str;
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str) 
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (5);
		}
		else 
		{
			MyString str1(this->_p, 0, pos);
			MyString str2 = str;
			MyString str3(*this, pos, strlen(this->_p)-pos);
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (insert) function." << endl;
		exit(-1073740791);
	}
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen) 
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (5);
		}
		else if (subpos > strlen(str._p))
		{
			throw  (6);
		}
		else 
		{
			MyString str1(this->_p, 0, pos);
			MyString str2(str, subpos, sublen);
			MyString str3(*this, pos, strlen(this->_p)-pos);
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		if (error == 5)
		{
			cout << "Error out of range: " << error << ": error in (insert) function." << endl;
			exit(-1073740791);
		}
		else if (error == 6)
		{
			cout << "Error of length: " << error << ": error in (insert) function." << endl;
			exit(-1073740791);
		}
	}
}
MyString& MyString::insert(size_t pos, const char* s) 
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (5);
		}
		else
		{
			MyString str1(this->_p, 0, pos);
			MyString str2(s);
			MyString str3(*this, pos, strlen(this->_p)-pos);
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (insert) function." << endl;
		exit(-1073740791);
	}
}
MyString& MyString::insert(size_t pos, const char* s, size_t n) 
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (8);
		}
		else if (n > strlen(s))
		{
			throw  (9);
		}
		else
		{
			MyString str1(this->_p, 0, pos);
			MyString str2(s, n);
			MyString str3(*this, pos, strlen(this->_p)-pos);
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		if (error == 8)
		{
			cout << "Error out of range code: " << error << ": error in (insert) function." << endl;
			exit(-1073740791);
		}
		else if (error == 9)
		{
			cout << "Error of length code: " << error << ": error in (insert) function." << endl;
			exit(-1073740791);
		}
	}
}
MyString& MyString::insert(size_t pos, size_t n, char c) 
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (5);
		}
		else
		{
			MyString str1(this->_p, 0, pos);
			MyString str2(n, c);
			MyString str3(*this, pos, strlen(this->_p)-pos);
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (insert) function." << endl;
		exit(-1073740791);
	}
}

MyString& MyString::erase(size_t pos, size_t len)
{
	char* strTemp;
	if (int(len) >= 0)
	{
		int l = 0;
		strTemp = new char[strlen(this->_p)];
		for (int i = 0; i < strlen(this->_p); i++)
		{
			if (i < pos || i >= pos + len)
			{
				strTemp[l] = this->_p[i];
				l++;
			}
		}

		this->_p = new char[l + 1];
		for (int i = 0; i < l; i++)
		{
			this->_p[i] = strTemp[i];
		}
		this->_p[l] = NULL;
		delete[] strTemp;
		return *this;
	}
	else
	{
		int l = 0;
		strTemp = new char[strlen(this->_p) + 1];
		for (int i = 0; i < strlen(this->_p); i++)
		{
			if (i < pos)
			{
				strTemp[l] = this->_p[i];
				l++;
			}
		}

		this->_p = new char[l + 1];
		for (int i = 0; i < l; i++)
		{
			this->_p[i] = strTemp[i];
		}
		this->_p[l] = NULL;

		delete[] strTemp;
		return *this;
	}
}

MyString& MyString::replace(size_t pos, size_t len, const MyString& str) 
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (10);
		}
		else
		{
			MyString str1(*this, 0, pos);
			MyString str2 = str;
			MyString str3;
			if (pos + len == len) 
			{
				if (pos + len < strlen(this->_p))
				{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
				}
			}
			else if (pos + len > len&& pos + len < strlen(this->_p)) 
			{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
			}
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (replace) function." << endl;
		exit(-1073740791);
	}
}
MyString& MyString::replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) 
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (10);
		}
		else if (subpos > strlen(str._p))
		{
			throw  (11);
		}
		else
		{
			MyString str1(*this, 0, pos);
			MyString str2(str, subpos, sublen);
			MyString str3;
			if (pos + len == len) 
			{
				if (pos + len < strlen(this->_p))
				{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
				}
			}
			else if (pos + len > len&& pos + len < strlen(this->_p)) 
			{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
			}
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		if (error == 10)
		{
			cout << "Error out of range: " << error << ": error in (replace) function." << endl;
			exit(-1073740791);
		}
		else if (error == 11)
		{
			cout << "Error of length: " << error << ": error in (replace) function." << endl;
			exit(-1073740791);
		}
	}
}
MyString& MyString::replace(size_t pos, size_t len, const char* s) 
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (10);
		}
		else
		{
			MyString str1(*this, 0, pos);
			MyString str2(s);
			MyString str3;
			if (pos + len == len) 
			{
				if (pos + len < strlen(this->_p))
				{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
				}
			}
			else if (pos + len > len&& pos + len < strlen(this->_p)) 
			{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
			}
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (replace) function." << endl;
		exit(-1073740791);
	}
}
MyString& MyString::replace(size_t pos, size_t len, const char* s, size_t n) 
{
	try
	{
		if (n > strlen(s))
		{
			throw  (11);
		}
		else if (pos > strlen(this->_p))
		{
			throw  (10);
		}
		else
		{
			MyString str1(*this, 0, pos);
			MyString str2(s, n);
			MyString str3;
			if (pos + len == len) {
				if (pos + len < strlen(this->_p))
				{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
				}
			}
			else if (pos + len > len&& pos + len < strlen(this->_p)) 
			{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
			}
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		if (error == 10)
		{
			cout << "Error out of range: " << error << ": error in (replace) function." << endl;
			exit(-1073740791);
		}
		else if (error == 11)
		{
			cout << "Error of length: " << error << ": error in (replace) function." << endl;
			exit(-1073740791);
		}
	}
}
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c) {

	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (10);
		}
		else
		{
			MyString str1(*this, 0, pos);
			MyString str2(n, c);
			MyString str3;
			if (pos + len == len) {
				if (pos + len < strlen(this->_p))
				{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
				}
			}
			else if (pos + len > len&& pos + len < strlen(this->_p)) 
			{
					str3.assign(*this, pos + len, strlen(this->_p) - (pos + len));
			}
			*this = str1 + str2 + str3;
			return *this;
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (replace) function." << endl;
		exit(-1073740791);
	}
}

void MyString::swap(MyString& str)
{
	MyString strTemp = *this;
	* this = str;
	str = strTemp;
}

void MyString::pop_back() 
{
	MyString str(*this);
	this->MyString::~MyString();
	this->MyString::MyString(str, 0, str.length() - 1);
}


//STRING OPERATIONS
const char* MyString::c_str() const
{
	return this->_p;
}
const char* MyString::data() const
{
	return this->_p;
}

allocator<char> MyString::get_allocator() const
{
	allocator<char> s;
	char* strTemp = s.allocate(_length);
	strcpy(strTemp, _p);
	strTemp[_length] = '\0';
	return s;
}

size_t MyString::copy(char* s, size_t len, size_t pos) const
{
	if (pos > strlen(this->_p)) return 0;
	if (pos + len > strlen(this->_p)) 
	{
		for (int i = 0; i < strlen(this->_p) - pos; i++) 
		{
			s[i] = this->_p[pos + i];
		}
		return strlen(this->_p) - pos;
	}
	else 
	{
		for (int i = 0; i < len; i++)
		{
			s[i] = this->_p[pos + i];
		}
		return len;
	}
}

size_t MyString::find(const MyString& str, size_t pos) const 
{
	for (int i = int(pos); i < strlen(this->_p); i++)
	{
		bool flat = true;
		for (int j = 0; j < strlen(str._p); j++)
		{
			if (this->_p[i + j] != str._p[j])
			{
				flat = false;
			}
		}
		if (flat == true)
		{
			return size_t(i);
		}
	}
}
size_t MyString::find(const char* s, size_t pos) const 
{
	for (int i = int(pos); i < strlen(this->_p); i++)
	{
		bool flat = true;
		for (int j = 0; j < strlen(s); j++) 
		{
			if (this->_p[i + j] != s[j]) 
			{
				flat = false;
			}
		}
		if (flat == true) 
		{
			return size_t(i);
		}
	}
}
size_t MyString::find(const char* s, size_t pos, size_t n) const 
{
	for (int i = int(pos); i < strlen(this->_p); i++) 
	{
		bool flat = true;
		for (int j = 0; j < int(n); j++) 
		{
			if (this->_p[i + j] != s[j]) flat = false;
		}
		if (flat == true) 
		{
			return size_t(i);
		}
	}
}
size_t MyString::find(char c, size_t pos) const 
{
	for (int i = int(pos); i < strlen(this->_p); i++) 
	{
		if (this->_p[i] == c) 
		{
			return size_t(i);
		}
	}
}

size_t MyString::rfind(const MyString& str, size_t pos) const 
{
	size_t locate = -1;
	for (int i = 0; i < strlen(this->_p) - pos; i++) 
	{
		bool flat = true;
		for (int j = 0; j < strlen(str._p); j++) 
		{
			if (this->_p[i + j] != str._p[j]) 
			{
				flat = false;
			}
		}
		if (flat == true) 
		{
			locate = i;
		}
	}
	return locate;
}
size_t MyString::rfind(const char* s, size_t pos) const 
{
	size_t locate = -1;
	for (int i = 0; i < strlen(this->_p) - pos; i++)
	{
		bool flat = true;
		for (int j = 0; j < strlen(s); j++) 
		{
			if (this->_p[i + j] != s[j])
			{
				flat = false;
			}
		}
		if (flat == true) 
		{
			locate = i;
		}
	}
	return locate;
}
size_t MyString::rfind(const char* s, size_t pos, size_t n) const
{
	size_t locate = -1;
	for (int i = 0; i < strlen(this->_p) - pos; i++)
	{
		bool flat = true;
		for (int j = 0; j < int(n); j++) 
		{
			if (this->_p[i + j] != s[j]) 
			{
				flat = false;
			}
		}
		if (flat == true) 
		{
			locate = i;
		}
	}
	return locate;
}
size_t MyString::rfind(char c, size_t pos) const 
{
	size_t locate = -1;
	for (int i = 0; i < strlen(this->_p) - pos; i++) 
	{
		if (this->_p[i] == c) 
		{
			locate = i;
		}
	}
	return locate;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw (13);
		}
		else
		{
			char* temp;
			if (pos == strlen(this->_p))
			{
				temp = new char;
				MyString strTemp(temp);
				return strTemp;
			}
			else
			{
				size_t n = strlen(this->_p) - pos;
				if (len > n)
				{
					len = n;
				}
				temp = new char[len + 1];
				for (int i = 0; i < len; i++)
				{
					temp[i] = this->_p[pos + i];
				}
				temp[len] = NULL;
				MyString strTemp(temp);
				return strTemp;
			}
		}
	}
	catch (int error)
	{
		cout << "Error out of range: " << error << ": error in (substr) function." << endl;
		exit(-1073740791);
	}
}

int MyString::compare(const MyString& str) const 
{
	if (this->_length < str._length) 
	{ 
		for (int i = 0; i < this->_length; i++)
		{
			if (this->_p[i] < str._p[i]) return -1;
			else if (this->_p[i] > str._p[i]) return 1;
		}
		return 0;
	}
	else if (this->_length >= str._length)
	{
		for (int i = 0; i < str._length; i++)
		{
			if (this->_p[i] < str._p[i]) return -1;
			else if (this->_p[i] > str._p[i]) return 1;
		}
		return 0;
	}
}
int MyString::compare(size_t pos, size_t len, const MyString& str) const 
{
	try
	{
		if (pos > strlen(this->_p))
		{
			throw  (2);
		}
		else
		{
			MyString result(*this, pos, len);
			return result.compare(str);
		}
	}
	catch (int error)
	{
		cout << "Error " << error << ": error in (compare) function." << endl;
		exit(-1073740791);
	}
}
int MyString::compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const 
{
	MyString str1(*this, pos, len);
	MyString str2(str, subpos, sublen);
	return str1.compare(str2);
}
int MyString::compare(const char* s) const 
{
	MyString str(s);
	return (*this).compare(str);
}
int MyString::compare(size_t pos, size_t len, const char* s) const
{
	MyString str1(*this, pos, len);
	MyString str2(s);
	return str1.compare(str2);
}
int MyString::compare(size_t pos, size_t len, const char* s, size_t n) const 
{
	MyString str1(*this, pos, len);
	MyString str2(s, n);
	return str1.compare(str2);
}




//NON-MEMBER FUNCTION OVERLOADS
MyString operator+ (const MyString& lhs, const MyString& rhs)
{
	int dem = 0;
	char* temp1 = new char[lhs.size() + 1];
	char* temp2 = new char[rhs.size() + 1];
	char* str = new char[lhs.size() + rhs.size() + 1];
	for (int i = 0; i < lhs.size(); i++)
	{
		temp1[i] = lhs[i];
	}
	temp1[lhs.size()] = NULL;
	for (int i = 0; i < rhs.size(); i++)
	{
		temp2[i] = rhs[i];
	}
	temp2[rhs.size()] = NULL;
	for (int i = 0; i < strlen(temp1); i++)
	{
		str[dem++] = temp1[i];
	}
	for (int i = 0; i < strlen(temp2); i++)
	{
		str[dem++] = temp2[i];
	}
	str[lhs.size() + rhs.size()] = NULL;
	MyString tmp(str);
	return tmp;
}
MyString operator+ (const MyString& lhs, const char* rhs)
{
	int dem = 0;
	char* temp1 = new char[lhs.size() + 1];
	char* temp2 = new char[strlen(rhs) + 1];
	char* str = new char[lhs.size() + strlen(rhs) + 1];
	for (int i = 0; i < lhs.size(); i++)
	{
		temp1[i] = lhs[i];
	}
	temp1[lhs.size()] = NULL;
	for (int i = 0; i < strlen(rhs); i++)
	{
		temp2[i] = rhs[i];
	}
	temp2[strlen(rhs)] = NULL;
	for (int i = 0; i < strlen(temp1); i++)
	{
		str[dem++] = temp1[i];
	}
	for (int i = 0; i < strlen(temp2); i++)
	{
		str[dem++] = temp2[i];
	}
	str[lhs.size() + strlen(rhs)] = NULL;
	MyString tmp(str);
	return tmp;
}
MyString operator+ (const char* lhs, const MyString& rhs)
{
	int dem = 0;
	char* temp1 = new char[strlen(lhs) + 1];
	char* temp2 = new char[rhs.size() + 1];
	char* str = new char[strlen(lhs) + rhs.size() + 1];
	for (int i = 0; i < strlen(lhs); i++)
	{
		temp1[i] = lhs[i];
	}
	temp1[strlen(lhs)] = NULL;
	for (int i = 0; i < rhs.size(); i++)
	{
		temp2[i] = rhs[i];
	}
	temp2[rhs.size()] = NULL;
	for (int i = 0; i < strlen(temp1); i++)
	{
		str[dem++] = temp1[i];
	}
	for (int i = 0; i < strlen(temp2); i++)
	{
		str[dem++] = temp2[i];
	}
	str[strlen(lhs) + rhs.size()] = NULL;
	MyString tmp(str);
	return tmp;
}
MyString operator+ (const MyString& lhs, char rhs)
{
	int dem = 0;
	char* temp1 = new char[lhs.size() + 1];
	char* str = new char[lhs.size() + 2];
	for (int i = 0; i < lhs.size(); i++)
	{
		temp1[i] = lhs[i];
	}
	temp1[lhs.size()] = NULL;
	for (int i = 0; i < strlen(temp1); i++)
	{
		str[dem++] = temp1[i];
	}
	str[dem++] = rhs;
	str[lhs.size() + 1] = NULL;
	MyString tmp(str);
	return tmp;

}
MyString operator+ (char lhs, const MyString& rhs)
{
	int dem = 0;
	char* temp1 = new char[rhs.size() + 1];
	char* str = new char[rhs.size() + 2];
	for (int i = 0; i < rhs.size(); i++)
	{
		temp1[i] = rhs[i];
	}
	temp1[rhs.size()] = NULL;
	str[dem++] = lhs;
	for (int i = 0; i < strlen(temp1); i++)
	{
		str[dem++] = temp1[i];
	}
	str[1 + strlen(temp1)] = NULL;
	MyString tmp(str);
	return tmp;

}




bool operator== (const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) == 0)
	{
		return 1;
	}
	return 0;
}
bool operator== (const char* lhs, const MyString& rhs) 
{
	MyString str(lhs);
	if (str.compare(rhs) == 0)
	{
		return 1;
	}
	return 0;
}
bool operator== (const MyString& lhs, const char* rhs) 
{
	if (lhs.compare(rhs) == 0)
	{ 
		return 1; 
	}
	return 0;
}

bool operator!= (const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) != 0)
	{
		return 1;
	}
	return 0;
}
bool operator!= (const char* lhs, const MyString& rhs) 
{
	MyString str(lhs);
	if (str.compare(rhs) != 0)
	{
		return 1;
	}
	return 0;
}
bool operator!= (const MyString& lhs, const char* rhs)
{
	if (lhs.compare(rhs) != 0) 
	{ 
		return 1;
	}
	return 0;
}

bool operator< (const MyString& lhs, const MyString& rhs) 
{
	if (lhs.compare(rhs) < 0) 
	{ 
		return 1; 
	}
	return 0;
}
bool operator< (const char* lhs, const MyString& rhs) 
{
	MyString str(lhs);
	if (str.compare(rhs) < 0)
	{
		return 1;
	}
	return 0;
}
bool operator< (const MyString& lhs, const char* rhs) 
{
	if (lhs.compare(rhs) < 0)
	{
		return 1;
	}
	return 0;
}

bool operator<= (const MyString& lhs, const MyString& rhs) 
{
	if (lhs.compare(rhs) <= 0)
	{ 
		return 1; 
	}
	return 0;
}
bool operator<= (const char* lhs, const MyString& rhs)
{
	MyString str(lhs);
	if (str.compare(rhs) <= 0) 
	{ 
		return 1; 
	}
	return 0;
}
bool operator<= (const MyString& lhs, const char* rhs)
{
	if (lhs.compare(rhs) <= 0) 
	{ 
		return 1;
	}
	return 0;
}

bool operator> (const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) > 0)
	{
		return 1;
	}
	return 0;
}
bool operator> (const char* lhs, const MyString& rhs)
{
	MyString str(lhs);
	if (str.compare(rhs) > 0)
	{
		return 1;
	}
	return 0;
}
bool operator> (const MyString& lhs, const char* rhs) 
{
	if (lhs.compare(rhs) > 0) 
	{ 
		return 1; 
	}
	return 0;
}

bool operator>= (const MyString& lhs, const MyString& rhs) 
{
	if (lhs.compare(rhs) >= 0)
	{
		return 1;
	}
	return 0;
}
bool operator>= (const char* lhs, const MyString& rhs) 
{
	MyString str(lhs);
	if (str.compare(rhs) >= 0)
	{
		return 1;
	}
	return 0;
}
bool operator>= (const MyString& lhs, const char* rhs) 
{
	if (lhs.compare(rhs) >= 0)
	{
		return 1;
	}
	return 0;
}

void swap(MyString& x, MyString& y)
{
	MyString strTemp = x;
	x = y;
	y = strTemp;
}

istream& operator>>(istream& is, MyString& str)
{
	delete[] str._p;
	str.MyString::MyString();
	char c;
	while (is.get(c))
	{
		if (c != '\n' && c != ' ') break;
	}
	str += c;
	while (is.get(c) && c != '\n' && c != ' ')
	{
		str += c;
	}
	return is;
}
ostream& operator<<(ostream& os, const  MyString& str)
{
	for (int i = 0; i < strlen(str._p); i++)
	{
		os << str._p[i];
	}
	return os;
}

istream& getline(istream& is, MyString& str, char delim)
{
	delete[] str._p;
	str.MyString::MyString();
	char c;
	while (is.get(c) && c != delim)
	{
		str += c;
	}
	return is;
}
istream& getline(istream& is, MyString& str)
{
	is.clear();
	delete[] str._p;
	str.MyString::MyString();
	char c;
	while (is.get(c) && c != '\n')
	{
		str += c;
	}
	return is;
}