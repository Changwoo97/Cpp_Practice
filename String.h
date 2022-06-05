#ifndef ___STRING_H__
#define ___STRING_H__

#include <iostream>
#pragma warning(disable:4996)
#define _INPUT_MAX 100

namespace cwl
{
  using namespace std;
  
	class _string
	{
	private:
		char* str;
		int len;
	public:
		_string();
		_string(const char* const _str);
		_string(const _string& _str);
		~_string();

		_string& operator= (const char* const _str);
		_string& operator= (const _string& _str);

		_string operator+ (const char* const _str) const;
		_string operator+ (const _string& _str) const;
		friend _string operator+ (const char* const _str1, const _string& _str2);

		_string& operator+= (const char* const _str);
		_string& operator+= (const _string& _str);

		bool operator== (const char* const _str) const;
		bool operator== (const _string& _str) const;
		friend bool operator== (const char* const _str1, const _string& _str2);

		char operator[] (const int index) const;

		friend istream& operator>> (istream& is, _string& _str);
		friend ostream& operator<< (ostream& os, const _string& _str);
	};

	_string::_string() : str(nullptr), len(0) {}
	_string::_string(const char* const _str)
	{
		this->len = (int)strlen(_str) + 1;
		this->str = new char[this->len];
		strcpy(this->str, _str);
	}
	_string::_string(const _string& _str)
	{
		this->len = _str.len;
		this->str = new char[this->len];
		strcpy(this->str, _str.str);
	}
	_string::~_string()
	{
		if (this->str != nullptr)
			delete[] this->str;
	}

	_string& _string::operator= (const char* const _str)
	{
		if (this->str != nullptr)
			delete[] this->str;
		this->len = (int)strlen(_str) + 1;
		this->str = new char[this->len];
		strcpy(this->str, _str);
		return *this;
	}
	_string& _string::operator= (const _string& _str)
	{
		if (this->str != nullptr)
			delete[] this->str;
		this->len = _str.len;
		this->str = new char[this->len];
		strcpy(this->str, _str.str);
		return *this;
	}

	_string _string::operator+ (const char* const _str) const
	{
		if (this->str == nullptr)
			return _string(_str);
		_string temp;
		temp.len = this->len + (int)strlen(_str);
		temp.str = new char[temp.len];
		strcpy(temp.str, this->str);
		strcat(temp.str, _str);
		return temp;
	}
	_string _string::operator+ (const _string& _str) const
	{
		if (this->str == nullptr)
			return _str;
		_string temp;
		temp.len = this->len + (int)strlen(_str.str);
		temp.str = new char[temp.len];
		strcpy(temp.str, this->str);
		strcat(temp.str, _str.str);
		return temp;
	}
	_string operator+ (const char* const _str1, const _string& _str2)
	{
		return _str2 + _str1;
	}

	_string& _string::operator+= (const char* const _str)
	{
		return *this = *this + _str;
	}
	_string& _string::operator+= (const _string& _str)
	{
		return *this = *this + _str;
	}

	bool _string::operator== (const char* const _str) const
	{
		if (strcmp(this->str, _str) == 0)
			return true;
		return false;
	}
	bool _string::operator== (const _string& _str) const
	{
		if (strcmp(this->str, _str.str) == 0)
			return true;
		return false;
	}
	bool operator== (const char* const _str1, const _string& _str2)
	{
		return _str2 == _str1;
	}

	char _string::operator[] (const int index) const
	{
		if ((this->str == nullptr) || (index < 0) || (this->len - 2 < index))
			return NULL;
		return this->str[index];
	}

	istream& operator>> (istream& is, _string& _str)
	{
		char temp[_INPUT_MAX];
		is >> temp;
		_str = temp;
		return is;
	}
	ostream& operator<< (ostream& os, const _string& _str)
	{
		os << _str.str;
		return os;
	}
}

#endif
