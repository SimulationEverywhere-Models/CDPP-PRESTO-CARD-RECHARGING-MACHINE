/*******************************************************************
*
*  DESCRIPTION: Atomic Model Card Reader
*
*  AUTHOR: Tao Zhang
*
*
*  DATE: 20/10/2014
*
*******************************************************************/
#ifndef __CARDREADER_H
#define __CARDREADER_H

/** include files **/
#include "atomic.h"  // class Atomic


/** declarations **/
class CardReader: public Atomic
{
public:
	CardReader( const string &name = "CardReader" ) ;	 // Default constructor
	virtual string className() const
		{return "CardReader";}

protected:
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);
	Model &outputFunction( const InternalMessage &);

private:
	const Port &cardInfo_in ;
    Port &cardInfo_out;
    int   card_no;
    Time  preparationTime;
};


#endif    //__CARDREADER_H
