
# The first rule is the default
# may need to add .h files as we end up using them in .cpp files

a.out:	report.o inventory.o food_item.o
	g++ -o a.out report.o inventory.o food_item.o

report.o:	report.cpp inventory.h food_item.h
	g++ -c report.cpp

inventory.o:	inventory.cpp inventory.h
	g++ -c inventory.cpp

food_item.o:	food_item.cpp food_item.h
	g++ -c food_item.cpp

clean:	
	rm -f *.o a.out


