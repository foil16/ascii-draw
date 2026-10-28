# ASCII Draw

A small command-line drawing program in C. You give it a grid size and shape commands, and it renders lines, rectangles and circles as ASCII art.

## Tech stack

C (standard library and `math.h`), built with `make`.

## What's interesting

- **Line rasterization:** computes slope and intercept and rounds each column to the nearest row. On steep segments it fills the vertical gaps between columns, so lines stay connected.
- **Circle rasterization:** works one quadrant at a time. At each step it looks at the three neighbouring cells and picks the one whose distance from the centre is closest to the radius, a midpoint-style approach.
- **Command interpreter:** parses commands from stdin with `fgets`, `strtok` and `sscanf`, onto a fixed-size canvas of up to 1000×1000 cells.

## Commands

| Command | Effect |
|---|---|
| `GRID w h` | Create a `w × h` canvas (must come first) |
| `CHAR c` | Set the drawing character (default `*`) |
| `LINE x0,y0 x1,y1` | Draw a line between two points |
| `RECTANGLE x0,y0 x1,y1` | Draw a rectangle from its top-left to its bottom-right corner |
| `CIRCLE x,y r` | Draw a circle with centre `(x, y)` and radius `r` |
| `DISPLAY` | Print the canvas with axis labels |
| `END` | Quit |

The origin `(0, 0)` is the bottom-left corner.

## Running it

```bash
make
./asciidraw < example.txt
```

Example output, from `example.txt`:

```
1                              
0                              
9 ###########              **  
8 #         #            ***   
7 #         #           **     
6 #         #         ***      
5 #         #        **        
4 #         #       **         
3 #         #     ***          
2 ###########    **            
1              ***             
0              *               
 012345678901234567890123456789
```

You can also run `./asciidraw` and type commands interactively.

## Known issues

- Shapes are drawn one row lower than their y-coordinates.
- Circles can have small gaps.
