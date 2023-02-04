#include <sstream>

#include "grid.h"
#include "robot.h"

int main()
{
    // Create the robot toy that will traverse the grid.
    std::unique_ptr<IEntity> pRobot(new CRobot("iRobot"));
    
    // Create the 5x5 grid, but don't place the robot inside it yet.
    CGrid grid(5, 5);
    
    // Show some instructions to the user on how to play the game.
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << "HOW TO PLAY:"                                                                         << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Type the command(s) listed below exactly as they appear and press enter in order to"  << std::endl;
    std::cout << "issue instructions to the robot."                                                     << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << "COMMANDS:"                                                                            << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    std::cout << "place(x, y, facing) - Place the robot in specified location and facing direction"     << std::endl;
    std::cout << "                      x: integer"                                                     << std::endl;
    std::cout << "                      y: integer"                                                     << std::endl;
    std::cout << "                      facing: string that is one of (north, east, south, or west)"    << std::endl;
    std::cout << "move()              - Moves the robot 1 grid unit in the direction it is facing,"     << std::endl;
    std::cout << "                      unless that movement will cause the robot to fall off."         << std::endl;
    std::cout << "left()              - Rotate the robot 90 degrees counter-clockwise."                 << std::endl;
    std::cout << "right()             - Rotate the robot 90 degrees clockwise."                         << std::endl;
    std::cout << "report()            - Output the robot's current grid location and facing direction." << std::endl;
    std::cout << "quit()              - Quit the application."                                          << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
    
    // While the user has not quit the game continue playing indefinitely.
    while(true)
    {
        // Grab input form the user.
        std::string strInput;
        std::cout << "Command: ";
        std::getline(std::cin, strInput);
        
        // The application should discard all commands until a valid place() command has been executed.
        if(strInput.find("place(") != std::string::npos && strInput.find(")") != std::string::npos)
        {
            // Extract the arguments between the brackets (arg1, arg2, arg3, etc.)
            std::vector<std::string> vecArgs;
            std::stringstream strArgs(strInput.substr(strInput.find('('), strInput.find(')')));
            std::string strToken;
            
            // Split the string by function arguments and erase anything that's not a letter or a number.
            while(std::getline(strArgs, strToken, ','))
            {
                strToken.erase(std::remove_if(strToken.begin(), strToken.end(), [](unsigned char x){ return(!std::isalnum(x)); }), strToken.end());
                vecArgs.push_back(strToken);
            }
            
            // We expect there to be three arguments as follows place(x, y, facing).
            if(vecArgs.size() == 3)
            {
                pRobot->Place(grid.GetCell(TVec2<uint32_t>{static_cast<uint32_t>(std::stoi(vecArgs[0])), static_cast<uint32_t>(std::stoi(vecArgs[1]))}), IEntity::ConvertStringToDirection(vecArgs[2]));
            }
            else
            {
                std::cout << "ERROR: Ensure the arguments are as follows place(x, y, facing)." << std::endl;
            }
        }
        else if(strInput == "move()")
        {
            pRobot->Move();
        }
        else if(strInput == "left()")
        {
            pRobot->RotateLeft();
        }
        else if(strInput == "right()")
        {
            pRobot->RotateRight();
        }
        else if(strInput == "report()")
        {
            pRobot->Report();
        }
        else if(strInput == "quit()")
        {
            break;
        }
        else
        {
            std::cout << "ERROR: Invalid commands given!" << std::endl;
        }
    }
    
    return(0);
}
