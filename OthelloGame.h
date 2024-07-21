#include<bits/stdc++.h>
using namespace std;
class OthelloGame {
public:
    char grid[8][8];
    bool humanPlayer;
    int humanPlayerPieceCount;
    bool computerPlayer;
    int computerPlayerPieceCount;
    int whitePiecesOnBoard;
    int blackPiecesOnBoard;
    int difficulty;
    OthelloGame(){
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                grid[i][j]='-';
            }
        }
        grid[3][3]='W';
        grid[3][4]='B';
        grid[4][3]='B';
        grid[4][4]='W';
        humanPlayer=true;
        computerPlayer=false;
        humanPlayerPieceCount=30;
        computerPlayerPieceCount=30;
        whitePiecesOnBoard=2;
        blackPiecesOnBoard=2;
    }
    void display(){
        addValidMovesToTheBoard();
        for (int i=0; i<8; i++){
            cout<<i+1<<" ";
            for (int j=0; j<8; j++){
                cout<<grid[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    bool isThereAValidMove(){
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                if (grid[i][j]=='*'){
                    return true;
                }
            }
        }
        return false;
    }
    void switchTurns(){
        if (humanPlayer){
            humanPlayer=false;
            computerPlayer=true;
        }
        else{
            humanPlayer=true;
            computerPlayer=false;
        }
    }
    void addValidMovesToTheBoard(){
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                if (grid[i][j]=='*'){
                    grid[i][j]='-';
                }
            }
        }
        if (humanPlayer) {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (grid[i][j] == 'B') {
                        //check the column from below the piece
                        bool foundWhite=false;
                        for (int k=i+1; k<8; k++){
                            if (grid[k][j]=='B'){
                                break;
                            }
                            else if (grid[k][j]=='W'){
                                foundWhite=true;
                            }
                            else{
                                if (foundWhite){
                                    grid[k][j]='*';
                                    break;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                        //check the column from above the piece
                        foundWhite=false;
                        for (int k=i-1; k>=0; k--){
                            if (grid[k][j]=='B'){
                                break;
                            }
                            else if (grid[k][j]=='W'){
                                foundWhite=true;
                            }
                            else{
                                if (foundWhite){
                                    grid[k][j]='*';
                                    break;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                        //check the row from the right of the piece
                        foundWhite=false;
                        for (int c=j+1; c<8; c++){
                            if (grid[i][c]=='B'){
                                break;
                            }
                            else if (grid[i][c]=='W'){
                                foundWhite=true;
                            }
                            else{
                                if (foundWhite){
                                    grid[i][c]='*';
                                    break;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                        //check the row from the left of the piece
                        foundWhite=false;
                        for (int c=j-1; c>=0; c--){
                            if (grid[i][c]=='B'){
                                break;
                            }
                            else if (grid[i][c]=='W'){
                                foundWhite=true;
                            }
                            else{
                                if (foundWhite){
                                    grid[i][c]='*';
                                    break;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        else{
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (grid[i][j] == 'W') {
                        //check the row from below the piece
                        bool foundBlack=false;
                        for (int k=i+1; k<8; k++){
                            if (grid[k][j]=='W'){
                                break;
                            }
                            else if (grid[k][j]=='B'){
                                foundBlack=true;
                            }
                            else{
                                if (foundBlack){
                                    grid[k][j]='*';
                                    break;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                        //check the row from above the piece
                        foundBlack=false;
                        for (int k=i-1; k>=0; k--){
                            if (grid[k][j]=='W'){
                                break;
                            }
                            else if (grid[k][j]=='B'){
                                foundBlack=true;
                            }
                            else{
                                if (foundBlack){
                                    grid[k][j]='*';
                                    break;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                        //check the column from the right of the piece
                        foundBlack=false;
                        for (int c=j+1; c<8; c++){
                            if (grid[i][c]=='W'){
                                break;
                            }
                            else if (grid[i][c]=='B'){
                                foundBlack=true;
                            }
                            else{
                                if (foundBlack){
                                    grid[i][c]='*';
                                    break;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                        //check the column from the left of the piece
                        foundBlack=false;
                        for (int c=j-1; c>=0; c--){
                            if (grid[i][c]=='W'){
                                break;
                            }
                            else if (grid[i][c]=='B'){
                                foundBlack=true;
                            }
                            else{
                                if (foundBlack){
                                    grid[i][c]='*';
                                    break;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    bool humanPlay(int row, int column){
        if (humanPlayerPieceCount>0) {
            if (grid[row - 1][column - 1] == '*') {
                //check for white pieces above
                bool foundWhite=false;
                for (int i=row-2; i>=0; i--){
                    if (grid[i][column-1]=='W'){
                        foundWhite=true;
                    }
                    else if (grid[i][column-1]=='B' and foundWhite){
                        for (int j = row - 1; j > i; j--) {
                            grid[j][column - 1] = 'B';
                            blackPiecesOnBoard++;
                            whitePiecesOnBoard--;
                        }
                        whitePiecesOnBoard++;
                        break;
                    }
                    else{
                        break;
                    }
                }
                //check for white pieces below
                foundWhite=false;
                for (int i=row; i<8; i++){
                    if (grid[i][column-1]=='W'){
                        foundWhite=true;
                    }
                    else if (grid[i][column-1]=='B' and foundWhite){
                        for (int j = row - 1; j < i; j++) {
                            grid[j][column - 1] = 'B';
                            blackPiecesOnBoard++;
                            whitePiecesOnBoard--;
                        }
                        whitePiecesOnBoard++;
                        break;
                    }
                    else{
                        break;
                    }
                }
                //check for white pieces on the right of the piece
                foundWhite=false;
                for (int i=column; i<8; i++){
                    if (grid[row-1][i]=='W'){
                        foundWhite=true;
                    }
                    else if (grid[row-1][i]=='B' and foundWhite){
                        for (int j = column - 1; j < i; j++) {
                            grid[row - 1][j] = 'B';
                            blackPiecesOnBoard++;
                            whitePiecesOnBoard--;
                        }
                        whitePiecesOnBoard++;
                        break;
                    }
                    else{
                        break;
                    }
                }
                //check for white pieces on the left of the piece
                foundWhite=false;
                for (int i=column-2; i>=0; i--){
                    if (grid[row-1][i]=='W'){
                        foundWhite=true;
                    }
                    else if (grid[row-1][i]=='B' and foundWhite){
                        for (int j = column - 1; j > i; j--) {
                            grid[row - 1][j] = 'B';
                            blackPiecesOnBoard++;
                            whitePiecesOnBoard--;
                        }
                        whitePiecesOnBoard++;
                        break;
                    }
                    else{
                        break;
                    }
                }
                humanPlayerPieceCount--;
            }
            else {
                cout << "invalid move" << endl;
                return false;
            }
        }
        else{
            if (computerPlayerPieceCount==0){
                if (blackPiecesOnBoard>whitePiecesOnBoard){
                    cout<<"human won"<<endl;
                }
                else if (blackPiecesOnBoard<whitePiecesOnBoard){
                    cout<<"computer won"<<endl;
                }
                else{
                    cout<<"the game is a draw"<<endl;
                }
                return true;
            }
            else{
                switchTurns();
                return false;
            }
        }
        switchTurns();
        return false;
    }
    int calcScore(int row, int column){
        //check for black pieces above
        bool foundBlack=false;
        for (int i=row-1; i>=0; i--){
            if (grid[i][column]=='B'){
                foundBlack=true;
            }
            else if (grid[i][column]=='W' and foundBlack){
                return row-i-1;
            }
        }
        //check for black pieces bellow
        foundBlack=false;
        for (int i=row+1; i<8; i++){
            if (grid[i][column]=='B'){
                foundBlack=true;
            }
            else if (grid[i][column]=='W' and foundBlack){
                return i-row-1;
            }
        }
        //check for white pieces on the right of the piece
        foundBlack=false;
        for (int i=column+1; i<8; i++){
            if (grid[row][i]=='W'){
                foundBlack=true;
            }
            else if (grid[row][i]=='B' and foundBlack){
                return i-column-1;
            }
        }
        //check for white pieces on the left of the piece
        foundBlack=false;
        for (int i=column-1; i>=0; i--){
            if (grid[row][i]=='W'){
                foundBlack=true;
            }
            else if (grid[row][i]=='B' and foundBlack){
                return column-i-1;
            }
        }
        return 0;
    }
    pair<int,int> find_A_Valid_Move_Level1(){
        int lowestScore=INT_MAX;
        int rowOfLowestScore=0;
        int columnOfLowestScore=0;
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                if (grid[i][j]=='*'){
                    int score=calcScore(i,j);
                    if (score<lowestScore){
                        lowestScore=score;
                        rowOfLowestScore=i;
                        columnOfLowestScore=j;
                    }
                }
            }
        }
        return make_pair(rowOfLowestScore,columnOfLowestScore);
    }
    pair<int,int> find_A_Valid_Move_Level3(){
        vector<pair<int,pair<int,int>>>scores;
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                if (grid[i][j]=='*'){
                    int score=calcScore(i,j);
                    scores.emplace_back(score, make_pair(i,j));
                }
            }
        }
        // Define a lambda function to compare pairs based on the first int
        auto compare = [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first < b.first;
        };
        // Sort the vector based on the first int in each pair
        sort(scores.begin(), scores.end(), compare);
        return make_pair(scores[scores.size()/2].second.first,scores[scores.size()/2].second.second);
    }
    pair<int,int> find_A_Valid_Move_Level5(){
        int highestScore=INT_MIN;
        int rowOfHighestScore=0;
        int columnOfHighestScore=0;
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                if (grid[i][j]=='*'){
                    int score=calcScore(i,j);
                    if (score>highestScore){
                        highestScore=score;
                        rowOfHighestScore=i;
                        columnOfHighestScore=j;
                    }
                }
            }
        }
        return make_pair(rowOfHighestScore,columnOfHighestScore);
    }
    bool computerPlay(){
        if (computerPlayerPieceCount>0){
            pair<int,int>move;
            if (difficulty==1){
                move=find_A_Valid_Move_Level1();
            }
            else if (difficulty==3){
                move=find_A_Valid_Move_Level3();
            }
            else{
                move=find_A_Valid_Move_Level5();
            }
            int row=move.first;
            int column=move.second;
            //check for black pieces above
            bool foundBlack=false;
            for (int i=row-1; i>=0; i--){
                if (grid[i][column]=='B'){
                    foundBlack=true;
                }
                else if (grid[i][column]=='W' and foundBlack){
                    for (int j = row ; j > i; j--) {
                        grid[j][column] = 'W';
                        whitePiecesOnBoard++;
                        blackPiecesOnBoard--;
                    }
                    blackPiecesOnBoard++;
                    break;
                }
            }
            //check for black pieces bellow
            foundBlack=false;
            for (int i=row+1; i<8; i++){
                if (grid[i][column]=='B'){
                    foundBlack=true;
                }
                else if (grid[i][column]=='W' and foundBlack){
                    for (int j = row ; j < i; j++) {
                        grid[j][column] = 'W';
                        whitePiecesOnBoard++;
                        blackPiecesOnBoard--;
                    }
                    blackPiecesOnBoard++;
                    break;
                }
            }
            //check for black pieces on the right of the piece
            foundBlack=false;
            for (int i=column+1; i<8; i++){
                if (grid[row][i]=='B'){
                    foundBlack=true;
                }
                else if (grid[row][i]=='W' and foundBlack){
                    for (int j = column; j < i; j++) {
                        grid[row ][j] = 'W';
                        whitePiecesOnBoard++;
                        blackPiecesOnBoard--;
                    }
                    blackPiecesOnBoard++;
                    break;
                }
            }
            //check for black pieces on the left of the piece
            foundBlack=false;
            for (int i=column-1; i>=0; i--){
                if (grid[row][i]=='B'){
                    foundBlack=true;
                }
                else if (grid[row][i]=='W' and foundBlack){
                    for (int j = column; j > i; j--) {
                        grid[row ][j] = 'W';
                        whitePiecesOnBoard++;
                        blackPiecesOnBoard--;
                    }
                    blackPiecesOnBoard++;
                    break;
                }
            }
            computerPlayerPieceCount--;
        }
        else{
            if (humanPlayerPieceCount==0){
                if (blackPiecesOnBoard>whitePiecesOnBoard){
                    cout<<"human won"<<endl;
                    return true;
                }
                else if (blackPiecesOnBoard<whitePiecesOnBoard){
                    cout<<"computer won"<<endl;
                    return true;
                }
                else{
                    cout<<"the game is a draw"<<endl;
                    return true;
                }
            }
            else{
                switchTurns();
                return false;
            }
        }
        switchTurns();
        return false;
    }
};