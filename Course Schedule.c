typedef struct Node {
    int course_id;
    struct Node *next;
};

bool cycleCheck(int start, int *visited, struct Node **graph) {
    if (visited[start] == 1)
        return true;
    
    if (!visited[start]) {
        visited[start] = 1;
        for (struct Node *cur = graph[start]; cur != NULL; cur = cur->next) {
            if (cycleCheck(cur->course_id, visited, graph))
                return true;
        }
    }
    
    visited[start] = 2;
    return false;
}

struct Node *list_append (struct Node *list, int ele) {
    struct Node *new_node = calloc(1, sizeof(struct Node));
    new_node->course_id = ele;
    new_node->next = NULL;
    
    if (!list) {
        list = new_node;
        return list;
    }

    struct Node *cur = list;
    while (cur->next)
        cur = cur->next;
    cur->next = new_node;

    return list;
}

void graph_free(struct Node **graph, int colSize) {
    for (int i=0; i<colSize; i++)
        free(graph[i]);
    free(graph);
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {

    struct Node **graph = calloc(numCourses, sizeof(struct Node *));
    for (int i=0 ; i < prerequisitesSize; i++) {
        graph[prerequisites[i][0]] = list_append(graph[prerequisites[i][0]], prerequisites[i][1]);
    }

    int *visited = calloc(numCourses, sizeof(int));

    for (int i=0; i < numCourses; i++) {
        if (cycleCheck(i, visited, graph)) {
            graph_free(graph, numCourses);
            free(visited);
            return false; 
        }
    }

    graph_free(graph, numCourses);
    free(visited);
    return true;
}
