compile: DANGER.c
	@gcc -o DANGER DANGER.c

test: compile
	@./DANGER < input.txt

clean:
	@rm -f DANGER
