
# The first rule is the default

a.out:	inventory_analysis.o report.o inventory.o food_item.o
	g++ -o a.out inventory_analysis.o report.o inventory.o food_item.o

inventory_analysis.o:	inventory_analysis.cpp inventory.h food_item.h report.h
	g++ -c inventory_analysis.cpp

report.o:	report.cpp inventory.h food_item.h report.h
	g++ -c report.cpp

inventory.o:	inventory.cpp inventory.h
	g++ -c inventory.cpp

food_item.o:	food_item.cpp food_item.h
	g++ -c food_item.cpp

clean:	
	rm -f *.o a.out


