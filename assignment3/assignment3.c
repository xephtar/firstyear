#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define MAX_ODDS 2

void carlocate(int arr[][MAX_SIZE],int x,int y){
  arr[x][y] = 1;
}

void distancesum(int parkingarr[][MAX_SIZE],int locatex[],int locatey[], int distancearr[], int size) {

  int sumx,sumy = 0;
  int temp,tempx,tempy;
  for (int i = 1; i < size; i++) {
    for (int j = 1; j < size; j++) {

      if (parkingarr[i][j] == 1) {

        for (int x = 1; x < size; x++) {
          for (int y = 1; y < size; y++) {

            if (parkingarr[x][y] == 0) {
              sumx = i - x;
              sumy = j - y;
              if (sumx < 0) {
                sumx = -1*sumx;
              }
              if (sumy < 0) {
                sumy = -1*sumy;
              }

              distancearr[0] = sumx + sumy;

              if (distancearr[0] > distancearr[1]) {
                temp = distancearr[1];
                distancearr[1] = distancearr[0];
                distancearr[0] = temp;

                locatex[0] = x;
                locatey[0] = y;


                if (locatex[0] > locatex[1]) {
                  tempx = locatex[1];
                  locatex[1] = locatex[0];
                  locatex[0] = tempx;
                }
                if (locatey[0] > locatey[1]) {
                  tempy = locatey[1];
                  locatey[1] = locatey[0];
                  locatey[0] = tempy;
                }

              }


            }


          }


        }

      }


    }


  }

}


int main(){
  int parking_area[MAX_SIZE][MAX_SIZE] = {{0}};
  int locationx[MAX_ODDS];
  int locationy[MAX_ODDS];
  int higher_sum[MAX_ODDS] = {0};
  int xaxis = 0;
  int yaxis = 0;
  int size_of_p = 0;
  int size = 0;
  printf("Size:");
  scanf("%d", &size);

  size_of_p = size + 1;


  int area_of_p = (size) * (size);
  int number_of_c = 0;


  printf("Cars:");
  scanf("%d", &number_of_c);

//error checking
  switch (number_of_c) {
    case 0:
      printf("Best Slot Found In: %d %d", xaxis, yaxis );
  }


//error checking
  while ((number_of_c > area_of_p) || (number_of_c < 0)) {
    printf("Cars:");
    scanf("%d", &number_of_c);
  }


  for (int i = 0; i < number_of_c;i++) {
    printf("Locations:");
    scanf("%d %d", &xaxis , &yaxis);

    carlocate(parking_area, xaxis , yaxis);

  }

  distancesum(parking_area,locationx,locationy, higher_sum, size_of_p);

  printf("Best Slot Found In: %d %d", locationx[0], locationy[0]);


  return EXIT_SUCCESS;
}
