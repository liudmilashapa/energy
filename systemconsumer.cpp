// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "systemconsumer.hpp"
#include <ostream>

/*****************************************************************************/

SystemConsumer::SystemConsumer(int _id)
	:EnergyConsumer(_id)
{

}

void SystemConsumer::payment(double _payment)
{
	throw std::logic_error(Messages::SystemConsumersDontPay);
}


/*****************************************************************************/    