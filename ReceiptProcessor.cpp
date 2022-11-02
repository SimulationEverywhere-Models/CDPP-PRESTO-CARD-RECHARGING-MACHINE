/*atomic model change_maker*/

#include "ReceiptProcessor.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

ReceiptProcessor::ReceiptProcessor (const string &name) : Atomic (name)
, request_in( addInputPort("request_in") )
, central_control_in ( addInputPort ( "central_control_in" ))
, request_out ( addOutputPort("request_out") )
, receipt_out ( addOutputPort ("receipt_out") )
, preparationTime (0, 0, 2, 0)
{
	/*string time(MainSimulator::Instance().getParameter(description(), "preparation"));
	if (time!=" ")
		preparationTime = time;*/
}

Model &ReceiptProcessor :: initFunction()
{
	this->passivate();
	card_no=0;
	return *this;
}
Model &ReceiptProcessor::externalFunction( const ExternalMessage &msg)
{
	if ( msg.port() == request_in )
       	this->sendOutput ( msg.time(), request_out, -1 );
	if ( msg.port() == central_control_in )
		card_no = msg.value();
		this->holdIn (active, preparationTime);
	return *this;
}
Model &ReceiptProcessor::internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &ReceiptProcessor::outputFunction( const InternalMessage &msg)
{
	this->sendOutput ( msg.time(), receipt_out, card_no );
	return *this;
}
