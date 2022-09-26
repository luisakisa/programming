from random import shuffle
from copy import deepcopy
 
def make_assumptions(sudoku):
    for i, row in enumerate(sudoku):
        for j, value in enumerate(row):
            if not value:
                values = set(row) \
                    | set([sudoku[k][j] for k in range(4)]) \
                    | set([sudoku[m][n] for m in range((i // 2) * 2, (i // 2) * 2 + 2) 
                           for n in range((j // 2) * 2, (j // 2) * 2 + 2)])
                yield i, j, list(set(range(1, 5)) - values)
                
                
def solve_sudoku(sudoku):
    if all([k for row in sudoku for k in row]):
        return sudoku
    assumptions = list(make_assumptions(sudoku))
    shuffle(assumptions)
    x, y, values = min(assumptions, key=lambda x: len(x[2]))
 
    for v in values:
        new_sudoku = deepcopy(sudoku)
        new_sudoku[x][y] = v
        s = solve_sudoku(new_sudoku)
        if s:
            return s
    return None
 
sudoku = [[int(n) for n in input().split()[0]] for _ in range(4)]
for string in solve_sudoku(sudoku):
    print("".join(map(str, string)))