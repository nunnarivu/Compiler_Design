# Compiler_Design

C compiler developed as a part of Compiler Design Course in IIT Delhi

The C language grammar (c.y and c.l files) have been taken from:

http://www.quut.com/c/ANSI-C-grammar-y-2011.html

run commands:
```bash
cd A2_final
make
./cc ./examples/hello_world.c
lli codegen.txt
```

Note: BIOSN generates few warning because some grammars are redundant and actions for those are not in the scope of this assignment. Please ignore the warnings produced by bison.

This code uses llvm-9 The code is generated in codegen.txt
