/*
 * stack.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

//main avr libraries
#include "util/delay.h"
#include "avr/io.h"
#define F_CPU 8000000UL
//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"

#include "HStack_init.h"
#include <string.h>

void InitializeStack(Stack *ps)
{
    ps->StackTop = 0;
}

void push(void *pe, Stack *ps,u8 ElementSize)
{
    Element *ptr = (Element*)malloc(sizeof(Element));
    ptr->size = ElementSize;
    ptr->stackentry = malloc(ElementSize);
    memcpy(ptr->stackentry,pe,ElementSize);
    ps->entry[ps->StackTop] = ptr;
    ps->StackTop++;
}

void pop(void *pe , Stack *ps, pu8 z)
{
    ps->StackTop--;
    *z = ps->entry[ps->StackTop]->size;
    memcpy(pe,ps->entry[ps->StackTop]->stackentry,*z);
    free(ps->entry[ps->StackTop]->stackentry);
    free(ps->entry[ps->StackTop]);
}

void StackTop(void *pe , Stack *ps, pu8 z)
{
    *z = ps->entry[ps->StackTop-1]->size;
    memcpy(pe,ps->entry[ps->StackTop-1]->stackentry,*z);
}

u8 StackFull(Stack *ps)
{
    return ps->StackTop == MAXSTACK;
}

u8 StackEmpty(Stack *ps)
{
    return ps->StackTop == 0;
}

u8 StackSize(Stack *ps)
{
    return ps->StackTop;
}

void ClearStack(Stack *ps)
{
    ps->StackTop = 0;
}












