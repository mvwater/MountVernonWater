SEARCH_ACCOUNT = SearchAccount.o JavaScriptBridge.o DatabaseBridge.o AccountInfo.o

TEMP = SearchAccount.o AccountInfo.o

CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = canfield1

all: SearchAccount PutCGI PutHTML

	
AccountInfo.o: AccountInfo.cpp AccountInfo.h
	$(CC) $(FLAGS) AccountInfo.cpp $(CFLAGS)

JavaScriptBridge.o: JavaScriptBridge.cpp JavaScriptBridge.h AccountInfo.h
	$(CC) $(FLAGS) JavaScriptBridge.cpp $(CFLAGS)

DatabaseBridge.o: DatabaseBridge.cpp DatabaseBridge.h JavaScriptBridge.h
	$(CC) $(FLAGS) DatabaseBridge.cpp $(CFLAGS)

TestDatabase.o: TestDatabase.cpp DatabaseBridge.h AccountInfo.h
	$(CC) $(FLAGS) TestDatabase.cpp $(CFLAGS)
	
SearchAccount.o: SearchAccount.cpp JavaScriptBridge.h DatabaseBridge.h AccountInfo.h
	$(CC) $(FLAGS) SearchAccount.cpp $(CFLAGS)

# Linking after compiling
SearchAccount: $(SEARCH_ACCOUNT)
	$(CC) $(SEARCH_ACCOUNT) -o SearchAccount -L/usr/local/lib $(SQL_FLAGS)

PutCGI: SearchAccount
	chmod 757 SearchAccount
	cp SearchAccount /usr/lib/cgi-bin/$(USER)_searchByAccountNo.cgi

PutHTML:
	cp -R ../Web_Code /var/www/html/class/softdev/$(USER)/Mvwater

	echo "Current contents of HTML directory: "
	ls -l /var/www/html/class/softdev/$(USER)/Mvwater

clean:
	rm -f SearchAccount $(OUT)
	#rm -f $(OUT)



