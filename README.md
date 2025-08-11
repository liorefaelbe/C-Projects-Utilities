# C++ Projects & Utilities

This repository contains a collection of C++ implementations, utilities, and programming exercises covering:
- Data structures
- Object-Oriented Design
- Templates and metaprogramming
- File and directory handling
- Concurrency and synchronization

## Structure
- **inc/** – Header files for all modules.
- **src/** – Implementation files, organized into thematic folders.
- **test/** – Unit tests for each module.

## Topics Covered
- Custom `shared_ptr` implementation
- Bit manipulation utilities (`bitset`, `bitarr`)
- RAII patterns (`scopedlock`)
- String handling (`rcstring`, `simple_string`)
- Geometry (`point`, `shapes`, `complex`)
- File and directory manipulation (`file`, `dir`, `reg_file`)
- Concurrency examples
- Template metaprogramming

## Build Instructions
```bash
# Compile everything
make

# Run tests (example)
./test/bitarr_test
