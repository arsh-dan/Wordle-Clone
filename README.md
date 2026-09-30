# Terminal Wordle

A command-line clone of the popular word-guessing game **Wordle**, written in C++. A random 5-letter word is picked from a word list, and you have 5 attempts to guess it. After every guess, each letter is colour-coded to tell you how close you are.

## Features

- Random target word chosen from an external dictionary file
- Colour-coded feedback using ANSI escape codes
- Input validation (guesses must be exactly 5 letters)
- Case-insensitive input (`crane`, `CRANE`, and `Crane` all work)
- Play-again loop so you can keep playing without restarting the program

## How to Play

1. The game picks a secret 5-letter word.
2. Type a 5-letter guess and press **Enter**.
3. Each letter is coloured based on your guess:

| Colour | Meaning |
|--------|---------|
| 🟩 **Green** | The letter is in the word and in the **correct position** |
| 🟨 **Yellow** | The letter is in the word but in the **wrong position** |
| ⬜ **Gray** | The letter is **not** in the word |

4. You have **5 attempts**. Guess the word before they run out to win.
5. At the end of a round, enter `y` to play again or anything else to quit.

### Example Session

```
=== TERMINAL WORDLE ===
Type a 5-letter word and press Enter.

Guess (5 left): crane
CRANE            <- each letter is coloured in the terminal

Guess (4 left): slate
...
```

## Requirements

- A C++ compiler with C++11 support or later (e.g. `g++`, `clang++`, MSVC)
- A terminal that supports ANSI colour codes (most Linux/macOS terminals and Windows Terminal do)
- A word list file named `wordle-answers-alphabetical.txt` in the same directory as the executable

## Word List Format

The dictionary file must contain **one 5-letter word per line**:

```
aback
abase
abate
abbey
...
```

Words are converted to uppercase automatically when loaded. A common source for this list is the publicly available Wordle answers list on GitHub.

## Building and Running

**Compile:**

```bash
g++ wordle.cpp -o wordle
```

**Run (Linux / macOS):**

```bash
./wordle
```

**Run (Windows):**

```bash
wordle.exe
```

> Make sure `wordle-answers-alphabetical.txt` is in the folder you run the program from, otherwise the game will exit with a "Could not find" error.

## Project Structure

```
.
├── wordle.cpp                       # Game source code
├── wordle-answers-alphabetical.txt  # Dictionary of possible answers
└── README.md
```

## How It Works

| Function | Purpose |
|----------|---------|
| `LOADDICTIONARY()` | Reads the word file line by line, converts each word to uppercase, and stores it in a `vector<string>` |
| `GETRANDOMWORD()` | Picks a random word from the dictionary using `rand()` seeded with the current time |
| `VALIDATEINPUT()` | Checks that the guess is 5 letters long and converts it to uppercase |
| `CHECKGUESS()` | Compares the guess to the target and prints each letter in green, yellow, or gray |
| `main()` | Runs the game loop: loads the dictionary, handles attempts, win/lose messages, and replay |

## Known Limitations and Future Improvements

- Repeated letters: a letter that appears more than once in a guess may be marked yellow even if the target only contains it once, unlike the official Wordle rules.
- Guesses are not checked against a list of valid English words, so any 5-character string is accepted.
- Non-letter characters (numbers, symbols) are not rejected.
- Possible additions: a separate list of allowed guesses, a keyboard letter tracker, a win-streak counter, and difficulty modes.

## Author

Created by Arsh as a C++ practice project.

## License

Free to use and modify for learning purposes.
