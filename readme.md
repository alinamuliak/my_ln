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
- by default, creates **hard link** (if none of the options are specified);
- you cannot specify `--soft` _and_ `--hard` simultaneously;
- if you specified `--help`, program prints help message and exits successfully;
- if source file does not exist, prints error message and exits with non-zero code;
- if destination file does exist, prints error message and exits with non-zero code;
- if there is more than 2 file names, prints error message and exits with non-zero code.
