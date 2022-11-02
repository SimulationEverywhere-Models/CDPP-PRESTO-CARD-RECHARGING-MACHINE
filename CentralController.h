/*Class CentralController Definition*/


#ifndef __CENTRAL_CONTROLLER_H
#define __CENTRAL_CONTROLLER_H

#include <stdio.h>
#include "atomic.h"

class CentralController: public Atomic
{
public:
	CentralController ( const string &name = "CentralController" );
	virtual string className() const;
protected:
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);
	Model &outputFunction( const InternalMessage &);
private:
	const Port &message_in;
	Port &control_balance_out;
	Port &control_receipt_out;
	Port &queue_out;
	Time preparationTime;

	float currentBalance;
	int card_no;
	int returnPort;

	float processMsg(float);
};

inline string CentralController::className() const
{
	return "CentralController";
}
#endif












