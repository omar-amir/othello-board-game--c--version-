#include "OthelloGame.h"
using namespace std;
int main(){
    OthelloGame obj;
    cout << "Choose Difficulty, Easy 1, Medium 3, Hard 5: ";
    int difficulty;
    cin >> difficulty;
    obj.difficulty = difficulty;
    while (true) {
        if (obj.humanPlayer) {
            obj.display();
            if (obj.isThereAValidMove()) {
                cout<<"Black's score: "<<obj.blackPiecesOnBoard<<endl;
                cout<<"White's score: "<<obj.whitePiecesOnBoard<<endl;
                cout<<"Black pieces left: "<<obj.humanPlayerPieceCount<<endl;
                cout<<"White pieces left: "<<obj.computerPlayerPieceCount<<endl;
                cout << "black's turn" << endl;
                cout << "Enter the row and column of the place where you want to play: ";
                int row, column;
                cin >> row >> column;
                bool check = obj.humanPlay(row, column);
                if (check) {
                    cout << "Game Ended" << endl;
                    break;
                }
            }
            else{
                cout<<"no moves for black"<<endl;
                obj.switchTurns();
                obj.display();
                if (!obj.isThereAValidMove()){
                    if (obj.blackPiecesOnBoard>obj.whitePiecesOnBoard){
                        cout<<"human player won"<<endl;
                    }
                    else if (obj.blackPiecesOnBoard<obj.whitePiecesOnBoard){
                        cout<<"computer Player won"<<endl;
                    }
                    else{
                        cout<<"The Game Is A Draw"<<endl;
                    }
                    break;
                }
                cout<<"Black's score: "<<obj.blackPiecesOnBoard<<endl;
                cout<<"White's score: "<<obj.whitePiecesOnBoard<<endl;
                cout<<"Black pieces left: "<<obj.humanPlayerPieceCount<<endl;
                cout<<"White pieces left: "<<obj.computerPlayerPieceCount<<endl;
                cout << "white's turn" << endl;
                bool check=obj.computerPlay();
                if (check){
                    cout<<"Game Ended"<<endl;
                    break;
                }
            }
        }
        else {
            obj.display();
            if (obj.isThereAValidMove()) {
                cout<<"Black's score: "<<obj.blackPiecesOnBoard<<endl;
                cout<<"White's score: "<<obj.whitePiecesOnBoard<<endl;
                cout<<"Black pieces left: "<<obj.humanPlayerPieceCount<<endl;
                cout<<"White pieces left: "<<obj.computerPlayerPieceCount<<endl;
                cout << "white's turn" << endl;
                bool check=obj.computerPlay();
                if (check){
                    cout<<"Game Ended"<<endl;
                    break;
                }
            }
            else{
                cout<<"no moves for white"<<endl;
                obj.switchTurns();
                obj.display();
                if (!obj.isThereAValidMove()){
                    if (obj.blackPiecesOnBoard>obj.whitePiecesOnBoard){
                        cout<<"human player won"<<endl;
                    }
                    else if (obj.blackPiecesOnBoard<obj.whitePiecesOnBoard){
                        cout<<"computer Player won"<<endl;
                    }
                    else{
                        cout<<"The Game Is A Draw"<<endl;
                    }
                    break;
                }
                cout<<"Black's score: "<<obj.blackPiecesOnBoard<<endl;
                cout<<"White's score: "<<obj.whitePiecesOnBoard<<endl;
                cout<<"black's turn"<<endl;
                cout << "Enter the row and column of the place where you want to play: ";
                int row, column;
                cin >> row >> column;
                bool check = obj.humanPlay(row, column);
                if (check) {
                    cout << "Game Ended" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
