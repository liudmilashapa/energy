// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _SYSTEMCONSUMER_HPP_
#define _SYSTEMCONSUMER_HPP_

/*****************************************************************************/

#include "energyconsumer.hpp"
#include "messages.hpp"

/*****************************************************************************/


class SystemConsumer
	:	public EnergyConsumer
{

/*-----------------------------------------------------------------*/

public:
	SystemConsumer(int _id);

	virtual double getDebt() const override { return 0.0; };
	virtual bool isDiscon()  const override { return false; };

	virtual  void payment(double _payment) override;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif // _SYSTEMCONSUMER_HPP_