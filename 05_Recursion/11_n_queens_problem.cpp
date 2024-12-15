/**
 * @file 11_n_queens_problem.cpp
 * @author Nirmalya Dhara
 * @brief find all possible solutions to the N-Queens problem using recursion. N-Queens problem is a classic problem of placing N queens on an N x N chessboard so that no two queens attack each other.
 * @date 2024-12-15
 */
#include <iostream>
#include <vector>

/**
 * @brief Checks if a queen can be placed on the board at the given position.
 *
 * This function checks if placing a queen at the specified row and column
 * on the board is valid. It ensures that there are no other queens in the
 * same row, upper diagonal, or lower diagonal.
 *
 * @param board A reference to the chessboard represented as a vector of strings.
 * @param row The row index where the queen is to be placed.
 * @param col The column index where the queen is to be placed.
 * @param n The size of the chessboard (n x n).
 * @return true If the position is valid for placing a queen.
 * @return false If the position is not valid for placing a queen.
 */
bool validPosition(std::vector<std::string> &board, int row, int col, int n)
{
    //* Check if there is a queen in the same row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    //* Check if there is a queen in the upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    //* Check if there is a queen in the lower diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

/**
 * @brief Helper function to solve N-Queens problem using backtracking
 *
 * This recursive function attempts to place queens column by column, exploring all possible
 * valid positions in each column. It uses backtracking to undo invalid placements and
 * continue searching for solutions.
 *
 * @param board Current state of the chess board represented as strings
 * @param col Current column being processed
 * @param result Vector to store all valid solutions found
 * @param n Size of the chess board (n x n)
 *
 * Time Complexity: O(N!)
 * Space Complexity: O(N^2) for the board
 */
void solveNQueensUtil(std::vector<std::string> &board, int col, std::vector<std::vector<std::string>> &result, int n)
{
    if (col == n)
    {
        result.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (validPosition(board, row, col, n))
        {
            board[row][col] = 'Q';
            solveNQueensUtil(board, col + 1, result, n);
            board[row][col] = '.';
        }
    }
}

/**
 * @brief Utility function to solve N-Queens problem using optimized backtracking approach
 *
 * This function uses three arrays to track queen placements: one for columns, and two for diagonals.
 * It places queens column by column and checks if a position is safe using O(1) lookups.
 *
 * @param result Vector storing all valid board configurations found
 * @param board Current board configuration being built
 * @param colPlacements Array tracking which rows already have queens
 * @param lowerDiagonal Array tracking occupied lower diagonals (row + col)
 * @param upperDiagonal Array tracking occupied upper diagonals (n-1 + col - row)
 * @param col Current column being processed
 * @param n Size of the chess board (n x n)
 *
 * Time Complexity: O(N!)
 * Space Complexity: O(N) for recursion stack
 */
void solveNQueenUtilOptimal(std::vector<std::vector<std::string>> &result, std::vector<std::string> &board, std::vector<int> &colPlacements, std::vector<int> &lowerDiagonal, std::vector<int> &upperDiagonal, int col, int n)
{
    if (col == n)
    {
        result.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (colPlacements[row] || lowerDiagonal[row + col] || upperDiagonal[n - 1 + col - row])
            continue;
        colPlacements[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + col - row] = 1;
        board[row][col] = 'Q';
        solveNQueenUtilOptimal(result, board, colPlacements, lowerDiagonal, upperDiagonal, col + 1, n);
        board[row][col] = '.';
        colPlacements[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + col - row] = 0;
    }
}

/**
 * @brief Solves the N-Queens puzzle.
 *
 * The N-Queens puzzle is the problem of placing N chess queens on an N×N chessboard
 * such that no two queens threaten each other. Two queens threaten each other if they
 * share the same row, column, or diagonal.
 *
 * @param n The size of the chessboard and number of queens to place
 * @return std::vector<std::vector<std::string>> A vector containing all possible solutions.
 *         Each solution is represented as a vector of strings where:
 *         - Each string represents a row of the chessboard
 *         - 'Q' indicates a queen's position
 *         - '.' indicates an empty square
 *
 * @example
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 */
std::vector<std::vector<std::string>> solveNQueens(int n)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> board(n, std::string(n, '.'));

    // solveNQueensUtil(board, 0, result, n);
    //! OR
    std::vector<int> colPlacements(n, 0);
    std::vector<int> lowerDiagonal(2 * n - 1, 0);
    std::vector<int> upperDiagonal(2 * n - 1, 0);
    solveNQueenUtilOptimal(result, board, colPlacements, lowerDiagonal, upperDiagonal, 0, n);

    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cout << "Enter the value of N: ";
    std::cin >> n;

    std::vector<std::vector<std::string>> board = solveNQueens(n);
    for (auto row : board)
    {
        // std::cout << std::endl;
        for (auto cell : row)
            std::cout << cell << std::endl;
        std::cout << std::endl;
    }

    return 0;
}