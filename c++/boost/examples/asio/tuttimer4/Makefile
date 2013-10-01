CXX=g++
CFLAGS=-g -Wall
LIBS=boost_system pthread
BUILDDIR=build
BINDIR=$(BUILDDIR)/bin
OBJDIR=$(BUILDDIR)/obj
EXE=$(BINDIR)/boost_asio_tut_timer4
SOURCES=main.cpp
OBJECTS=$(SOURCES:%.cpp=$(OBJDIR)/%.o)
LIBDIRS=/usr/local/share/boost_1_54_0/stage/lib
LIBDIR_OBJS=$(LIBDIRS:%=-L%)
LIB_OBJS=$(LIBS:%=-l%)
DIRS=$(BUILDDIR) $(BINDIR) $(OBJDIR)

all: $(EXE)

$(EXE): $(DIRS) $(OBJECTS) Makefile
	$(CXX) $(CLFAGS) -o $@ $(OBJECTS) $(LIBDIR_OBJS) $(LIB_OBJS)

$(DIRS):
	mkdir -p $@

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CLFAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf $(BUILDDIR)
