<<<<<<< HEAD
CXXFLAGS += -std=c++11
LDLIBS += -lcppunit -lstdc++
=======
LDLIBS += -lcppunit -lstdc++
CXXFLAGS += -std=c++11
>>>>>>> 0a59f980ef1449300fe3da1144e1ba7fb3ef6350

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
