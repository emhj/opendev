CXX=g++
CFLAGS=-g -Wall
BUILDDIR=build
BINDIR=$(BUILDDIR)/bin
OBJDIR=$(BUILDDIR)/obj
EXE=$(BINDIR)/hello_world
SOURCES=main.cpp
OBJECTS=$(SOURCES:%.cpp=$(OBJDIR)/%.o)
DIRS=$(BUILDDIR) $(BINDIR) $(OBJDIR)

all: $(EXE)

$(EXE): $(DIRS) $(OBJECTS) Makefile
	$(CXX) $(CLFAGS) -o $@ $(OBJECTS)

$(DIRS):
	mkdir -p $@

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CLFAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf $(BUILDDIR)
