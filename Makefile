CXX=g++ -std=c++20
CXXFLAGS=-g -O3
WFLAGS=-Wall -Wextra -Wpedantic
RUNFLAGS=-fsanitize=undefined,address
EXECFILES=test_dict

all: $(EXECFILES)
	rm -rf *.dSYM
	./$^

%: %.cpp
	$(CXX) $(CXXFLAGS) $(WFLAGS) $(RUNFLAGS) $^ -o $@

clean:
	rm $(EXECFILES)
