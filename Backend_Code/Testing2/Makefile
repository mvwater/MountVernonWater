CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = canfield1

all: TestDatabase

AccountSnapshot.o: AccountSnapshot.cpp AccountSnapshot.h
	$(CC) $(FLAGS) AccountSnapshot.cpp $(CFLAGS)
	
AccountInfo.o: AccountInfo.cpp AccountInfo.h
	$(CC) $(FLAGS) AccountInfo.cpp $(CFLAGS)

JavaScriptBridge.o: JavaScriptBridge.cpp JavaScriptBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) JavaScriptBridge.cpp $(CFLAGS)

DatabaseBridge.o: DatabaseBridge.cpp DatabaseBridge.h AccountSnapshot.h JavaScriptBridge.h
	$(CC) $(FLAGS) DatabaseBridge.cpp $(CFLAGS)

TestDatabase.o: TestDatabase.cpp DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) TestDatabase.cpp $(CFLAGS)

# Linking after compiling
TestDatabase: TestDatabase.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o JavaScriptBridge.o
	$(CC) TestDatabase.o DatabaseBridge.o AccountInfo.o AccountSnapshot.o JavaScriptBridge.o -o TestDatabase -L/usr/local/lib $(SQL_FLAGS)

clean:
	rm -f TestDatabase $(OUT)

