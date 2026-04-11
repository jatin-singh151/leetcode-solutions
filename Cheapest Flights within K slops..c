#define INF (INT_MAX>>2)

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    // Create distance arrays to track minimum prices reached at each node
    int *dist = (int*)malloc(n * sizeof(int));
    int *dist_temp = (int*)malloc(n * sizeof(int));

    // Initialize all distances to infinity except the source
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        dist_temp[i] = INF;
    }
    dist[src] = 0; // Start from the source city with a cost of 0

    // Relax distances using Bellman-Ford algorithm for k iterations
    for (int k_iter = 0; k_iter <= k; k_iter++) {
        memcpy(&dist_temp[0], &dist[0], n * sizeof(int)); // Create a copy of the current distances

        // Iterate over all flights, updating distances if a cheaper path is found
        for (int i = 0; i < flightsSize; i++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            if (dist_temp[to] > dist[from] + price && dist[from] != INF) { // Avoid relaxation from infinity
                dist_temp[to] = dist[from] + price; // Update distance if shorter path found
            }
        }

        // Copy updated distances back to the main array
        memcpy(&dist[0], &dist_temp[0], n * sizeof(int));

        // Check for negative cycles (indicating arbitrage) using Bellman-Ford's property
        // If negative cycle detected, return -1
        for (int i = 0; i < n; i++) {
            if (dist[i] != INF && dist[i] < dist_temp[i]) { // Negative cycle detected
                return -1;
            }
        }
    }

    // Return the cheapest price reached at the destination, or -1 if not found
    int ret = dist[dst];
    free(dist);
    free(dist_temp);
    if (ret == INF) return -1;
    return ret;
}
