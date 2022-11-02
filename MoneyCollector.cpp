/*atomic model for MoneyCollector*/
#include "MoneyCollector.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

MoneyCollector :: MoneyCollector(const std::string &name): Atomic(name)
,money_in(addInputPort("money_in"))
,money_out(addOutputPort("money_out"))
,preparationTime(0,0,1,0)
{
	//std::string time(MainSimulator::Instance().getParameter(description(), "preparation"));
    //if (time!=" ")
    	//preparationTime = time;
}


Model &MoneyCollector :: initFunction()
{
	cout << "MoneyCollector initFunction() start" << endl;
	this->passivate();
	money_amount = 0;
	return *this;
}

Model &MoneyCollector :: externalFunction(const ExternalMessage &msg)
{
	cout << "MoneyCollector externalFunction() start at"<<msg.time()<<endl;
	money_amount = msg.value();
	cout << "I received money: " << msg.value() << " dollars at " << msg.time() << endl;
	this->holdIn(active, preparationTime);
	return *this;
}


Model &MoneyCollector :: internalFunction ( const InternalMessage &)
{
	cout << "MoneyCollector internalFunction() start" << endl;
	this->passivate();
	return *this;
}
Model &MoneyCollector :: outputFunction( const InternalMessage &msg)
{
	cout << "MoneyCollector outputFunction() start at "<<msg.time()<<endl;
	this->sendOutput ( msg.time(), money_out, money_amount );
	cout << "I send out the money " << money_amount << "dollars at " << msg.time() << endl;
	return *this;
}
