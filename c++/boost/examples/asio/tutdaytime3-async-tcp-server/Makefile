CXX=g++
CFLAGS=-g -Wall

INCLUDE_PATH=/usr/local/include
INCLUDE_PATH_OBJS=$(INCLUDE_PATH:%=-I%)

LIBS=boost_system pthread
LIBRARY_PATH=/usr/local/lib
LIBDIR_OBJS=$(LIBRARY_PATH:%=-L%)
LIB_OBJS=$(LIBS:%=-l%)

SOURCES=main.cpp
OBJECTS=$(SOURCES:%.cpp=$(OBJDIR)/%.o)

BUILDDIR=build
BINDIR=$(BUILDDIR)/bin
OBJDIR=$(BUILDDIR)/obj
EXE=$(BINDIR)/boost_asio_tut_daytime3_tcp_async_server

DIRS=$(BUILDDIR) $(BINDIR) $(OBJDIR)

all: $(EXE)

$(EXE): $(DIRS) $(OBJECTS) Makefile
	$(CXX) $(CFLAGS) $(INCLUDE_PATH_OBJS) \
         $(LIBDIR_OBJS) $(OBJECTS) $(LIB_OBJS) -o $@

$(DIRS):
	mkdir -p $@

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf $(BUILDDIR)
