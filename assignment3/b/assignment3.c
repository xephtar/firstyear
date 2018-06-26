#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define MAX_ODDS 3

//void carlocate(int arr[][MAX_SIZE],int x,int y,int size){
//  if(x <= size && y <= size){
//   arr[x][y] = 1;
// }else{
//   arr[x][y] = 0;
// }
//}

void distancesum(int parkingarr[][MAX_SIZE],int location[][MAX_ODDS], int distancearr[], int size)
{

  int sumx,sumy = 0;
  distancearr[1] = 2*size;
  for (int i = 1; i < size; i++) {
    for (int j = 1; j < size; j++) {
      if (parkingarr[i][j] == 0) {
        for (int x = 1; x < size; x++) {
         for (int y = 1; y < size; y++) {
          if (parkingarr[x][y] == 1) {
           sumx = i - x;
           sumy = j - y;
           if(sumx < 0){
            sumx = -1*sumx;
           }
           if(sumy < 0){
            sumy = -1*sumy;
           }
           distancearr[0] = sumx + sumy;
           if(distancearr[1] > distancearr[0]){
            distancearr[1] = distancearr[0];
           }
          }
         }
        }
        if (distancearr[2] < distancearr[1]) {
          location[0][0] = i;
          location[0][1] = j;
          distancearr[2] = distancearr[1];
        }
        distancearr[1] = 2*size;

      }
     }
   }
}




int main(){
  int parking_area[MAX_SIZE][MAX_SIZE] = {{0}};
  int locate[MAX_ODDS][MAX_ODDS];
  int higher_sum[MAX_ODDS] = {0};
  int xaxis = 0;
  int yaxis = 0;
  int size_of_p = 0;
  int size = 0;
  printf("Size: ");
  scanf("%d", &size);

  while(size > 50 || size < 0){
  printf("max size must be 50");
  printf("Size: ");
  scanf("%d", &size);
  }


  size_of_p = size + 1;


  int area_of_p = (size) * (size);
  int number_of_c = 0;


  printf("Cars: ");
  scanf("%d", &number_of_c);

//error checking
  switch (number_of_c) {
    case 0:
      printf("Best Slot Found In: %d %d\n", xaxis+1, yaxis+1 );
      return EXIT_SUCCESS;
      break;
  }

//error checking
  if(number_of_c == area_of_p){
      printf("Best Slot Found In: %d %d\n", xaxis, yaxis );
      return EXIT_SUCCESS;
  }
//error checking
  while ((number_of_c > area_of_p) || (number_of_c < 0)) {
    printf("Cars: ");
    scanf("%d", &number_of_c);
  }


  for (int i = 0; i < number_of_c;i++) {
    printf("Locations: ");
    scanf("%d %d", &xaxis , &yaxis);
    if((xaxis <= size) && (yaxis <= size)){
     parking_area[xaxis][yaxis] = 1;
    }else{
     parking_area[xaxis][yaxis] = 0;
    }

  }

  distancesum(parking_area,locate, higher_sum, size_of_p);

  printf("Best Slot Found In: %d %d\n", locate[0][0], locate[0][1]);


  return EXIT_SUCCESS;

}
