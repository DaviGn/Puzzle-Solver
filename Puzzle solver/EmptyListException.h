#pragma once
#include <iostream>
#include <exception>

class EmptyListException : public std::exception
{
	const char* what() const throw ()
	{
		return "A lista n�o cont�m elementos";
	}
};