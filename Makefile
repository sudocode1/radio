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

push-base:
	git add compiler.cpp 
	git add Makefile 
	git add README.md
	git commit 
	git push 

push-compiler:
	git add compiler.cpp 
	git commit 
	git push 

push-makefile:
	git add Makefile  
	git commit 
	git push 


push-all:
	git add *
	git commit 
	git push

push-all-force:
	git add * -f 
	git commit 
	git push 

push-docs:
	git add README.md 
	git add /docs 
	git commit 
	git push 