#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

extern int solutions;

class Board
{
public:
    Board(int N) : size(N){
        for(int i = 0; i < N; i++){
            board.push_back({});
            for(int j = 0; j < N; j++){
                board.at(i).push_back(0);
            }
        }
    };

    int size { 0 };
    int row { 0 };
    int col { 0 };
    std::vector<std::vector<int>> board;

    void print();
};

void setQueen(Board& B);

void crossOut(Board& B);

bool isFull(Board& B);

void delQueen(Board &B);

void printRes(Board &B);

void findComb(Board &B);