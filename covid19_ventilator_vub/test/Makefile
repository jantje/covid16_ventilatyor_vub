TEST_OBJS=suite.o \
		  Print.o \

OBJS=\
	 ../Alarm.o \
	 arduino-mock/src/Arduino.o \
	 arduino-mock/src/ArduinoMockAll.o \
	 arduino-mock/src/Serial.o \
	 arduino-mock/src/Wire.o \

TEST_SRCS=$(TEST_OBJS:.o=.cpp)
SRCS=$(OBJS:.o=.cpp)

CXXFLAGS:=-I../\
	-I.\
	-I../libs/LiquidCrystal_I2C \
	-Iarduino-mock/include/arduino-mock/ \
	-Iarduino-mock/include/ \

LDFLAGS:=-lgtest

.PHONY: test

test: suite
	./suite

%.o: %.cpp .deps
	$(CXX) -MMD -MF .deps/$$(basename $*).d -MP \
		$(CXXFLAGS) \
	    -fprofile-arcs -ftest-coverage \
		-c $< \
		-o $@

suite: $(TEST_OBJS) $(OBJS) .deps
	$(CXX) -MMD -MF .deps/$@.d -MP \
		$(CXXFLAGS)\
		$(LDFLAGS)\
	    -fprofile-arcs -ftest-coverage \
		$< -o $@

.deps:
	mkdir -p .deps

deps=$(addprefix .deps/,$(SRCS:.cpp=.d)) $(addprefix .deps/,$(TEST_SRCS:.cpp=.d))
-include $(deps)
