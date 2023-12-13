TARGET= main
OX= -O3
SRCS= $(wildcard *.c)
OBJS= $(patsubst %.c, %.o, $(SRCS))
INCS= 
LIBS= 
CFLAGS= -std=c17 -Wall -g

all: $(TARGET)

%.o: %.c
	gcc -o $@ -c $^ $(INCS) $(LIBS) $(CFLAGS) $(OX)

main: $(OBJS)
	gcc -o $@ $(INCS) $(OBJS) $(LIBS) $(CFLAGS) $(OX)

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

.PHONY: clean