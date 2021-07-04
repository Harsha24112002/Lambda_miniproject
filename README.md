# Lambda_miniproject
# Game inspired from Space Invaders
# Installing the Game
- Clone this repository-
- Make sure you have a g++ compiler.
- Maku sure you have installed the SFML library. If you don't have one, download from
[here](https://www.sfml-dev.org/download.php)
- Build this using the makefile by making necessary changes to SFML library location in the makefile.
- If SFML is installed in the standard path, you can just run by 
> ./Game
- If not, 
> export LD_LIBRARY_PATH=(sfml-install-path)/lib && ./Game
# About the Game
##  Introduction
- It supports **single** and **dual** player mode.
- The game runs on a full screen mode.
- It has attributes for the player like health,score.
- There are some **Powerups** for the players.
- It has a liitle bit of animation for explosion.

## GAME
- There will be enemies moving right and left continuously and firing at you.
- You have to escape from the bullets of enemies and simultaneously kill them.
- When both player bullet and enemy bullet collide they get destroyed.
- The health bar corresponds to three collisions,meaning if you are hit by three bullets without picking any powerups, *GAME ENDS*.
- Score is put to zero after end of every level.

## EXITING THE GAME

- You can press Exit(at Mainmenu) to closs the application.
- To pause in middle of a level press:
>Escape key
- You have an option to Exit into the Mainmenu from the Pause menu.

## Single Player Mode:

###### Controls
- For moving player left press :
> Left arrow key 
- For moving player Right press :
> Right arrow key 
- For firing press :
> Spacebar

## Dual Player Mode:
###### Controls for *Player 1*
- For moving player left press :
> Left arrow key 
- For moving player Right press :
> Right arrow key 
- For firing press :
> Spacebar
###### Controls for *Player 2*
- For moving player left press :
> A 
- For moving player Right press :
> D
- For firing press :
> Q

- Health bars and scores are in the color of respective players.
- In this mode, if anyone of the player dies he gets revived automatically into the game after sometime(Atleast one should be alive till then), but his score is again put to zero.


## About Powerups
- There are three powerups which fall randomly during the game play
- **SHIELD** -> It acts as shield against enemybullets.(Shield shaped Powerup)
- **INVISIBILITY** -> It makes the player invisible(visible to us with more transparency) to the enemies, thereby making them stopping to fire.(Circle shape powerup)
- **HEAL** -> It fills the health bar.(Heart shaped powerup)





