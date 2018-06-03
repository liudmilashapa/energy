// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "personconsumer.hpp"
#include "energyprice.hpp"

/*****************************************************************************/

PersonConsumer::PersonConsumer(int _id) 
	:EnergyConsumer(_id)
{

}

double PersonConsumer::getDebt() const
{
	double debt = 0.0;
	if (getEnergy() < EnergyPrice_PersonalSmallConsumptionThreshold)
		debt = getEnergy() * EnergyPrice_PersonalSmall - getMoney();
	else
		debt = (EnergyPrice_PersonalSmallConsumptionThreshold * EnergyPrice_PersonalSmall) + ((getEnergy() - EnergyPrice_PersonalSmallConsumptionThreshold) * EnergyPrice_PersonalLarge - getMoney());
	return debt;
}


/*****************************************************************************/    