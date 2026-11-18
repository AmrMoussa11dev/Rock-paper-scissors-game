# ✊Rock Paper Scissors Game (C++)

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B)
![Platform](https://img.shields.io/badge/Platform-Console-lightgrey?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

An interactive, console-based Rock, Paper, Scissors game built in C++[span_0](start_span)[span_0](end_span). This project simulates the classic hand game between a human player and a computer opponent, focusing on clean code architecture, modular design, and user-friendly console interaction.

---

## 📖 Overview
This project was developed to apply and reinforce core C++ and Structured Programming principles. Rather than writing all logic in a single block, the game is broken down into small, reusable, and single-responsibility functions.

### 🧠 Core Concepts Applied
- Modular Programming: Separating game logic, UI rendering, and score tracking into dedicated functions.
- **Enumerations (enum):** Enhancing code readability and type safety for game choices and round winners.
- **Structures (struct):** Grouping round and final game statistics cleanly.
- Control Flow: Utilizing loops and conditional statements (if-else, switch) for game progression.
- Randomization: Using rand() and srand() to generate unpredictable computer moves.
- Input Validation: Ensuring the user enters valid choices and round numbers without crashing the program.

---

## 🚀 Key Features
- Customizable Match Length: Choose between 1 to 10 rounds per match.
- Smart Console Feedback: Clear, formatted round summaries showing both player and computer choices, round winner, and visual color/sound cues (if supported by OS).
- Real-Time Score Tracking: Keeps accurate count of Player Wins, Computer Wins, and Draws.
- Replayability: Option to start a new match immediately after viewing the final game-over summary.

---

## 🎮 How It Works
1. Setup: Enter the desired number of rounds (1 to 10).
2. Gameplay Loop: 
   - Select your move: [1] Stone, [2] Paper, or [3] Scissors.
   - The computer randomly selects its move.
   - The round winner is evaluated and displayed instantly.
3. Final Summary: Once all rounds conclude, a comprehensive Game Over screen displays total rounds, individual win counts, draws, and the overall champion.

---

## 🛠️ How to Run Locally
1. Clone the repository:
   `bash
   git clone [https://github.com/AmrMoussa11dev/Rock-paper-scissors-game.git](https://github.com/AmrMoussa11dev/Rock-paper-scissors-game.git)
