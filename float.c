/*
** EPITECH PROJECT, 2023
** float
** File description:
** Rush 2.
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    float x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        raise("Invalid CLass");
    this->x = (float)va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (!this)
        raise("Invalid CLass");
    this->x = '\0';
}

static char *Float_str(FloatClass *this)
{
    size_t len;
    char *str = NULL;

    if (!this)
        raise("CLASS NOT VALID");
    len = snprintf(NULL, 0, "<Float (%f)>", this->x) + 1;
    str = malloc(sizeof(char) * len);
    if (snprintf(str, len, "<Float (%f)>", this->x) == -1)
        raise("ERROR");
    return (str);
}

static Object *Float_add(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    FloatClass *p1 = (FloatClass *)one;
    FloatClass *p2 = (FloatClass *)two;
    return(new(Float, p1->x + p2->x));
}

static Object *Float_sub(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    FloatClass *p1 = (FloatClass *)one;
    FloatClass *p2 = (FloatClass *)two;
    return(new(Float, p1->x - p2->x));
}

static Object *Float_mult(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    FloatClass *p1 = (FloatClass *)one;
    FloatClass *p2 = (FloatClass *)two;
    return(new(Float, p1->x * p2->x));
}

static Object *Float_div(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    FloatClass *p1 = (FloatClass *)one;
    FloatClass *p2 = (FloatClass *)two;
    return(new(Float, p1->x / p2->x));
}

static bool Float_eq(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    FloatClass *p1 = (FloatClass *)one;
    FloatClass *p2 = (FloatClass *)two;
    return((p1->x == p2->x));
}

static bool Float_gt(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    FloatClass *p1 = (FloatClass *)one;
    FloatClass *p2 = (FloatClass *)two;
    return(p1->x > p2->x);
}

static bool Float_lt(const Object *one, const Object *two)
{
    if (!one || !two)
        raise("Not Initialised");
    FloatClass *p1 = (FloatClass *)one;
    FloatClass *p2 = (FloatClass *)two;
    return(p1->x < p2->x);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mult,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0
};

const Class *Float = (const Class *)&_description;
