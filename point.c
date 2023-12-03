/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this) // class valide ou pas
        raise("CLASS NOT VALID");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (!this) // class valide ou pas
        raise("CLASS NOT VALID");
    this->x = 0;
    this->y = 0;
}


static char *Point_str(PointClass *this)
{
    size_t len;
    char *str = NULL;

    if (!this)
        raise("CLASS NOT VALID");
    len = snprintf(NULL, 0, "<Point (%d, %d)>", this->x, this->y) + 1;
    str = malloc(sizeof(char) * len);
    if (snprintf(str, len, "<Point (%d, %d)>", this->x, this->y) == -1)
        raise("ERROR");
    return (str);
}

static Object *Point_add(const Object *one, const Object *two)
{
    PointClass *p1 = (PointClass *)one;
    PointClass *p2 = (PointClass *)two;
    return(new(Point, p1->x + p2->x, p1->y + p2->y));
}

static Object *Point_sub(const Object *one, const Object *two)
{
    PointClass *p1 = (PointClass *)one;
    PointClass *p2 = (PointClass *)two;
    return(new(Point, p1->x - p2->x, p1->y - p2->y));
}

static Object *Point_mult(const Object *one, const Object *two)
{
    PointClass *p1 = (PointClass *)one;
    PointClass *p2 = (PointClass *)two;
    return(new(Point, p1->x * p2->x, p1->y * p2->y));
}

static Object *Point_div(const Object *one, const Object *two)
{
    PointClass *p1 = (PointClass *)one;
    PointClass *p2 = (PointClass *)two;
    return(new(Point, p1->x / p2->x, p1->y / p2->y));
}

static bool Point_eq(const Object *one, const Object *two)
{
    PointClass *p1 = (PointClass *)one;
    PointClass *p2 = (PointClass *)two;

    return((p1->x == p2->x) && (p1->y == p2->y));
}

static bool Point_gt(const Object *one, const Object *two)
{
    PointClass *p1 = (PointClass *)one;
    PointClass *p2 = (PointClass *)two;

    return((p1->x + p1->y) > (p2->x + p2->y));
}

static bool Point_lt(const Object *one, const Object *two)
{
    PointClass *p1 = (PointClass *)one;
    PointClass *p2 = (PointClass *)two;

    return((p1->x + p1->y) < (p2->x + p2->y));
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = (binary_operator_t)&Point_mult,
        .__div__ = (binary_operator_t)&Point_div,
        .__eq__ = (binary_comparator_t)&Point_eq,
        .__gt__ = (binary_comparator_t)&Point_gt,
        .__lt__ = (binary_comparator_t)&Point_lt
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
