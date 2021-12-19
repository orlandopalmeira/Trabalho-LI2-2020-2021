all: compile docS

compile:
	gcc -std=gnu11 -Wall -Wextra -pedantic-errors -O ./source/stack.c ./source/operators.c ./source/parser.c ./source/main.c -o main -lm
	mv main ./source

docS:
	mv ./source/**.c ./source/**.h .
	doxygen
	mv **.c **.h source
	mv html latex xml ./docs

test:
	while :; do echo Nova sessão do interpretador; echo -n ">>> ";./source/main ; done