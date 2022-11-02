/*Class BalanceDisplay Definition*/


#ifndef __BALANCE_DISPLAY_H
#define __BALANCE_DISPLAY_H

#include "atomic.h"



class BalanceDisplay : public Atomic
{
public:
	BalanceDisplay ( const string &name = "BalanceDisplay" );
	virtual string className() const
	{	return "BalanceDisplay"; };

protected:

	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);
	Model &outputFunction( const InternalMessage &);

private:
	const Port &balance_in;
	Port &balance_out;
	float balance;
	Time  preparationTime;
};

#endif
