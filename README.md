# CPPND: Capstone TileMiner

This is the capstone project for Udacity CPP ND. TileMiner is a super basic mining simulation that uses threads to mine a tile map that's 9x9 big. Each square is one tile and is an available spot for one block. Blocks are basically the miners. Tiles can be `grass`, `iron`, `copper`, `stone`, or `coal`. Grass tiles are not available for placing a block and has the capacity of 0.

Each time you run the `./tileminer`, program will generate a random set of 9x9 tiles with random capacity, place a block to available spots and start mining the tiles. Mining rate is also a random number that changes each run. In the output, you'll see something similar to this line which indicated the current operation on tiles.

```
Mining... block id: 5 | tile id: 5		cap: 458		out: 61		stored: 610
```

That's all so far. I do realise the interface for this isn't the best and the general status can be improved. With the limited time I have this September, this is the best I can do at the moment.

All the best.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./tileminer`.
