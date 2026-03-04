#include "framework.hpp"

int solutions = 0;

void Board::print()
{
    for (auto it : board)
    {
        for (auto jt : it)
        {
            printf("%i    ", jt);
        }
        printf("\n");
    }
    printf("-----------------------------------\n");
}

void setQueen(Board &B)
{
    B.col = 0;
    int q = 0;
    for (int k = B.col; k < B.size; k++)
    {
        if (B.board[B.row][k] == 0)
        {
            B.board[B.row][k] = -1;
            break;
        }
        B.col++;
    }
}

void crossOut(Board &B)
{

    for (size_t k = 0; k < B.size; k++)
    {
        if (k != B.col && B.board[B.row][k] == 0)
            B.board[B.row][k] = B.row + 2;
    }

    for (size_t k = B.row + 1; k < B.size; k++)
    {
        if (B.board[k][B.col] == 0)
            B.board[k][B.col] = B.row + 2;
    }

    auto down = B.size - B.row - 1;
    auto it = std::min(B.col, down);
    for (int k = 0; k < it; k++)
    {
        if (B.board[B.row + 1 + k][B.col - 1 - k] == 0)
            B.board[B.row + 1 + k][B.col - 1 - k] = B.row + 2;
    }

    it = std::min(B.size - B.col - 1, down);
    for (int k = 0; k < it; k++)
    {
        if (B.board[B.row + 1 + k][B.col + 1 + k] == 0)
            B.board[B.row + 1 + k][B.col + 1 + k] = B.row + 2;
    }
}


bool isFull(Board &B)
{
    bool f = true;

    if(B.row + 1 == B.size){
        return f;
    } 

    for (size_t k = 0; k < B.size; k++)
    {
        if (B.board[B.row + 1][k] == 0)
        {
            f = false;
            break;
        }
    }
    return f;
}

void delQueen(Board &B){
    
    for(size_t i = 0; i < B.size; i++){
        if(B.board[B.row][i] == -1){
            B.board[B.row][i] = B.row + 1;
        } 
    }

    for(size_t i = 0; i < B.size; i++){
        for(size_t j = B.row; j < B.size; j++){
            if(B.board[j][i]==B.row + 2){
                B.board[j][i] = 0;
            }
        }
    }
}

void printRes(Board &B){
    for (auto it : B.board)
    {
        for (auto jt : it)
        {
            if(jt != -1){
                printf("%i    ", 0);
            }
            else{
                printf("%i    ", 1);
            }
        }
        printf("\n");
    }
    printf("--------------------------------------------------------------------------------------------------------------\n");
}

void findComb(Board &B){
    size_t count { 0 };
    for(size_t i = 0; i < B.size; i++){
        if(B.board[B.row][i] == 0)count++;
    }
    for(size_t j = 0; j < count; j++){
        if(isFull(B)){
            delQueen(B);
        }
        setQueen(B);
        crossOut(B);
        if(B.row + 1 == B.size){
            //printRes(B);
            solutions++;
        }
        if(isFull(B)){
            delQueen(B);
        }else{
            B.row++;
            findComb(B);
        }
    }
    delQueen(B);
    B.row--;
}