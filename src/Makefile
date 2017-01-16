CC 	= g++

CFLAGS 	= -O3 -fomit-frame-pointer
LIBS = -lm

OBJS   	= main.o\
	  allocate.o\
	  excp.o\
	  excp_fd.o\
	  excp_sd.o\
	  cal_g.o\
	  cal_u.o\
	  fft.o\
	  fft4g.o\
	  initialize.o\
	  iterate.o\
	  output.o\
	  output_gvv.o\
	  output_xsv.o\
	  read_input.o\
	  sum.o\

PROGRAM = eda
.cc.o:
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(PROGRAM)

$(PROGRAM) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(PROGRAM)

clean:;	@rm -f $(OBJS) core

$(OBJS) : 
