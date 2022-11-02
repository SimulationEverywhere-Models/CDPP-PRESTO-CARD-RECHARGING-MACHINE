/*Atomic Model BalanceDisplay*/

#include "BalanceDisplay.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"


BalanceDisplay :: BalanceDisplay ( const string &name ) : Atomic (name)
, balance_in( addInputPort("balance_in") )
, balance_out( addOutputPort("balance_out") )
, preparationTime (0, 0, 0, 0)
{

}

Model &BalanceDisplay :: initFunction()
{
	cout << "BalanceDisplay initFunction() start" << endl;
	this->passivate();
	balance = 0.0;
	return *this;
}
Model &BalanceDisplay :: externalFunction( const ExternalMessage &msg)
{
	cout << "BalanceDisplay externalFunction() start at "<<msg.time()<<endl;
	balance =  msg.value();
	cout << "I received the balance: " << balance << "  at " << msg.time() << endl;
	this->holdIn ( active, preparationTime );
	return *this;
}
Model &BalanceDisplay :: internalFunction ( const InternalMessage &)
{
	cout << "BalanceDisplay internalFunction() start" << endl;
	this->passivate();
	return *this;
}
Model &BalanceDisplay :: outputFunction( const InternalMessage &msg)
{
	cout << "BalanceDisplay outputFunction() start at "<<msg.time()<<endl;
	this->sendOutput ( msg.time(), balance_out, balance );
	return *this;
	cout << "I send out the balance " << balance << " at " << msg.time() << endl;
}

