#include "assembler.h"
#include "struct.h"
#include "external_vars.h"

/* In this file we have all functions regarding the linked list of extern labels */

/* This function adds a node to the end of the list */
extPtr add_ext(extPtr* lptr, char* name, unsigned int reference) {

    extPtr t = *lptr;
    extPtr temp;

    temp = (extPtr)malloc(sizeof(ext));
    if (!temp)
    {
        printf("\nerror, cannot allocate memory\n");
        exit(1);
    }

    temp->address = reference;
    strcpy(temp->name, name);

    if (!(*lptr)) /* If the list is empty */
    {
        *lptr = temp;
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    ((*lptr)->prev)->next = temp;
    temp->next = t;
    temp->prev = t->prev;
    (*lptr)->prev = temp;

    return temp;
}

void print_ext(extPtr* lptr) {	
    int add= (*lptr)->address;
    do{
        printf("\n %s %d\n",(*lptr)->name,(*lptr)->address);
        *lptr = (*lptr)->next;
    } while ((*lptr)->address!=add);
    
}


/* This function frees the allocated memory for the list */
void free_ext(extPtr* lptr) {

    /* Frees the extern list by going over each extern node and free it*/
    extPtr temp = *lptr;
    if (temp) {
        unsigned int last_reference = ((*lptr)->prev)->address;
        unsigned int reference = 0;
        do {
            temp = *lptr;
            reference = temp->address;
            *lptr = (*lptr)->next;
            free(temp);
        } while (reference != last_reference);
    }
}