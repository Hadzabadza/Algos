LDFLAGS += -lcppunit -lstdc++

ifeq ($(OS),Windows_NT)
  MYOS := Windows
else
  MYOS := $(shell uname -s)
endif

ifeq ($(MYOS),Darwin)
CPPUNITDIR = /Users/Shared/CppUnit
CPPFLAGS += -I$(CPPUNITDIR)/include
LDFLAGS += -L$(CPPUNITDIR)/lib
endif