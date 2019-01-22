compile: QUADAREA.c
	@gcc -o QUADAREA QUADAREA.c -lm

test: compile
	@./QUADAREA < input.txt

clean:
	@rm -f QUADAREA
