/*
** EPITECH PROJECT, 2023
** new.c
** File description:
** new
*/

#include "new.h"

void *new(const Class *class, ...)
{
    void *obj;
    va_list args;

    va_start(args, class); //initia liste args variables pour valist
    obj = calloc(1, class->__size__); // Alloue memoire 1 objet et set 0
    memcpy(obj, class, class->__size__); // cp donnes dans obj
    if (class->__ctor__) // si deja construct
        class->__ctor__(obj, &args); // construct  obj + variables
    va_end(args); // fin de la liste
    return (obj);
}

void *va_new(const Class *class, va_list *ap)
{
    void *p;

    if (!class || !class->__size__) // class valide ou pas
        raise("CLASS NOT VALID"); // class pas valide
    p = calloc(1, class->__size__); // alloue  mem p en utilisant calloc
    memcpy(p, class, class->__size__); // copie les données de class dans p
    if (class->__ctor__) // si constructeur
        class->__ctor__(p, ap); //constructeur de p
    return (p);
}


void delete(Object *ptr)
{
    const Class *class = ptr; // classe const = ptr objet

    if (ptr && class->__dtor__) // si ptr obj ok et destructeur
        class->__dtor__(ptr); // destructeur ptr
    free(ptr);
}
