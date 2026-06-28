class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        # Fill sets with existing numbers
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    rows[i].add(board[i][j])
                    cols[j].add(board[i][j])
                    boxes[(i // 3) * 3 + j // 3].add(board[i][j])

        def backtrack():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == ".":
                        box = (i // 3) * 3 + j // 3

                        for num in "123456789":
                            if (num not in rows[i] and
                                num not in cols[j] and
                                num not in boxes[box]):

                                board[i][j] = num
                                rows[i].add(num)
                                cols[j].add(num)
                                boxes[box].add(num)

                                if backtrack():
                                    return True

                                board[i][j] = "."
                                rows[i].remove(num)
                                cols[j].remove(num)
                                boxes[box].remove(num)

                        return False

            return True

        backtrack()