CXX = g++
EXECUTABLE = motor

IDIR = ./include
ODIR = ./build
SDIR = ./src

CXX_FLAGS = -std=c++11
LIBS = -lJetsonGPIO -lpthread

_DEPS = pwm.h encoder.h motor.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o encoder.o motor.o pwm.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
		@echo "Building. . ."
		$(CXX) -c -o $@ $< -I$(IDIR) $(CXX_FLAGS)

$(ODIR)/$(EXECUTABLE): $(OBJ)
	$(CXX) $^ -o $@ -I$(IDIR) $(LIBS) $(CXX_FLAGS)

all: $(ODIR)/$(EXECUTABLE)

run: clean all
	@echo "Executing. . ."
	./$(ODIR)/$(EXECUTABLE)

.PHONY: clean

clean:
	@echo "Cleaning up. . ."
	rm -rf build/*
