# Building "The Lost Kite" with MSYS2 MINGW64

## MSYS2 MINGW64 Setup & Dependencies

### 1. Install Required Packages in MSYS2 MINGW64

Open **MSYS2 MINGW64** terminal and run:

```bash
# Update package database
pacman -Syu

# Install MinGW64 compiler and build tools
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make

# Install FreeGLUT development files (includes OpenGL headers)
pacman -S mingw-w64-x86_64-freeglut

# Install pkg-config for library detection
pacman -S mingw-w64-x86_64-pkg-config
```

### 2. Verify Installation

Check that the compiler and libraries are installed:

```bash
gcc --version
pkg-config --cflags --libs glut
```

## Compilation Commands

### Option A: Direct Compilation (Single Command)

```bash
# Compile all source files and link with OpenGL/FreeGLUT libraries
gcc -o the_lost_kite.exe main.c member1.c member2.c member3.c member4.c member5.c \
  -I. $(pkg-config --cflags glut) $(pkg-config --libs glut) \
  -lm -std=c99 -Wall -Wextra
```

### Option B: Using a Makefile

Create a file named `Makefile` in the project directory:

```makefile
# The Lost Kite - Makefile for MSYS2 MINGW64
# Build with: make
# Clean with: make clean
# Run with: make run

CC = gcc
CFLAGS = -I. -std=c99 -Wall -Wextra
LDFLAGS = $(shell pkg-config --cflags --libs glut) -lm
TARGET = the_lost_kite.exe

SOURCES = main.c member1.c member2.c member3.c member4.c member5.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c lost_kite.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean
```

Build with:
```bash
make          # Compile
make run      # Compile and run
make clean    # Remove compiled files
```

## Running the Application

After successful compilation, run:

```bash
./the_lost_kite.exe
```

**Controls:**
- **ESC** - Exit the application
- **SPACE** or **ENTER** - Advance to next scene (or restart if on last scene)

## Troubleshooting

### Issue: "glut.h: No such file or directory"
- **Solution**: Ensure FreeGLUT is installed: `pacman -S mingw-w64-x86_64-freeglut`
- Verify: `pkg-config --cflags glut` should return a path like `-IC:/msys64/mingw64/include`

### Issue: "undefined reference to `glutInit`"
- **Solution**: Check that glut libraries are linked: `pkg-config --libs glut`
- Should include `-lfreeglut` or `-lglut`

### Issue: Compiler not found
- **Solution**: Ensure you're in the MINGW64 terminal (not MSYS2 base)
- Verify MinGW64 gcc: `gcc --version` should show `x86_64-w64-mingw32`

### Issue: "make: command not found"
- **Solution**: Install make: `pacman -S mingw-w64-x86_64-make`

## Code Comments for main.c

Add these comments to [main.c](main.c) for clarity:

```c
/*
 * The Lost Kite - Computer Graphics Assignment
 * 
 * MSYS2 MINGW64 Compilation Notes:
 * 
 * Required Libraries (install via pacman):
 * - mingw-w64-x86_64-gcc (compiler)
 * - mingw-w64-x86_64-freeglut (OpenGL/GLUT headers and libraries)
 * - mingw-w64-x86_64-make (build tool, optional but recommended)
 * 
 * Compilation Command (Windows MSYS2 MINGW64 terminal):
 * gcc -o the_lost_kite.exe main.c member1.c member2.c member3.c member4.c member5.c \
 *   $(pkg-config --cflags --libs glut) -lm -std=c99
 * 
 * Alternative with Make:
 * make
 * 
 * Run the application:
 * ./the_lost_kite.exe
 * 
 * Controls:
 * - ESC: Exit
 * - SPACE/ENTER: Next scene
 */
```

## Library Details

### FreeGLUT (GLUT alternative)
- Provides window creation and event handling
- OpenGL initialization and rendering context
- Input callbacks (keyboard, mouse, reshape, display timer)
- Cross-platform (Windows, Linux, macOS)

### Link Flags Explained
- `$(pkg-config --cflags --libs glut)` — Automatically adds:
  - Include paths for GLUT/OpenGL headers
  - Linker flags for FreeGLUT libraries
  - Typically: `-lfreeglut -lopengl32 -lgdi32`
- `-lm` — Links the C math library (for `sin()`, `cos()`, etc.)
- `-std=c99` — Uses C99 standard for modern C features

## Verifying OpenGL Output

When you run the application:

1. **Window appears** with title "The Lost Kite - Bresenham Edition"
2. **Scenes animate** automatically (each scene has a time duration)
3. **Graphics render** using:
   - Bresenham line drawing for precision
   - 2D orthographic projection
   - Blending for smooth transparency effects
4. **Press SPACE** to advance scenes manually
5. **Press ESC** to exit

Expected output is a 900×600 pixel window with animated scenes showing a story with children, kites, birds, rain, and more.
