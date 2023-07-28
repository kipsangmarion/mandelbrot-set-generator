/**
 * file: mandelbrot_set_generator.c
 * author: mrion
 * description: c code to generate the mandelbrot set
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// define image size in pixels
#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

typedef struct{
	double real;
	double imag;
} Complex;

int setIteration(Complex c) {
	Complex z = {0.0, 0.0};
	int iterations = 0;
	
	while (iterations < MAX_ITERATIONS){
		double z_real_square = z.real * z.real;
		double z_imag_square = z.imag * z.imag; 
		
		if(z_real_square + z_imag_square > 4.0){
			// When the sequence tends to infinity
			break;
		}
		
		// implementing z = z^2 + c
		double z_real_new = z_real_square - z_imag_square + c.real;
		double z_imag_new = 2.0 * z.real * z.imag + c.imag;
		z.real = z_real_new;
		z.imag = z_imag_new;
		
		iterations++;
	}
	
	return iterations;
}

void generateSet(){
	// write to file in binary mode
	// PPM = portable pixmap format, uses text format to info about image
	FILE *fp = fopen("mandelbrot.ppm", "wb");
	if (!fp){
		printf("Error: Unable to open file.\n");
		return;
	}
	
	// PPM header
	fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
	
	// Center of the region
	Complex center = {-0.5, 0.0};
	// Zoom level
	double zoom = 1.5;
	
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			// Position of pixel representing the complex number
			Complex c = {
				center.real + (x - WIDTH / 2.0) / (zoom * WIDTH),
				center.imag + (y - HEIGHT / 2.0) / (zoom * HEIGHT)
			};
			
			int iterations = setIteration(c);
			
			// Assign color based on number of iterations
			unsigned char color[3];
			if (iterations == MAX_ITERATIONS){
				// Black for points in the set
				color[0] = color[1] = color[2] = 0;
			} else{
				// Gradient for points outside
				color[0] = iterations % 256;
				color[1] = (iterations * 2) % 256;
				color[2] = (iterations * 5) % 256;
			}
			
			fwrite(color, sizeof(unsigned char), 3, fp);
		}
	}
	fclose(fp);
}

int main(){
	generateSet();
	return 0;
}
