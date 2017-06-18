#pragma once
#include <iostream>
#include <string>
#include <windows.h>

class Exceptions //Wyj¹tki - Klasa abstrakcyjna
{
protected:
	std::string comm;

public:
	Exceptions(std::string);
	virtual ~Exceptions() = default;

	std::string what() const; //Zwraca treœæ b³êdu
	virtual void sysWindow() const = 0; //Metoda tworz¹ca systemowe okno dialogowe
};

class CriticalException : public Exceptions //Wyj¹tek krytyczny
{
public:
	CriticalException(std::string comm);
	void sysWindow() const override;
};

class WarningException : public Exceptions //Wyj¹tek ostrzegawczy
{
public:
	WarningException(std::string comm);
	void sysWindow() const override;
};

class Info : public Exceptions //Wyj¹tek informacyjny
{
public:
	Info(std::string comm);
	void sysWindow() const override;
};