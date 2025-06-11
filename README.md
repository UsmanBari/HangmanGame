# 🪓 Hangman SFML Game

A graphical twist on the classic **Hangman** word-guessing game built in **C++** with **SFML**. Guess the word letter by letter before the full stickman is drawn — or it’s game over!

![Language](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square)
![Framework](https://img.shields.io/badge/SFML-2.5-green?style=flat-square)
![Status](https://img.shields.io/badge/Status-Completed-purple?style=flat-square)
![License](https://img.shields.io/badge/License-Educational-lightgrey?style=flat-square)

---

## 🧠 Features

- 📝 Randomly selected words from a preset list of 50
- 🧍 ASCII-style stickman rendered as you lose lives
- ⌨️ Real-time keyboard input via SFML events
- 🧩 Word progress displayed with blanks and revealed letters
- ☠️ Game-over and win message handling


---

## 🛠 Requirements

- C++17 or later
- SFML 2.5+
- `arial.ttf` font file (must be in the executable directory)

---

## ⚙️ How to Compile

### On Linux:

```bash
sudo apt install libsfml-dev
g++ hangman.cpp -o hangman -lsfml-graphics -lsfml-window -lsfml-system
./hangman
```

### On Windows:

- Install [SFML](https://www.sfml-dev.org/)
- Use **Visual Studio**, **Code::Blocks**, or **MinGW**
- Link required SFML libraries
- Place `arial.ttf` next to your `.exe`

---

## 📂 Files Included

```
hangman.cpp      # Main source code
arial.ttf        # Required font (user must add manually)
README.md        # Game info and instructions
```

---

## 👨‍💻 Developer

- **Muhammad Usman Bari** 

---

## 📝 License

This project is for **educational and personal use only**. Third-party assets (fonts, etc.) must be legally obtained and used under their respective licenses.

---

> 🎮 A fun take on Hangman — now with GUI and purple-code vibes.
