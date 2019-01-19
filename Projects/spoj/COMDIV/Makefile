compile: COMDIV.c
	@gcc -o COMDIV COMDIV.c -lm

test: compile
	@./COMDIV < input.txt

clean:
	@rm -f COMDIV
