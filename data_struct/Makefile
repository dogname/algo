all: demo
linklist.o:linklist.cpp linklist.h
	g++ -c linklist.cpp -o linklist.o
demo:main.cpp linklist.o stack.hpp squeue.hpp bittree.hpp myrbtree.hpp
	g++ -o demo main.cpp linklist.o
