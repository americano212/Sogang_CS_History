CC = g++
CFLAGS = -g -O3 -w

INCLUDES =
OBJECTS = main.o Str.o

TARGET = runfile

all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJECTS)
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
.PHONY : clean
clean:
	rm $(OBJECTS) $(TARGET)
