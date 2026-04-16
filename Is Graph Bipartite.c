bool
isBipartite(int **G, int n, int *cols)
{
    int u = 0, v = 0;
    int top = 0;
    int *Q = calloc(n, sizeof(int));
    int *color = calloc(n, sizeof(int));
    int *visited = calloc(n, sizeof(int));
    int *enqueued = calloc(n, sizeof(int));
    
	/* Run a BFS from every node that is still unvisited. */
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;
        color[i] = 1;
        Q[top++] = i;
        
        while (top)
        {
            u = Q[--top];
            enqueued[u] = 0;
            visited[u] = 1;
			
			/* Visit each neighbor of u. */
            for (int j = 0; j < cols[u]; j++)
            {
                v = G[u][j];
                if (visited[v]) continue;
				
				/* If u and v are the same color, then the graph is not bipartite. */
                if (color[u] == color[v]) return false;
				
				/* Else set v to the opposite color of u. */
                color[v] = -color[u];
				
                /* Check if a node has been already enqueued. If we don't check, our Q might have
				 * to hold many nodes multiple times increasing our memory requirement.
				 */
				if (enqueued[v]) continue;
				
                Q[top++] = v;
                enqueued[v] = 1;
            }
        }
    }
    
	return true;
}
