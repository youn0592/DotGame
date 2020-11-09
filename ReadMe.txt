Game and Graphics II - A4 - Dot Game.
Christian Young
Novemember 8th 2020

Level Transitions:
	-Player and Enemies Freeze.
	-ImGui pop up telling player they beat the level and which level they beat.
	-Arena Shrinks for 2 seconds.
	-After the 2 seconds, Player and Enemies unfreeze, and play continues.

Enemies:
	-Green Enemies knows the players position at spawn and moves at that direction. 
	-Yellow Enemies know the players position at spawn and moves at that direction, increasing in speed while alive.
	-White Enemies know the players position at spawn and moves at that direction, in a SineWave motion.
	-Enemy is selected randomly when spawning.
	-When Playing Levels Gamemode, enemies will get added as the player progresses through the game.
	-Green Enemies only spawn in Level 1.
	-Green Enemies and Yellow Enemies only spawn in Level 2.
	-All Enemies spawn in levels 3 - 5.

Main Menu:
	-Added a Main Menu system through ImGui.
	-Game is frozen until the player selectes which Gamemode they want to play.
	-Player can return to Main Menu whenever they want while playing the game by hitting 'M' on their Keyboard.

Gamemodes:
		Levels:
			-If player survives for 5 seconds, Level will transition to the next level.
			-If the player beats 5 levels, they will have won the game and be presented with a win.
			-Arena will shrink as player progresses.
			-On Lost ImGui pop up will tell the player which level they made it too. 

		Survival:
			-There is no win state for this gamemode.
			-Player now has a timer in the ImGui to see how long they've survived for, and pops up with the you lost popup.
			-All Enemies are active from the begining of Survival.
			-Arena does not shrink, and stays at its Level 1 size.

Player:
	-Player has a boost feature, pushing Shift on the keyboard will allow the player to move faster.
		