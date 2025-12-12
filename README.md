# Fract-ol

Interactive fractal viewer with real-time exploration and manipulation.

## Description

An application that renders and allows exploration of different fractal sets such as Mandelbrot and Julia in real time. The program generates complex mathematical visualizations and lets the user navigate fractals with interactive zoom and point inspection.

## Implemented Fractals

### Mandelbrot

The Mandelbrot set: for each complex parameter c, iterate z = z² + c starting at z = 0 and test boundedness. The set is known for its self-similarity and intricate boundaries.

### Julia

The Julia set: for a fixed complex parameter c, iterate z = z² + c for each initial z. Different values of c produce varied and intricate patterns.

## Features

- Interactive real-time fractal rendering
- Smooth zoom with mouse scroll
- Keyboard navigation
- Adjustable iteration count for detail control
- Customizable color schemes
- Point inspection and bookmarking (where implemented)
- Performance optimizations
- Uses MiniLibX for rendering

## Included Files

- `src/` - Source code
- `includes/` - Header files
- `libft/` - Custom C library
- `MLX42/` - MiniLibX graphics library (or variant)
- `bonus/` - Additional bonus features

## Build

```bash
make              # Build fract-ol
make bonus        # Build bonus version
make clean        # Remove object files
make fclean       # Remove executables and object files
make re           # Rebuild from scratch
```

## Usage

```bash
./fractol mandelbrot
./fractol julia
```

### Bonus Version

```bash
./fractol_bonus mandelbrot
./fractol_bonus julia
./fractol_bonus tricorn
```

## Controls

| Control | Action |
|---|---|
| Mouse scroll up | Zoom in |
| Mouse scroll down | Zoom out |
| Left click | Center view on point |
| Arrow keys | Pan view |
| `+` / `-` | Increase / decrease iteration count |
| `C` | Cycle color scheme |
| `R` | Reset view |
| `ESC` | Exit |

## Requirements

- C compiler (gcc, clang, etc.)
- Make
- MLX42 (provided or available in the project)
- GLFW and graphics dependencies on Linux (if applicable)
- Linux or macOS

## Rendering Details

- Iterative escape-time algorithm for fractal computation
- Smooth coloring techniques for continuous gradients
- Optional anti-aliasing
- Cache-friendly optimizations

## Configurable Parameters

- Maximum iterations: affects detail level
- Zoom range: enables deep exploration
- Color schemes: different color mappings
- View center: controls navigation

## Optimizations

- Optimized complex arithmetic and escape checks
- Memory-efficient buffers
- Parallel rendering (bonus version)
- Precomputed tables and other micro-optimizations

## Mathematical Outline

### Mandelbrot (per pixel c = x + yi)

```
z = 0
repeat: z = z*z + c
count iterations until |z| > 2
```

### Julia (per pixel z = x + yi)

```
c is constant
repeat: z = z*z + c
count iterations until |z| > 2
```

## Bonus Version

The bonus build may include extra features such as:
- Additional fractals (e.g., Tricorn)
- Multithreaded rendering
- Animations and parameter sweeps
- Image export
- Enhanced UI controls

## Notes

- Higher iteration counts increase precision and detail
- Deep zooms may require higher floating-point precision
- Performance depends on iteration count and resolution
- Fractals exhibit infinite complexity at arbitrary zoom levels

---

Last updated: December 2025
