#include <stdio.h> //scanf,printf
#include <stdlib.h> //exit_success

int main()
{
  int century = 100;
  int q,m,k,j,year,end_year,matching_days = 0; //day,month,century,year,end year handler
  int month_of_thirtyone = 31;

  printf("Enter date [year month day]: ");
  scanf("%d %d %d", &year, &m, &q );

  if(q <= 0 || q > month_of_thirtyone || m >= 12 || m <= 0 || (m == 2 && q > 28)){//checking day input and month input
    printf("Invalid date.\n");
    return EXIT_FAILURE;
  }else if(q == 31){//if month is 31 day, checking months which are 31 days
    switch (m) {
      case 2:
        printf("Invalid date.\n");
        return EXIT_FAILURE;
        break;
      case 4:
        printf("Invalid date.\n");
        return EXIT_FAILURE;
        break;
      case 6:
        printf("Invalid date.\n");
        return EXIT_FAILURE;
        break;
      case 9:
        printf("Invalid date.\n");
        return EXIT_FAILURE;
        break;
      case 11:
        printf("Invalid date.\n");
        return EXIT_FAILURE;
        break;
      default:
        printf("Enter end year:\n");
        scanf("%d", &end_year );

    }
  }else if (q <= 31) {
    printf("Enter end year: ");
    scanf("%d", &end_year );
  }

  switch (m) {
    case 1:
      m += 12;
      j = (year - 1) / century;
      k = (year - 1) % century;
      break;
    case 2:
      m += 12;
      j = (year - 1) / century;
      k = (year - 1) % century;
      break;
    default :
      j = year / century;
      k = year % century;
  }

  int day_of_week_algorithm = (q + (13*(m+1)/5) + k + k/4 + j/4 + 5*j) % 7;

  switch (day_of_week_algorithm) {
    case 0:
      printf("It's a Saturday.\n");
      break;
    case 1:
      printf("It's a Sunday.\n");
      break;
    case 2:
      printf("It's a Monday.\n");
      break;
    case 3:
      printf("It's a Tuesday.\n");
      break;
    case 4:
      printf("It's a Wednesday.\n");
      break;
    case 5:
      printf("It's a Thursday.\n");
      break;
    case 6:
      printf("It's a Friday.\n");
      break;
  }

  int first_year = year + 1; //holding first year

  for (; year < end_year; year++) {
    switch (m) {
      case 1:
        m += 12;
        j = (year - 1) / century;
        k = (year - 1) % century;
        break;
      case 2:
        m += 12;
        j = (year - 1) / century;
        k = (year - 1) % century;
        break;
      default :
        j = year / century;
        k = year % century;
    }
    int day_of_week_algorithm2 = (q + (13*(m+1)/5) + k + k/4 + j/4 + 5*j) % 7;
    if (day_of_week_algorithm == day_of_week_algorithm2) {
      matching_days += 1;
    }
  }


  printf("Same day-and-month on same weekday between %d and %d: %d" , first_year, end_year, matching_days);

  return EXIT_SUCCESS;
}
