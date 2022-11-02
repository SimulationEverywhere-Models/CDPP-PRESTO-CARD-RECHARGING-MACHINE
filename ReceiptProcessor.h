/*Class ReceiptProcessor Definition*/


#ifndef __RECEIPT_PROCESSOR_H
#define __RECEIPT_PROCESSOR_H

#include "atomic.h"

class ReceiptProcessor: public Atomic
{
public:
	ReceiptProcessor ( const string &name = "ReceiptProcessor" );
	virtual string className() const;
protected:
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);
	Model &outputFunction( const InternalMessage &);
private:
	const Port &request_in;
	Port &central_control_in;
	Port &receipt_out;
	Port &request_out;
	int  card_no;
	Time  preparationTime;
};
inline string ReceiptProcessor::className() const
{
	return "ReceiptProcessor";
}
#endif
