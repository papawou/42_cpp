#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
public:
	//iterators
	typedef typename std::stack<T>::container_type::iterator	iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

	iterator	begin(void);
	const_iterator	begin(void) const;
	reverse_iterator	rbegin(void);
	const_reverse_iterator rbegin(void) const;

	iterator	end(void);
	const_iterator	end(void) const;
	reverse_iterator	rend(void);
	const_reverse_iterator rend(void) const;

	MutantStack<T>(void);
	MutantStack<T>(MutantStack<T> const &);
	MutantStack<T> &operator=(MutantStack<T> const &);
	virtual ~MutantStack(void);
};

#include "MutantStack.tpp"

#endif