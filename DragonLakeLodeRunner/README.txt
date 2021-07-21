Hello!

Your task is to implement *simple* Lode Runner game
(please, see Lode Runner (1983) game for a reference if you like - https://www.youtube.com/watch?v=72k1ZYp83tc).

Game reference - https://strategywiki.org/wiki/Lode_Runner

Gameplay

- The player controls a character who must collect all the gold pieces in a level and get to the end while being chased by a number of enemies
- The player can dig holes into floors to temporarily trap guards and may safely walk atop trapped guards. Should a guard be carrying a bar of gold when he falls into a hole it will be left behind, and can be retrieved by the player. Over time, floors dug into will regenerate, filling in these holes. A trapped guard who cannot escape a hole before it fills is consumed, immediately respawning in a random location at the top of the level. Unlike guards, the player's character may not climb up out of a hole, and will be killed if it fills before he can escape by other means
- Floors may contain trapdoors, through which the player and guards will fall, and bedrock, through which the player cannot dig.
- The player starts with five lives; each level completion awards an extra life. Should a guard catch the player, one life is subtracted, and the current level restarts. The player's character can fall from arbitrary heights without any injury but cannot jump, and players can trap themselves in pits from which the only escape is to abort the level, costing a life, and begin again.
- The guards do not always take the shortest path to the player, but can also move in counterintuitive ways. Sometimes, when the player and a guard are on the same ladder, for instance, the guard will move away from the player.

Note: it is not required to make level switching for this task (only one game level is enough). However, you can make more if you want.

Controls

You control the main character with a keyboard and mouse:
  - Left/Right buttons - move left or right
  - Up/Down buttons - use ladders
  - Mouse LeftButton - dig a hole right/left depending on player's direction
  - Mouse LeftButton + keyboard Left/Right buttons - dig a hole left/right to the character

Assets

Assets for the game may be found here - https://www.spriters-resource.com/nes/loderunner/

Technical Requirements

Window size should be possible to set from the command-line, e.g.:

game -window 800x600 

Functionality provided by Framework should be enough to do all required drawing. You can load TGA, JPG and PNG images as sprites with it.
Please, see example project for a template implementation. When implementing application take special care about performance and memory usage.

Try to use data oriented programming approach.

In case of any questions please contact: l.kholodov@dragonlk.com

Good luck!
Bye.

--
