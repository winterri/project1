/*
 * Project Title:
 * - EscapeRoom
 * Description:
 * - You start this game trapped in the basement of a house after being kidnapped
 * - Your goal is to try to maneuver your way through the house and use the objects througout it to escape
 * - There are 8 different objects scattered throughout the 5 rooms in the house
 * - Note that not every item is needed to successfully escape from the house
 * - This is how the game works:
 * - First, you will be given a small description of your surroundings
 * - Next, you will be prompted to make a decision, upon which you will be given a list of options
 * - Each option is labeled with a number
 * - To choose the option you want, you will type the label number associated with that decision
 * - After you make that decision, you will then be given a new description
 * - Then you will then have to make another decision, and so on
 * - The game is played entirely in number keys
 * - Do not press anyhing but number keys or the game will crash
 * - Your goal is escape the house in the fewest possible moves
 * - The minimum amount of moves to complete the game is 11
 *
 *
 * Developers:
 * - Mason Douglas - Douglamc@mail.uc.edu
 * - Ryan Winterhalter - Winterri@mail.uc.edu
 *
 * Help Received:
 * - None
 *
 * Special Instructions:
 * - Game is played entirely in number keys
 * - DO NOT PRESS ANYTHING BUT NUMBER KEYS OR THE GAME WILL CRASH!!!
 *
 * Developer comments:
 * Mason Douglas:
 * - I wrote the Basement Function, Kitchen function, Main function, and was reponsible for the Code organization or piecing everything together.
 * - The functions are all relatively similar, and each one allows the user to make choices using case structures.
 * - The users options are layed out for them and they then enter a number to go along with the corresponding choice.
 * - The most complex of these functions was the kitchen as the code actually contains two nested case structures.
 * - Another important thing to note is that the same variables are passed through all of our functions so that they can be accessed anywhere in the code.
 * - I learned that under the right aplication goto functions can actually be a very useful in the right situation, as well as
 * - that case structures are better then if statements if there are many different options for the user to pick from.
 * Ryan Winterhalter:
 * - I wrote the livingRoom function, the bedroom function, the bathroom function, the instructions function, and the escape function for our game.
 * - Each of these functions had fairly the same structure to it.  I would start by giving a description of whatever room you had entered (which
 * - I had determined from the name of the function and the map we had drawn out before the project started).  Next, I would move on to give the
 * - user all of the possible choices they could make in that room.  Then I would ask the user to input their action, which I usually defined only
 * - in each of the functions as the variable only had meaning within the function for the case statements that would execute certain code based
 * - on what option the user chose.  I also spent a lot of time debugging the code after testing to make sure that we had no unclosed loops, no
 * - missing break statements, etc.  From writing these functions, I learned the value of switch statements.  Switch statements helped keep my
 * - functions very organized, much more so than if I were to use if-else if-else statements.  I also learned the value of pass by reference
 * - when passing all of our variables, like moves and all of our boolean values for the items.  It makes it so that we don't have to use global
 * - variables for any of our items and that we can define all of our variables in the main function.  I also learned the value of writing most
 * - of your code in functions because it is much easier to keep the main function organized.
 */

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <ctype.h>

using namespace std;

// All functions declaring here so that they can be called later in the code, without worry of the order in which they are defined
void Basement(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves);
void LivingRoom(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves);
void Kitchen(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves);
void Bathroom(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves);
void escape(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves);
void Bedroom(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves);


// The basement function is the code for the basement in the game, it allows the user to make choices of what moves they want to make while they are in the basement
void Basement(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves){
    int action; // input for the first case statement within the basement function
    int action2; // inout for a second case statement in the basement function
    int object; // used for an if statement in the basement function
    int answer1; // used for a nested if statement
    int answer2; // used for a nested if statement
    bool goodDecision = 1; // used for the while loop in basement function

    if(basementDoorLocked == 1){
    cout << "You wake up to find yourself in a dimly lit room with no windows" << endl;
    cout << "You are able to determine that it's probably a basement" << endl;
    cout << "There is a locked door and some cabinets in the room" << endl;
    cout << endl;
    }
    BASEMENTFIRSTMOVE: cout << "What is your first move?" << endl;
    cout << endl;

    while(goodDecision == 1){ //loop starts here

    cout << "1) Open door" << endl;
    cout << "2) Open cabinet" << endl;
    cout << "3) Scream for help" << endl;
    cout << "4) Open help menu" << endl;
    cout << endl;
    cin >> action;

    switch(action){
    case 1:
        if(bobbyPin == 1 && screwdriver == 1){
            DOORITEM: cout << "What item would you like to use to open the door?" << endl;
            cout << endl;
            cout << "1) The screwdriver" << endl;
            cout << "2) The bobby pin" << endl;
            cout << "3) Open help menu" << endl;
            cout << endl;
            cin >> action2;
            switch(action2){ // allows the user to chose one of the options
                case 1:
                    cout << "That didn't work" << endl;
                    cout << endl;
                    break;
                case 2:
                    cout << "You were able to pick the lock using the bobby pin, the door is open, you head up the stairs" << endl;
                    cout << endl;
                    basementDoorLocked = 0;
                    goodDecision = 0;
                    LivingRoom(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
                    break;
                case 3:
                    cout << "This is how the game works:" << endl;
                    cout << "First, you will be given a small description of your surroundings" << endl;
                    cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
                    cout << "Each option is labeled with a number" << endl;
                    cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
                    cout << "After you make that decision, you will then be given a new description" << endl;
                    cout << "Then you will then have to make another decision, and so on" << endl;
                    cout << "The game is played entirely in number keys" << endl;
                    cout << "Do not press anything but number keys or the game will crash" << endl;
                    cout << "Your goal is escape the house in the fewest possible moves" << endl;
                    cout << "The minimum amount of moves to complete the game is 11" << endl;
                    cout << endl;
                    goto DOORITEM;
                default:
                    cout << "You have to chose which item to use. What are you gonna do punch it?" << endl;
                    cout << endl;
                    break;
            }
        }
        else if(bobbyPin == 1 && screwdriver == 0){
            cout << "You were able to pick the lock using the bobby pin. The door is open, you head up the stairs" << endl;
            cout << endl;
            goodDecision = 0;
            basementDoorLocked = 0;
            LivingRoom(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
        }
        else if(bobbyPin == 0 && screwdriver == 1){
            cout << "You were unable to open the door with the screwdriver" << endl;
            cout << endl;
        }
        else{
            cout << "The door is locked.....suprising" << endl;
            cout << endl;
        }
        moves = moves + 1;
        break;
    case 2:
        if(bobbyPin == 0 && screwdriver == 0){

        INSIDECABINET: cout << "Inside the cabinet you find a screwdriver and a bobby pin" << endl;
        cout << endl;
        cout << "1) Pick up screwdriver" << endl;
        cout << "2) Pick up bobby pin" << endl;
        cout << "3) Pick up both" << endl;
        cout << "4) Open help menu" << endl;
        cout << endl;
        cin >> object;
        if(object == 1){
            cout << "You have picked up the screwdriver" << endl;
            cout << endl;
            screwdriver = 1;
        }
        else if(object == 2){
            cout << "You have picked up the bobby pin" << endl;
            cout << endl;
            bobbyPin = 1;
        }
        else if(object == 3){
            cout << "You have picked up both the screwdriver and the bobby pin" << endl;
            cout << endl;
            screwdriver = 1;
            bobbyPin = 1;
        }
        else if(object == 4){
            cout << "This is how the game works:" << endl;
            cout << "First, you will be given a small description of your surroundings" << endl;
            cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
            cout << "Each option is labeled with a number" << endl;
            cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
            cout << "After you make that decision, you will then be given a new description" << endl;
            cout << "Then you will then have to make another decision, and so on" << endl;
            cout << "The game is played entirely in number keys" << endl;
            cout << "Do not press anything but number keys or the game will crash" << endl;
            cout << "Your goal is escape the house in the fewest possible moves" << endl;
            cout << "The minimum amount of moves to complete the game is 11" << endl;
            cout << endl;
            goto INSIDECABINET;
        }
        else{
            cout << "Can you seriously not count to three?? I mean it is literally laid out infront of you, just pick one" << endl;
            cout << endl;
        }
     }
        else if(bobbyPin == 1 && screwdriver == 0){
            XYZ: cout << "Inside the cabinet there is a screwdriver" << endl;
            cout << endl;
            XXX: cout << "Do you want to pick it up?" << endl;
            cout << endl;
            cout << "1) Yes" << endl;
            cout << "2) No" << endl;
            cout << "3) Open help menu" << endl;
            cout << endl;
            cin >> answer1;

            if(answer1 == 1){
                cout << "You pick up the screwdriver" << endl;
                cout << endl;
                screwdriver = 1;
            }
            else if(answer1 == 2){
                cout << "You leave the screwdriver where it is" << endl;
                cout << endl;
            }
            else if(answer1 == 3){
                cout << "This is how the game works:" << endl;
                cout << "First, you will be given a small description of your surroundings" << endl;
                cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
                cout << "Each option is labeled with a number" << endl;
                cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
                cout << "After you make that decision, you will then be given a new description" << endl;
                cout << "Then you will then have to make another decision, and so on" << endl;
                cout << "The game is played entirely in number keys" << endl;
                cout << "Do not press anything but number keys or the game will crash" << endl;
                cout << "Your goal is escape the house in the fewest possible moves" << endl;
                cout << "The minimum amount of moves to complete the game is 11" << endl;
                cout << endl;
                goto XYZ;
            }
            else{
                cout << "That is not a valid option" << endl;
                cout << endl;
                goto XXX;
            }
        }
        else if(bobbyPin == 0 && screwdriver == 1){
            ABCD: cout << "Inside the cabinet there is a bobby pin" << endl;
            cout << endl;
            YYY: cout << "Do you want to pick it up?" << endl;
            cout << endl;
            cout << "1) Yes" << endl;
            cout << "2) No" << endl;
            cout << "3) Open help menu" << endl;
            cout << endl;
            cin >> answer2;

            if(answer2 == 1){
                cout << "You pick up the bobby pin" << endl;
                cout << endl;
                bobbyPin = 1;
            }
            else if(answer2 == 2){
                cout << "You leave the bobby pin where it is" << endl;
                cout << endl;
            }
            else if(answer2 == 3){
                cout << "This is how the game works:" << endl;
                cout << "First, you will be given a small description of your surroundings" << endl;
                cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
                cout << "Each option is labeled with a number" << endl;
                cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
                cout << "After you make that decision, you will then be given a new description" << endl;
                cout << "Then you will then have to make another decision, and so on" << endl;
                cout << "The game is played entirely in number keys" << endl;
                cout << "Do not press anything but number keys or the game will crash" << endl;
                cout << "Your goal is escape the house in the fewest possible moves" << endl;
                cout << "The minimum amount of moves to complete the game is 11" << endl;
                cout << endl;
                goto ABCD;
            }
            else{
                cout << "That is not a valid option" << endl;
                cout << endl;
                goto YYY;
            }

        }
        else{
            cout << "There is nothing left in the cabinet" << endl;
            cout << endl;
        }
        moves = moves + 1;
        break;
     case 3:
        cout << "Why are you screaming? How will this help your situation?" << endl;
        cout << endl;
        moves = moves + 1;
        break;
    case 4:
        cout << "This is how the game works:" << endl;
        cout << "First, you will be given a small description of your surroundings" << endl;
        cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
        cout << "Each option is labeled with a number" << endl;
        cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
        cout << "After you make that decision, you will then be given a new description" << endl;
        cout << "Then you will then have to make another decision, and so on" << endl;
        cout << "The game is played entirely in number keys" << endl;
        cout << "Do not press anything but number keys or the game will crash" << endl;
        cout << "Your goal is escape the house in the fewest possible moves" << endl;
        cout << "The minimum amount of moves to complete the game is 11" << endl;
        cout << endl;
        moves = moves + 1;
        goto BASEMENTFIRSTMOVE;
    default:
        cout << "Undecisive are we?" << endl;
        cout << endl;
        moves = moves + 1;
        break;
    }
  }
}
// The living room function controls what the user can do once they enter the living room.  It outlines all of their choices they can make in the basement and will run code in different cases in a switch statement based on what choice the user makes
void LivingRoom(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves){
    int action; // This is the variable that controls what initial choice the user makes in the living room
                // Action is only defined in this function because it's only used in this function
    int inputDoorCode; // This is the door code to unlock the door to the unknown location (the bedroom)
    bool goodDecision = 1; // This is a condition for the while loop that we named goodDecision because we defined a "good decision" as one where the user would exit the loop and the room

    cout << "You enter the living room" << endl;
    cout << "On a desk to your right, there is a cell phone next to a jar" << endl;
    cout << "In front of you, there is a couch with a small coffee table.  The TV is on" << endl;
    cout << "All of the windows to your right are boarded up" << endl;
    cout << "Straight ahead of you, you see the front door on the other side of the room" << endl;
    cout << "There are also two doors to your left: one of them has a small window, which appears to lead to the kitchen" << endl;
    cout << "You cannot see where the other door leads" << endl;
    cout << endl;
    LIVINGROOMDECISION: cout << "What would you like to do?" << endl; // We put this label in here because we use multiple goto statements later if the user enters a value that does not match one of the choices outlined to them
    cout << endl;

    while(goodDecision == 1){ // This is the loop that will check to see if the user made a "good decision" that warrants leaving the while loop and moving to a different location within the house

    cout << "1) Use cell phone to call for help" << endl;
    cout << "2) Sit on the couch and see what is on the TV" << endl;
    cout << "3) Search the jar on the desk" << endl;
    cout << "4) Open the front door" << endl;
    cout << "5) Pry the boards off of the windows" << endl;
    cout << "6) Open the door to the unknown location on your left" << endl;
    cout << "7) Open the door to the kitchen" << endl;
    cout << "8) Go back down the stairs to the basement" << endl;
    cout << "9) Open help menu" << endl;
    cout << endl;
    cin >> action; // This is where the user will enter the integer value of the choice they want to make of all the choices previously outlined with the cout statements

    switch(action){ // This is where the switch statement begins
                    // The switch statement will execute a certain case based on what number the user enters
    case 1: // For example, if the user inputs 1, case 1 will execute
        cout << "That was a good idea, but the cell phone is dead, so you won't be able to make a call" << endl;
        cout << "What would you like to do next?" << endl;
        cout << endl;
        moves = moves + 1; // Every time the user makes a choice, like this one, we add one more move to the total number of moves they have made
        break;
    case 2:
        cout << "Do you really think now is a good time to be watching TV?  What could possibly be on that would help you?" << endl;
        cout << "What would you like to do next?" << endl;
        cout << endl;
        moves = moves + 1;
        break;
    case 3:
        if(code == 0){
            cout << "Inside of the jar you find a paper with a small 3-digit code on it" << endl;
            cout << "The numbers read: " << doorCode << endl;
            code = 1; // This changes the boolean value for code which means that the user picked up the code piece of paper
            cout << "You pick up the small piece of paper" << endl;
            cout << endl;
        }
        else{
            cout << "You look inside the jar, but find nothing else useful since you already have the paper with the code" << endl;
            cout << "The numbers read: " << doorCode << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
        }
        moves = moves + 1;
        break;
    case 4:
        if(key == 0){
            cout << "Good idea, but the front door is locked and the lock is too complex to pick with a bobby pin" << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
            moves = moves + 1;
            break;
        }
        else{
            goodDecision = 0;
            moves = moves + 1;
            escape(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
            break;
        }
    case 5:
        if(crowbar == 0){
            cout << "You try to pry the boards off of the windows, but they won't move" << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
        }
        else{
            cout << "You try to use the crowbar to pry the boards off of the windows, but they won't seem to move" << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
        }
        moves = moves + 1;
        break;
    case 6:
        cout << "The door appears to have a key-code lock on it" << endl;
        if(bedroomDoorLocked == 1){ // This is the if statement that will operate if the door is locked
            cout << "The door is locked." << endl;
            int enterCode = 1;
            while(enterCode == 1){ // This is the while loop that will run if the user wants to enter the code
                ENTERINITIALCODE: cout << "Would you like to enter the code?" << endl;
                cout << "1) Yes" << endl;
                cout << "2) No" << endl;
                cout << "3) Open help menu" << endl;
                cin >> enterCode;
                if(enterCode == 2){ // This executes if the user says no to entering the code
                    cout << "What would you like to do next?" << endl;
                    cout << endl;
                    break;
                }
                else if(enterCode == 1){ // This is the code that will execute if the user wants to enter the code
                    ENTERCODE1: cout << "What is the code: ";
                    enterCode = 1;
                    cin >> inputDoorCode;
                    if(inputDoorCode == doorCode){ // This code will operate if the code the user entered matches the randomly generated code
                        bedroomDoorLocked = 0; // This unlocks the door
                        goodDecision = 0; // This exits the loop
                        cout << "You open the door and go into the unknown room, which to your surprise is the bedroom" << endl;
                        cout << endl;
                        // The bedroom will be called here to make the user enter the bedroom
                        Bedroom(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
                        break;
                    }
                    else{ // This will execute if the code is incorrect
                        cout << "The code you entered is incorrect" << endl;
                        cout << endl;
                        int tryAgain = 1;
                        while(tryAgain == 1){ // This is the while loop that will operate if the user wants to enter the code again
                        TRYCODEAGAIN: cout << "Would you like to try again?" << endl;
                        cout << "1) Yes" << endl;
                        cout << "2) No" << endl;
                        cout << "3) Open help menu" << endl;
                        cin >> tryAgain;
                        if(tryAgain == 1){
                            goto ENTERCODE1;
                        }
                        else if(tryAgain == 2){
                            break;
                        }
                        else if(tryAgain == 3){
                            cout << "This is how the game works:" << endl;
                            cout << "First, you will be given a small description of your surroundings" << endl;
                            cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
                            cout << "Each option is labeled with a number" << endl;
                            cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
                            cout << "After you make that decision, you will then be given a new description" << endl;
                            cout << "Then you will then have to make another decision, and so on" << endl;
                            cout << "The game is played entirely in number keys" << endl;
                            cout << "Do not press anything but number keys or the game will crash" << endl;
                            cout << "Your goal is escape the house in the fewest possible moves" << endl;
                            cout << "The minimum amount of moves to complete the game is 11" << endl;
                            cout << endl;
                            tryAgain = 1;
                            goto TRYCODEAGAIN;
                        }
                        else{
                            cout << "I'm sorry, I didn't understand that" << endl;
                            tryAgain = 1;
                            }
                        }
                    break;
                    }
                }
                else if(enterCode == 3){ // This is the help statement
                    cout << "This is how the game works:" << endl;
                    cout << "First, you will be given a small description of your surroundings" << endl;
                    cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
                    cout << "Each option is labeled with a number" << endl;
                    cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
                    cout << "After you make that decision, you will then be given a new description" << endl;
                    cout << "Then you will then have to make another decision, and so on" << endl;
                    cout << "The game is played entirely in number keys" << endl;
                    cout << "Do not press anything but number keys or the game will crash" << endl;
                    cout << "Your goal is escape the house in the fewest possible moves" << endl;
                    cout << "The minimum amount of moves to complete the game is 11" << endl;
                    cout << endl;
                    goto ENTERINITIALCODE;
                }
                else{
                    cout << "Sorry, I didn't understand that." << endl;
                    cout << endl;
                    enterCode = 'y';
                }
            }
        }
        else if(bedroomDoorLocked == 0){ // This will execute if the bedroom door is unlocked
            cout << "You enter the bedroom" << endl;
            cout << endl;
            goodDecision = 0;
            // The user would then enter the bedroom
            Bedroom(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
            break;
        }
        moves = moves + 1;
        break;
    case 7:
        goodDecision = 0;
        cout << "You go through the door and now find yourself in the kitchen" << endl;
        cout << endl;
        moves = moves + 1;
        Kitchen(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
        break;
    case 8:
        goodDecision = 0;
        cout << "You turn around and walk back down the stairs to the basement" << endl;
        cout << endl;
        moves = moves + 1;
        Basement(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
        break;
    case 9:
        cout << "This is how the game works:" << endl;
        cout << "First, you will be given a small description of your surroundings" << endl;
        cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
        cout << "Each option is labeled with a number" << endl;
        cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
        cout << "After you make that decision, you will then be given a new description" << endl;
        cout << "Then you will then have to make another decision, and so on" << endl;
        cout << "The game is played entirely in number keys" << endl;
        cout << "Do not press anything but number keys or the game will crash" << endl;
        cout << "Your goal is escape the house in the fewest possible moves" << endl;
        cout << "The minimum amount of moves to complete the game is 11" << endl;
        cout << endl;
        moves = moves + 1;
        goto LIVINGROOMDECISION;
    default: // This will execute if the user input does not match one of the chioces
        cout << "I'm sorry, I didn't understand that" << endl;
        cout << "What would you like to do next?" << endl;
        cout << endl;
        moves = moves + 1;
        break;
    }
  }
}

// This is the code for the bedroom, which will be called from other functions
void Bedroom(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves){
    int action; // This action variable is defined only in this function because it is only used to choose the option within this function that the user chooses
    int goodDecision = 1; // This goodDecision variable is similar to the one used in the LivingRoom function
    int takeHanger; // This variable is used to determine if the user took the hanger or not

    cout << "You enter the bedroom" << endl;
    cout << "In the middle of the room against one wall is a large bed" << endl;
    cout << "On one side of the room you see a large closet" << endl;
    cout << "At the other end of the room, you see a door that looks like it leads to the bathroom" << endl;
    cout << "You see a nightstand next to the bed with nothing on it, but it looks like it has drawers" << endl;
    cout << "On the wall opposite the bed, there is the door back to the living room" << endl;
    cout << endl;
    BEDROOMDECISION: cout << "What would you like to do?" << endl; // This label is used for later goto statements within this function
    cout << endl;

    while(goodDecision == 1){ // This is where the loop of the decision-making for the bedroom begins
        cout << "1) Go into the bathroom" << endl;
        cout << "2) Search under the bed covers for anything useful" << endl;
        cout << "3) Check for something under the bed" << endl;
        cout << "4) Search the drawers of the nightstand" << endl;
        cout << "5) Go into the closet" << endl;
        cout << "6) Go back into the living room" << endl;
        cout << "7) Open help menu" << endl;
        cout << endl;
        cin >> action; // User will input their choice here, and the below switch statement will execute a certain case based on their input

        switch(action){
        case 1:
            goodDecision = 0; // Just like the LivingRoom function, every time goodDecision is set equal to zero is when the user leaves the room and therefore must exit the loop
            moves = moves + 1;
            Bathroom(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
            break;
        case 2:
            cout << "You look under the covers, but you find nothing useful" << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
            moves = moves + 1;
            break;
        case 3:
            cout << "You serach under the bed, but there is nothing there" << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
            moves = moves + 1;
            break;
        case 4:
            cout << "You open the drawer next to the bed and find a note" << endl;
            cout << "It appears to be a grocery list, so you don't think it'll be useful" << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
            moves = moves + 1;
            break;
        case 5:
            if(hanger == 0){ // This if statement will execute if the user does not currently have the coat hanger
                cout << "You go into the closet and find a wired coat hanger" << endl;
                cout << endl;
                TAKEHANGER: cout << "What would you like to do?" << endl;
                cout << endl;
                cout << "1) Take coat hanger" << endl;
                cout << "2) Leave coat hanger" << endl;
                cout << "3) Open help menu" << endl;
                cout << endl;
                cin >> takeHanger;
                if(takeHanger == 1){ // User will take the hanger
                    cout << "You take the coat hanger" << endl;
                    cout << endl;
                    hanger = 1;
                    cout << "What would you like to do next?" << endl;
                    cout << endl;
                }
                else if(takeHanger == 2){  // User will leave the coat hanger
                    cout << "You leave the coat hanger in the closet" << endl;
                    cout << "What would you like to do next?" << endl;
                    cout << endl;
                }
                else if(takeHanger == 3){
                    cout << "This is how the game works:" << endl;
                    cout << "First, you will be given a small description of your surroundings" << endl;
                    cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
                    cout << "Each option is labeled with a number" << endl;
                    cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
                    cout << "After you make that decision, you will then be given a new description" << endl;
                    cout << "Then you will then have to make another decision, and so on" << endl;
                    cout << "The game is played entirely in number keys" << endl;
                    cout << "Do not press anything but number keys or the game will crash" << endl;
                    cout << "Your goal is escape the house in the fewest possible moves" << endl;
                    cout << "The minimum amount of moves to complete the game is 11" << endl;
                    cout << endl;
                    goto TAKEHANGER;
                }
                else{
                    cout << "I'm sorry, I didn't understand that" << endl;
                    cout << endl;
                    goto TAKEHANGER;
                }
            }
            else{
                cout << "You walk into the closet and find some wired coat hangers" << endl;
                cout << "However, you already have a coat hanger in your inventory" << endl;
                cout << "What would you like to do next?" << endl;
                cout << endl;
            }
            moves = moves + 1;
            break;
        case 6:
            goodDecision = 0;
            moves = moves + 1;
            LivingRoom(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
            break;
        case 7:
            cout << "This is how the game works:" << endl;
            cout << "First, you will be given a small description of your surroundings" << endl;
            cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
            cout << "Each option is labeled with a number" << endl;
            cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
            cout << "After you make that decision, you will then be given a new description" << endl;
            cout << "Then you will then have to make another decision, and so on" << endl;
            cout << "The game is played entirely in number keys" << endl;
            cout << "Do not press anything but number keys or the game will crash" << endl;
            cout << "Your goal is escape the house in the fewest possible moves" << endl;
            cout << "The minimum amount of moves to complete the game is 11" << endl;
            cout << endl;
            moves = moves + 1;
            goto BEDROOMDECISION;
        default: // This code will execute if the user does not input a proper input that matches with any of the above choices in the switch statement
            cout << "Sorry, I didn't quite understand that" << endl;
            cout << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
            moves = moves + 1;
            break;
        }
    }
}
// This code allows the user to make choices in the kitchen
void Kitchen(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves){
    bool kitchen = 1; //used for the while loop in the kitchen function
    int action; // used for case structure 1
    int action2; // used for case structure 2
    int action3; // used for case structure 3

    if(lights == 0){
    cout << "The lights are off" << endl;
    }
    cout << "Directly in front of you, there is a large boarded window" << endl;
    cout << "To your right, there is a refridgerator and a pantry" << endl;
    cout << "On your left, there are some cabinets and a sink" << endl;
    cout << endl;

    while(kitchen == 1){ // start of while loop

    KITCHENDECISION: cout << "What would you like to do now?" << endl;
    cout << endl;
    cout << "1) Open the fridge" << endl;
    cout << "2) Search the pantry" << endl;
    cout << "3) Turn on the light" << endl;
    cout << "4) Look in the cabinets" << endl;
    cout << "5) Try to pry the boards off the window" << endl;
    cout << "6) Exit the kitchen the from where you entered" << endl;
    cout << "7) Open help menu" << endl;
    cout << endl;
    cin >> action;

    switch(action){ //case statement 1

    case 1:
       cout << "You open the fridge and a terrible smell floods the room" << endl;
       cout << "You quickly become aware that there is nothing but rotten food in the fridge and close it" << endl;
       cout << endl;
       moves = moves + 1;
       break;
    case 2:
       cout << "You open the pantry door" << endl;
       cout << endl;
       if(crowbar == 0){
            cout << "The pantry is fairly empty, but you do see a crowbar leaning against the wall" << endl;
            cout << endl;
            TAKECROWBAR: cout << "Would you like to take the crowbar?" << endl;
            cout << endl;
            cout << "1) Yes" << endl;
            cout << "2) No" << endl;
            cout << "3) Open help menu" << endl;
            cout << endl;
            cin >> action2;

            switch(action2){ // case statement 2
                case 1:
                    cout << "You grab the crowbar and add it to your inventory" << endl;
                    cout << endl;
                    crowbar = 1;
                    break;
                case 2:
                    cout << "You leave the crowbar where it is and close the pantry door" << endl;
                    cout << endl;
                    break;
                case 3:
                    cout << "This is how the game works:" << endl;
                    cout << "First, you will be given a small description of your surroundings" << endl;
                    cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
                    cout << "Each option is labeled with a number" << endl;
                    cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
                    cout << "After you make that decision, you will then be given a new description" << endl;
                    cout << "Then you will then have to make another decision, and so on" << endl;
                    cout << "The game is played entirely in number keys" << endl;
                    cout << "Do not press anything but number keys or the game will crash" << endl;
                    cout << "Your goal is escape the house in the fewest possible moves" << endl;
                    cout << "The minimum amount of moves to complete the game is 11" << endl;
                    cout << endl;
                    goto TAKECROWBAR;
                default:
                    cout << "Not a valid option" << endl;
                    cout << endl;
                    goto TAKECROWBAR;
            }
         }
       else{
            cout << "You look around but find nothing, other than some stale chips" << endl;
            cout << endl;
       }
       moves = moves + 1;
       break;
     case 3:
        if(key == 0){
            cout << "You reach for the light switch but accidentaly hit the switch for the garbage disposal" << endl;
            cout << "Intrigued by this, you reach for the actual light switch and look down the sink" << endl;
            cout << "You can see that there is a key lodged in the blades of the garbage disposal" << endl;
            cout << endl;
            GRABKEY: cout << "Would you like to try to grab the key?" << endl;
            cout << endl;
            cout << "1) Yes" << endl;
            cout << "2) No" << endl;
            cout << "3) Open help menu" << endl;
            cout << endl;
            cin >> action3;

            switch(action3){ // case statement 3
                case 1:
                if(hanger == 1){
                    cout << "You bend a hook in the coat hanger and are able to use it to hook the key" << endl;
                    cout << "The key has been added to your inventory" << endl;
                    cout << endl;
                    key = 1;
                }
                else{
                    cout << "Your hand is too wide to fit down the drain" << endl;
                    cout << "You will need to find something to grab it with" << endl;
                    cout << endl;
                }
                    break;
                case 2:
                    cout << "You leave the key and continue on" << endl;
                    cout << endl;
                    break;
                case 3:
                    cout << "This is how the game works:" << endl;
                    cout << "First, you will be given a small description of your surroundings" << endl;
                    cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
                    cout << "Each option is labeled with a number" << endl;
                    cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
                    cout << "After you make that decision, you will then be given a new description" << endl;
                    cout << "Then you will then have to make another decision, and so on" << endl;
                    cout << "The game is played entirely in number keys" << endl;
                    cout << "Do not press anything but number keys or the game will crash" << endl;
                    cout << "Your goal is escape the house in the fewest possible moves" << endl;
                    cout << "The minimum amount of moves to complete the game is 11" << endl;
                    cout << endl;
                    goto GRABKEY;
                default:
                    cout << "Invalid option" << endl;
                    cout << endl;
                    goto GRABKEY;
            }
        }
        else{
            cout << "The lights are already on" << endl;
            cout << endl;
        }
        moves = moves + 1;
        break;
     case 4:
        cout << "You look in the cabinets, but there is nothing useful, just some cleaning supplies" << endl;
        cout << endl;
        moves = moves + 1;
        break;
     case 5:
        if(crowbar == 1){
            cout << "You try to use the crowbar to pry off the boards, but you are unsuccesful" << endl;
            cout << "The boards are screwed into the frame" << endl;
            cout << endl;
        }
        else{
            cout << "You try to pry the boards off with your hands, but it does not work" << endl;
            cout << endl;
        }
        moves = moves + 1;
        break;
     case 6:
        kitchen = 0;
        moves = moves + 1;
        LivingRoom(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
        break;
    case 7:
        cout << "This is how the game works:" << endl;
        cout << "First, you will be given a small description of your surroundings" << endl;
        cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
        cout << "Each option is labeled with a number" << endl;
        cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
        cout << "After you make that decision, you will then be given a new description" << endl;
        cout << "Then you will then have to make another decision, and so on" << endl;
        cout << "The game is played entirely in number keys" << endl;
        cout << "Do not press anything but number keys or the game will crash" << endl;
        cout << "Your goal is escape the house in the fewest possible moves" << endl;
        cout << "The minimum amount of moves to complete the game is 11" << endl;
        cout << endl;
        moves = moves + 1;
        goto KITCHENDECISION;
    default:
        cout << "I'm sorry, I didn't quite understand that input" << endl;
        cout << endl;
        moves = moves + 1;
        goto KITCHENDECISION;
    }
  }
}

// This bathroom code will execute when the user enters the bathroom, which will be called only from the bedroom function
void Bathroom(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves){
    int action; // This action variable is only defined in this function because it only controls what the user will do in the bathroom and not in any other room, so it doesn't need to be defined outside of the function
    int exitRoom = 1; // This is the condition for the while loop much like the goodDecision condition in the LivingRoom function

    cout << "You enter the bathroom" << endl;
    cout << "Directly in front of you, there is a shower with a closed curtain" << endl;
    cout << "There is a box sitting on top of the toilet seat keeping it held down to your left" << endl;
    cout << "Underneath the bathroom sink to your right, there are a few cabinets" << endl;
    cout << "A mirror is on the wall above the sink, but you think you see a small hole behind the mirror" << endl;
    cout << endl;
    BATHROOMDECISION: cout << "What would you like to do?" << endl;
    cout << endl;
    while(exitRoom == 1) { // This is where the while loop for the user choice will begin

    cout << "1) Search behind the shower curtain" << endl;
    cout << "2) Check inside the box on the toilet" << endl;
    cout << "3) Search the cabinets below the sink" << endl;
    cout << "4) Search behind the mirror on the wall" << endl;
    cout << "5) Turn around and go back into the bedroom" << endl;
    cout << "6) Open help menu" << endl;
    cout << endl;
    cin >> action; // User will enter their choice from the above choices here

    switch(action){ // Switch statement will execute specific cases based on what the user inputs for the choice they want to make
    case 1:
        cout << "You pull the shower curtain to the side and find a message smeared in blood on the wall of the shower" << endl;
        cout << "The message reads: HELP" << endl;
        cout << "You find nothing else in the shower" << endl;
        cout << "What would you like to do next?" << endl;
        cout << endl;
        moves = moves + 1;
        break;
    case 2:
        cout << "You open the cardboard box that is on the closed toilet seat, but it turns out to be empty" << endl;
        cout << "What would you like to do next?" << endl;
        cout << endl;
        moves = moves + 1;
        break;
    case 3:
        if(flashlight == 0){ // This will execute if the user does not have the flashlight already
            flashlight = 1; // This will give the user the flashlight
            cout << "You open up the cabinets and find them mostly empty except for a flashlight" << endl;
            cout << "You grab the flashlight and place it in your inventory with your other items" << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
        }
        else{
            cout << "You open the cabinets, but since you already took the flashlight, you find them completely empty" << endl;
            cout << "What would you like to do next?" << endl;
            cout << endl;
        }
        moves = moves + 1;
        break;
    case 4:
        cout << "You take the mirror off of the wall and find a large hole behind it" << endl;
        cout << "After searching the hole in the wall, you find nothing of interest" << endl;
        cout << "What would you like to do next?" << endl;
        cout << endl;
        moves = moves + 1;
        break;
    case 5:
        cout << "You turn around and walk back into the bedroom" << endl;
        exitRoom = 0; // When the user leaves the bathroom, they must exit the bathroom loop and go back into the bedroom, which is why the while loop conditional is changed and then the Bedroom function is called
        cout << endl;
        moves = moves + 1;
        Bedroom(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
        break;
    case 6:
        cout << "This is how the game works:" << endl;
        cout << "First, you will be given a small description of your surroundings" << endl;
        cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
        cout << "Each option is labeled with a number" << endl;
        cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
        cout << "After you make that decision, you will then be given a new description" << endl;
        cout << "Then you will then have to make another decision, and so on" << endl;
        cout << "The game is played entirely in number keys" << endl;
        cout << "Do not press anything but number keys or the game will crash" << endl;
        cout << "Your goal is escape the house in the fewest possible moves" << endl;
        cout << "The minimum amount of moves to complete the game is 11" << endl;
        cout << endl;
        moves = moves + 1;
        goto BATHROOMDECISION;
    default: // This will execute if the user enters an option for the choice that does not match one of the previously labeled choices
        cout << "Sorry, I didn't quite understand what you chose" << endl;
        cout << "What would you like to do?" << endl;
        cout << endl;
        moves = moves + 1;
        break;
    }
  }
}

// The escape function will only run once the user has left the living room through the front door
void escape(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves){
    if(flashlight == 0){ // This code will execute if the user does not have the flashlight because they will then fall back into the trap because they cannot see it without the flashlight
        basementDoorLocked = 1; // Every door is relocked and every item is dropped if you fall into the trap
        bedroomDoorLocked = 1;
        bobbyPin = 0;
        screwdriver = 0;
        code = 0;
        hanger = 0;
        crowbar = 0;
        key = 0;
        lights = 0;
        flashlight = 0;
        cout << "You walk out of the front door, but it's too dark outside to see" << endl;
        cout << "You fall into a deep hole set by your captor" << endl;
        cout << "After hours of lying in the hole, you start to get tired" << endl;
        cout << "Eventually you pass out" << endl;
        cout << endl;
        moves = moves + 1;
        // We call the basement function again if you fall into the trap, basically causing you to start the game over
        Basement(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
    }
    else{ // This will execute if the user has the flashlight, which will then cause the game to end
        cout << "You walk out of the front door" << endl;
        cout << "Because you grabbed the flashlight, you are able to see the giant hole in the ground in front of you" << endl;
        cout << "You walk around the trap and escape to safety" << endl;
        cout << endl;
        cout << "Congratulations, you escaped the house in " << moves << " moves!" << endl; // This will output the number of total moves it took for the user to complete the game and escape to safety
    }
}

// This is the instructions code which is just a series of cout statements outlining the rules and concept of the game to the user before they start playing
void instructions(bool bobbyPin, bool screwdriver, bool code, bool hanger, bool crowbar, bool key, bool lights, bool flashlight, bool basementDoorLocked, bool bedroomDoorLocked, int doorCode, int moves){
    int startGame; // These two variables are in this function to make sure that the user does not start the game until they have read all of the rules and understand how the game is played, even though they can still access the help menu through any switch statement
    int understandRules;
    RULES: cout << "Welcome to Escape Room!" << endl;
    cout << endl;
    cout << "You start this game trapped in the basement of a house after being kidnapped" << endl;
    cout << "Your goal is to try to maneuver your way through the house and use the objects througout it to escape" << endl;
    cout << "There are 8 different objects scattered throughout the 5 rooms in the house" << endl;
    cout << "Note that not every item is needed to successfully escape from the house" << endl;
    cout << endl;
    cout << "This is how the game works:" << endl;
    cout << "First, you will be given a small description of your surroundings" << endl;
    cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
    cout << "Each option is labeled with a number" << endl;
    cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
    cout << "After you make that decision, you will then be given a new description" << endl;
    cout << "Then you will then have to make another decision, and so on" << endl;
    cout << "The game is played entirely in number keys" << endl;
    cout << "Do not press anything but number keys or the game will crash" << endl;
    cout << "Your goal is escape the house in the fewest possible moves" << endl;
    cout << "The minimum amount of moves to complete the game is 11" << endl;
    cout << endl;
    READY: cout << "Are you ready to begin?" << endl; // This section checks to make sure the user is ready to start the game and that they have understood all of the rules
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cout << "3) Open help menu" << endl;
    cin >> startGame;
    switch(startGame){
    case 1:
        // This code will execute if the user understands the rules and selects that they are ready to begin the game, which will call the basement function where the game starts
        Basement(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
        break;
    case 2: // If the user says they are not ready to start the game yet, we run them through the rules again by making sure they either understand them or are shown them again
        UNDERSTAND1: cout << "Did you understand the rules?" << endl;
        cout << "1) Yes" << endl;
        cout << "2) No" << endl;
        cout << "3) Open help menu" << endl;
        cin >> understandRules;
        switch(understandRules){
        case 1:
            cout << "Well then what are you waiting for?" << endl;
            cout << endl;
            goto READY;
        case 2:
            cout << "Let's take another look at the rules" << endl;
            cout << endl;
            goto RULES;
        case 3:
            cout << "This is how the game works:" << endl;
            cout << "First, you will be given a small description of your surroundings" << endl;
            cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
            cout << "Each option is labeled with a number" << endl;
            cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
            cout << "After you make that decision, you will then be given a new description" << endl;
            cout << "Then you will then have to make another decision, and so on" << endl;
            cout << "The game is played entirely in number keys" << endl;
            cout << "Do not press anything but number keys or the game will crash" << endl;
            cout << "Your goal is escape the house in the fewest possible moves" << endl;
            cout << "The minimum amount of moves to complete the game is 11" << endl;
            cout << endl;
            goto READY;
        default: // This will execute if the user selects an option that does not match the previously outlined options
            cout << "Sorry, I didn't understand that input" << endl;
            cout << endl;
            goto UNDERSTAND1;
        }
    case 3:
        cout << "This is how the game works:" << endl;
        cout << "First, you will be given a small description of your surroundings" << endl;
        cout << "Next, you will be prompted to make a decision, upon which you will be given a list of options" << endl;
        cout << "Each option is labeled with a number" << endl;
        cout << "To choose the option you want, you will type the label number associated with that decision" << endl;
        cout << "After you make that decision, you will then be given a new description" << endl;
        cout << "Then you will then have to make another decision, and so on" << endl;
        cout << "The game is played entirely in number keys" << endl;
        cout << "Do not press anything but number keys or the game will crash" << endl;
        cout << "Your goal is escape the house in the fewest possible moves" << endl;
        cout << "The minimum amount of moves to complete the game is 11" << endl;
        cout << endl;
        goto READY;
    default: // This will execute if the user selects an option that does not match the previously outlined options
        cout << "I'm sorry, I didn't quite understand that output" << endl;
        cout << endl;
        goto READY;
    }
}

int main(){
    bool bobbyPin = 0; // this variable is passed between funtions to keep track of if the user has the bobby pin or not
    bool screwdriver = 0; //this variable is passed between funtions to keep track of if the user has the screwdriver or not
    bool code = 0; // this variable is passed between funtions to keep track of if the user has the code or not
    bool hanger = 0; // this variable is passed between funtions to keep track of if the user has the hanger or not
    bool crowbar = 0; // this variable is passed between funtions to keep track of if the user has the crowbar or not
    bool key = 0; // this variable is passed between funtions to keep track of if the user has the key or not
    bool lights = 0; // this variable is passed between funtions to keep track of if the lights are on or not
    bool flashlight = 0; // this variable is passed between funtions to keep track of if the user has the flashlight or not
    bool basementDoorLocked = 1; // this variable is passed between funtions to keep track of if the basement door is locked or not
    bool bedroomDoorLocked = 1; // this variable is passed between funtions to keep track of if the bedroom door is locked or not
    int moves = 0;

    srand(time(NULL)); // This randomizes the seed for the random number generator, which will be used to randomize the door code to the bedroom
    int doorCode = (rand() % 900) + 100; // This randomized the door code to the bedroom
    // The instructions function is the only function we need to call in main because from this function on, every function will be called from another function (basement will be called from instructions, living room will be called from basement, etc.)
    instructions(bobbyPin, screwdriver, code, hanger, crowbar, key, lights, flashlight, basementDoorLocked, bedroomDoorLocked, doorCode, moves);
}
