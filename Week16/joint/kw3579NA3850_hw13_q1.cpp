//Group Project: Nik Aberle and Kristine Wetch
//Doodlebug Program
//04/15/2024

#include <iostream>
#include <vector>
using namespace std;

// Define the Organism class - need to create virtual functions and static values, only display function created
class Organism {
public:

    void display() const {
        cout << "O"; // Placeholder representation of an Organism
    }

};

//need Doodlebug class derived from organism

//need Ant class derived from organism



// Define the Board class template
class Board {
private:
    static const int maxSize = 20;
    vector<vector<Organism*>> board;

public:
    // Constructor
    Board() : board(maxSize, vector<Organism*>(maxSize, nullptr)) {}

    // Destructor to clean up allocated memory by deleting all cells - will automatically run when object
    // is out of scope
    ~Board() {
        for (auto& row : board) {
            for (Organism* cell : row) {
                delete cell;
            }
        }
    }

    // Function to set an Organism at a given position - passing over the row number and column number and
    //the memory address for the organism - not sure if this one will work
    bool setOrganism(int row, int col, Organism* organism) {
        if (row >= 0 && row < maxSize && col >= 0 && col < maxSize) {
            delete board[row][col]; // Clean up existing organism
            board[row][col] = organism; // Set new organism
            return true;
        }
        return false;
    }

    // Function to destroy an Organism at a given position - for when they die


    // Function to get a pointer to the Organism at a given position - can be used for detection logic


    // Function to print the board
    void printBoard() const {
        for (const auto& row : board) {
            for (const Organism* organism : row) {
                if (organism) {
                    organism->display();
                } else {
                    cout << "-";
                }
                cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Board board;

    //need code to generate random positions for 100 ants and 5 doodlebugs

    // code to create organisms - loops should follow this format

    board.setOrganism(0, 0, new Organism());
    board.setOrganism(1, 1, new Organism());
    board.setOrganism(2, 2, new Organism());

    //code to iterate the day stepper - loop and do the same movements each step until terminated

    // Print the board the board after each step
    board.printBoard();




    return 0;
}