#include <stdio.h>

int main() {
    
    float interarrivaltime = 3240;
    float totalarrivaltime = 1620;
    
    float meaninterarrivaltime, meanarrivaltime;
    
    meaninterarrivaltime = interarrivaltime / 0.5;
    meanarrivaltime = totalarrivaltime / 0.5;
    
    printf("The mean interarrival time is: %f\n", meaninterarrivaltime);
    printf("The mean arrival time is: %f\n", meanarrivaltime);
    
    return 0;
}
