#pragma once
#include "ConsoleUtils.h"
#include <string>
#include <fstream>
#include <iostream>

class DerivedCredits : public ConsoleUtils
{
public:
	void showCredits() override;
};

