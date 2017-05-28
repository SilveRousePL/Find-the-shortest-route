#pragma once
#include "ADrawObject.h"

class Connect : public ADrawObject
{
public:
	Connect();
	~Connect();

	void gCreate() override;
};
