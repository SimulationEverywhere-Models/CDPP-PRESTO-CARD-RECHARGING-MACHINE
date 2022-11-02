#include "CentralController.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

CentralController::CentralController (const string &name): Atomic (name)
, message_in( addInputPort("message_in") )
, control_balance_out ( addInputPort ( "control_balance_out" ) )
, control_receipt_out ( addOutputPort ("control_receipt_out") )
, queue_out ( addOutputPort ("queue_out") )
, preparationTime (0, 0, 1, 0)
{
	/*printf("constructed\n");
	string time(MainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;*/
}

Model &CentralController :: initFunction()
{
	this->passivate();
	currentBalance = 0;
	return *this;
}
Model &CentralController::externalFunction( const ExternalMessage &msg)
{

	if ( msg.port() == message_in )
	{
		float msgout = processMsg((float)msg.value());
		cout<<"Message comes from the Queue, the value is: "<<msg.value()<<endl;
		if(returnPort == 1)
		{
			this->sendOutput (msg.time(), control_receipt_out, int(msgout) );
			cout<<"The card no " << int(msgout) << "is sent to the ReceiptProcessor"<<endl;
		}
       	this->sendOutput (msg.time(), queue_out, 1 );
       	cout<<"Message "<< msg.value()<<" processed by the CentralController"<<endl;
		this->holdIn ( active, preparationTime );
	}
	return *this;
}


Model &CentralController::internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &CentralController::outputFunction( const InternalMessage &msg)
{
	this->sendOutput (msg.time(), control_balance_out, currentBalance );
	return *this;
}

//This function deal with the message coming from the MessageQueue
float CentralController::processMsg(float msg)
{
	if (msg == -1) /*receipt_request message from ReceiptProcessor*/
	{
		returnPort = 1;
		return card_no;
	}
	if ((msg > 0) && (msg <=100)) /*money message from MoneyCollector*/
	{
		currentBalance += msg;
		returnPort = 0;   //BalanceDisplay
		return currentBalance;
	}
	if (msg >100) //card message from CardReader
	{
		card_no = msg;
	}
	return 0;
}


