SEARCH_ADDRESS = SearchAddress.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o
TEST_SEARCH_ADDRESS = TestSearchAddress.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o

CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14

all: TestSearchAddress

AccountSnapshot.o: AccountSnapshot.cpp AccountSnapshot.h
	$(CC) $(FLAGS) AccountSnapshot.cpp $(CFLAGS)

DatabaseBridge.o: DatabaseBridge.cpp DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) DatabaseBridge.cpp $(CFLAGS)

JavaScriptBridge.o: JavaScriptBridge.cpp JavaScriptBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) JavaScriptBridge.cpp $(CFLAGS)

TestSearchAddress.o: TestSearchAddress.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) TestSearchAddress.cpp $(CFLAGS)

SearchAddress.o: SearchAddress.cpp JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h
	$(CC) $(FLAGS) SearchAddress.cpp $(CFLAGS)

# Linking after compiling
TestSearchAddress: $(TEST_SEARCH_ADDRESS)
	$(CC) $(TEST_SEARCH_ADDRESS) -o TestSearchAddress -L/usr/local/lib $(SQL_FLAGS)
  
clean:
	#rm -f SearchAddress $(OUT)
	rm -f $(OUT)
