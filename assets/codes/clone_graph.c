/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
 
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->numNeighbors = 0;
    newNode->neighbors = NULL;
    return newNode;
}

void dfs(struct Node* curr, struct Node* node, struct Node** visited) {
    visited[node->val] = node;
    for (int i = 0; i < curr->numNeighbors; i++) {
        struct Node* ele = curr->neighbors[i];
        if (visited[ele->val] == NULL) {
            struct Node* newnode = createNode(ele->val);
            node->neighbors = (struct Node**)realloc(node->neighbors, (node->numNeighbors + 1) * sizeof(struct Node*));
            node->neighbors[node->numNeighbors++] = newnode;
            dfs(ele, newnode, visited);
        } else {
            node->neighbors = (struct Node**)realloc(node->neighbors, (node->numNeighbors + 1) * sizeof(struct Node*));
            node->neighbors[node->numNeighbors++] = visited[ele->val];
        }
    }
}

struct Node* cloneGraph(struct Node* node) {
    if (node == NULL)
        return NULL;
    
    struct Node** visited = (struct Node**)calloc(1000, sizeof(struct Node*));
    struct Node* copy = createNode(node->val);
    visited[node->val] = copy;

    for (int i = 0; i < node->numNeighbors; i++) {
        struct Node* curr = node->neighbors[i];
        if (visited[curr->val] == NULL) {
            struct Node* newnode = createNode(curr->val);
            copy->neighbors = (struct Node**)realloc(copy->neighbors, (copy->numNeighbors + 1) * sizeof(struct Node*));
            copy->neighbors[copy->numNeighbors++] = newnode;
            dfs(curr, newnode, visited);
        } else {
            copy->neighbors = (struct Node**)realloc(copy->neighbors, (copy->numNeighbors + 1) * sizeof(struct Node*));
            copy->neighbors[copy->numNeighbors++] = visited[curr->val];
        }
    }
    free(visited);
    return copy;
}