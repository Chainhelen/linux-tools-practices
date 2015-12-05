objects : more01.o more02.o who1.o who2.o
all:$(objects)

$(objects):%.o : %.c
	cc -c $< -o $@

.PHONY:clean
clean:
	rm -rf $(objects)
