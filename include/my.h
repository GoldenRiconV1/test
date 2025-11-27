/*
** EPITECH PROJECT, 2025
** myls
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #define TOTAL_CERCLE 10

typedef struct node_s {
    sfCircleShape *circle;
    struct node_s *next;
} node_t;

typedef struct corner_s
{
    sfIntRect area;
    unsigned int nb_circles;
    sfCircleShape **circle;
    node_t head;
} corner_t;
#endif
