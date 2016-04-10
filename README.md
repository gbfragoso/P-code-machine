# P-code-machine
C implementation of p-code machine, exercise from university

# Available Functions
You can read about all these functions [here](http://blackmesatech.com/2011/12/pl0/pl0.xhtml).
Note: We use functions in uppercase letters because some of your functions has the same name of C-language keywords. The instruction's format is: name(char[3]) level(int) arg(int)

* LIT (Literals) 
* OPR (Operation) 
  * RTN (Return) ```OPR 0 0``` 
  * NEG (Negative) ```OPR 0 1```
  * ADD (Add) ```OPR 0 2```
  * SUB (Subtract) ```OPR 0 3```
  * MUL (Multiply) ```OPR 0 4```
  * DIV (Divide) ```OPR 0 5```
  * MOD (Module) ```OPR 0 6```
  * ODD (Odd) ```OPR 0 7```
  * EQL (Equals) ```OPR 0 8```
  * NEQ (Not equals) ```OPR 0 9```
  * LSS (Less than) ```OPR 0 10```
  * LEQ (Less equals) ```OPR 0 11```
  * GTR (Greater than) ```OPR 0 12```
  * GEQ (Greater equals) ```OPR 0 13```
* LOD (Load)
* STO (Store)
* CAL (Call subroutine)
* INT (Internal) 
* JMP (Jump)
* JPC (Conditional Jump)
* WRT (Write)

# Compilation
```gcc -o pcode pcode.c```

# Running
./pcode

# Examples
## Sum 2 numbers
```
INT 0 5
LIT 0 8
STO 0 3
LIT 0 4
STO 0 4
LOD 0 3 
LOD 0 4
OPR 0 2
END 0 0

Output:
Inst       Level           Arg             Top             Counter         Stack
INT        0               5               0               1               0 0 0 0 0 
LIT        0               8               8               2               0 0 0 0 0 8 
STO        0               3               0               3               0 0 0 8 0 
LIT        0               4               4               4               0 0 0 8 0 4 
STO        0               4               4               5               0 0 0 8 4 
LOD        0               3               8               6               0 0 0 8 4 8 
LOD        0               4               4               7               0 0 0 8 4 8 4 
OPR        0               2               4               8               0 0 0 8 4 12 

```

## Subtract 2 numbers
```
INT 0 5
LIT 0 8
STO 0 3
LIT 0 4
STO 0 4
LOD 0 3 
LOD 0 4
OPR 0 3
END 0 0

Output:
Inst       Level           Arg             Top             Counter         Stack
INT        0               5               0               1               0 0 0 0 0 
LIT        0               8               8               2               0 0 0 0 0 8 
STO        0               3               0               3               0 0 0 8 0 
LIT        0               4               4               4               0 0 0 8 0 4 
STO        0               4               4               5               0 0 0 8 4 
LOD        0               3               8               6               0 0 0 8 4 8 
LOD        0               4               4               7               0 0 0 8 4 8 4 
OPR        0               3               4               8               0 0 0 8 4 4 
```

## Negate a number
```
INT 0 2
LIT 0 1
OPR 0 1
END 0 0

Output:
Inst       Level           Arg             Top             Counter         Stack
INT        0               2               0               1               0 0 
LIT        0               1               1               2               0 0 1 
OPR        0               1               -1              3               0 0 -1 
```

## Verify if num 1 > num 2
```
INT 0 5
LIT 0 5
STO 0 3
LIT 0 4
STO 0 4
LOD 0 3
LOD 0 4
OPR 0 12
END 0 0

Output: (1 at top is true, that is 5>4)
Inst       Level           Arg             Top             Counter         Stack
INT        0               5               0               1               0 0 0 0 0 
LIT        0               5               5               2               0 0 0 0 0 5 
STO        0               3               0               3               0 0 0 5 0 
LIT        0               4               4               4               0 0 0 5 0 4 
STO        0               4               4               5               0 0 0 5 4 
LOD        0               3               5               6               0 0 0 5 4 5 
LOD        0               4               4               7               0 0 0 5 4 5 4 
OPR        0               12              1               8               0 0 0 5 4 1

INT 0 5
LIT 0 8
STO 0 3
LIT 0 9
STO 0 4
LOD 0 3
LOD 0 4
OPR 0 12
END 0 0

Output: (0 at top is false, that is 8<9)
Inst       Level           Arg             Top             Counter         Stack
INT        0               5               0               1               0 0 0 0 0 
LIT        0               8               8               2               0 0 0 0 0 8 
STO        0               3               0               3               0 0 0 8 0 
LIT        0               9               9               4               0 0 0 8 0 9 
STO        0               4               9               5               0 0 0 8 9 
LOD        0               3               8               6               0 0 0 8 9 8 
LOD        0               4               9               7               0 0 0 8 9 8 9 
OPR        0               12              0               8               0 0 0 8 9 0 
```

# Useful links
[Step-by-step execution for PL/0 machine](http://blackmesatech.com/2011/12/pl0/index.xhtml)

[PL/0 machine functions description](http://blackmesatech.com/2011/12/pl0/pl0.xhtml)

[Reference code](https://en.wikipedia.org/wiki/P-code_machine)

[Reference code 2](https://github.com/thebeta/p-code-machine-C)
