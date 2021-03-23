#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include "bmplib.h"

using namespace std;

//============================Add function prototypes here======================
void dummy(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB]);
void convolve(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
        int N, double kernel[][11]);
void sobel(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB]);
void gaussian(double k[][11], int N, double sigma);
void gaussian_filter(unsigned char out[][SIZE][RGB], unsigned char 
		in[][SIZE][RGB], int N, double sigma);
void unsharp(unsigned char output[][SIZE][RGB], unsigned char in[][SIZE][RGB],
		int N, double sigma, double alpha);
//============================Do not change code in main()======================

#ifndef AUTOTEST

int main(int argc, char* argv[])
{
   //First check argc
  if(argc < 3)
    {
      //we need at least ./filter <input file> <filter name> to continue
      cout << "usage: ./filter <input file> <filter name> <filter parameters>";
      cout << " <output file name>" << endl;
      return -1;
    }
   //then check to see if we can open the input file
   unsigned char input[SIZE][SIZE][RGB];
   unsigned char output[SIZE][SIZE][RGB];
   char* outfile;
   int N;
   double sigma, alpha;

   // read file contents into input array
   int status = readRGBBMP(argv[1], input); 
   if(status != 0)
   {
      cout << "unable to open " << argv[1] << " for input." << endl;
      return -1;
   }
   //Input file is good, now look at next argument
   if( strcmp("sobel", argv[2]) == 0)
   {
     sobel(output, input);
     outfile = argv[3];
   }
   else if( strcmp("blur", argv[2]) == 0)
   {
     if(argc < 6)
       {
	 cout << "not enough arguments for blur." << endl;
	 return -1;
       }
     N = atoi(argv[3]);
     sigma = atof(argv[4]);
     outfile = argv[5];
     gaussian_filter(output, input, N, sigma);
   }
   else if( strcmp("unsharp", argv[2]) == 0)
   {
     if(argc < 7)
       {
	 cout << "not enough arguments for unsharp." << endl;
	 return -1;
       }
     N = atoi(argv[3]);
     sigma = atof(argv[4]);
     alpha = atof(argv[5]);
     outfile = argv[6];
     unsharp(output, input, N, sigma, alpha);

   }
   else if( strcmp("dummy", argv[2]) == 0)
   {
     //do dummy
     dummy(output, input);
     outfile = argv[3];
   }
   else
   {
      cout << "unknown filter type." << endl;
      return -1;
   }

   if(writeRGBBMP(outfile, output) != 0)
   {
      cout << "error writing file " << argv[3] << endl;
   }
   
}   

#endif 

//=========================End Do not change code in main()=====================


// Creates an identity kernel (dummy kernel) that will simply
// copy input to output image and applies it via convolve()
//
// ** This function is complete and need not be changed.
// Use this as an example of how to create a kernel array, fill it in
// appropriately and then use it in a call to convolve.
void dummy(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB])
{
   double k[11][11];
   for (int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         k[i][j] = 0;
      }
   }
   k[1][1] = 1;
   convolve(out, in, 3, k);
}


// Convolves an input image with an NxN kernel to produce the output kernel
// You will need to complete this function by following the 
//  instructions in the comments
void convolve(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
	      int N, double kernel[][11])
{
 
   int padded[SIZE+11][SIZE+11][RGB];  // Use for input image with appropriate 
                                       // padding
   int temp[SIZE][SIZE][RGB];          // Use for the unclamped output pixel 
                                       // values then copy from temp to out, 
                                       // applying clamping 

   //first set all of padded to 0 (black)
    for (int a = 0; a < SIZE+11; a++){
        for (int b = 0; b < SIZE+11; b++){
            for (int c = 0; c < RGB; c++){
                padded[b][a][c] = 0;
            }
        }
    }


   //now copy input into padding to appropriate locations
    for (int a = 0; a < SIZE; a++){
        for (int b = 0; b < SIZE; b++){
            for (int c = 0; c < RGB; c++){
                padded[b + (N / 2)][a + (N / 2)][c] = in[b][a][c];
            }
        }
    }


   //initialize temp pixels to 0 (black)
    for (int a = 0; a < SIZE; a++){
        for (int b = 0; b < SIZE; b++){
            for (int k = 0; k < RGB; k++){
                temp[b][a][k] = 0;
            }
        }
    } 

  //now perform convolve (using convolution equation on each pixel of the 
  // actual image) placing the results in temp (i.e. unclamped result)
  //Here we give you the structure of the convolve for-loops, you need
  //to figure out the loop limits
  for(int b = 0; b < SIZE; b++){
      for(int a = 0; a < SIZE; a++){
          for(int c = 0; c < RGB; c++){
              for(int i = -N/2; i <= N/2; i++){
                  for(int j = -N/2; j<= N/2; j++){
                      temp[b][a][c] += (padded[b + i + (N / 2)][a + j +
                        (N / 2)][c])*(kernel[(N / 2) + i][(N / 2) + j]);
                  }
              }
          }
      }
  }


   //now clamp and copy to output
   // You may need to cast to avoid warnings from the compiler:
   // (i.e. out[i][j][k] = (unsigned char) temp[i][j][k];)
    for (int a = 0; a < SIZE; a++){
        for (int b = 0; b < SIZE; b++){
            for (int c = 0; c < RGB; c++){
                if (temp[b][a][c] > 255){
                    temp[b][a][c] = 255;
                }else if (temp[b][a][c] < 0){
                    temp[b][a][c] = 0;
                }
                out[b][a][c] = (unsigned char)temp[b][a][c];
            }
        }
    }
}

// You will need to complete this function by following the 
//  instructions in the comments
void sobel(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB])
{
   double k[11][11];
   double s_h1[3][3] = { {-1, 0, 1}, 
                         {-2, 0, 2}, 
                         {-1, 0, 1} };
   double s_h2[3][3] = { {1, 0, -1}, 
                         {2, 0, -2}, 
                         {1, 0, -1} };
   
   unsigned char h1_soble[SIZE][SIZE][RGB]; //hold intemediate images
   unsigned char h2_soble[SIZE][SIZE][RGB]; 

   for (int i = 0; i < 11; i++){
      for(int j = 0; j < 11; j++){
         k[j][i] = 0;
      }
   }


   // Copy in 1st 3x3 horizontal sobel kernel (i.e. copy s_h1 into k)
    for (int i = 0; i < 3; i++){
	    for(int j = 0; j < 3; j++){
	      	k[j][i] = s_h1[j][i];
	    }
	}


   // Call convolve to apply horizontal sobel kernel with result in h1_soble
    convolve(h1_soble, in, 3, k);


   // Copy in 2nd 3x3 horizontal sobel kernel (i.e. copy s_h2 into k)
    for (int i = 0; i < 3; i++){
  		for(int j = 0; j < 3; j++){
  	   		k[j][i] = s_h2[j][i];
  		}
	}


   // Call convolve to apply horizontal sobel kernel with result in h2_soble
    convolve(h2_soble, in, 3, k);


   // Add the two results (applying clamping) to produce the final output 
    for (int a = 0; a < SIZE; a++){
        for (int b = 0; b < SIZE; b++){
            for (int c = 0; c < RGB; c++){
                int temp = h1_soble[b][a][c] + h2_soble[b][a][c];
                if (temp > 255){
                	temp = 255;
                }else if (out[b][a][c] < 0){
                	temp = 0;
                }
            out[b][a][c] = temp;
            }
        }
    }
}


// Add the rest of your functions here (i.e. gaussian, gaussian_filter, unsharp)

void gaussian (double k[][11], int N, double sigma)
{
	double gaus_x[11][11]; //Array for gaus x values
	double gaus_y[11][11]; //Array for gaus x values
	double sum = 0;

	//Initialize gaus_x & gaus_y to i - (N / 2)
	for (int a = 0; a < N; a++){
		for (int b = 0; b < N; b++){
			gaus_x[b][a] = a - (N / 2);
			gaus_y[b][a] = b - (N / 2);
		}
	}

	for (int a = 0; a < N; a++){
		for (int b = 0; b < N; b++){
			double c = (pow(gaus_x[b][a], 2) / (2 * pow(sigma,2)));
			double d = (pow(gaus_y[b][a], 2) / (2 * pow(sigma,2)));
			k[b][a] = exp(-1*(c + d));
			sum += k[b][a];
		}
	}
	for (int a = 0; a < N; a++){
		for (int b = 0; b < N; b++){
			k[b][a] /= sum;
			cout << k[b][a] << ", ";
		}
		cout << endl;
	}
}

void gaussian_filter(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB],
		int N, double sigma)
{
	double k[11][11]; 
	for (int a = 0; a < N; a++){
		for (int b = 0; b < N; b++){
			k[b][a] = 0; 
		}
	}
	gaussian(k, N, sigma); 
	convolve(out, in, N, k); 
}

void unsharp(unsigned char out[][SIZE][RGB], unsigned char in[][SIZE][RGB], 
		int N, double sigma, double alpha)
{
	unsigned char d[SIZE][SIZE][3]; 
	int e[SIZE][SIZE][3]; 

	double temp; 

	gaussian_filter(d, in, N, sigma); 

	for (int a = 0; a < SIZE; a++){
		for (int b = 0; b < SIZE; b++){
			for (int c = 0; c < RGB; c++){
				e[b][a][c] = (int)in[b][a][c] - (int)d[b][a][c];
			}
		}
	}

	for (int a = 0; a < SIZE; a++){
		for (int b = 0; b < SIZE; b++){
			for (int c = 0; c < RGB; c++){
				temp = (int)in[b][a][c] + (alpha * (double)e[b][a][c]);
				if (temp > 255){
					temp = 255;
				}else if (temp < 0){
					temp = 0;
				}
				out[b][a][c] = (unsigned char)temp;
			}
		}
	}
}

