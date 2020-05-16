Compiler project implementing a subset of features from Go

**Getting started**

* `programs`: Test programs that are used by test scripts. These are organized by compilation phase and by expected result. Valid programs should output `OK` and status code `0`, while invalid programs should output `Error: <description>` and status code `1`.
  * `Scan+parse`: Runs both the scanner and parser phases
  * `Typecheck`: Runs until the end of the typechecker phase
  * `Codegen`: Runs until your compiler outputs the target code
* `include` : hpp files. Most of the abstract syntax tree implementation is done in the .hpp files instead of have a .cpp file
* `src`: Source code 

The following three scripts are provided as an assignment template, modified to use CMake:
* `build.sh`: Builds your compiler using `Make` or similar. You should replace the commands here if necessary to build your compiler
* `run.sh`: Runs your compiler using two arguments (mode - $1 and input file - $2). You should replace the commands here if necessary to invoke your compiler
* `test.sh`: Automatically runs your compiler against test programs in the programs directory and checks the output
