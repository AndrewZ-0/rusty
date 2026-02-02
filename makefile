CXX = g++
CXXFLAGS = -std=c++17 -O3 -Iincludes
TARGET = rusty

SRC = $(wildcard src/**/*.cpp)

all:
	$(CXX) ${CXXFLAGS} $(SRC) rusty.cpp -o ${TARGET}
