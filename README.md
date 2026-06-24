# The Lost Kite

A Computer Graphics assignment project built in `C` and `FreeGLUT` for Assignment 2. This story-driven animation showcases custom rendering algorithms, animated scenes, and teamwork across five members.

## Project Overview

**The Lost Kite** is an animated graphics application that plays through a sequence of scenes featuring:
- sunrise and sunset backgrounds
- moving clouds and birds
- a child flying and searching for a kite
- rain and thunder effects
- animated kite motion and scene transitions
- final credit display

The project uses custom Bresenham line and circle drawing techniques together with FreeGLUT rendering.

## Key Features

- Custom Bresenham line renderer for pixel-aligned drawing
- Bresenham-based circle drawing and filled primitives
- Modular scene design with 10 animated scenes
- Time-based animation and transition control
- Keyboard handling for scene control and exit
- Window resizing with orthographic projection adaptation

## Technologies Used

- `C`
- `OpenGL` / `FreeGLUT`
- `Bresenham` rasterization algorithms
- 2D animation and rendering

## Files

- `main.c` — application entry point, window setup, and main loop
- `lost_kite.h` — shared definitions, globals, and function declarations
- `member1.c` — Bresenham rendering, primitives, and core display/timer logic
- `member2.c` — circle rendering, child, clouds, mountains, initial scenes
- `member3.c` — kite rendering, thunderbolt, mid-game scenes
- `member4.c` — bird, tree, rain, later scenes
- `member5.c` — interpolation helper and final scenes
- `The lost kite.mp4` — demo video of the animation

## Member Roles

- **Member 1**: Implemented the core rendering and animation framework, including Bresenham line drawing, basic primitives, scene management, timing, and input handling.
- **Member 2**: Built circle rendering, character drawing, environment elements, and early scene composition.
- **Member 3**: Added kite and thunderbolt artwork plus additional scene logic.
- **Member 4**: Created birds, trees, rain effects, and later animation scenes.
- **Member 5**: Implemented interpolation, final scene transitions, and title/credit display.

## Build and Run

### Requirements

- `gcc` or another C compiler
- `FreeGLUT` development libraries
- OpenGL support

### Example build command (Windows)

```bash
gcc main.c member1.c member2.c member3.c member4.c member5.c -lfreeglut -lopengl32 -lglu32 -o lost_kite.exe
```

### Run

```bash
lost_kite.exe
```

### Controls

- `Esc` — exit the application
- `Space` or `Enter` — advance to the next scene or restart

## Notes

- The project is designed for educational use and demonstrates core graphics concepts from the Computer Graphics module.
- The animation uses a manual rendering pipeline rather than modern shaders.

## License

Feel free to use this project for portfolio purposes and coursework demonstration.
