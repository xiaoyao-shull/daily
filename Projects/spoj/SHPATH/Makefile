compile: SHPATH.c
	@gcc -o SHPATH SHPATH.c

test: compile
	@./SHPATH < input.txt

clean:
	@rm -f SHPATH
