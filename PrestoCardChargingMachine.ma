[top]
components : balance@BalanceDisplay
components : card@CardReader
components : receipt@ReceiptProcessor
components : money@MoneyCollector
components : RechargeController

in : money_in card_in request_in
out : balance_out request_out
Link : money_in money_in@money
Link : money_out@money inMC@RechargeController
Link : card_in cardInfo_in@card
Link : cardInfo_out@card inCR@RechargeController
Link : request_in request_in@receipt
Link : request_out@receipt inRP@RechargeController
Link : outCRP@RechargeController central_control_in@receipt
Link : receipt_out@receipt request_out
Link : outCBD@RechargeController balance_in@balance
Link : balance_out@balance balance_out



[RechargeController]
components : message@MessageQueue
components : central@CentralController
in : inMC inCR inRP
out : outCBD outCRP
Link : inMC money_in@message
Link : inCR card_in@message
Link : inRP receipt_request_in@message
Link : control_balance_out@central outCBD
Link : control_receipt_out@central outCRP
Link : queue_out@central done@message
Link : message_out@message message_in@central


