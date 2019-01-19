compile: ABCPATH-dfs.c
	@gcc -o ABCPATH ABCPATH-dfs.c

test: compile
	@./ABCPATH < input.txt

clean:
	@rm -f ABCPATH
