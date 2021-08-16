assembler: assembler.o scanOne.o struct.o externalStruct.o scanTwo.o functions.o
	gcc -g -ansi -Wall -pedantic assembler.o scanOne.o externalStruct.o scanTwo.o functions.o struct.o -lm -o assembler

assembler.o: assembler.c scanFunctions.h assembler.h external_vars.h struct.h functions.h
	gcc -c -ansi -Wall -pedantic assembler.c -o assembler.o

scanOne.o: scanOne.c scanFunctions.h assembler.h external_vars.h struct.h functions.h
	gcc -c -ansi -Wall -pedantic scanOne.c -o scanOne.o 

struct.o: struct.c scanFunctions.h assembler.h external_vars.h struct.h functions.h
	gcc -c -ansi -Wall -pedantic struct.c -o struct.o

functions.o: functions.c scanFunctions.h assembler.h external_vars.h struct.h functions.h
	gcc -c -ansi -Wall -pedantic functions.c -o functions.o

scanTwo.o: scanTwo.c scanFunctions.h assembler.h external_vars.h struct.h
	gcc -c -ansi -Wall -pedantic scanTwo.c -o scanTwo.o

externalStruct.o: externalStruct.c scanFunctions.h assembler.h external_vars.h struct.h
	gcc -c -ansi -Wall -pedantic externalStruct.c -o externalStruct.o