all: demo
linklist.o:linklist.cpp linklist.h
	g++ -g -c linklist.cpp -o linklist.o
demo:main.cpp linklist.o stack.hpp squeue.hpp bittree.hpp myrbtree.hpp treap.hpp
	g++ -g -o demo main.cpp linklist.o
