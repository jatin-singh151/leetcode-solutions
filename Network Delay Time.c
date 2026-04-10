#define SOURCE times[i][0] - 1
#define DESTINATION times[i][1] - 1
#define WEIGHT times[i][2]
#define MAX 100001
#define MAXCOST 101

void init(int array[], int initializer, int n){
    for(int i = 0; i < n; i++){
        array[i] = initializer;
    }
}

int **prepareSparse(int n, int **times, int timeSize, int* timesColSize){
    int **matrix = (int **) malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++){
        matrix[i] = (int *) malloc(sizeof(int) * n);
        init(matrix[i], MAX, n);
    }

    for(int i = 0; i < timeSize; i++){
        matrix[SOURCE][DESTINATION] = WEIGHT;
    }
    return matrix;
}

int getMin(int cost[], int visited[], int n){
    int index = -1;
    int min = MAXCOST;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            if(index == -1 || cost[i] < min){
                min = cost[i];
                index = i;
            }
        }
    }
    return index;
}


int* SingleSourceShortestPath(int n, int **matrix, int k){
    int *cost = (int *) malloc(sizeof(int) * n);
    int *visited = (int *) malloc(sizeof(int) * n);
    int vertex;

    for(int i = 0; i < n; i++){
        cost[i] = matrix[k - 1][i];
        visited[i] = 0;
    }
    cost[k - 1] = 0;
    visited[k - 1] = 1;
    
    while((vertex = getMin(cost, visited, n)) != -1){
        for(int i = 0; i < n; i++){
            if(visited[i] == 0 && cost[i] > cost[vertex] + matrix[vertex][i]){
                cost[i] = cost[vertex] + matrix[vertex][i];
            }
        }
        visited[vertex] = 1;
    }

    return cost;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    int **matrix = prepareSparse(n, times, timesSize, timesColSize);
    int *cost = SingleSourceShortestPath(n, matrix, k);
    int max = -1;

    for(int i = 0; i < n; i++){
        max = (max > cost[i])?max:cost[i];
    }

    return (max < MAX)?max:-1;
}

