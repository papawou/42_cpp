#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	//iterators
	typedef typename Container::iterator	iterator;
	typedef typename Container::const_iterator	const_iterator;
	typedef typename Container::const_reverse_iterator	const_reverse_iterator;
	typedef typename Container::reverse_iterator	reverse_iterator;

	iterator	begin(void);
	const_iterator	begin(void) const;
	reverse_iterator	rbegin(void);
	const_reverse_iterator rbegin(void) const;

	iterator	end(void);
	const_iterator	end(void) const;
	reverse_iterator	rend(void);
	const_reverse_iterator rend(void) const;

	MutantStack<T, Container>(void);
	MutantStack<T, Container>(MutantStack<T, Container> const &);
	MutantStack<T, Container> &operator=(MutantStack<T, Container> const &);
	virtual ~MutantStack(void);
};

#include "MutantStack.tpp"

#endif