#include <stdio.h>

#define NUM_POINTS 8
#define NUM_CHARGING_STATIONS 2
#define POINT_LETTERS "ABCDEFGH"  
#define ROAD_NETWORK_SIZE NUM_POINTS

int main() {
    int road_network[ROAD_NETWORK_SIZE][ROAD_NETWORK_SIZE] = {
        {1, 1, 0, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1}
    };
    
    int charging_stations[NUM_CHARGING_STATIONS] = {2, 3};
    
    int destination;
    printf("Which point are you located? 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G, 7 - H (%d): ", NUM_POINTS-1);
    scanf("%d", &destination);
    
    printf("At point: %c\n", POINT_LETTERS[destination]);
    
    for (int i = 0; i < NUM_CHARGING_STATIONS; i++) {
        if (destination == charging_stations[i]) {
            printf("%c is a charging station.\n", POINT_LETTERS[destination]);
            return 0;
        }
    }
    
    int nearest_station = -1;
    int min_distance = ROAD_NETWORK_SIZE+1; 
    
    for (int i = 0; i < NUM_CHARGING_STATIONS; i++) {
        if (road_network[destination][charging_stations[i]]) {

            if (min_distance > 1) {
                min_distance = 1;
                nearest_station = charging_stations[i];
            }
        } else {

            for (int j = 0; j < ROAD_NETWORK_SIZE; j++) {
                if (road_network[destination][j] && road_network[j][charging_stations[i]]) {
                    int distance = 2; 
                    if (distance < min_distance) {
                        min_distance = distance;
                        nearest_station = charging_stations[i];
                    }
                }
            }
        }
    }
    
    if (nearest_station == -1) {
        printf("There is no charging station that can be reached from point %c.\n", POINT_LETTERS[destination]);
    } else {
        printf("point: %c arrived to charging station.\n", POINT_LETTERS[nearest_station]);
    }
    
    return 0;
}
