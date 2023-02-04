**HOW TO RUN:**  
Download the files and add them to a project solution of an IDE of your choice (e.g., Visual Studio, Xcode, etc.) All code is written and compliant to C++14 with no external dependencies. Build/run and you should see a command prompt where you can play the game and issue commands to the robot with some basic instructions printed to the user. The code is fairly lightweight with comments added where appropriate.

**SOME ASSUMPTIONS MADE:**  
1.	Only one robot can be placed on the grid and manipulated via commands, however the code can easily be extended so that each cell has an std::list of robotic entities that can be added and removed from each cell on the grid. The grid has also been made so that it can be extended to a smaller or a larger size.
2.	All commands are case-sensitive, that is, they must be typed as displayed in the terminal with the only exception being the four cardinal facing directions (north can be North/NORTH/NOrth/NorTH, etc.)
3.	The brief didn’t mention anything regarding a quit() command so that was added so the user can exit the application at will. Otherwise, all commands are discarded until a valid place() command has been issued first as per requirement.
4.	If a command has failed, visual output is displayed describing the failure. On success, a new line with the text “Command:” is printed to the user indicating that the last command succeeded and they can issue a new instruction for the robot.
