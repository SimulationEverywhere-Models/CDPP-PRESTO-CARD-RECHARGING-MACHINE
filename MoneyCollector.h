/*Class MoneyCollector Definition*/

#ifndef __MONEYCOLLECTOR_H
#define __MONEYCOLLECTOR_H

#include "atomic.h"
#include <string>

class MoneyCollector : public Atomic
{
public:
	MoneyCollector(const std::string &name ="MoneyCollector");
	virtual std::string className() const;
protected:
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);
	Model &outputFunction( const InternalMessage &);
private:
	const Port &money_in;
	Port &money_out;
	float money_amount;
	Time  preparationTime;
};

inline std::string MoneyCollector::className() const
{
    return "MoneyCollector";
}

#endif


