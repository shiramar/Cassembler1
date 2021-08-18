#ifndef assembler_h

#define assembler_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>

/*data*/

#define MAX_INPUT 81 /*max line's chars*/
#define MAX_LABEL 32 /*max label's chars*/
#define DEFAULT_IC 100 /*initial ic*/
#define EMPTY_ERROR 0
#define ERROR 1
#define NO_MATCH -1 /*no match in comparison*/
#define MAX_LINES 500 /*max line in data tables*/
#define UNKNOWN_FUNCT 0
#define NUMBER_OF_COMMANDS 27
#define MIN_REGISTER_NUM 0 /*first register*/
#define MAX_REGISTER_NUM 31 /*latest register*/


/*Enums for guidances*/

enum guidance {ENTRY, DB = 1, DH = 2, ASCIZ, DW = 4, EXTERN, UNKNOWN_TYPE};

/*Enum for commands*/
enum commands { ADD, SUB, AND, OR, NOR, MOVE, MVHI, MVLO, ADDI, SUBI, ANDI, ORI, NORI, BNE, BEQ, BLT, BGT, LB, SB, LW, SW, LH, SH, JMP, LA, CALL, STOP , UNKNOWN_COMMAND };


/*Enum of out file types*/
enum filetype {FILE_OBJECT, FILE_ENTRY, FILE_EXTERN };

/* Methods for the operands */
enum methods {METHOD_REGISTER, METHOD_LABEL, METHOD_IMMEDIATE };

/*for colon check*/
enum { NO_COLO, COLON };

/* Errors types */
enum errors {
    INVALID_SYNTAX = 1, INVALID_LABEL_LINE, MISSING_SYNTAX, NO_PARAMETER_AVAILABLE, GUIDANCE_INVALID_NUM_PARAMS, DATA_EXPECTED_NUM,
    DATA_EXPECTED_COMMA_AFTER_NUM, DATA_COMMAS_IN_A_ROW, DATA_UNEXPECTED_COMMA, STRING_TOO_MANY_OPERANDS, STRING_OPERAND_NOT_VALID,
    EXTERN_NO_LABEL, EXTERN_INVALID_LABEL, EXTERN_TOO_MANY_OPERANDS, COMMAND_UNEXPECTED_CHAR, COMMAND_TOO_MANY_OPERANDS, COMMAND_INVALID_OPERANDS_METHODS,
    COMMAND_INVALID_NUMBER_OF_OPERANDS, COMMAND_INVALID_METHOD, CANNOT_OPEN_FILE, COMMAND_LABEL_DOES_NOT_EXIST,
    LABEL_TOO_LONG, LABEL_INVALID_FIRST_CHAR, LABEL_CANT_BE_COMMAND, LABEL_CANT_BE_REGISTER, LABEL_ALREADY_EXISTS, ENTRY_CANT_BE_EXTERN,
    ENTRY_LABEL_DOES_NOT_EXIST, UNVALID_REG, NO_LABEL_FOUND, UNVALID_LABEL, MEMORY_ALLOCATION_FAILED
};

#endif
