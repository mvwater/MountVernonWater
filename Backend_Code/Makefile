SEARCH_ADDRESS = SearchAddress.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o

CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = brydon1

DatabaseBridge.o: DatabaseBridge.cpp DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) DatabaseBridge.cpp $(CFLAGS)

AccountSnapshot.o: AccountSnapshot.cpp AccountSnapshot.h
	$(CC) $(FLAGS) AccountSnapshot.cpp $(CFLAGS)

JavaScriptBridge.o: JavaScriptBridge.cpp JavaScriptBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) JavaScriptBridge.cpp $(CFLAGS)

SearchAddress.o: SearchAddress.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) SearchAddress.cpp $(CFLAGS)



clean:
	rm -f $(OUT)