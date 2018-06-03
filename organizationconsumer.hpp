// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ORGANIZATIONCONSUMER_HPP_
#define _ORGANIZATIONCONSUMER_HPP_

/*****************************************************************************/

#include "energyconsumer.hpp"


/*****************************************************************************/


class OrganizationConsumer
	:	public EnergyConsumer
{

/*-----------------------------------------------------------------*/

public:
	OrganizationConsumer(int _id);
	virtual double getDebt() const override;

	virtual void consume(int _energy) override;
	virtual bool isDiscon()  const override;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif // _ORGANIZATIONCONSUMER_HPP_