PROG = sikidom   # a program neve (ezt allitjuk elo)
PROG_O = Circle.o main.o Polygon.o Shape.o Square.o Triangle.o Vector2.o # program object fajljai 
PROG_H = Circle.h Polygon.h Shape.h Square.h Triangle.h Vector2.h # program header fajljai
PROG_L =              # program libjei

CXX = g++   # a C fordito neve
#CXX = clang++ # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS = -pedantic -Wall -Werror # kapcsolok: legyen bobeszedu es pedans
CXXFLAGS += -ggdb # es legyen debug info is
LDFLAGS = -ggdb # debug a linkelesnel 

# osszes object, osszes header osszes lib
OBJS = $(PROG_O)
HEADS = $(PROG_H)
LIBS = $(PROG_L) 

# alapertelmezett cel: program
.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LIBS)

# feltetelezzuk, hogy az osszes obj fugg az osszes headertol
$(OBJS): $(HEADS)

# takaritas igeny szerint
.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)

