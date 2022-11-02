/*atomic model for CardReader*/
#include "CardReader.h"
#include "message.h"
#include "mainsimu.h"
#include "strutil.h"

CardReader::CardReader( const string &name ) : Atomic( name )
, cardInfo_in( addInputPort( "cardInfo_in" ) )
, cardInfo_out( addOutputPort( "cardInfo_out" ) )
, preparationTime(0,0,1,0)
{

}

Model &CardReader :: initFunction()
{
	cout << "CardReader initFunction() start" << endl;
	this->passivate();
	return *this;
}

Model &CardReader :: externalFunction(const ExternalMessage &msg)
{
	cout << "CardReader externalFunction() start at"<<msg.time()<<endl;
	if(this->state() == passive)
	{
		if (msg.port() == cardInfo_in)
		{
			card_no =  ((double)rand()/(double)RAND_MAX ) * 900 + 100;
			this->holdIn( active, preparationTime ) ;
			cout << "I received the card: " << card_no << "  at " << msg.time() << endl;
		}
	}
	return *this;
}

Model &CardReader :: internalFunction ( const InternalMessage &)
{
	cout << "CardReader internalFunction() start" << endl;
	this->passivate();
	return *this;
}


Model &CardReader::outputFunction( const InternalMessage &msg )
{
	cout << "CardReader outputFunction() start at "<<msg.time()<<endl;
	this->sendOutput ( msg.time(), cardInfo_out, card_no );
	cout << "I send out the card no. " << card_no << " at " << msg.time() << endl;
	return *this;
}

