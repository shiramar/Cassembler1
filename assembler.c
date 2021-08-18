#include "assembler.h"
#include "external_vars.h"
#include "scanFunctions.h"
#include "functions.h"

/*List of commands*/
const char* commands[] = { "add", "sub", "and", "or", "nor", "move", "mvhi", "mvlo", "addi", "subi", "andi", "ori", "nori", "bne", "beq", "blt", "bgt", "lb", "sb", "lw", "sw", "lh", "sh", "jmp", "la", "call", "stop"};

/*List of guidance*/
const char* guidance[] = { ".entry", ".db", ".dh", ".asciz", ".dw", ".extern" };

unsigned int instructions_image[MAX_LINES];
unsigned char data_image[MAX_LINES];
int ic;
int dc;
int error;

labelPtr symbols_table; /*symbol tabel for the labels*/
extPtr ext_list;
boolean entry_exists, extern_exists, error_exist; /*To mark if it is one of these types*/

/* The fucnction that resets all flags for next file */
void reset_flags() {
    symbols_table = NULL;
    ext_list = NULL;
    entry_exists = FALSE;
    extern_exists = FALSE;
    error_exist = FALSE;
}

/* Check if file end with .as*/
int check_file_name(char *name){
    int len = strlen(name)-3;
    int i=0;
    for (i = 0; i < len; i++)
    {
        name++;
    }
    return (strcmp(name,".as")==0);
}


/* maim function */
int main(int argc, char* argv[]) {
    int i;
    FILE* fp;

    if (argc < 2) {
        fprintf(stdout, "there aren't arguments, please try enter a file name to process\n");
        exit(1);
    }
    else {
        for (i = 1; i < argc; i++) {
            if (!check_file_name(argv[i]))/*check if the file name ends in '.as'*/
                fprintf(stderr, "\nInvalid file type: %s\n", argv[i]);
            else{
                if ((fp = fopen(argv[i], "r")) == NULL) { /*Open the file*/
                    fprintf(stderr, "\nProblem opening the file: %s\n", argv[i]);
                }
                else {
                    if (feof(fp) == 1)/*check if it's a empty file */
                        fprintf(stderr, "\nThe file is empty\n");
                    else {
                        reset_flags();/* we will resets flags for the next file */
                        scanOne(fp);

                        if (error == 0) {/* no errors, start second pass*/
                            rewind(fp);/*return to the start of the file for the second pass*/
                            scanTwo(fp, argv[i]);
                        }
                        else {/* there are errors, stop processing the file */
                            fprintf(stdout, "Errors found in file: %s, stoped process this file\n", argv[i]);
                        }
                        fclose(fp); /* Close the file */
                    }
                }
                
            }
        }
    }
    return 0;
}
