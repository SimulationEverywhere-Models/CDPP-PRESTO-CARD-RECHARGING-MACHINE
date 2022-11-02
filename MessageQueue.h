/*Class MessageQueue Definition*/


#ifndef __MESSAGE_QUEUE_H
#define __MESSAGE_QUEUE_H

#include <list>
#include "atomic.h"

class MessageQueue : public Atomic


{
public:
	MessageQueue ( const string &name = "MessageQueue" );
	virtual string className() const;
protected:
	Model &initFunction();
	Model &externalFunction(const ExternalMessage &);
	Model &internalFunction(const InternalMessage &);
	Model &outputFunction( const InternalMessage &);
private:
	const Port &money_in;
	Port &card_in;
	Port &receipt_request_in;
	Port &message_out;
	Port &done;
	Time preparationTime;
	typedef list<Value> ElementList;
	ElementList elements;
};

inline string MessageQueue::className() const
{
	return "MessageQueue";
}

#endif
