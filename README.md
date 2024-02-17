# So Long

## Description
So Long is an engaging 42 project where you create a game using the MinilibX library. Explore graphics, handle events, and navigate through challenges. Immerse yourself in C programming and game development within the 42 ecosystem.

## Features
- Game development using MinilibX
- Graphics rendering and event handling
- Challenges and interactive gameplay
## Game Rules
### Objective

The goal of So Long is to navigate the player character through the game map, collecting designated items, and reaching the exit.

### Player Controls
- Move Up: Press the up arrow key to move the player character upward.
- Move Down: Press the down arrow key to move the player character downward.
- Move Left: Press the left arrow key to move the player character to the left.
- Move Right: Press the right arrow key to move the player character to the right.
- Exit Game: Press the ESC key or Q to exit the game.

### Interaction
- Collectibles: Collect all designated items to unlock the exit.
- Exit: Reach the exit to complete the level.

## Map Rules
- Walls (1): Represented by the character 1, walls define the boundaries of the game. The player and entities cannot move through walls.
- Empty Space (0): Represented by the character 0, empty spaces are areas where the player and entities can move freely.
- Collectibles (C): Collectibles, denoted by the character C, are items that the player can collect to achieve certain objectives or score points.
- Exit (E): The exit, represented by the character E, is a location the player must reach to complete the level.
- Player (P): The player's starting position is marked by the character P. The player can move in different directions to navigate the map.

## Usage
# Libraries needed in linux system: xext, x11, lbsd.
1. Clone this repository: 
```bash
git clone https://github.com/manugonz42/So_long.git so_long
```
2. Navigate to the project directory:
Mac:
```bash
cd so_long
```
Linux:
```bash
cd so_long/so_long_linux
```
3. Compile the project:
```bash
make
```
4. Run the game with the provided map or customize as needed.

## Example
### Map Example

1111111111111<br>
100000C0000C1<br>
1C00111111001<br>
1P0011E000001<br>
1111111111111<br>
### Execution
```bash
./so_long assets/maps/valid/map3.ber
