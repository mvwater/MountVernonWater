OBJS	= TestSearchAddress.o JavaScriptBridge.o DatabaseBridge.o AccountSnapshot.o SearchAddress.o
SOURCE	= TestSearchAddress.cpp JavaScriptBridge.cpp DatabaseBridge.cpp AccountSnapshot.cpp SearchAddress.cpp
HEADER	= JavaScriptBridge.h DatabaseBridge.h AccountSnapshot.h
OUT	= TestSearchAddress.o
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

TestSearchAddress.o: TestSearchAddress.cpp
	$(CC) $(FLAGS) TestSearchAddress.cpp 

JavaScriptBridge.o: JavaScriptBridge.cpp
	$(CC) $(FLAGS) JavaScriptBridge.cpp 

DatabaseBridge.o: DatabaseBridge.cpp
	$(CC) $(FLAGS) DatabaseBridge.cpp 

AccountSnapshot.o: AccountSnapshot.cpp
	$(CC) $(FLAGS) AccountSnapshot.cpp 

SearchAddress.o: SearchAddress.cpp
	$(CC) $(FLAGS) SearchAddress.cpp 


clean:
	rm -f $(OBJS) $(OUT)
