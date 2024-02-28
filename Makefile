EXECFILES=test_dict

all: $(EXECFILES)
	rm -rf *.dSYM
	./$^

%: %.cpp
	$(CXX) $(CXXFLAGS) -O3 $^ $(LDFLAGS) -o $@

clean:
	rm -rf $(EXECFILES)

.PHONY: all
