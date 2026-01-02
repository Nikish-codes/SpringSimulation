# Spring Mass Simulation

![Simulation Screenshot](image.png)

A physics-based simulation of a spring-mass system built with Raylib. This project demonstrates the mechanics of a mass connected to an anchor point via a spring, visualizing the spring's deformation and the mass's motion.



## Overview

This simulation renders a mass sliding horizontally on a floor, connected to a fixed anchor point above by a spring. The spring dynamically stretches and compresses as the mass moves, with a zigzag coil pattern that accurately represents real spring mechanics.

The mass moves at a constant velocity to demonstrate how the spring adapts to changing distance between the anchor and the mass.

## Features

- Real-time spring visualization with dynamic coil deformation
- Zigzag spring pattern that stretches along the axis between anchor and mass
- Smooth 120 FPS animation
- Minimal, clean codebase for easy understanding and modification
- Cross-platform support (Windows, Linux, macOS) via Raylib

## Building and Running

### Prerequisites

- C compiler (gcc, clang, or MSVC)
- Raylib library installed and linked

### Compilation

Compile the project using your preferred compiler. For example, with gcc:

```bash
gcc spring.c -o spring_simulation -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

Note: Linker flags may vary depending on your system and Raylib installation.

### Running

After compilation:

```bash
./spring_simulation
```

## Controls

- The simulation runs automatically upon launch
- The mass moves continuously to the right at a constant velocity
- Close the window to exit

## Code Structure

- `drawSpring()` - Renders the spring with a zigzag coil pattern between anchor and mass
- `drawMass()` - Draws the rectangular mass object
- `drawFloor()` - Renders the floor line
- `main()` - Main game loop handling initialization, updates, and rendering

## Configuration

Key constants are defined at the top of the file for easy customization:

- `FPS` - Target frames per second (default: 120)
- `WIDTH`, `HEIGHT` - Window dimensions
- `SPRING_LEN` - Number of coil segments in the spring
- `SPRING_THICKNESS` - Thickness of spring lines
- `SPRING_ELASTICITY` - Spring width offset for coil visualization
- `MASS_LENGTH` - Size of the mass block
- `FLOOR_Y` - Y-position of the floor

## How It Works

The spring is drawn by calculating the vector from the anchor point to the mass position. This vector is normalized to determine the spring's main axis direction. A perpendicular vector is then calculated to define the zigzag offset direction.

For each segment of the spring:
1. A point is positioned along the main axis based on segment progress
2. A perpendicular offset is applied, alternating left and right for each segment
3. This creates the characteristic coil pattern of a spring

The result is a spring that visually stretches and compresses as the mass moves, maintaining realistic proportions and appearance.

## Future Enhancements

Potential improvements to expand the simulation:

- Add physics-based spring motion using Hooke's Law
- Implement user controls to interact with the mass (drag and release)
- Add damping and friction effects
- Multiple masses and springs for complex systems
- Adjustable spring constants and mass values via UI
- Real-time physics visualization (force vectors, velocity indicators)
- Pendulum mode for vertical oscillation

## License

This project is provided as-is for educational purposes.

## Credits

Built with Raylib - A simple and easy-to-use library to enjoy videogames programming.
