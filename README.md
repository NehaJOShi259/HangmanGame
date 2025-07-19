🎮 Hangman Game in C++

This is a command-line Hangman game built in C++ using basic object-oriented programming concepts. The game selects a random fruit name from a list, and the player has limited chances to guess the word correctly. For every incorrect guess, a part of the hangman figure is drawn using ASCII art.

---

✅ Features

- 🔤 Random fruit name selection
- 🎯 Tracks correct and incorrect guesses
- 🔁 Repeated guess detection
- 🖼️ ASCII art of Hangman shown after each wrong guess
- ❌ Ends when attempts are over or word is guessed
- 🧱 Written using basic OOP (class and object)

---

🧠 Concepts Used

- C++ Classes & Objects  
- String and Character handling  
- Loops and Conditionals  
- Vectors from STL  
- ASCII Art  
- Basic I/O using `cin` and `cout`

---

📁 File Structure

| File         | Description                        |
|--------------|------------------------------------|
| `hangman.cpp` | Contains the complete game logic   |

---

🚀 How to Run

🔹 Option 1: Using Terminal (Linux/macOS/Windows with g++)

```bash
git clone https://github.com/NehaJOShi259/hangman-game-cpp.git
cd hangman-game-cpp
g++ -o hangman hangman.cpp      # compile
./hangman                       # run (Windows: hangman.exe)
