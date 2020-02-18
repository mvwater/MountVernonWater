#VIEW_COMMENTS = ViewComments.o ArtDBCommunicator.o JSCommunicator.o CommentManager.o Query.o Comment.o Artwork.o Member.o UserManager.o

CC	 = g++
SQL_FLAGS = -lcgicc -lmysqlcppconn
FLAGS	 = -g -c -Wall
CFLAGS 	 = -std=c++14
USER     = brydon1

#all: ViewComments PutCGI PutHTML

DatabaseBridge.o: DatabaseBridge.cpp DatabaseBridge.h
	$(CC) $(FLAGS) DatabaseBridge.cpp $(CFLAGS)

# Linking after compiling
#ViewComments: $(VIEW_COMMENTS)
#	$(CC) $(VIEW_COMMENTS) -o ViewComments -L/usr/local/lib $(SQL_FLAGS)

#PutCGI: ViewComments
	#chmod 757 ViewComments
	#cp ViewComments /usr/lib/cgi-bin/$(USER)_artAppGetCommentsPhoto.cgi

	#echo "Current contents of your cgi-bin directory: "
	#ls -l /usr/lib/cgi-bin/

PutHTML:
	cp -R ../Web_Code /var/www/html/class/softdev/$(USER)/CityWaterDatabase

	echo "Current contents of HTML directory: "
	ls -l /var/www/html/class/softdev/$(USER)/CityWaterDatabase

clean:
	rm -f ViewComments $(OUT)
