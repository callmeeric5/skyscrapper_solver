int count_views_row_left(int row, int board[4][4]);
int count_views_row_right(int row, int board[4][4]);
int count_views_col_top(int row, int board[4][4]);
int count_views_col_bottom(int row, int board[4][4]);

int check_views(int board[4][4], int views[16])
{
    int i;
    i = 0;
    while (i < 4)
    {
        if (count_views_col_top(i, board) != views[i])
            return 0;
        if (count_views_col_bottom(i, board) != views[4 + i])
            return 0;
        if (count_views_row_left(i, board) != views[8 + i])
            return 0;
        if (count_views_row_right(i, board) != views[12 + i])
            return 0;
        i++;
    }
    return 1;
}

int check_row(int row, int board[4][4], int views[16])
{
    int i;
    int filled;
    i = 0;
    filled = 1;
    while (i < 4)
    {
        if (board[row][i++] == 0)
            filled = 0;
    }
    if (filled)
    {
        if (count_views_row_left(row, board) != views[8 + row])
            return 0;
        if (count_views_row_right(row, board) != views[12 + row])
            return 0;
    }
    return 1;
}

int check_col(int col, int board[4][4], int views[16])
{
    int i;
    int filled;
    i = 0;
    filled = 1;
    while (i < 4)
    {
        if (board[i++][col] == 0)
            filled = 0;
    }
    if (filled)
    {
        if (count_views_col_top(col, board) != views[col])
            return 0;
        if (count_views_col_bottom(col, board) != views[4 + col])
            return 0;
    }
    return 1;
}

int check_views_partial(int row, int col, int board[4][4], int views[16])
{
    if (!check_row(row, board, views))

        return 0;
    if (!check_col(col, board, views))

        return 0;
    return 1;
}