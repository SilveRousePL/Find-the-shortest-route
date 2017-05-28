#pragma once
#include <iostream>
#include <string>
#include <windows.h>

class Exceptions
{
protected:
	std::string comm;

public:
	Exceptions(std::string);

	std::string what() const;
	void sysWindow() const;
};

class CriticalException : public Exceptions
{
public:
	CriticalException(std::string comm);
};

class WarningException : public Exceptions
{
public:
	WarningException(std::string comm);
};

class InfoException : public Exceptions
{
public:
	InfoException(std::string comm);
};