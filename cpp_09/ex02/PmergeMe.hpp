#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <sstream>
#include <iostream>

template <typename T>
class PmergeMe
{
public:
	static const int K = 10;
	class InvalidParseException : public std::exception
	{
		virtual const char *what() const throw();
	};

	static double bench(T &c, std::string const &str);
	static void	print_bench(T &c, std::string const &type, double time_elapsed);

	virtual ~PmergeMe<T>(void);
private:
	static void insert_sort(T &c);
	static void merge_sort(T &c);
	static T merge_sort_merge(T &left, T &right);
	static void parse(T &c, std::string const &str);

	PmergeMe<T>(void);
	PmergeMe<T>(PmergeMe const &);
	PmergeMe<T> &operator=(PmergeMe<T> const &);
};

template <typename T>
PmergeMe<T>::PmergeMe(void)
{
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe<T> const &rhs)
{
	(void)rhs;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(PmergeMe<T> const &rhs)
{
	*this = rhs;
}

template <typename T>
PmergeMe<T>::~PmergeMe(void)
{
}

template <typename T>
void PmergeMe<T>::insert_sort(T &c)
{
	typename T::iterator it(c.begin());
	typename T::iterator jt;
	typename T::iterator t;
	int tmp;
	int curr;

	if (it != c.end())
		++it;
	while (it != c.end())
	{
		curr = *it;
		jt = it;
		--jt;
		while (curr < *jt)
		{
			t = jt;
			++t;
			tmp = *t;
			*t = *jt;
			*jt = tmp;
			if (jt == c.begin())
				break;
			--jt;
		}
		++it;
	}
}

template <typename T>
T PmergeMe<T>::merge_sort_merge(T &left, T &right)
{
	T ret;
	typename T::iterator it_left;
	typename T::iterator it_right;

	it_left = left.begin();
	it_right = right.begin();
	while (it_left != left.end() && it_right != right.end())
	{
		if (*it_left <= *it_right)
		{
			ret.push_back(*it_left);
			++it_left;
		}
		else
		{
			ret.push_back(*it_right);
			++it_right;
		}
	}

	while (it_left != left.end())
	{
		ret.push_back(*it_left);
		++it_left;
	}

	while (it_right != right.end())
	{
		ret.push_back(*it_right);
		++it_right;
	}

	return (ret);
}

template <typename T>
void PmergeMe<T>::merge_sort(T &c)
{
	T left;
	T right;
	typename T::iterator mid;

	if (c.size() <= PmergeMe<T>::K)
	{
		PmergeMe<T>::insert_sort(c);
		return ;
	}
	mid = c.begin();
	std::advance(mid, c.size() / 2);
	left.insert(left.end(), c.begin(), mid);
	right.insert(right.end(), mid, c.end());
	PmergeMe<T>::merge_sort(left);
	PmergeMe<T>::merge_sort(right);
	c = PmergeMe<T>::merge_sort_merge(left, right);
}

template <typename T>
double PmergeMe<T>::bench(T &c, std::string const &str)
{
	clock_t start;
	clock_t end;

	PmergeMe<T>::parse(c, str);

	start = clock();
	PmergeMe<T>::merge_sort(c);
	end = clock();
	return static_cast<double>(end - start);
}

template <typename T>
void PmergeMe<T>::parse(T &c, std::string const &str)
{
	std::istringstream is(str);
	std::string tmp;
	int value;

	while (!is.eof())
	{
		tmp.clear();
		is >> tmp;
		for (std::string::iterator it = tmp.begin(); it != tmp.end(); ++it)
		{
			if (!isdigit(*it))
				throw PmergeMe::InvalidParseException();
		}
		if (tmp.length() == 0)
			continue;
		value = stoi(tmp);
		c.push_back(value);
	}
}

template <typename T>
void PmergeMe<T>::print_bench(T &c, std::string const &type, double time_elapsed)
{
	std::cout << type << ": ";
	for (typename T::iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << c.size() << " elements with std::" << type << " : " << std::fixed << time_elapsed / CLOCKS_PER_SEC << std::endl;
}

template <typename T>
const char *PmergeMe<T>::InvalidParseException::what() const throw()
{
	return ("error while parsing");
}

#endif