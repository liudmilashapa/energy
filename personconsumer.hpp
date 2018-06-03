// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _PERSONCONSUMER_HPP_
#define _PERSONCONSUMER_HPP_

/*****************************************************************************/

#include "energyconsumer.hpp"

/*****************************************************************************/


class PersonConsumer
	:	public EnergyConsumer
{

/*-----------------------------------------------------------------*/
public:
	PersonConsumer(int _id);
	virtual double getDebt() const override;
	virtual bool isDiscon()  const override { return false; };

/*-----------------------------------------------------------------*/
};


/*****************************************************************************/

#endif // _PERSONCONSUMER_HPP_