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
	virtual ~Exceptions() = default;

	std::string what() const;
	virtual void sysWindow() const = 0;
};

class CriticalException : public Exceptions
{
public:
	CriticalException(std::string comm);
	void sysWindow() const override;
};

class WarningException : public Exceptions
{
public:
	WarningException(std::string comm);
	void sysWindow() const override;
};

class Info : public Exceptions
{
public:
	Info(std::string comm);
	void sysWindow() const override;
};