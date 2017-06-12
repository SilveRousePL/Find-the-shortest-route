#include "Exceptions.h"

using namespace std;

Exceptions::Exceptions(string comm) : comm(comm) {}

string Exceptions::what() const
{
	return this->comm;
}

CriticalException::CriticalException(string comm) : Exceptions(comm) {}

void CriticalException::sysWindow() const
{
	MessageBox(nullptr,
		("Exception occurred and application will be closed.\n" + what()).c_str(),
		"Error, exception occurred", MB_ICONERROR | MB_DEFBUTTON1);
}

WarningException::WarningException(string comm) : Exceptions(comm) {}

void WarningException::sysWindow() const
{
	MessageBox(nullptr,what().c_str(), "Warning", MB_ICONWARNING | MB_DEFBUTTON1);
}

Info::Info(string comm) : Exceptions(comm) {}

void Info::sysWindow() const
{
	MessageBox(nullptr, what().c_str(), "Info", MB_ICONINFORMATION | MB_DEFBUTTON1);
}