compile: CADYDIST.c
	@gcc -o CADYDIST CADYDIST.c

clean:
	@rm -f CADYDIST

test: compile
	@./CADYDIST < input.txt
