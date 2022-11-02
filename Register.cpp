#include <modeladm.h>
#include <mainsimu.h>
#include "MoneyCollector.h" // class MoneyCollector
#include "BalanceDisplay.h" //class BalanceDisplay
#include "ReceiptProcessor.h" // class ReceiptProcessor
#include "MessageQueue.h" //class MessageQueue
#include "CentralController.h" // class CentralController
#include "CardReader.h" // class CardReader




void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MoneyCollector>() , "MoneyCollector" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<BalanceDisplay>() , "BalanceDisplay" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ReceiptProcessor>() , "ReceiptProcessor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<MessageQueue>() , "MessageQueue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CentralController>() , "CentralController" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CardReader>() , "CardReader" ) ;
}
