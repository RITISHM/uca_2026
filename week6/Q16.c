#include <stdio.h>
#include <stdbool.h>

void simulate_lru(int page_requests[], int num_requests, int num_frames) {
    int frames[num_frames];
    int last_used[num_frames]; // Timestamp array
    int page_faults = 0;

    // Initialize empty slots
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }
    
    // Print header for the output table
    printf("Request\tStatus\tRAM State\n");

    for (int time = 0; time < num_requests; time++) {
        int page = page_requests[time];
        bool hit = false;
        int replace_idx = -1;

        // TODO 1: Check if 'page' is already in 'frames' (HIT)
        for (int i = 0; i < num_frames; i++) {
            if (frames[i] == page) {
                hit = true;
                last_used[i] = time; // Update timestamp to current time
                break;
            }
        }

        // TODO 2: Handle PAGE FAULT if not found
        if (!hit) {
            page_faults++;
            
            // Assume the first frame is the least recently used initially
            int lru_time = time + 1; // Start higher than any possible current time
            
            for (int i = 0; i < num_frames; i++) {
                // If there's an empty slot, prioritize it
                if (frames[i] == -1) {
                    replace_idx = i;
                    break;
                }
                
                // Otherwise, find the smallest timestamp (oldest)
                if (last_used[i] < lru_time) {
                    lru_time = last_used[i];
                    replace_idx = i;
                }
            }
            
            // Replace the LRU frame (or empty slot) with the new page
            frames[replace_idx] = page;
            last_used[replace_idx] = time; // Set its timestamp
        }

        // Print current step details to match the Example Output
        printf("%d\t%s\t[", page, hit ? "HIT" : "FAULT");
        for (int i = 0; i < num_frames; i++) {
            if (frames[i] == -1) {
                printf("-");
            } else {
                printf("%d", frames[i]);
            }
            if (i < num_frames - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int num_requests = sizeof(requests) / sizeof(requests[0]);
    
    simulate_lru(requests, num_requests, 3);
    return 0;
}
