# Lab work: `my_ln`
#### Author: [Alina Muliak](https://github.com/alinamuliak)

## Prerequisites
- `Make`, `CMake`
- `UNIX`


### Compilation
```
./compile.sh
```
After compilation the binary file will be located at `bin` directory named `my_ln`.

### Usage

```
my_ln [--soft | --hard | --help] source_file destination_file
```
- you cannot specify `--soft` _and_ `--hard` simultaneously;
- if you specified `--help`, program prints help message and exits successfully;
- if source file does not exist, print error message and exits with non-zero code;
- if destination file does exist, print error message and exits with non-zero code.

