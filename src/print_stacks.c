#include "../includes/push_swap.h"
#include <stdio.h>

#define WIDTH 38

void print_line_separator() {
    printf("-----------------------------------------------------------------------------------\n");
}

void print_stack_line(const char *label_a, const char *value_a, const char *label_b, const char *value_b) {
    printf("| %-*s | %-*s |\n", WIDTH, label_a, WIDTH, label_b);
    printf("| %-*s | %-*s |\n", WIDTH, value_a, WIDTH, value_b);
}

void print_stacks(t_stack_node *stack_a, t_stack_node *stack_b) {
    t_stack_node *a = stack_a;
    t_stack_node *b = stack_b;

    print_line_separator();
    printf("| %-*s | %-*s |\n", WIDTH, "STACK A", WIDTH, "STACK B");
    print_line_separator();

    while (a || b) {
        char buffer_a[100], buffer_b[100];

        if (a) {
            snprintf(buffer_a, sizeof(buffer_a), "Noeud : %p", (void *)a);
            snprintf(buffer_b, sizeof(buffer_b), "Valeur : %d", a->value);
        } else {
            snprintf(buffer_a, sizeof(buffer_a), " ");
            snprintf(buffer_b, sizeof(buffer_b), " ");
        }

        char label_b[100], value_b[100];

        if (b) {
            snprintf(label_b, sizeof(label_b), "Noeud : %p", (void *)b);
            snprintf(value_b, sizeof(value_b), "Valeur : %d", b->value);
        } else {
            snprintf(label_b, sizeof(label_b), " ");
            snprintf(value_b, sizeof(value_b), " ");
        }

        print_stack_line(buffer_a, buffer_b, label_b, value_b);

        if (a) {
            snprintf(buffer_a, sizeof(buffer_a), "Adresse du suivant : %p", (void *)a->next);
            snprintf(buffer_b, sizeof(buffer_b), "Adresse du précédent : %p", (void *)a->prev);
        } else {
            snprintf(buffer_a, sizeof(buffer_a), " ");
            snprintf(buffer_b, sizeof(buffer_b), " ");
        }

        if (b) {
            snprintf(label_b, sizeof(label_b), "Adresse du suivant : %p", (void *)b->next);
            snprintf(value_b, sizeof(value_b), "Adresse du précédent : %p", (void *)b->prev);
        } else {
            snprintf(label_b, sizeof(label_b), " ");
            snprintf(value_b, sizeof(value_b), " ");
        }

        print_stack_line(buffer_a, buffer_b, label_b, value_b);

        print_line_separator();

        if (a) a = a->next;
        if (b) b = b->next;
    }
}
