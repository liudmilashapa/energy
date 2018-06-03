// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _ENERGYCONSUMER_HPP_
#define _ENERGYCONSUMER_HPP_

/*****************************************************************************/


class EnergyConsumer
{

/*-----------------------------------------------------------------*/
public:
	EnergyConsumer(int _id);
	EnergyConsumer(const EnergyConsumer &) = delete;
	EnergyConsumer & operator = (const EnergyConsumer &) = delete;
	virtual ~EnergyConsumer() = default;

	virtual void payment(double _payment)  { m_money += _payment; };
	virtual void consume(int _energy) { m_energy += _energy; };
	virtual double getDebt()  const = 0;
	virtual bool isDiscon()  const = 0;
	virtual int getEnergy()  const { return m_energy; };
	virtual double getMoney() const { return m_money; };


private:
	int m_id;
	int m_energy;
	double m_money;

/*-----------------------------------------------------------------*/

};


/*****************************************************************************/

#endif // _ENERGYCONSUMER_HPP_