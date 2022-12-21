# Autocli

AutoCLI is a command line-based automation and programming game similar to games
like Screeps, Factorio, and Satisfactory, in which the player must create,
manage, and defend a factory run by programmable robots.

## Features

* Goal / Resource Sink
  1. infinite research
  2. increasing external demands
  3. end-goal that requires an exorbitant amount of resources
  The first two allow for a game to go on for as long as the player wishes, as
  resource demands should scale with the increased output, so I'd like to do
  one or both of those two, rather than the third one.

* Robots
  * The main force driving the factory
  * Start only able to do simple tasks, but can be upgraded to do more:
    * Increased memory capacity
    * Increased number of possible jobs
    * Increased battery life
    * Durability, speed, efficiency
  * Robots given orders using player-made Lua scripts

* Scripting
  * Ideally only the bare minimum to fully interact with the world should be
  provided. More complex functionality like pathfinding should be implemented
  by the player themselves.

* Trains / boats for longer-distance mass transport

* Setting
  * Due to CLI graphics, perhaps it'd be best to simply set it in an abstract
  void or something?
  * Maybe a Screeps-like approach where it appears to be some sort of cave
  * Should there be enemies? What is the source of the conflict?
    * In Factorio, they attack due to our polution, and they get stronger from
    it as well
    * Screeps's conflict is from conflict between two players due to limited
    space and resources

* Graphics / Appearance
  * To be played on the command line, and thus would use ASCII for graphics
  * Perspective is top-down like Screeps and Factorio and unlike Satisfactory
    * No way am I making a 3D CLI-based engine, nor does a platformer seem the
    best choice here

* Controls
  * vim-like bindings would make sense, considering this is a mouseless game
    * but it'd isolate players who've never used vim, so perhaps have a normal
    wasd-based movement scheme and a toggleable vim-like scheme, as well as full
    control over all keybinds for those who prefer something else entirely

* Perhaps no player character, but instead just a floating camera akin to
Factorio's map view

## Back-end Design

* Entities stored in chunks to more quickly find necessary entities
