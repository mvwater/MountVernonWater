SEARCH_ADDRESS = SearchAddress.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o
TEST_SEARCH_ADDRESS = TestSearchAddress.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o
TEST_JAVASCRIPT = TestJavaScript.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o

CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = brydon1

#all: SearchAddress PutCGI PutHTML
all: TestDatabase TestJavaScript PutCGI PutHTML
#all: TestDatabase

#AccountInfo.o: AccountInfo.cpp AccountInfo.h
#	$(CC) $(FLAGS) AccountInfo.cpp $(CFLAGS)

AccountSnapshot.o: AccountSnapshot.cpp AccountSnapshot.h
	$(CC) $(FLAGS) AccountSnapshot.cpp $(CFLAGS)

DatabaseBridge.o: DatabaseBridge.cpp DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) DatabaseBridge.cpp $(CFLAGS)

JavaScriptBridge.o: JavaScriptBridge.cpp JavaScriptBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) JavaScriptBridge.cpp $(CFLAGS)

TestJavaScript.o: TestJavaScript.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) TestSearchAddress.cpp $(CFLAGS)

TestSearchAddress.o: TestSearchAddress.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) TestSearchAddress.cpp $(CFLAGS)

SearchAddress.o: SearchAddress.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) SearchAddress.cpp $(CFLAGS)

TestDatabase.o: TestDatabase.cpp DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) TestDatabase.cpp $(CFLAGS)

# Linking after compiling
TestDatabase: TestDatabase.o DatabaseBridge.o AccountSnapshot.o JavaScriptBridge.o
	$(CC) TestDatabase.o DatabaseBridge.o AccountSnapshot.o JavaScriptBridge.o -o TestDatabase -L/usr/local/lib $(SQL_FLAGS)

TestJavaScript: $(TEST_JAVASCRIPT)
	$(CC) $(TEST_JAVASCRIPT) -o TestJavaScript -L/usr/local/lib $(SQL_FLAGS)

TestSearchAddress: $(TEST_SEARCH_ADDRESS)
	$(CC) $(TEST_SEARCH_ADDRESS) -o TestSearchAddress -L/usr/local/lib $(SQL_FLAGS)

SearchAddress: $(SEARCH_ADDRESS)
	$(CC) $(SEARCH_ADDRESS) -o SearchAddress -L/usr/local/lib $(SQL_FLAGS)

#PutCGI: SearchAddress
PutCGI: TestJavaScript
	#chmod 757 SearchAddress
	chmod 757 TestJavaScript
	#cp SearchAddress /usr/lib/cgi-bin/$(USER)_searchByAddress.cgi
	cp TestJavaScript /usr/lib/cgi-bin/$(USER)_searchByAddress.cgi

	#echo "Current contents of your cgi-bin directory: "
	#ls -l /usr/lib/cgi-bin/

PutHTML:
	cp -R ../Web_Code /var/www/html/class/softdev/$(USER)/Mvwater

	echo "Current contents of HTML directory: "
	ls -l /var/www/html/class/softdev/$(USER)/Mvwater

clean:
	rm -f TestDatabase SearchAddress TestSearchAddress $(OUT)
	#rm -f $(OUT)

