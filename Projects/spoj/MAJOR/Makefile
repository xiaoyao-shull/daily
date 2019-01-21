compile: MAJOR-sort.c
	@gcc -o MAJOR MAJOR-sort.c

test: compile
	@./MAJOR < input.txt

clean:
	@rm -f MAJOR
