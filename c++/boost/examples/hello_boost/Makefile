CXX=g++
CFLAGS=-g -Wall
BUILDDIR=build
EXE=$(BUILDDIR)/hello_world
SOURCES=main.cpp
OBJECTS=$(SOURCES:%.cpp=$(BUILDDIR)/%.o)

all: $(EXE)

$(EXE): $(BUILDDIR) $(OBJECTS) Makefile
	$(CXX) $(CLFAGS) -o $@ $(OBJECTS)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.cpp
	$(CXX) $(CLFAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf $(BUILDDIR)
