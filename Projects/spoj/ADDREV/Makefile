compile: compile-java
test: test-java

compile-java: Main.java
	@javac Main.java

test-java: compile-java
	@java Main < input.txt

compile-c: ADDREV.c
	@gcc -o ADDREV ADDREV.c

test-c: compile
	./ADDREV < input.txt

clean:
	@rm -f ADDREV
	@rm -f *.class