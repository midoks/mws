EXE = mws
all: $(EXE) clean

CC = gcc
CFLAGS = -g -W -Wall
LIBS = -lpthread

OBJS = mws.o deamon.o connect.o times.o

-include $(OBJS:.o=.d)

mws: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS) $(LIBS)

%.d: %.c
	set -e; $(CC) -MM $(CFLAGS) $< \
		| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
		[ -s $@ ] || rm -f $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	cp $(EXE) ../
	rm -f $(EXE) *.o *~ core.* *.d

