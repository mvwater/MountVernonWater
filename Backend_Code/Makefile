SEARCH_ADDRESS = SearchAddress.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o AccountInfo.o BillingInfo.o CommentInfo.o
SEARCH_ACCOUNT = SearchAccount.o JavaScriptBridge.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o BillingInfo.o CommentInfo.o
SEARCH_BILLING = SearchAccount.o JavaScriptBridge.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o BillingInfo.o CommentInfo.o
SEARCH_COMMENTS = SearchComments.o JavaScriptBridge.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o BillingInfo.o CommentInfo.o
SEARCH_CONSUMPTION = SearchConsumption.o JavaScriptBridge.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o BillingInfo.o CommentInfo.o
SEARCH_PAYMENTS = SearchPayments.o JavaScriptBridge.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o BillingInfo.o CommentInfo.o
SEARCH_RECEIVABLES = SearchReceivables.o JavaScriptBridge.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o BillingInfo.o CommentInfo.o


#TEST_SEARCH_ADDRESS = TestSearchAddress.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o
#TEST_JAVASCRIPT = TestJavaScript.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o

TEMP = SearchAddress.o AccountSnapshot.o SearchBilling.o SearchComments.o SearchAccount.o AccountInfo.o BillingInfo.o CommentInfo.o

CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = canfield1

all: TestDatabase SearchAccount SearchBilling SearchAddress SearchComments PutCGI PutHTML


AccountInfo.o: AccountInfo.cpp AccountInfo.h
	$(CC) $(FLAGS) AccountInfo.cpp $(CFLAGS)

BillingInfo.o: BillingInfo.cpp BillingInfo.h
	$(CC) $(FLAGS) BillingInfo.cpp $(CFLAGS)

AccountSnapshot.o: AccountSnapshot.cpp AccountSnapshot.h
	$(CC) $(FLAGS) AccountSnapshot.cpp $(CFLAGS)

JavaScriptBridge.o: JavaScriptBridge.cpp JavaScriptBridge.h AccountInfo.h AccountSnapshot.h BillingInfo.h CommentInfo.h
	$(CC) $(FLAGS) JavaScriptBridge.cpp $(CFLAGS)

DatabaseBridge.o: DatabaseBridge.cpp DatabaseBridge.h AccountInfo.h AccountSnapshot.h BillingInfo.h CommentInfo.h
	$(CC) $(FLAGS) DatabaseBridge.cpp $(CFLAGS)

#TestJavaScript.o: TestJavaScript.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h AccountInfo.h
	#$(CC) $(FLAGS) TestJavaScript.cpp $(CFLAGS)

#TestSearchAddress.o: TestSearchAddress.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h AccountInfo.h
	#$(CC) $(FLAGS) TestSearchAddress.cpp $(CFLAGS)

TestDatabase.o: TestDatabase.cpp DatabaseBridge.h AccountInfo.h AccountSnapshot.h BillingInfo.h CommentInfo.h
	$(CC) $(FLAGS) TestDatabase.cpp $(CFLAGS)

SearchAccount.o: SearchAccount.cpp JavaScriptBridge.h DatabaseBridge.h AccountInfo.h AccountSnapshot.h BillingInfo.h CommentInfo.h
	$(CC) $(FLAGS) SearchAccount.cpp $(CFLAGS)

SearchAddress.o: SearchAddress.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h AccountInfo.h BillingInfo.h CommentInfo.h
	$(CC) $(FLAGS) SearchAddress.cpp $(CFLAGS)

SearchBilling.o: SearchBilling.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h AccountInfo.h BillingInfo.h CommentInfo.h
	$(CC) $(FLAGS) SearchBilling.cpp $(CFLAGS)

SearchComments.o: SearchComments.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h AccountInfo.h BillingInfo.h CommentInfo.h
	$(CC) $(FLAGS) SearchComments.cpp $(CFLAGS)

SearchConsumption.o: SearchConsumption.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h AccountInfo.h  CommentInfo.h BillingInfo.h
	$(CC) $(FLAGS) SearchConsumption.cpp $(CFLAGS)

SearchPayments.o: SearchPayments.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h AccountInfo.h  CommentInfo.h BillingInfo.h
	$(CC) $(FLAGS) SearchPayments.cpp $(CFLAGS)

SearchReceivables.o: SearchReceivables.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h AccountInfo.h  CommentInfo.h BillingInfo.h
	$(CC) $(FLAGS) SearchReceivables.cpp $(CFLAGS)

#TestDatabase.o: TestDatabase.cpp DatabaseBridge.h AccountSnapshot.h
	#$(CC) $(FLAGS) TestDatabase.cpp $(CFLAGS)


# Linking after compiling
TestDatabase: TestDatabase.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o BillingInfo.o CommentInfo.o JavaScriptBridge.o
	$(CC) TestDatabase.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o BillingInfo.o CommentInfo.o JavaScriptBridge.o -o TestDatabase -L/usr/local/lib $(SQL_FLAGS)


SearchAccount: $(SEARCH_ACCOUNT)
	$(CC) $(SEARCH_ACCOUNT) -o SearchAccount -L/usr/local/lib $(SQL_FLAGS)

SearchBilling: $(SEARCH_BILLING)
	$(CC) $(SEARCH_BILLING) -o SearchBilling -L/usr/local/lib $(SQL_FLAGS)

SearchAddress: $(SEARCH_ADDRESS)
	$(CC) $(SEARCH_ADDRESS) -o SearchAddress -L/usr/local/lib $(SQL_FLAGS)

SearchComments: $(SEARCH_COMMENTS)
	$(CC) $(SEARCH_COMMENTS) -o SearchComments -L/usr/local/lib $(SQL_FLAGS)

SearchConsumption: $(SEARCH_CONSUMPTION)
	$(CC) $(SEARCH_CONSUMPTION) -o SearchConsumption -L/usr/local/lib $(SQL_FLAGS)

SearchPayments: $(SEARCH_PAYMENTS)
	$(CC) $(SEARCH_PAYMENTS) -o SearchPayments -L/usr/local/lib $(SQL_FLAGS)

SearchReceivables: $(SEARCH_RECEIVABLES)
	$(CC) $(SEARCH_RECEIVABLES) -o SearchReceivables -L/usr/local/lib $(SQL_FLAGS)

#TestDatabase: TestDatabase.o DatabaseBridge.o AccountSnapshot.o JavaScriptBridge.o
	#$(CC) TestDatabase.o DatabaseBridge.o AccountSnapshot.o JavaScriptBridge.o -o TestDatabase -L/usr/local/lib $(SQL_FLAGS)

	#TestJavaScript: $(TEST_JAVASCRIPT)
	#	$(CC) $(TEST_JAVASCRIPT) -o TestJavaScript -L/usr/local/lib $(SQL_FLAGS)

	#TestSearchAddress: $(TEST_SEARCH_ADDRESS)
	#	$(CC) $(TEST_SEARCH_ADDRESS) -o TestSearchAddress -L/usr/local/lib $(SQL_FLAGS)

PutCGI: SearchAddress SearchAccount SearchBilling SearchComments SearchConsumption SearchPayments SearchReceivables
	chmod 757 SearchAccount
	chmod 757 SearchAddress
	chmod 757 SearchBilling
	chmod 757 SearchComments
	chmod 757 SearchConsumption
	chmod 757 SearchPayments
	chmod 757 SearchReceivables

	cp SearchAccount /usr/lib/cgi-bin/$(USER)_searchByAccount.cgi
	cp SearchAddress /usr/lib/cgi-bin/$(USER)_searchByAddress.cgi
	cp SearchBilling /usr/lib/cgi-bin/$(USER)_billingInfoByAccountNo.cgi
	cp SearchComments /usr/lib/cgi-bin/$(USER)_commentInfoByAccountNo.cgi
	cp SearchConsumption /usr/lib/cgi-bin/$(USER)_consumptionByAccountNo.cgi
	cp SearchPayments /usr/lib/cgi-bin/$(USER)_paymentsByAccountNo.cgi
	cp SearchReceivables /usr/lib/cgi-bin/$(USER)_receivablesByAccountNo.cgi

PutHTML:
	cp -R ../Web_Code /var/www/html/class/softdev/$(USER)/Mvwater
	echo "Current contents of HTML directory: "
	ls -l /var/www/html/class/softdev/$(USER)/Mvwater

#PutHTML:
#	cp -R ../Web_Code /var/www/html/class/softdev/$(USER)/ShaneMvwater
#	echo "Current contents of HTML directory: "
#	ls -l /var/www/html/class/softdev/$(USER)/ShaneMvwater



clean:
	rm -f SearchAccount SearchAddress SearchBilling SearchComments $(OUT)
