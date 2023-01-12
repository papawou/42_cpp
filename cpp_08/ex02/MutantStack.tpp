#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

//iterators
template<class T, class Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template<class T, class Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::begin(void) const
{
	return (this->c.begin());
}

template<class T, class Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin(void)
{
	return (this->c.rbegin());
}

template<class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rbegin(void) const
{
	return (this->c.rbegin());
}

template<class T, class Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

template<class T, class Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::end(void) const
{
	return (this->c.end());
}

template<class T, class Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend(void)
{
	return (this->c.rend());
}

template<class T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rend(void) const
{
	return (this->c.rend());
}

template<typename T, class Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>()
{
}

template<typename T, class Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &mt) : std::stack<T, Container>(mt)
{
	*this = mt;
}

template<typename T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack<T, Container> const &mt)
{
	if (this != &mt)
		*this = mt;
	return (*this);
}

template<typename T, class Container>
MutantStack<T, Container>::~MutantStack(void)
{
}

#endif