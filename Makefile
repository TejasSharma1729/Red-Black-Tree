CXX=clang++
CXXFLAGS=-g -std=c++23 -march=native -stdlib=libc++ -O3
LDFLAGS=-fuse-ld=lld
WFLAGS=-Wall -Wextra -Wpedantic -Wshadow
RUNFLAGS=-fsanitize=undefined,address,leak,bounds
EXECFILES=test_dict

all: $(EXECFILES)
	rm -rf *.dSYM
	./$^

%: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(WFLAGS) $(RUNFLAGS) $^ -o $@

clean:
	rm $(EXECFILES)
