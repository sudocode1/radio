# compile the compiler
compiler: compiler.cpp
	g++ -o compiler.out compiler.cpp -I.

# compile the compiled radio file
compile: output.c
	gcc output.c -I.

fullcompile: compiler.cpp output.c
	### COMPILE COMPILER ###
	g++ -o compiler.out compiler.cpp -I.
	### RUN COMPILER ###
	./compiler.out
	### COMPILE COMPILED RADIO FILE ###
	gcc output.c -I.
	### RUN COMPILED RADIO FILE ###
	./a.out 