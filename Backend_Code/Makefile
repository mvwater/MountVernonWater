SEARCH_ADDRESS = SearchAddress.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o

CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = brydon1

#all: SearchAddress

# ISSUES with cgicc link??
#SearchAddress.o: SearchAddress.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h
#	$(CC) $(FLAGS) SearchAddress.cpp $(CFLAGS)

JavaScriptBridge.o: JavaScriptBridge.cpp JavaScriptBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) JavaScriptBridge.cpp $(CFLAGS)

DatabaseBridge.o: DatabaseBridge.cpp DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) DatabaseBridge.cpp $(CFLAGS)

AccountSnapshot.o: AccountSnapshot.cpp AccountSnapshot.h
	$(CC) $(FLAGS) AccountSnapshot.cpp $(CFLAGS)






clean:
	rm -f SearchAddress $(OUT)