#include "Exceptions.h"

using namespace std;

Exceptions::Exceptions(string comm)
{
	this->comm = comm;
}

string Exceptions::what() const
{
	return this->comm;
}

void Exceptions::sysWindow() const
{
	MessageBox(nullptr,
		("Exception occurred and application will be closed.\n" + what()).c_str(),
		"Error, exception occurred", MB_ICONERROR | MB_DEFBUTTON1);
}

CriticalException::CriticalException(string comm) : Exceptions(comm) {}
WarningException::WarningException(string comm) : Exceptions(comm) {}
InfoException::InfoException(string comm) : Exceptions(comm) {}
