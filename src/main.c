/*
** EPITECH PROJECT, 2025
** MyRadar
** File description:
** main.c
*/

#include "../include/my.h"

//remplacer avec le fetch
sfCircleShape *generate_circle()
{

}

bool is_in_rect(sfIntRect rect, sfVector2f pos)
{
    if (pos.x > rect.left
        && pos.x < rect.left + rect.width
        && pos.y > rect.top
        && pos.y < rect.top + rect.height)
        return true;
    return false;
}

void add_circle_node(node_t **nd, sfCircleShape *circle)
{
    node_t *new = malloc(sizeof(node_t));
    node_t *last = nd;
    new->circle = circle;
    new->next = NULL;

    if (*nd == NULL) {
        *nd = circle;
        return;
    }
    for (node_t *it = *nd; it != NULL; it = it->next) {
        if (it->next == NULL)
            last = it;
    }
    new->next = circle;
}

void filling_corner(corner_t *c1, corner_t *c2, corner_t *c3, corner_t *c4)
{
    sfCircleShape *newshape = generate_circle();
    sfVector2f pos = sfCircleShape_getOrigin(newshape);

    if (is_in_rect(c1->area, pos)) {
        sfCircleShape_setFillColor(newshape, sfWhite);
        add_circle_node(&c1->head, newshape);
    } else if (is_in_rect(c2->area, pos)) {
        sfCircleShape_setFillColor(newshape, sfRed);
        add_circle_node(&c2->head, newshape);
    } else if (is_in_rect(c3->area, pos)) {
        sfCircleShape_setFillColor(newshape, sfBlue);
        add_circle_node(&c3->head, newshape);
    } else if (is_in_rect(c4->area, pos)) {
        sfCircleShape_setFillColor(newshape, sfGreen);
        add_circle_node(&c4->head, newshape);
    }
}

corner_t *create_corner(sfVector2i pos)
{
    corner_t *my_corner = malloc(sizeof(corner_t));

    my_corner->area.height = pos.x;
    my_corner->area.left = pos.y;
    my_corner->area.top = 400;
    my_corner->area.width = 300;
    my_corner->nb_circles = 0;
    my_corner->head.next = NULL;
}

sfCircleShape *create_circle(sfColor color)
{
    sfCircleShape *shape;
    float radius = 50.0f;

    shape = sfCircleShape_create();
    sfCircleShape_setRadius(shape, radius);
    sfCircleShape_setFillColor(shape, color);
    return shape;
}

static bool hasColision(sfCircleShape *shape1, sfCircleShape *shape2)
{
    sfVector2f c = sfCircleShape_getPosition(shape1);
    float cr = sfCircleShape_getRadius(shape1);
    sfVector2f d = sfCircleShape_getPosition(shape2);
    float dr = sfCircleShape_getRadius(shape2);

    if ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y) <= (cr + dr) * (cr + dr))
        return true;
    return false;
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfEvent event;
    sfCircleShape *circle1 = create_circle(sfRed);
    sfCircleShape *circle2 = create_circle(sfBlue);
    sfVector2f cpos1 = {0, 0};
    sfVector2f cpos2 = {40, 0};
    corner_t *c1 = create_corner((sfVector2i){0, 0});
    corner_t *c2 = create_corner((sfVector2i){0, 400});
    corner_t *c3 = create_corner((sfVector2i){300, 0});
    corner_t *c4 = create_corner((sfVector2i){300, 400});
    filling_corner(c1, c2, c3, c4);
    sfCircleShape_setPosition(circle1, cpos1);
    sfCircleShape_setPosition(circle2, cpos2);

    window = sfRenderWindow_create(mode, "SFML window",
        sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawCircleShape(window, circle1, NULL);
        sfRenderWindow_drawCircleShape(window, circle2, NULL);
        // if (hasColision(circle1, circle2))
        //     printf("oui\n");
        sfRenderWindow_display(window);
    }
    sfCircleShape_destroy(circle1);
    sfCircleShape_destroy(circle2);
    sfRenderWindow_destroy(window);
    return 0;
}
