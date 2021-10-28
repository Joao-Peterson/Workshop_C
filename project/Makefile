OBJS := main.o
LIBS := lib/libdoc.a lib/libcmdf.a

I_FLAGS := -Iinc

main : main.o $(LIBS)
	gcc $^ -o $@

%.o : %.c
	gcc $(I_FLAGS) -c $^ -o $@