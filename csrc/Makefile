CXX=g++

# Set CXXFLAGS to include the base set of flags

LIBS=-lboost_program_options -ldl

CXXFLAGS=-Wall -Werror -O2 -g $(LIBS)
LDDFLAGS=$(LIBS)
DT = $(shell date --iso=seconds)


all: predict

predict: main.o node.o reader.o predictions.o writer.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.cc.o:
	$(CXX) -o $@ -c $(CXXFLAGS) $<


run:
	./predict -i ../data/train.csv -t ../data/test.csv -o ../result$(DT).csv

clean:
	rm predict
	rm *.o

# Add a target-specific addition to CXXFLAGS for Code1:
#Code1: CXXFLAGS += -I/opt/local/include
