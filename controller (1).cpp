// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "controller.hpp"
#include "messages.hpp"

/*****************************************************************************/

Controller::~Controller()
{
	for (auto it = consumers.begin(); it != consumers.end(); it++)
		delete it->second;
}

/**************************************************************/

void Controller::NegativeConsumerID(int _consumerID) const
{
	if (_consumerID < 0)
		throw std::logic_error(Messages::NegativeConsumerID);
}


void Controller::NonUniqueConsumerID(int _consumerID) const
{
	if (consumers.find(_consumerID) != consumers.end())
		throw std::logic_error(Messages::NonUniqueConsumerID);
}

void Controller::UnknownConsumerID(int _consumerID) const
{
	if (consumers.find(_consumerID) == consumers.end())
		throw std::logic_error(Messages::UnknownConsumerID);
}

void Controller::InvalidateConsumerID(int _consumerID) const
{
	NegativeConsumerID(_consumerID);
	NonUniqueConsumerID(_consumerID);
}

/**************************************************************/



void Controller::createPersonConsumer(int _consumerID)
{
	InvalidateConsumerID(_consumerID);
	EnergyConsumer * consumer = new PersonConsumer(_consumerID);
	consumers.insert(std::make_pair(_consumerID, consumer));
}

void Controller::createOrganizationConsumer(int _consumerID)
{
	InvalidateConsumerID(_consumerID);
	EnergyConsumer * consumer = new OrganizationConsumer(_consumerID);
	consumers.insert(std::make_pair(_consumerID, consumer));
}

void Controller::createSystemConsumer(int _consumerID)
{
	InvalidateConsumerID(_consumerID);
	EnergyConsumer * consumer = new SystemConsumer(_consumerID);
	consumers.insert(std::make_pair(_consumerID, consumer));
}

void Controller::consume(int _consumerID, int _kiloWatts)
{
	UnknownConsumerID(_consumerID);
	if (_kiloWatts <= 0)
		throw std::logic_error(Messages::NonPositiveConsumption);
	consumers.at(_consumerID)->consume(_kiloWatts);
}

double Controller::getConsumerDebt(int _consumerID) const
{
	UnknownConsumerID(_consumerID);
	return consumers.at(_consumerID)->getDebt();
}

double Controller::getTotalDebt() const
{
	double totalDebt = 0.0;
	for (auto it = consumers.begin(); it != consumers.end(); it++)
	{
		totalDebt += it->second->getDebt();
	}
	return totalDebt;
}

bool Controller::isConsumerBlocked(int _consumerID) const
{
	UnknownConsumerID(_consumerID);
	return consumers.at(_consumerID)->isDiscon();
}

void Controller::trackConsumerPayment(int _consumerID, double _payment)
{
	UnknownConsumerID(_consumerID);
	if (_payment <= 0.0)
		throw std::logic_error(Messages::NonPositivePaymentAmount);
	consumers.at(_consumerID)->payment(_payment);
}


/*****************************************************************************/    