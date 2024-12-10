#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 30

int calculate_days_to_rostering_value(int n, int m, int friendships[][2], int k) {
    int friends[MAX_EMPLOYEES][MAX_EMPLOYEES] = {0};
    int current_status[MAX_EMPLOYEES];
    int total_rostering_value = n;
    int days = 1;
    
    for (int i = 0; i < m; i++) {
        int a = friendships[i][0];
        int b = friendships[i][1];
        friends[a][b] = 1;
        friends[b][a] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        current_status[i] = 1;
    }
    
    while (total_rostering_value < k) {
        int new_status[MAX_EMPLOYEES];
        memcpy(new_status, current_status, sizeof(current_status));
        for (int employee = 0; employee < n; employee++) {
            int wfo_friends = 0;
            for (int colleague = 0; colleague < n; colleague++) {  // Renamed variable
                if (friends[employee][colleague] && current_status[colleague] == 1) {
                    wfo_friends++;
                }
            }
            
            if (current_status[employee] == 1) {
                new_status[employee] = (wfo_friends == 3) ? 1 : 0;
            } else {
                new_status[employee] = (wfo_friends < 3) ? 1 : 0;
            }
        }
        
        memcpy(current_status, new_status, sizeof(new_status));
        int daily_rostering_value = 0;
        for (int i = 0; i < n; i++) {
            if (current_status[i] == 1) {
                daily_rostering_value++;
            }
        }
        total_rostering_value += daily_rostering_value;
        days++;
    }
    
    return days;
}

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    int friendships[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &friendships[i][0], &friendships[i][1]);
    }
    scanf("%d", &k);
    
    int result = calculate_days_to_rostering_value(n, m, friendships, k);
    printf("%d\n", result);
    return 0;
}