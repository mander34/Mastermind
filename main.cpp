//
// Created by Maddie Anderson, Robert Baranov, Austin Batistoni
// CS205B 
// 15 February 2018
//
#include <iostream>
#include <fstream>
#include <locale>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * This program is a recreation of the game Mastermind. Player can play as either
 * codemaker or codebreaker. Game statistics are saved locally to a file. 
 */
int main() {
    bool play_again;
    bool quit = false;
    int num_games = 0;
    int num_wins = 0;
    int num_lose = 0;
    
    string file = "stats.txt";
    
    ifstream in_file (file); 
    if (in_file.is_open()){ //If file exists, pull stat info
        in_file >> num_games; 
        in_file >> num_wins;
        in_file >> num_lose;
    }else{
        ofstream output_file (file); //Creates the file and populates with data
        output_file << num_games << endl;
        output_file << num_wins << endl;
        output_file << num_lose << endl; 
        output_file.close();
    }
    
    //Menu loop
    while(!quit){
        cout << "Welcome to Mastermind!" << endl;

        int menu_choice;
        
        cout << "1. Codebreaker" << endl;
        cout << "2. Codemaker" << endl;
        cout << "3. How to play" << endl;
        cout << "4. Stats" << endl;
        cout << "5. Quit" << endl;
        cin >> menu_choice;

        //Invalid input handling
        while (menu_choice > 5 || menu_choice < 1) {
            cout << "Invalid choice, please try again";
            cin >> menu_choice;
        }
        
        //-------------CODEBREAKER---------------
        if (menu_choice == 1){
            play_again = true;
            while (play_again == true){
                string randoms[] = {"r", "g", "b", "o", "y", "p"};
                string computer_code_matrix[1][4];
                string guessmatrix[12][4];

                string cpu_choice1 = randoms[rand() % 6];
                string cpu_choice2 = randoms[rand() % 6];
                string cpu_choice3 = randoms[rand() % 6];
                string cpu_choice4 = randoms[rand() % 6];

                computer_code_matrix[0][0] = cpu_choice1;
                computer_code_matrix[0][1] = cpu_choice2;
                computer_code_matrix[0][2] = cpu_choice3;
                computer_code_matrix[0][3] = cpu_choice4;
                
                cout << cpu_choice1;
                cout << cpu_choice2;
                cout << cpu_choice3;
                cout << cpu_choice4 << endl;
               
                cout << "The computer has selected a color code" << endl;
                
                bool win = false;
                
                for (int i = 0; i < 12; ++i){
                    if (!win){
                        cout << "What are your guesses?" << endl;

                        string user_guess1, user_guess2, user_guess3, user_guess4;
                        
                        for (int j = 1; j < 5; j++){
                            cout << "Color " << j << ": ";
                            cin >> guessmatrix[i][j-1];
                            
                            while (guessmatrix[i][j-1] != "r" && guessmatrix[i][j-1] != "g" && guessmatrix[i][j-1] != "b" &&
                                guessmatrix[i][j-1] != "o" && guessmatrix[i][j-1] != "y" && guessmatrix[i][j-1] != "p"){
                                cout << "Incorrect color entered." << endl;
                                cout << "Color " << j << ": ";
                                cin >> guessmatrix[i][j-1];
                            }
                        }
                        
                        

                        user_guess1 = guessmatrix[i][0];
                        user_guess2 = guessmatrix[i][1];
                        user_guess3 = guessmatrix[i][2];
                        user_guess4 = guessmatrix[i][3];

                        cout << "Your Guess: ";
                        for (int x = 0; x < 4; x++){
                            cout << guessmatrix[i][x];
                        }
                        cout << endl;

                        if (guessmatrix[i][0] == computer_code_matrix[0][0] && guessmatrix[i][1] == computer_code_matrix[0][1] &&
                            guessmatrix[i][2] == computer_code_matrix[0][2] &&
                            guessmatrix[i][3] == computer_code_matrix[0][3]) {
                            cout << endl << "You win!" << endl;
                            win = true;
                            num_wins++;

                        }

                        if (!win){
                            cout << "Key: ";
                            for(int j=0; j<4; j++){		
                                if(guessmatrix[i][j] == computer_code_matrix[0][j]){
                                    cout << "W";
                                }
                            }
                            if (user_guess2 == cpu_choice1 | user_guess3 == cpu_choice1 | user_guess4 == cpu_choice1) {
                                cout << "B";
                            }

                            if (user_guess1 == cpu_choice2 | user_guess3 == cpu_choice2 | user_guess4 == cpu_choice2) {
                                cout << "B";
                            }

                            if (user_guess1 == cpu_choice3 | user_guess2 == cpu_choice3  | user_guess4 == cpu_choice3) {
                                cout << "B";
                            }

                            if (user_guess1 == cpu_choice4 | user_guess2 == cpu_choice4 | user_guess3 == cpu_choice4 ) {
                                cout << "B";
                            }

                            cout << endl;
                        }
                    }
                }
                if (!win){
                    cout << endl;
                    cout << "You lose!" << endl;
                    num_lose++;
                    cout << endl;

                    cout << "Computer's pegs: ";
                    cout << computer_code_matrix[0][0];
                    cout << computer_code_matrix[0][1];
                    cout << computer_code_matrix[0][2];
                    cout << computer_code_matrix[0][3];
                    cout << endl;

                    cout << "Your Guesses: " << endl;

                    for (int x = 0; x < 12; x++)  // loop 3 times for three lines
                    {
                        for (int y = 0; y < 4; y++)  // loop for the three elements on the line
                        {
                            cout << guessmatrix[x][y];  // display the current element out of the array
                        }
                        cout << endl;  // when the inner loop is done, go to a new line
                    }
                }
                num_games++;
                string play_again_input = "";
                cout << "Do you want to play again? (y/n)";
                cin >> play_again_input;
                
                while (play_again_input != "y" && play_again_input != "n"){
                    cout << "Invalid response." << endl;
                    cin >> play_again_input;
                }
                
                if (play_again_input == "n"){
                    play_again = false;
                    ofstream output_file(file);
                    output_file << num_games << endl;
                    output_file << num_wins << endl;
                    output_file << num_lose << endl;
                }
            }
        }
        
        
        //-----------------CODEMAKER-----------------------
        else if (menu_choice == 2) {
            play_again = true;
            while (play_again == true){
                cout << "Choose the color of your four pegs for the computer to guess" << endl;

                string peg1, peg2, peg3, peg4;                
                
                string randoms[] = {"r", "g", "b", "o", "y", "p"};
                string yourmatrix[1][4];
                string guessmatrix[12][4];
                
                for (int i = 1; i < 5; i++){
                    cout << "Color " << i << ": ";
                    cin >> yourmatrix[0][i-1];
                    
                    while (yourmatrix[0][i-1] != "r" && yourmatrix[0][i-1] != "g" && yourmatrix[0][i-1] != "b" &&
                            yourmatrix[0][i-1] != "o" && yourmatrix[0][i-1] != "y" && yourmatrix[0][i-1] != "p"){
                        cout << "Incorrect color entered." << endl;
                        cout << "Color " << i << ": ";
                        cin >> yourmatrix[0][i-1];
                    }
                    
                }

                // assigning values
                peg1 = yourmatrix[0][0];
                peg2 = yourmatrix[0][1];
                peg3 = yourmatrix[0][2];
                peg4 = yourmatrix[0][3];


              


                for (int i = 0; i < 12; i++) {

                    string show_guess = "";
                    cout << "Display next guess? (press n to continue)";
                    cin >> show_guess;
                    if (show_guess == "n") {

                        string guess1 = randoms[rand() % 6];
                        string guess2 = randoms[rand() % 6];
                        string guess3 = randoms[rand() % 6];
                        string guess4 = randoms[rand() % 6];


                        guessmatrix[i][0] = guess1;
                        guessmatrix[i][1] = guess2;
                        guessmatrix[i][2] = guess3;
                        guessmatrix[i][3] = guess4;
                        cout << endl;


                        cout << "Computer's Guess: ";
                        for (int x = 0; x < 4; x++){
                            cout << guessmatrix[i][x];
                        }
                        cout << endl;

                        if (guessmatrix[i][0] == yourmatrix[0][0] && guessmatrix[i][1] == yourmatrix[0][1] &&
                            guessmatrix[i][2] == yourmatrix[0][2] &&
                            guessmatrix[i][3] == yourmatrix[0][3]) {
                            cout << endl << "The computer wins!" << endl;
                            num_lose++;

                        }
                        cout << "Key: ";
                        for(int j=0; j<4; j++){		
                            if(guessmatrix[i][j] == yourmatrix[0][j]){
				cout << "W";
                            }
                        }
                        if (guess2 == peg1 | guess3 == peg1 | guess4 == peg1) {
                            cout << "B";
                        }

                        if (guess1 == peg2 | guess3 == peg2 | guess4 == peg2) {
                            cout << "B";
                        }

                        if (guess1 == peg3 | guess2 == peg3  | guess4 == peg3) {
                            cout << "B";
                        }

                        if (guess1 == peg4 | guess2 == peg4 | guess3 == peg4 ) {
                            cout << "B";
                        }

                        cout << endl;

                    }
                }
                cout << endl << "You win!" << endl;
                num_wins++;
                cout << endl;

                cout << "Your pegs" << endl;

                cout << yourmatrix[0][0];
                cout << yourmatrix[0][1];
                cout << yourmatrix[0][2];
                cout << yourmatrix[0][3];
                cout << endl;

                cout << "The computer's guesses" << endl;

                for (int x = 0; x < 12; x++)  // loop 3 times for three lines
                {
                    for (int y = 0; y < 4; y++)  // loop for the three elements on the line
                    {
                        cout << guessmatrix[x][y];  // display the current element out of the array
                    }
                    cout << endl;  // when the inner loop is done, go to a new line
                }
                string play_again_input = "";
                cout << "Do you want to play again? (y/n)";
                cin >> play_again_input;
                
                while (play_again_input != "y" && play_again_input != "n"){
                    cout << "Invalid response." << endl;
                    cin >> play_again_input;
                }
                if (play_again_input == "n"){
                    play_again = false;
                    num_games++;
                    ofstream output_file(file);
                    output_file << num_games << endl;
                    output_file << num_wins << endl;
                    output_file << num_lose << endl;
                    output_file.close();
                }
            }

        }
        
        //----------------HOW TO PLAY------------------
        else if (menu_choice == 3){
            cout << endl << "HOW TO PLAY" << endl;
            cout << "The goal of mastermind is to guess the secret code consisting of a series of 4 colored pegs." << endl;
            cout << "The pegs can be r: red, b: blue, g: green, y: yellow, o: orange, p: purple." << endl;
            cout << "You can play as the codemaker which means you chose the 4 pegs and the computer has 12 tries to guess the series." << endl;
            cout << "You can play as the codebreaker and the computer will chose 4 pegs and you have 12 tries to guess the series. " << endl;
            cout << "The Key Matrix displays B: black and W: white pegs. A white peg indicates a correct colored peg in the correct position." << endl;
            cout << "A black colored peg indicates a correct colored peg, but in the wrong position." << endl;
            cout << endl;
        }
        
        //--------------STATISTICS--------------------
        else if (menu_choice == 4){
            cout << endl;
            cout << "STATS" << endl;
            cout << "----------------" << endl;
            cout << "Games played: " << num_games << endl;
            cout << "Wins: " << num_wins << endl;
            cout << "Losses: " << num_lose << endl;
            cout << endl;
        }
        
        //----------------QUIT----------------------
        else if (menu_choice == 5){
            cout << "Thanks for playing!!";
            quit = true;
        }
    }

    return 0;  // return 0 to the OS.

}
   
 


