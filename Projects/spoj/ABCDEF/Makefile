compile: ABCDEF.c
	@gcc -o ABCDEF ABCDEF.c

test: compile
	@./ABCDEF < input.txt

clean:
	@rm -f ABCDEF
