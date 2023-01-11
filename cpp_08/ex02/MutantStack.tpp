#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

//iterators
template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template<class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template<class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin(void) const
{
	return (this->c.rbegin());
}

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (this->c.end());
}

template<class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template<class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend(void) const
{
	return (this->c.rend());
}

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &mt) : std::stack<T>(mt)
{
	*this = mt;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &mt)
{
	if (this != &mt)
		*this = mt;
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
}

#endif