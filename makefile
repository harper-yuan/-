target = main
srcpp = main.cpp buffer.cpp
obj = $(srcpp:.cpp=.o)
$(target):$(obj)
	g++ -o $(target) $(obj) -std=c++11 -pthread -g
$(obj):$(srcpp)
	g++ -c $(srcpp) -std=c++11 -pthread -g

.PHONY: clean
clean:
	rm *.o