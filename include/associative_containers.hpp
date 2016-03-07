#ifndef ASSOCIATIVE_CONTAINER_HPP
#define ASSOCIATIVE_CONTAINER_HPP
#include <map>
#include <iostream>
#include <string>
#include <initializer_list>
#include <set>
#include <unordered_set>


class AssociativeContainer
{
	public:
		void associative_container_usage();
};

struct Record
{
	std::string label;
	int value;
};

struct Nocase_hash
{
	Nocase_hash(int d_var){d = d_var;}
	int d = 1;
	size_t operator()(const Record& r) const {
		size_t h = 0;
		for(auto charcter : r.label)
		{
			h <<= d;
			h ^=  toupper(charcter);
		}
		return h;
	}
};

struct Nocase_equal
{
	bool operator()(const Record& r1, const Record& r2) const //these function needs to be const
	{
		if(r1.label.size() != r2.label.size())
			return false;
		for(size_t index = 0; index < r1.label.size(); index++)
		{
			if(toupper(r1.label[index]) != toupper(r2.label[index]))
				return false;
		}
		return true;
	}
};

#endif
