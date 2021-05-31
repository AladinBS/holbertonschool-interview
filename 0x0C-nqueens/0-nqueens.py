#!/usr/bin/python3
import sys
"""nqueenss"""


def ins(n):
    board = []
    for i in range(n):
        row = []
        for j in range(n):
            row.append(0)
        board.append(row)
    return(board)


def dsplybrd(board, n):
    a = []
    for i in range(n):
        b = []
        for j in range(n):
            if board[i][j] == 1:
                b.append(i)
                b.append(j)
                a.append(b)
    print(a)


def safe(board, row, col, n):
    for i in range(col):
        if board[row][i] == 1:
            return False

    i = row
    j = col
    while i >= 0 and j >= 0:
        if (board[i][j]):
            return False
        i -= 1
        j -= 1

    i = row
    j = col
    while j >= 0 and i < n:
        if (board[i][j]):
            return False
        i = i + 1
        j = j - 1

    return True


def nqb(board, col, n):
    if (col == n):
        dsplybrd(board, n)
        return True

    res = False
    for i in range(n):
        if (safe(board, i, col, n)):
            board[i][col] = 1

            res = nqb(board, col + 1, n) or res

            board[i][col] = 0

    return res


def nq(board, n):
    if (nqb(board, 0, n) is False):
        print("Solution does not exist")
        exit(1)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        if not type(int(sys.argv[1])) is int:
            print("N must be a number")
            exit(1)
    except:
        print("N must be a number")
        exit(1)

    n = int(sys.argv[1])

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = ins(n)

    nq(board, n)
