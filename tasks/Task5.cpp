#include "Task5.h"
#include "Util.h"
#include "SimpleFraction.h"

Task5::Task5(std::string header_value)
{
	this->initializeMenu(header_value);
}

Task5::~Task5()
{
}

void Task5::manualItems()
{
	SimpleFraction* fraction1 = new SimpleFraction();
	std::cin >> *fraction1;

	SimpleFraction* fraction2 = new SimpleFraction();
	std::cin >> *fraction2;

	std::cout << "First fraction: " << *fraction1 << ", IsInteger: " << fraction1->checkIsInteger() << std::endl;
	std::cout << "Second fraction: " << *fraction2 << ", IsInteger: " << fraction2->checkIsInteger() << std::endl;
	
	SimpleFraction fractionSumResult = *fraction1 + *fraction2;
	std::cout << "Fraction addition result: " << fractionSumResult << ", IsInteger: " << fractionSumResult.checkIsInteger() << std::endl;

	delete fraction1;
	delete fraction2;
}

void Task5::randomItems()
{
	SimpleFraction* fraction1 = new SimpleFraction();
	fraction1->setNumerator(Util::randomInt(1, 100));
	fraction1->setDenominator(Util::randomInt(1, 100));
	std::cout << "First fraction: " << *fraction1 << ", IsInteger: " << fraction1->checkIsInteger() << std::endl;

	SimpleFraction* fraction2 = new SimpleFraction();
	fraction2->setNumerator(Util::randomInt(1, 100));
	fraction2->setDenominator(Util::randomInt(1, 100));
	std::cout << "Second fraction: " << *fraction2 << ", IsInteger: " << fraction2->checkIsInteger() << std::endl;

	SimpleFraction fractionSumResult = *fraction1 + *fraction2;
	std::cout << "Fraction addition result: " << fractionSumResult << ", IsInteger: " << fractionSumResult.checkIsInteger() << std::endl;
}


