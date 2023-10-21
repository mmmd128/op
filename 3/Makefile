CFLAGS := -Wall -Wextra -O2 -g
CPP := c++

all: 2 3 4

2: 1.cpp 2.cpp
	$(CPP) $(CFLAGS) 1.cpp 2.cpp -o 2

3: 1.cpp 3.cpp
	$(CPP) $(CFLAGS) 1.cpp 3.cpp -o 3

4: 1.cpp 4.cpp
	$(CPP) $(CFLAGS) 1.cpp 4.cpp -o 4

clean:
	rm -f 2 3 4
