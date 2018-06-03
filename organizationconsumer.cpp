// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "organizationconsumer.hpp"
#include "energyprice.hpp"

/*****************************************************************************/

OrganizationConsumer::OrganizationConsumer(int _id)
	:EnergyConsumer(_id)
{

}

void OrganizationConsumer::consume(int _energy)
{
	if (isDiscon()) return;
	else EnergyConsumer::consume(_energy);
}

bool OrganizationConsumer::isDiscon()  const
{
	if (getDebt() / EnergyPrice_Corporate >= EnergyPrice_OrganizationDebtThreshold) return true;
	return false;
}

double OrganizationConsumer::getDebt() const
{ 
	return getEnergy() * EnergyPrice_Corporate - getMoney(); 
};


/*****************************************************************************/    