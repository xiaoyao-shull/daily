compile: compile-java

test: test-java

compile-java: Main.java
	@javac Main.java

test-java: compile-java
	@java Main < input.txt

compile-c: TEST.c
	@gcc -o TEST TEST.c

test-c: compile
	@./TEST < input.txt

clean:
	@rm -f TEST
	@rm -f *.class
