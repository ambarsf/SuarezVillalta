exe.o:	main.o fscursorlist.o fsarraylist.o linkedlist.o tdalist.o integer.o object.o
	g++ main.o fscursorlist.o fsarraylist.o linkedlist.o tdalist.o integer.o object.o -o exe

main.o:	main.cpp tdalist.h linkedlist.h fscursorlist.h fsarraylist.h integer.h
	g++ -c main.cpp

fscursorlist.o: fscursorlist.cpp fscursorlist.h 
		g++ -c fscursorlist.cpp

fsarraylist.o: fsarraylist.cpp fsarraylist.h object.h
		g++ -c fsarraylist.cpp

linkedlist.o: linkedlist.cpp object.h tdalist.h
		g++ -c linkedlist.cpp

tdalist.o: tdalist.cpp tdalist.h object.h
		g++ -c tdalist.cpp

integer.o: integer.cpp integer.h object.h
		g++ -c integer.cpp

object.o: object.cpp object.h
		g++ -c object.cpp
