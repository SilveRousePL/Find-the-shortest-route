#pragma once
#include <iostream>
#include <string>
#include <windows.h>

class Exceptions //Wyj�tki - Klasa abstrakcyjna
{
protected:
	std::string comm;

public:
	Exceptions(std::string);
	virtual ~Exceptions() = default;

	std::string what() const; //Zwraca tre�� b��du
	virtual void sysWindow() const = 0; //Metoda tworz�ca systemowe okno dialogowe
};

class CriticalException : public Exceptions //Wyj�tek krytyczny
{
public:
	CriticalException(std::string comm);
	void sysWindow() const override;
};

class WarningException : public Exceptions //Wyj�tek ostrzegawczy
{
public:
	WarningException(std::string comm);
	void sysWindow() const override;
};

class Info : public Exceptions //Wyj�tek informacyjny
{
public:
	Info(std::string comm);
	void sysWindow() const override;
};