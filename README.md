# learning_project
# Space Mission Game (C)

A simple terminal-based space survival game written in C.
Your mission is to safely navigate through space and reach Earth while managing critical resources.

---

## Gameplay Overview

You are the commander of a spaceship trying to reach Earth.

You must manage:

* Fuel
* Oxygen
* Health

Make the right decisions in random events to survive and complete your mission.

---

## Objective

Reach a **distance of 100** while keeping:

* Fuel > 0
* Oxygen > 0
* Health > 0

---

## Game Features

* Decision-based gameplay (3 choices per event)
* Random events (no repetition back-to-back)
* Level progression system:

  * Level 1 → Easy
  * Level 2 → Medium
  * Level 3 → Hard
* Level-up bonus rewards
* Final mission report (win/lose analysis)

---

## How to Play

1. Run the program
2. Choose **Start Mission**
3. For each event:

   * Enter `1`, `2`, or `3`
4. Try to survive and reach distance 100

---

## How to Run

### Compile:

```bash
gcc game.c -o game
```

### Run:

```bash
./game
```

---

## File Structure

```
main_code.c        # Main game source code
README.md          # Project documentation
```

---

## Future Improvements

* Add graphics (using SDL/OpenGL)
* Save/load game progress
* Sound effects
* Better UI design
* Difficulty selection

---

## License

This project is open-source and free to use.
