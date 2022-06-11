CFLAGS+= -g -w
SOURCES = $(wildcard *.cpp) $(wildcard src\*.cpp) ${wildcard src\core\*.cpp} ${wildcard src\utils\*.c}
OBJS := $(patsubst %.cpp, %.o,$(SOURCES))
    
CC = gcc
main: $(OBJS)
		@echo "source files:" $(SOURCES)
		@echo "object files:" $(OBJS)
		$(CC) $(OBJS)  -D$(MACRO) $(CFLAGS) -o main  
sinclude $(SOURCES:.c=.d)
%d: %c
		@echo "create depend"
		$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
		sed 's,\($*\)\.o[ :]*,\1.o $@ ,g' < $@.$$$$ > $@; \
		$(RM) $@.$$$$