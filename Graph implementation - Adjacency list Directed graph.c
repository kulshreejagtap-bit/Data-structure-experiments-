#include <stdio.h>
        }
        prev = curr;
        curr = curr->next;
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}

void deleteVertex(int *N) {
    int v;
    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);

    if (*N == 0) {
        printf("Graph is empty.\n");
        return;
    }

    if (v < 1 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE temp = graph[v];
    while (temp != NULL) {
        GNODE t = temp;
        temp = temp->next;
        free(t);
    }
    graph[v] = NULL;

    for (int i = 1; i <= *N; i++) {
        if (i == v) continue;

        GNODE curr = graph[i], prev = NULL;
        while (curr != NULL) {
            if (curr->vertex == v) {
                if (prev == NULL)
                    graph[i] = curr->next;
                else
                    prev->next = curr->next;

                GNODE t = curr;
                curr = curr->next;
                free(t);
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    for (int i = v; i < *N; i++) {
        graph[i] = graph[i + 1];
    }
    graph[*N] = NULL;

    for (int i = 1; i < *N; i++) {
        GNODE curr = graph[i];
        while (curr != NULL) {
            if (curr->vertex > v)
                curr->vertex--;
            curr = curr->next;
        }
    }

    (*N)--;

    printf("After deleting vertex the adjacency list is : \n");
    if (*N > 0)
        print(N);
}
