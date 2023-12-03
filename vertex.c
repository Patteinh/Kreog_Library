/*
** EPITECH PROJECT, 2023
** Vertex
** File description:
** Rush 2.
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x, y, z;
}   vertexClass;

static void vertex_ctor(vertexClass *this, va_list *args)
{
    if (!this)
        raise("Invalid CLass");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void vertex_dtor(vertexClass *this)
{
    if (!this)
        raise("Invalid CLass");
    this->x = '\0';
    this->y = '\0';
    this->z = '\0';
}

static char *vertex_str(vertexClass *this)
{
    size_t len;
    char *str = NULL;

    if (!this)
        raise("CLASS NOT VALID");
    len = snprintf(NULL, 0, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z) + 1;
    str = malloc(sizeof(char) * len);
    if (snprintf(str, len, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z) == -1)
        raise("ERROR");
    return (str);
}

static Object *vertex_add(const Object *one, const Object *two)
{
    vertexClass *p1 = (vertexClass *)one;
    vertexClass *p2 = (vertexClass *)two;

    return(new(Vertex, p1->x + p2->x, p1->y + p2->y, p1->z + p2->z));
}

static Object *vertex_sub(const Object *one, const Object *two)
{
    vertexClass *p1 = (vertexClass *)one;
    vertexClass *p2 = (vertexClass *)two;

    return(new(Vertex, p1->x - p2->x, p1->y - p2->y, p1->z - p2->z));
}

static Object *vertex_mult(const Object *one, const Object *two)
{
    vertexClass *p1 = (vertexClass *)one;
    vertexClass *p2 = (vertexClass *)two;
    return(new(Vertex, p1->x * p2->x, p1->y * p2->y, p1->z * p2->z));
}

static Object *vertex_div(const Object *one, const Object *two)
{
    vertexClass *p1 = (vertexClass *)one;
    vertexClass *p2 = (vertexClass *)two;
    return(new(Vertex, p1->x / p2->x, p1->y / p2->y, p1->z / p2->z));
}

static bool vertex_eq(const Object *one, const Object *two)
{
    vertexClass *p1 = (vertexClass *)one;
    vertexClass *p2 = (vertexClass *)two;

    return((p1->x == p2->x) && (p1->y == p2->y) && (p1->z == p2->z));
}

static bool vertex_gt(const Object *one, const Object *two)
{
    vertexClass *p1 = (vertexClass *)one;
    vertexClass *p2 = (vertexClass *)two;

    return((p1->x + p1->y + p1->z) > (p2->x + p2->y + p2->z));
}

static bool vertex_lt(const Object *one, const Object *two)
{
    vertexClass *p1 = (vertexClass *)one;
    vertexClass *p2 = (vertexClass *)two;

    return((p1->x + p1->y + p1->z) < (p2->x + p2->y + p1->z));
}

static const vertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(vertexClass),
        .__name__ = "vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = (dtor_t)&vertex_dtor,
        .__str__ = (to_string_t)&vertex_str,
        .__add__ = (binary_operator_t)&vertex_add,
        .__sub__ = (binary_operator_t)&vertex_sub,
        .__mul__ = (binary_operator_t)&vertex_mult,
        .__div__ = (binary_operator_t)&vertex_div,
        .__eq__ = (binary_comparator_t)&vertex_eq,
        .__gt__ = (binary_comparator_t)&vertex_gt,
        .__lt__ = (binary_comparator_t)&vertex_lt
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
