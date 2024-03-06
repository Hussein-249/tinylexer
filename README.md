# tinylexer
![](https://img.shields.io/badge/Development-Ongoing-blue)
> A barebones lexer for minimal C-like languages, written in C.

## Description
The functions of a compiler can be split into lexing, creating an abstract syntax tree (AST), creating an intermediate representation (IR), and code generation. Compilers can be viewed as having a 'front end' in which the language is read and an AST is produced, which can then be handed over to the 'back end' which accepts ASTs and generate platform-specific IRs and bytecode. This lexer aims to model the front end of a compiler for C-like languages.

## Purpose
This is a personal project, and as such is likely to be a sub-optimal solution.

# Environment
This lexer is written using the standard C library in ```Ubuntu 22.04```. Cross-platform compatibility may be introduced, but not in the the near future.

# Tests

This lexer is meant to be barebones. No tests will be included in this repo.

# Documentation

To be written once a fully-working model is released.
