CC 	= g++

CFLAGS 	= -O3 -fomit-frame-pointer -fopenmp
LIBS = -lfftw3_threads -lfftw3 -lm

OBJS   	= main.o\
	  
PROGRAM = eda
.cc.o:
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(PROGRAM)

$(PROGRAM) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(PROGRAM)

clean:;	@rm -f $(OBJS) core

$(OBJS) : 




