# define the C++ compiler to use
CXX = g++

# define any compile-time flags
CXXFLAGS = -Wall -g

# define the C++ source files
SRCS = main.cpp

# define the C++ object files
OBJS = $(SRCS:.cpp=.o)

# define the executable file 
MAIN = program

.PHONY: depend clean

all:    $(MAIN)
	@echo  The program has been compiled

$(MAIN): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(MAIN) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $^
