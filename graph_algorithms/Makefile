# Configure compiler settings
CXX=clang++
CXXFLAGS=-gdwarf-4 -std=c++11 -Werror
# The object files for the program.
OFILES = \
	directedGraph.o \
	undirectedGraph.o \
	graphAlgorithms.o \

# The header files for the program
HFILES = $(shell ls -1 *.h)

# UnitTest++ keeps its object files in this library.
UNITTEST_LIB = -lUnitTest++

# uncomment applications as you implement them
all:  wmi oatp cc mst manualTests tests 


# This target builds your tests.
tests: tests.o $(OFILES) $(HFILES)
	$(CXX) $(CXXFLAGS) -o $@ tests.o $(OFILES) $(UNITTEST_LIB)

# This target builds your manual testing program.
manualTests: manualTests.o $(HFILES) $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ manualTests.o $(OFILES)

# This target builds your Cross Country solution
cc: cc.o $(HFILES) $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ cc.o $(OFILES)

# This target builds your where's my internet
wmi: wmi.o $(HFILES) $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ wmi.o $(OFILES)

# This target builds your On Average They're Purple program
oatp: oatp.o $(HFILES) $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ oatp.o $(OFILES)

# This target builds your MST implementation
mst: mst.o $(HFILES) $(OFILES)
	$(CXX) $(CXXFLAGS) -o $@ mst.o $(OFILES)

# This target describes how to compile a .o file from a .cpp file.
%.o: %.cpp $(HFILES)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# This target deletes the temporary files we have built.
.PHONY: clean
clean:
	rm -f *.o
	rm -f tests
	rm -f manualTests
	rm -f wmi
	rm -f oatp
	rm -f mst
	rm -f ttp
	rm -f bat
	rm -f cc
