CXX=g++

# Set CXXFLAGS to include the base set of flags

LIBS=-lboost_program_options -ldl

CXXFLAGS=-Wall -Werror -O2 -g $(LIBS)
LDDFLAGS=$(LIBS)

all: predict

predict: main.cc node.cc reader.cc predictions.cc writer.cc
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

run:
	./predict -i ../data/train.csv -t ../data/test.csv -o results.csv

# Add a target-specific addition to CXXFLAGS for Code1:
#Code1: CXXFLAGS += -I/opt/local/include
