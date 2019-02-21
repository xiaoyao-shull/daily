compile: LENGFACT.c
	@gcc -o LENGFACT LENGFACT.c -lm

test: compile
	@./LENGFACT < input.txt

clean:
	@rm -f LENGFACT
