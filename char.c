/*
** EPITECH PROJECT, 2023
** char
** File description:
** Rush 2.
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("Invalid CLass");
    this->x = (char)va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (!this)
        raise("Invalid CLass");
    this->x = '\0';
}

static char *Char_str(CharClass *this)
{
    size_t len;
    char *str = NULL;

    if (!this)
        raise("CLASS NOT VALID");
    len = snprintf(NULL, 0, "<Char (%c)>", this->x) + 1;
    str = malloc(sizeof(char) * len);
    if (snprintf(str, len, "<Char (%c)>", this->x) == -1)
        raise("ERROR");
    return (str);
}

static Object *Char_add(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    CharClass *p1 = (CharClass *)one;
    CharClass *p2 = (CharClass *)two;
    return(new(Char, p1->x + p2->x));
}

static Object *Char_sub(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    CharClass *p1 = (CharClass *)one;
    CharClass *p2 = (CharClass *)two;
    return(new(Char, p1->x - p2->x));
}

static Object *Char_mult(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    CharClass *p1 = (CharClass *)one;
    CharClass *p2 = (CharClass *)two;
    return(new(Char, p1->x * p2->x));
}

static Object *Char_div(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    CharClass *p1 = (CharClass *)one;
    CharClass *p2 = (CharClass *)two;
    return(new(Char, p1->x / p2->x));
}

static bool Char_eq(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    CharClass *p1 = (CharClass *)one;
    CharClass *p2 = (CharClass *)two;
    return((p1->x == p2->x));
}

static bool Char_gt(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    CharClass *p1 = (CharClass *)one;
    CharClass *p2 = (CharClass *)two;
    return(p1->x > p2->x);
}

static bool Char_lt(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    CharClass *p1 = (CharClass *)one;
    CharClass *p2 = (CharClass *)two;
    return(p1->x < p2->x);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mult,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0
};

const Class *Char = (const Class *)&_description;
