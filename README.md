# radio
The Radio programming language.

## Information
Radio is a simple programming language which compiles to C. <br>
Here is a Hello World program. <BR>
```
out! "Hello World!"
```

## Usage
You will need g++ and/or gcc. The compiler has solely been tested on C++20 (gcc 9.3.0) on Linux, but it should work with C++17. <br>
If you have Make/Makefile installed, you can use the pre-made Makefile scripts to compile everything.

## Docs
You will need node.js v16 (may work on v15/v14). The docgen script was made by [1s3k3b](https://github.com/1s3k3b). You can edit it how you like and make pull requests to update or improve it. 

## Makefile scripts
All push scripts also push CHANGELOG.md
| Script | Results | Requirements
|---|---|---|
| `make compiler` | Compile the compiler | g++ or gcc |
| `make compile` | Compile output.c (compiled Radio file) | gcc |
| `make fullcompile` | Compile the compiler, run the compiler, compile output.c and run it | g++ and/or gcc |
| `make docs` | Build the docs | node.js (only tested on v16) |
| `make push-base` | Push compiler.cpp, Makefile and README.md | git |
| `make push-compiler` | Push compiler.cpp | git |
| `make push-makefile` | Push the Makefile | git |
| `make push-all` | Push everything other than anything in .gitignore | git |
| `make push-all-force` | Push everything | git |
| `make push-docs` | Push the DOCS.md and docgen | git |
| `make push-docgen` | Push docgen | git |