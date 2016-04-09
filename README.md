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
```gcc -o pcode pcode.c``` or copy/paste in some IDE

# Running
./pcode

# Example
Sum of 2 numbers
```
Starting the P-code Machine.
Please enter the instructions (Instruction END 0 0 to stop the input)
INT 0 5
Top: 0 Base: 1 Counter: 1 Stack: 0 0 0 0 0 
LIT 0 3
Top: 3 Base: 1 Counter: 2 Stack: 0 0 0 0 0 3 
STO 0 3
Top: 0 Base: 1 Counter: 3 Stack: 0 0 0 3 0 
LIT 0 5
Top: 5 Base: 1 Counter: 4 Stack: 0 0 0 3 0 5 
STO 0 4
Top: 5 Base: 1 Counter: 5 Stack: 0 0 0 3 5 
LOD 0 3
Top: 3 Base: 1 Counter: 6 Stack: 0 0 0 3 5 3 
LOD 0 4
Top: 5 Base: 1 Counter: 7 Stack: 0 0 0 3 5 3 5
OPR 0 2
Top: 8 Base: 1 Counter: 8 Stack: 0 0 0 3 5 8 
END 0 0

Stop ...
```

# Useful links
[Step-by-step execution for PL/0 machine](http://blackmesatech.com/2011/12/pl0/index.xhtml)

[PL/0 machine functions description](http://blackmesatech.com/2011/12/pl0/pl0.xhtml)

[Reference code](https://en.wikipedia.org/wiki/P-code_machine)

[Reference code 2](https://github.com/thebeta/p-code-machine-C)
