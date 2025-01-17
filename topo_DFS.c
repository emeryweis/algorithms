/*
There are a total of numCourses courses you have to take, 
labeled from 0 to numCourses - 1. You are given an array prerequisites 
where prerequisites[i] = [ai, bi] indicates that you 
must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 
you have to first take course 1.
Return the ordering of courses you should take to finish all courses. 
If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper function to perform DFS
bool dfs(int course, int **graph, int *graphSize, int *visited, int *stack, int *stackIndex) {
    if (visited[course] == 1) return false; // Cycle detected
    if (visited[course] == 2) return true;  // Already processed
    
    visited[course] = 1; // Mark as visiting
    
    // Visit all neighbors
    for (int i = 0; i < graphSize[course]; i++) {
        if (!dfs(graph[course][i], graph, graphSize, visited, stack, stackIndex)) {
            return false; // Cycle detected
        }
    }
    
    visited[course] = 2; // Mark as processed
    stack[(*stackIndex)++] = course; // Add to topological order
    return true;
}

// Main function
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    // Step 1: Build the graph
    int **graph = (int**)malloc(numCourses * sizeof(int*));
    int *graphSize = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int)); // Allocate memory for adjacency list
    }
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][graphSize[prereq]++] = course; // Add edge prereq -> course
    }
    
    // Step 2: Initialize visited array and stack
    int *visited = (int*)calloc(numCourses, sizeof(int));
    int *stack = (int*)malloc(numCourses * sizeof(int));
    int stackIndex = 0;
    
    // Step 3: Perform DFS on each course
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, graph, graphSize, visited, stack, &stackIndex)) {
                *returnSize = 0;
                return NULL; // Cycle detected, return empty array
            }
        }
    }
    
    // Step 4: Reverse the stack to get the topological order
    int *result = (int*)malloc(numCourses * sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        result[i] = stack[numCourses - 1 - i];
    }
    
    *returnSize = numCourses;
    return result;
}

// Example usage
int main() {
    int numCourses = 4;
    int prerequisitesArray[4][2] = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int prerequisitesSize = 4;
    int prerequisitesColSize[4] = {2, 2, 2, 2};
    
    int *prerequisites[4];
    for (int i = 0; i < 4; i++) {
        prerequisites[i] = prerequisitesArray[i];
    }
    
    int returnSize;
    int *order = findOrder(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize, &returnSize);
    
    if (returnSize == 0) {
        printf("No valid order exists.\n");
    } else {
        printf("Course order: ");
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");
    }
    
    return 0;
}
