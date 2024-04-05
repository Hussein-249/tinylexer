# tinylexer
![](https://img.shields.io/badge/Development-Ongoing-blue)
> A barebones lexer for a subset of C grammar, written in C.

## Description
The functions of a compiler can be split into lexing, creating an abstract syntax tree (AST), creating an intermediate representation (IR), and code generation. Compilers can be viewed as having a 'front end' in which the language is read and an AST is produced, which can then be handed over to the 'back end' which accepts ASTs and generate platform-specific IRs and bytecode. This lexer aims to model the front end of a compiler for C-like languages.

## Purpose
This is a personal project, and as such is likely to be a sub-optimal solution. It is intended to be used where a lexer is needed, such as in a parser or text editor.

# Environment
This lexer is written using the standard C library in ```Ubuntu 22.04```, with cross-platform compatibility to be intorduced in the future.

# Tests

Some simple test files will be included in the test directory, along with their expected output.

To run, them, simply pass the desired file as an argument:

``` bash
./tinylexer <filename>.c
```

# Documentation

Full documentation can be viewed [here.](https://github.com/Hussein-249/tinylexer/wiki)

This section only briefly covers the most critical functions of the lexer.

