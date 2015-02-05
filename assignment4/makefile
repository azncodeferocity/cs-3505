
# The first rule is the default
# may need to add .h files as we end up using them in .cpp files

tester:	report.o inventory.o food_item.o tester.o
	g++ -o tester report.o inventory.o food_item.o tester.o

report.o:	report.cpp report.h
	g++ -c report.cpp

inventory.o:	inventory.cpp inventory.h
	g++ -c inventory.cpp

food_item.o:	food_item.cpp food_item.h
	g++ -c food_item.cpp

tester.o:	tester.cpp 
	g++ -c tester.cpp

clean:	
	rm -f *.o a.out


