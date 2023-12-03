/*
** EPITECH PROJECT, 2023
** int
** File description:
** Rush 2.
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
}   IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    if (!this)
        raise("Invalid CLass");
    this->x = va_arg(*args, int);
}

static void int_dtor(IntClass *this)
{
    if (!this)
        raise("Invalid CLass");
    this->x = '\0';
}

static char *int_str(IntClass *this)
{
    size_t len;
    char *str = NULL;

    if (!this)
        raise("CLASS NOT VALID");
    len = snprintf(NULL, 0, "<Int (%d)>", this->x) + 1;
    str = malloc(sizeof(char) * len);
    if (snprintf(str, len, "<Int (%d)>", this->x) == -1)
        raise("ERROR");
    return (str);
}

static Object *int_add(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    IntClass *p1 = (IntClass *)one;
    IntClass *p2 = (IntClass *)two;
    return(new(Int, p1->x + p2->x));
}

static Object *int_sub(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    IntClass *p1 = (IntClass *)one;
    IntClass *p2 = (IntClass *)two;
    return(new(Int, p1->x - p2->x));
}

static Object *int_mult(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    IntClass *p1 = (IntClass *)one;
    IntClass *p2 = (IntClass *)two;
    return(new(Int, p1->x * p2->x));
}

static Object *int_div(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    IntClass *p1 = (IntClass *)one;
    IntClass *p2 = (IntClass *)two;
    return(new(Int, p1->x / p2->x));
}

static bool int_eq(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    IntClass *p1 = (IntClass *)one;
    IntClass *p2 = (IntClass *)two;
    return((p1->x == p2->x));
}

static bool int_gt(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    IntClass *p1 = (IntClass *)one;
    IntClass *p2 = (IntClass *)two;
    return(p1->x > p2->x);
}

static bool int_lt(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    IntClass *p1 = (IntClass *)one;
    IntClass *p2 = (IntClass *)two;
    return(p1->x < p2->x);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_ctor,
        .__dtor__ = (dtor_t)&int_dtor,
        .__str__ = (to_string_t)&int_str,
        .__add__ = (binary_operator_t)&int_add,
        .__sub__ = (binary_operator_t)&int_sub,
        .__mul__ = (binary_operator_t)&int_mult,
        .__div__ = (binary_operator_t)&int_div,
        .__eq__ = (binary_comparator_t)&int_eq,
        .__gt__ = (binary_comparator_t)&int_gt,
        .__lt__ = (binary_comparator_t)&int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;
