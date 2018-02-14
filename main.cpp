//
// Created by madis on 2/1/2018.
//
#import <iostream>
using namespace std;


int main() {

    //enum Color {r=1, y=2, b=3, g=4, p=5, o=6};

    cout << "Welcome to Mastermind!" << endl;
    cout << "Rules of the game:" << endl;

    string input;
    cout << "Do you want to be the Codemaker or the Codebreaker? ";
    cin >> input;

    while (input != "codebreaker" && input != "codemaker") {
        cout << "Invalid choice, please try again";
        cin >> input;
    }
    if (input == "codebreaker"){
        string randoms[] = {"r", "g", "b", "o", "y", "p"};
        string computer_code_matrix[1][4];
        string keymatrix[12][4];
        string guessmatrix[12][4];

        string cpu_choice1 = randoms[rand() % 6];
        string cpu_choice2 = randoms[rand() % 6];
        string cpu_choice3 = randoms[rand() % 6];
        string cpu_choice4 = randoms[rand() % 6];

        computer_code_matrix[0][0] = cpu_choice1;
        computer_code_matrix[0][1] = cpu_choice2;
        computer_code_matrix[0][2] = cpu_choice3;
        computer_code_matrix[0][3] = cpu_choice4;

        cout << "The computer has selected a color code" << endl;

        for (int i = 0; i < 12; ++i){
            cout << "What are your guesses?" << endl;

            string user_guess1;
            cout << "Guess 1: " << endl;
            cin >> user_guess1;

            string user_guess2;
            cout << "Guess 2: " << endl;
            cin >> user_guess2;

            string user_guess3;
            cout << "Guess 3: " << endl;
            cin >> user_guess3;

            string user_guess4;
            cout << "Guess 4: " << endl;
            cin >> user_guess4;

            guessmatrix[i][0] = user_guess1;
            guessmatrix[i][1] = user_guess2;
            guessmatrix[i][2] = user_guess3;
            guessmatrix[i][3] = user_guess4;

            for (int x = 0; x < i + 1; x++)  // loop 3 times for three lines
            {
                for (int y = 0; y < 4; y++)  // loop for the three elements on the line
                {
                    cout << guessmatrix[x][y];  // display the current element out of the array
                }
                cout << endl;  // when the inner loop is done, go to a new line
            }
            if (guessmatrix[i][0] == computer_code_matrix[0][0] && guessmatrix[i][1] == computer_code_matrix[0][1] &&
                guessmatrix[i][2] == computer_code_matrix[0][2] &&
                guessmatrix[i][3] == computer_code_matrix[0][3]) {
                cout << "You win!" << endl;

            }
            if (user_guess1 == cpu_choice1 | user_guess2 == cpu_choice1 | user_guess3 == cpu_choice1 | user_guess4 == cpu_choice1) {
                keymatrix[i][0] = "w";
            } else {
                keymatrix[i][0] = "b";
            }
            if (user_guess1 == cpu_choice2 | user_guess2 == cpu_choice2 | user_guess3 == cpu_choice2 | user_guess4 == cpu_choice2) {
                keymatrix[i][1] = "w";
            } else {
                keymatrix[i][1] = "b";
            }
            if (user_guess1 == cpu_choice3 | user_guess2 == cpu_choice3 | user_guess3 == cpu_choice3 | user_guess4 == cpu_choice3) {
                keymatrix[i][2] = "w";
            } else {
                keymatrix[i][2] = "b";
            }
            if (user_guess1 == cpu_choice4 | user_guess2 == cpu_choice4 | user_guess3 == cpu_choice4 | user_guess4 == cpu_choice4) {
                keymatrix[i][3] = "w";
            } else {
                keymatrix[i][3] = "b";
            }


            cout << "Key Matrix" << endl;

            for (int x = 0; x < i + 1; x++)  // loop 3 times for three lines
            {
                for (int y = 0; y < 4; y++)  // loop for the three elements on the line
                {
                    cout << keymatrix[x][y];  // display the current element out of the array
                }
                cout << endl;  // when the inner loop is done, go to a new line
            }
        }
        cout << "You lose!" << endl;
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
        string input = "";
        cout << "Do you want to play again? (y/n)";
        cin >> input;
        if (input == "y"){
            //restart
        }
        else{
            cout << "Thanks for playing!" << endl;
        }

    }

    if (input == "codemaker") {
        cout << "Choose the color of your four pegs for the computer to guess" << endl;

        string peg1;
        cout << "Peg 1? ";
        cin >> peg1;

        string peg2;
        cout << "Peg 2? ";
        cin >> peg2;

        string peg3;
        cout << "Peg 3? ";
        cin >> peg3;

        string peg4;
        cout << "Peg 4? ";
        cin >> peg4;


        //ADD ERROR CHECKING FOR PEG INPUT

        string yourmatrix[1][4];
        string keymatrix[12][4];
        string guessmatrix[12][4];


        // assigning values
        yourmatrix[0][0] = peg1;
        yourmatrix[0][1] = peg2;
        yourmatrix[0][2] = peg3;
        yourmatrix[0][3] = peg4;


        string randoms[] = {"r", "g", "b", "o", "y", "p"};


        for (int i = 0; i < 12; i++) {

            input = "";
            cout << "Display next guess? (press n to continue)";
            cin >> input;
            if (input == "n") {

                string guess1 = randoms[rand() % 6];
                string guess2 = randoms[rand() % 6];
                string guess3 = randoms[rand() % 6];
                string guess4 = randoms[rand() % 6];

                cout << "Computer Guesses" << endl;

                guessmatrix[i][0] = guess1;
                guessmatrix[i][1] = guess2;
                guessmatrix[i][2] = guess3;
                guessmatrix[i][3] = guess4;
                cout << endl;

                for (int x = 0; x < i + 1; x++)  // loop 3 times for three lines
                {
                    for (int y = 0; y < 4; y++)  // loop for the three elements on the line
                    {
                        cout << guessmatrix[x][y];  // display the current element out of the array
                    }
                    cout << endl;  // when the inner loop is done, go to a new line
                }

                if (guessmatrix[i][0] == yourmatrix[0][0] && guessmatrix[i][1] == yourmatrix[0][1] &&
                    guessmatrix[i][2] == yourmatrix[0][2] &&
                    guessmatrix[i][3] == yourmatrix[0][3]) {
                    cout << "The computer wins!" << endl;

                }


                if (guess1 == peg1 | guess2 == peg1 | guess3 == peg1 | guess4 == peg1) {
                    keymatrix[i][0] = "w";
                } else {
                    keymatrix[i][0] = "b";
                }
                if (guess1 == peg2 | guess2 == peg2 | guess3 == peg2 | guess4 == peg2) {
                    keymatrix[i][1] = "w";
                } else {
                    keymatrix[i][1] = "b";
                }
                if (guess1 == peg3 | guess2 == peg3 | guess3 == peg3 | guess4 == peg3) {
                    keymatrix[i][2] = "w";
                } else {
                    keymatrix[i][2] = "b";
                }
                if (guess1 == peg4 | guess2 == peg4 | guess3 == peg4 | guess4 == peg4) {
                    keymatrix[i][3] = "w";
                } else {
                    keymatrix[i][3] = "b";
                }


                cout << "Key Matrix" << endl;

                for (int x = 0; x < i + 1; x++)  // loop 3 times for three lines
                {
                    for (int y = 0; y < 4; y++)  // loop for the three elements on the line
                    {
                        cout << keymatrix[x][y];  // display the current element out of the array
                    }
                    cout << endl;  // when the inner loop is done, go to a new line
                }


            }
        }
        cout << "The computer lost!" << endl;
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
        input = "";
        cout << "Do you want to play again? (y/n)";
        cin >> input;
        if (input == "y"){
            //restart
        }
        else{
            cout << "Thanks for playing!" << endl;
        }

    }

    return 0;  // return 0 to the OS.

}
