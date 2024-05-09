PROGRAM = \
    p1
	# p1 \
	# p2 \
	# p3


CPPFLAGS = -std=c++17
CC = g++

all: $(PROGRAM)

p1: Graph.o GraphKit.o GraphKit_dfs.o GraphKit_idfs.o GraphKit_maxcut.o GraphKit_dp.o main.o
	$(CC) $(CPPFLAGS) -o $@ $^

# p1: Graph.o GraphKit.o GraphKit_dfs.o
# 	$(CC) $(CPPFLAGS) -o $@ $^

# p2: Graph.o GraphKit.o GraphKit_maxcut.o
# 	$(CC) $(CPPFLAGS) -o $@ $^

# p3: Graph.o GraphKit.o GraphKit_dp.o
# 	$(CC) $(CPPFLAGS) -o $@ $^

%.o: %.cpp %.h
	$(CC) $(CPPFLAGS) -c $*.cpp -o $@


# ***************************************************************
# Standard entries to remove files from the directories
#    clean -- delete derived files in preparation for rebuild

clean:
	rm -f *.o *.a $(PROGRAM)
