/**
 * file: mandelbrot_set_generator.c
 * author: mrion
 * description: c code to generate the mandelbrot set
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
		double z_real_square = z.real ** 2;
		double z_imag_square = z.imag ** 2; 
		if(z_real_square + z_imag_square > 4.0){
			break;
		}
		
		double z_real_temp = z_real_squared - z_imag_square + c.real
		double z_imag_temp = 2.0 * z.real * z.imag +c.imag;
		z.real = z_real_temp;
		z_imag = z_imag_temp;
		
		iterations++;
	}
	
	return iterations;
}

void generateSet(){
	FILE *fp = fopen("mandelbrot.ppm", "wb");
	if (!fp){
		printf("Error: Unable to open file.\n");
		return;
	}
	
	fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
	
	Complex center = {-0.5, 0.0};
	double zoom = 1.5;
	
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			Complex c = {
				center.real + (x - WIDTH / 2.0) / (zoom * WIDTH),
				center.imag + (y - HEIGHT / 2.0) / (zoom * HEIGHT)
			};
			
			int iterations = setIteration(c);
			
			unsigned char color[3];
			if (iterations == MAX_ITERATIONS){
				color[0] = color[1] = color[2] = 0;
			} else{
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
