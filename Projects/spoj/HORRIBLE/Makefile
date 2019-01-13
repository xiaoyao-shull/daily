compile: HORRIBLE-binary-index-tree.c
	@gcc -o HORRIBLE HORRIBLE-binary-index-tree.c

test: compile
	@./HORRIBLE < input.txt

clean:
	@rm -f HORRIBLE
