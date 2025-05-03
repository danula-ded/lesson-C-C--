#pragma once
#include <array>
#include <string>
#include <vector>

class TicTacToe {
public:
    // Константы для размера поля и символов
    static constexpr int BOARD_SIZE = 3;
    static constexpr char EMPTY = ' ';
    static constexpr char PLAYER_X = 'X';
    static constexpr char PLAYER_O = 'O';

    TicTacToe();
    
    // Основные методы игры
    void play();
    void printBoard() const;
    bool makeMove(int row, int col, char player);
    bool isGameOver() const;
    char getWinner() const;
    
    // Методы для ИИ
    std::pair<int, int> getBestMove() const;
    
private:
    std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> board;
    char currentPlayer;
    bool gameOver;
    
    // Вспомогательные методы
    bool checkWin(int row, int col) const;
    bool isBoardFull() const;
    int evaluateBoard() const;
    int minimax(int depth, bool isMaximizing);
    std::vector<std::pair<int, int>> getEmptyCells() const;
    bool isValidMove(int row, int col) const;
}; 