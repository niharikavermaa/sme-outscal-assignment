# SME-Assignment
Space invader test

Target - To find all the bugs and enable the game to run 

Part 1 - Setting up your Project 
    Took around 20 minutes to execute this.
    This was the initial stage of the project where I was supposed to setup my project.
    Here, I was supposed to fork and clone the given repository to my local device to use it further.
    And the next step of this part was to add the SFML files to my project by following the given setup guide.

Part 2 - Bug Fixing
    In this step, the code was unable to run for which I had to find a deliberate bug in the code which was causing the issue for the same. 
    The bug was in PlayerController.h, the path is mentioned below :-
    space invasion -> header -> Player -> PlayerController.h

    To solve the issue, I just had to define the two class as :-
    "class PlayerModel; " and "class PlayerView; ". 
    I did this because the two classes were being accessed by the file without being defined in the file.
    Line 10 and 11 added to the same file.


Part 3 – Small Improvements 
    Here, I added the processBuletfire() function to the PLayerController.cpp
    The Event Left mouse Click demands a bullet fire.
    Defined a function processBulletFire() under the file PlayerController.h file and Playercontroller.cpp
    spawnParticleSystem() function is called by this fucntion in the ParticleSystem. 
    The Bullet is initialiased at the starting point which is the current location of the player.
    Called a bullet fire sound effect from the Global -> ServiceLocator.cpp.
    Therefore, the aim of this step was to add bullets.

