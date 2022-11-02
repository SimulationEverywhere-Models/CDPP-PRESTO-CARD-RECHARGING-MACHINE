#include "MessageQueue.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

MessageQueue::MessageQueue (const string &name) : Atomic (name)
, money_in( addInputPort("money_in") )
, card_in ( addInputPort ( "card_in" ) )
, receipt_request_in ( addInputPort ( "receipt_request_in") )
, done ( addInputPort ( "done" ) )
, message_out ( addOutputPort ("message_out") )
, preparationTime (0, 0, 0, 0)
{

}

Model &MessageQueue :: initFunction()
{
	this->passivate();
	this->elements.erase(elements.begin(), elements.end() );
	return *this;
}

Model &MessageQueue::externalFunction(const ExternalMessage &msg)
{
	if (( msg.port() == money_in )||(msg.port() == card_in )||(msg.port() == receipt_request_in))
	{
		elements.push_back (msg.value());
		if (elements.size() == 1 )
			this->holdIn ( active, preparationTime );
	}

	if ( msg.port() == done )
	{
		elements.pop_front();
		if ( !elements.empty() )
		{
			this->holdIn ( active, preparationTime );
		}
	}

	return *this;
}
Model &MessageQueue::internalFunction ( const InternalMessage &)
{
	this->passivate();
	return *this;
}
Model &MessageQueue::outputFunction( const InternalMessage &msg)
{
	this->sendOutput ( msg.time(), message_out, elements.front() );
	return *this;
}
