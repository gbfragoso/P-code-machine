/*
    Author: Gustavo B. Fragoso
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX_INSTRUCTIONS 14 // Define your own

typedef struct{
    int operation;
    int level;
    int argument;
} Tinstruction;

int stack[1024] = {-1};	    		// Vector with only integers, used as a datastore
int base = 1;				// Points to the base address in the stack for the current invocation of a given procedure
int top = 0; 				// Points to the current top of the stack
int counter = 0;  			// Points to an instruction in the program area

// Array of instructions (Input)
Tinstruction instructions[MAX_INSTRUCTIONS]; 

// List of available instructions
enum { LIT, OPR, LOD, STO, CAL, INT, JMP, JPC, WRT } instructionCode;
char * instructionString[] = { "LIT", "OPR", "LOD", "STO", "CAL", "INT", "JMP", "JPC", "WRT" };

// List of available arithmetic operations
enum { RTN, NEG, ADD, SUB, MUL, DIV, ODD, MOD, EQL, NEQ, LSS, LEQ, GTR, GEQ } operationCode;
char * operationString[] = { "RTN", "NEG", "ADD", "SUB", "MUL", "DIV", "MOD", "ODD", "EQL", "NEQ", "LSS", "LEQ", "GTR", "GEQ"};

// Prototypes 
void executeInstruction();
void stackOperation(int argument);
int getBase(int level);
int getInstructionCode(char *c);

int main (int argc, char **argv){
	
    // Operation
    char a[3];
    
    // Params
    int i=0,b=0,c=0;
    
    printf("Starting the P-code Machine.\nPlease enter the instructions (Instruction END 0 0 to stop the input)\n");
    
    // User input
    for(i = 0; i<MAX_INSTRUCTIONS; i++){
	    scanf("\n%[^ ] %d %d",a,&b,&c); 

	    if(strcmp(a,"END") == 0){
			printf("\nStop ...\n");
			break;
	    }else{
	    	int code = getIntructionCode(a);
	    	if(code != -1){
		    	Tinstruction instruction;
			    instruction.operation = code;
			    instruction.level = b;
			    instruction.argument = c;
				
				// Store the instruction in instructions array
				instructions[i] = instruction;
				
				// Execution and trace
				executeInstruction();
	    	}else{
	    		printf("Unknown instruction, continue input with valid instructions\n");
	    	}
	    }
    }
}

void executeInstruction(){
	int aux;

	Tinstruction instruction = instructions[counter];
	counter++;
	switch (instruction.operation){
		case LIT:
			top++;
			stack[top] = instruction.argument;
			break;
		case OPR:
			switch(instruction.argument){
				case RTN:
					top = base - 1;
					counter = stack[top+3];
					base = stack[top+2];
					break;
				case NEG:
					stack[top]= -1*stack[top];
					break;
				case ADD:
					top--;
					stack[top] += stack[top+1];
					break;
				case SUB:
					top--;
					stack[top] -= stack[top+1];
					break;
				case MUL:
					top--;
					stack[top] *= stack[top+1];
					break;
				case DIV:
					top--;
					stack[top] /= stack[top+1];
					break;
				case MOD:
					top--;
					stack[top] %= stack[top+1]; 
					break;
				case ODD:
					stack[top] = (stack[top]%2 == 1);
					break;
				case EQL:
					top--;
					stack[top] = (stack[top] == stack[top+1]);
					break;
				case NEQ:
					top--;
					stack[top] = (stack[top] != stack[top+1]);
					break;
				case LSS:
					top--;
					stack[top] = (stack[top] < stack[top+1]);
					break;
				case LEQ:
					top--;
					stack[top] = (stack[top] <= stack[top+1]);
					break;
				case GTR:
					top--;
					stack[top] = (stack[top] > stack[top+1]);
					break;
				case GEQ:
					top--;
					stack[top] = (stack[top] >= stack[top+1]);
					break;
				default:
					printf("Esta subfuncao do OPR nao foi implementada");
					break;
				}
			break;
		case LOD:
			top++;
			stack[top] = stack[ getBase(instruction.level) + instruction.argument ];
			break;
		case STO:
			stack[ getBase(instruction.level) + instruction.argument ] = stack[top];
			top--;
			break;
		case CAL:
			stack[top+1] = getBase( instruction.level );
			stack[top+2] = base;
			stack[top+3] = counter;
			base = top+1;
			counter = instruction.argument;
			break;
		case INT:
			top += instruction.argument;
			break;
		case JMP:
			counter = instruction.argument-1;
			break;
		case JPC:
			if (stack[top] == 0){
				counter = instruction.argument-1;
			}
			top--;	
			break;
		default:
			printf("Essa operacao nao foi implementada");
	}
		
	// PrintStackTrace
	printf("Top: %d Base: %d Counter: %d Stack: ", stack[top], base, counter);

	for (aux = base; aux<top+1;aux++){
		printf("%d ", stack[aux]);
	}
	printf("\n");
}

int getBase(int level){
    int newBase;
	newBase = base;
	while (level>0){
		newBase = stack[newBase];
		level--;
	}
	return newBase;
}

int getIntructionCode(char *c){
	int i;
	for (i = 0; i<9;i++){
		if(strcmp(c, instructionString[i]) == 0){
			return i;
		}
	}
	return -1;
}
