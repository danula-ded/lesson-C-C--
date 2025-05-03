#include "game.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <random>
#include <chrono>

TicTacToe::TicTacToe() : currentPlayer(PLAYER_X), gameOver(false) {
    // Инициализация пустого поля
    for (auto& row : board) {
        row.fill(EMPTY);
    }
}

void TicTacToe::play() {
    std::cout << "Добро пожаловать в игру Крестики-нолики!\n";
    std::cout << "Вы играете за X, компьютер за O\n\n";
    
    while (!gameOver) {
        printBoard();
        
        if (currentPlayer == PLAYER_X) {
            // Ход игрока
            int row, col;
            do {
                std::cout << "Ваш ход (строка [1-3] и столбец [1-3]): ";
                std::cin >> row >> col;
                row--; col--; // Преобразование в индексы
            } while (!isValidMove(row, col));
            
            makeMove(row, col, PLAYER_X);
        } else {
            // Ход компьютера
            std::cout << "Ход компьютера...\n";
            auto [row, col] = getBestMove();
            makeMove(row, col, PLAYER_O);
        }
        
        // Проверка окончания игры
        if (checkWin(row, col) || isBoardFull()) {
            gameOver = true;
            printBoard();
            
            char winner = getWinner();
            if (winner == PLAYER_X) {
                std::cout << "Поздравляем! Вы победили!\n";
            } else if (winner == PLAYER_O) {
                std::cout << "Компьютер победил!\n";
            } else {
                std::cout << "Ничья!\n";
            }
        }
        
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
}

void TicTacToe::printBoard() const {
    std::cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        std::cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < BOARD_SIZE - 1) {
            std::cout << "---+---+---\n";
        }
    }
    std::cout << "\n";
}

bool TicTacToe::makeMove(int row, int col, char player) {
    if (!isValidMove(row, col)) {
        return false;
    }
    
    board[row][col] = player;
    return true;
}

bool TicTacToe::isGameOver() const {
    return gameOver;
}

char TicTacToe::getWinner() const {
    // Проверка по горизонтали
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    
    // Проверка по вертикали
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    
    // Проверка диагоналей
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    return EMPTY;
}

bool TicTacToe::checkWin(int row, int col) const {
    char player = board[row][col];
    
    // Проверка строки
    bool rowWin = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] != player) {
            rowWin = false;
            break;
        }
    }
    if (rowWin) return true;
    
    // Проверка столбца
    bool colWin = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] != player) {
            colWin = false;
            break;
        }
    }
    if (colWin) return true;
    
    // Проверка диагоналей
    if (row == col) {
        bool diagWin = true;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][i] != player) {
                diagWin = false;
                break;
            }
        }
        if (diagWin) return true;
    }
    
    if (row + col == BOARD_SIZE - 1) {
        bool diagWin = true;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][BOARD_SIZE - 1 - i] != player) {
                diagWin = false;
                break;
            }
        }
        if (diagWin) return true;
    }
    
    return false;
}

bool TicTacToe::isBoardFull() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

std::pair<int, int> TicTacToe::getBestMove() const {
    int bestScore = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove;
    
    // Если это первый ход, выбираем случайную клетку
    if (isBoardFull()) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, BOARD_SIZE - 1);
        return {dis(gen), dis(gen)};
    }
    
    for (const auto& [row, col] : getEmptyCells()) {
        board[row][col] = PLAYER_O;
        int score = minimax(0, false);
        board[row][col] = EMPTY;
        
        if (score > bestScore) {
            bestScore = score;
            bestMove = {row, col};
        }
    }
    
    return bestMove;
}

int TicTacToe::evaluateBoard() const {
    char winner = getWinner();
    if (winner == PLAYER_O) return 10;
    if (winner == PLAYER_X) return -10;
    return 0;
}

int TicTacToe::minimax(int depth, bool isMaximizing) {
    int score = evaluateBoard();
    
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (isBoardFull()) return 0;
    
    if (isMaximizing) {
        int bestScore = std::numeric_limits<int>::min();
        for (const auto& [row, col] : getEmptyCells()) {
            board[row][col] = PLAYER_O;
            bestScore = std::max(bestScore, minimax(depth + 1, false));
            board[row][col] = EMPTY;
        }
        return bestScore;
    } else {
        int bestScore = std::numeric_limits<int>::max();
        for (const auto& [row, col] : getEmptyCells()) {
            board[row][col] = PLAYER_X;
            bestScore = std::min(bestScore, minimax(depth + 1, true));
            board[row][col] = EMPTY;
        }
        return bestScore;
    }
}

std::vector<std::pair<int, int>> TicTacToe::getEmptyCells() const {
    std::vector<std::pair<int, int>> emptyCells;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                emptyCells.emplace_back(i, j);
            }
        }
    }
    return emptyCells;
}

bool TicTacToe::isValidMove(int row, int col) const {
    return row >= 0 && row < BOARD_SIZE && 
           col >= 0 && col < BOARD_SIZE && 
           board[row][col] == EMPTY;
} 