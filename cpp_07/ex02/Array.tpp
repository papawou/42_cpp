#ifndef ARRAY_TPP
# define ARRAY_TPP

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return _size;
}

template<typename T>
T&	Array<T>::operator[](unsigned int idx)
{
	if (idx < 0 || idx >= _size)
		throw std::exception();
	return _data[idx];
}

template<typename T>
T	Array<T>::operator[](unsigned int idx) const
{
	if (idx < 0 || idx >= _size)
		throw std::exception();
	return _data[idx];
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(new T[_size]())
{
}

template<typename T>
Array<T>::Array(void) : _size(0), _data(new T[_size]())
{
}

template<typename T>
Array<T>::Array(Array<T> const &copy) : _size(copy._size), _data(new T[_size]())
{
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = copy._data[i];
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		delete [] _data;
		_size = rhs._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = rhs._data[i];	
	}
	return (*this);
}

template<typename T>
Array<T>::~Array<T>(void)
{
	delete [] _data;
}

#endif