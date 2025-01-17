# Libft

So_long is my first graphic project! It's a game where you need to collect all coins, reach the exit with the fewest possible movements, and avoid enemies (in the bonus version).

My so_long project is divided into two parts:

   * Mandatory: A simple game with basic sprites.
   * Bonus: Includes animations and enemies for an extra challenge.

Keep reading to learn how to play the game!

> **Note:** Some functions rely on `<unistd.h>`, so this code is not compatible with Windows.

## How to Compile

1. Clone the repository:
   ```bash
   git clone https://github.com/lhenriqu42/so_long
   ```

2. Navigate to the repository folder:
   ```bash 
   cd so_long
   ```

3. Compile for the Mandatory Version:
   ```bash
   make
   ```
   This generates the so_long executable for the mandatory version.

4. Compile for the Bonus Version:
   ```bash
   make bonus
   ```
   This generates the so_long_bonus executable for the bonus version.

## How to play

1. Run the executable with the desired map file as an argument. For example:
   ```bash
   ./so_long /maps/test.ber
   ```
   Or for the bonus version:

   ```bash
   ./so_long_bonus maps/bonus.ber
   ```

## Map Creation Rules

To create your own maps, you need to use a file with the .ber extension.

The map must follow these rules:

    '1': Wall
    '0': Floor
    'C': Coins
    'P': Player's starting position (must be unique)
    'E': Exit position (must be reachable after collecting all coins)

For the bonus version, you can also include:

    'K': Enemy positions

Ensure your map is valid and follows the game logic before playing!
