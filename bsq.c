
#include "my.h"

void print_bsq(bsq_t *b)
{
    int i = (b->y + 1) - b->bsq;
    int j = (b->x + 1) - b->bsq;
    for (; i <= b->y; i++) {
        for (int k = j; k <= b->x; k++) {
            b->map[i][k] = 'x';
        }
    }
}

void big_sq(bsq_t *b, char *buff)
{
    int **map = init_tab(buff, b);
    if (b->nb_char == b->nb_o) {
        display(b->map);
        return;
    }
    if (b->lines == 1)
        b = one_line_bsq(b, b->cols);
    else if (b->cols == 1)
        b = one_col_bsq(b, b->lines);
    else {
        b = square_finder(map, b->lines, b->cols, b);
        print_bsq(b);
    }
    display(b->map);
    free_map(map);
    free_tab(b->map);
}

int bsq(char **av)
{
    bsq_t *b = (bsq_t *)malloc(sizeof(bsq_t));
    char *buff = read_map(av[1]); int i = 0;
    if (buff == NULL) return 84;
    for (; buff[i] != '\n'; i++);
    for (; buff[i] != '\0'; i++) {
        if (buff[i] != '.' && buff[i] != 'o' && buff[i] != '\n')
            return 84;
    }
    big_sq(b, buff);
    free(b);
}

int main(int ac, char **av)
{
    if (ac == 1) return 84;
    if (ac == 2) {
        int i = bsq(av);
        if (i == 84) return 84;
    }
}
