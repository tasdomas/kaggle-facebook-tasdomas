CXX=g++

# Set CXXFLAGS to include the base set of flags

LIBS=-lboost_program_options -ldl

CXXFLAGS=-Wall -Werror -O2 -g $(LIBS)
LDDFLAGS=$(LIBS)

all: predict

predict: main.cc node.cc reader.cc
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

# Add a target-specific addition to CXXFLAGS for Code1:
#Code1: CXXFLAGS += -I/opt/local/include
