CC = clang++
CFLAGS = -std=c++11
INCLUDES = -I.

lab:
	$(CC) $(CFLAGS) $(INCLUDES) *.cpp

single:
	$(CC) $(CFLAGS) $(INCLUDES) [!Lab4]*.cpp