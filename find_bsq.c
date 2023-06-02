
#include "my.h"

bsq_t *one_col_bsq(bsq_t *b, int rows)
{
    for (int i = 0; i < rows; i++) {
        if (b->map[i][0] == '.') {
            b->map[i][0] = 'x';
            b->bsq = 1;
            b->y = i;
            b->x = 0;
            return b;
        }
    }
}

bsq_t *one_line_bsq(bsq_t *b, int cols)
{
    for (int j = 0; j < cols; j++) {
        if (b->map[0][j] == '.') {
            b->map[0][j] = 'x';
            b->bsq = 1;
            b->y = 0;
            b->x = j;
            return b;
        }
    }
}

int find_min(int **map, int i, int j)
{
    int min = map[i][j - 1];
    if (map[i - 1][j - 1] < min)
        min = map[i - 1][j - 1];
    if (map[i - 1][j] < min)
        min = map[i - 1][j];
    return min;
}

void verify_bsq(int min, bsq_t *b, int i, int j)
{
    if (min > b->bsq) {
        b->bsq = min;
        b->y = i;
        b->x = j;
    }
}

bsq_t *square_finder(int **map, int rows, int cols, bsq_t *b)
{
    int min = 0;
    b->bsq = 1;
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            min = find_min(map, i, j);
            map[i][j] = (map[i][j] == 1 && min != 0) ? ++min : map[i][j];
            verify_bsq(min, b, i, j);
        }
    }
    return b;
}
