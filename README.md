# Mandelbrot Set Generator

![Mandelbrot Set](mandelbrot1.png)

## Description

This C program generates the Mandelbrot set and saves the visualization as a PPM image file. The Mandelbrot set is a well-known fractal in complex dynamics that exhibits intricate and beautiful self-replicating patterns.

The program uses the Mandelbrot iteration algorithm to determine whether points in the complex plane are part of the set. It colors the points based on the number of iterations required to determine whether the sequence of complex numbers remains bounded or tends to infinity.

## How the Program Works

The Mandelbrot iteration algorithm works as follows:

1. Define a region in the complex plane that you want to visualize as the Mandelbrot set. This region is centered at the point (-0.5, 0.0) with a default zoom level of 1.5. You can modify these parameters to explore different regions and zoom levels.

2. Discretize the complex plane into a grid of pixels within the specified region. Each pixel represents a complex number.

3. For each pixel, iterate the Mandelbrot iteration formula: `z = z^2 + c`, where `z` is a complex number starting from 0, and `c` is the complex number corresponding to the pixel. The iteration is repeated until the sequence either becomes unbounded or reaches a maximum number of iterations (set to 1000 by default).

4. Assign a color to each pixel based on the number of iterations required. Points that remain bounded within the maximum iterations are considered part of the Mandelbrot set and are colored black. Points that exceed the maximum iterations are colored with a gradient based on the number of iterations.

## Getting Started

### Prerequisites

To run this program, you need a C compiler installed on your system.

### Compiling the Program

Compile the C program using your preferred C compiler. For example, with GCC, use the following command:

```bash
gcc -o mandelbrot_set_generator mandelbrot_set_generator.c -lm
```

### Running the Program

After compilation, execute the generated binary:

```bash
./mandelbrot_set_generator
```

## Configuration

You can modify the following parameters in the `mandelbrot_set_generator.c` file to customize the Mandelbrot set visualization:

- `WIDTH`: Image width in pixels.
- `HEIGHT`: Image height in pixels.
- `MAX_ITERATIONS`: Maximum number of iterations for each pixel.
- `center`: The center of the region in the complex plane.
- `zoom`: The zoom level to adjust the region's magnification.

## Output

The program will generate a PPM image file named `mandelbrot.ppm` representing the Mandelbrot set. You can view this image using an image viewer that supports the PPM format.

## Example

Here is an example of the Mandelbrot set generated with the default parameters:

![Mandelbrot Set](mandelbrot2.png)
