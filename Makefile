# compilers
compiler: compiler.cpp
	g++ -o compiler.out compiler.cpp -I.

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

# docs
docs:
	node docs/docgen
	### Completed

# git
push-base:
	git add compiler.cpp 
	git add Makefile 
	git add README.md
	git add CHANGELOG.md 
	git commit 
	git push 

push-compiler:
	git add compiler.cpp
	git add CHANGELOG.md 
	git commit 
	git push 

push-makefile:
	git add Makefile
	git add CHANGELOG.md 
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
	git add ./docs 
	git add DOCS.md 
	git add CHANGELOG.md
	git commit 
	git push 

push-docgen: 
	git add ./docs
	git add CHANGELOG.md 
	git commit 
	git push 