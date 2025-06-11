#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

// Constants for the grid
const int resolutionX = 640;
const int resolutionY = 640;
const int boxSize = 64;

// Maximum lives and word list
const int MAX_LIVES = 6;
const string wordList[50] = {
    "apple", "table", "grape", "brush", "cream", "house", "heart", "bread", "dream", "light",
    "stone", "plant", "chair", "river", "cloud", "piano", "money", "grass", "scale", "flame",
    "paper", "pearl", "glass", "space", "clock", "mouse", "crowd", "drama", "water", "flute",
    "white", "smile", "shape", "blood", "round", "dance", "block", "plaza", "store", "beach",
    "shade", "horse", "shine", "ocean", "fruit", "plume", "dance", "sword", "vocal", "wings"
};

// Hangman class
class HangmanGame {
private:
    string wordToGuess;
    bool guessedLetters[50] = { false };
    int lives;
    string currentGuess;
    string displayedWord;

    // Draw hangman parts based on lives
    void drawHangman(sf::RenderWindow& window, sf::Font& font) {
        sf::Text hangmanText;
        hangmanText.setFont(font);
        hangmanText.setCharacterSize(40);
        hangmanText.setFillColor(sf::Color::Red);

        switch (lives) {
        case 5: hangmanText.setString("O"); break; // Head
        case 4: hangmanText.setString("O\n |"); break; // Body
        case 3: hangmanText.setString("O\n/|"); break; // One arm
        case 2: hangmanText.setString("O\n/|\\"); break; // Both arms
        case 1: hangmanText.setString("O\n/|\\\n/"); break; // One leg
        case 0: hangmanText.setString("O\n/|\\\n/ \\"); break; // Both legs
        }

        hangmanText.setPosition(10, 10);
        window.draw(hangmanText);
    }

    // Update displayed word
    void updateDisplayedWord() {
        displayedWord = "";
        for (size_t i = 0; i < wordToGuess.length(); i++) {
            if (guessedLetters[i]) {
                displayedWord += wordToGuess[i];
            }
            else {
                displayedWord += "_";
            }
            displayedWord += " ";
        }
    }

    // Check if all letters are guessed
    bool isWordGuessed() {
        for (size_t i = 0; i < wordToGuess.length(); i++) {
            if (!guessedLetters[i]) return false;
        }
        return true;
    }

    // Process a player's guess
    void processGuess(char guess) {
        bool correct = false;
        for (size_t i = 0; i < wordToGuess.length(); i++) {
            if (tolower(wordToGuess[i]) == tolower(guess) && !guessedLetters[i]) {
                guessedLetters[i] = true;
                correct = true;
            }
        }
        if (!correct) lives--;
    }

public:
    HangmanGame() : lives(MAX_LIVES) {
        srand(static_cast<unsigned>(time(0)));
        wordToGuess = wordList[rand() % 50];
        updateDisplayedWord();
    }

    void run() {
        sf::RenderWindow window(sf::VideoMode(resolutionX, resolutionY), "Hangman Game");
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            cerr << "Error: Could not load font!" << endl;
            return;
        }

        sf::Text wordText, messageText, livesText;
        wordText.setFont(font);
        wordText.setCharacterSize(30);
        wordText.setFillColor(sf::Color::White);
        wordText.setPosition(100, 500);

        messageText.setFont(font);
        messageText.setCharacterSize(24);
        messageText.setFillColor(sf::Color::Yellow);
        messageText.setPosition(100, 550);

        livesText.setFont(font);
        livesText.setCharacterSize(24);
        livesText.setFillColor(sf::Color::White);
        livesText.setPosition(500, 20);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::TextEntered && lives > 0 && !isWordGuessed()) {
                    char guess = static_cast<char>(event.text.unicode);
                    if (isalpha(guess)) {
                        processGuess(guess);
                        updateDisplayedWord();
                    }
                }
            }

            // Update visuals
            wordText.setString("Word: " + displayedWord);
            livesText.setString("Lives: " + to_string(lives));

            if (isWordGuessed()) {
                messageText.setString("Congratulations! You guessed the word!");
            }
            else if (lives <= 0) {
                messageText.setString("Game Over! The word was: " + wordToGuess);
            }

            window.clear(sf::Color::Black);
            drawHangman(window, font);
            window.draw(wordText);
            window.draw(messageText);
            window.draw(livesText);
            window.display();
        }
    }
};

int main() {
    HangmanGame game;
    game.run();
    return 0;
}
