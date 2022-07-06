#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "llist.h"
#include "queue.h"

int main()
{
    printf("Enter all songs (as strings), End with \"-1\"\n");
    queue *playlist;
    // playlist->back = NULL;
    // playlist->front = NULL;
    lin *store = (lin *)malloc(sizeof(lin));
    store->node = NULL;
    int count = 0;
    while (1)
    {
        char *buffer[20];
        size_t bsize = 20;
        fgets(*buffer, bsize, stdin);
        if (strcmp(*buffer, "-1\n") == 0)
            break;
        if (strcmp(*buffer, "\n") == 0)
            continue;
        insert_node(store, *buffer, &count);
    }
    printf("All songs entered!\n");
    printf("Create Playlist, end with \"-1\"\n");
    while (1)
    {
        char buffer[20];
        size_t bsize = 20;
        fgets(buffer, bsize, stdin);
        if (strcmp(buffer, "-1\n") == 0)
            break;
        if (strcmp(buffer, "\n") == 0)
            continue;
        if (find_element(buffer, store, count) != -1)
        {
            enqueue(playlist, buffer);
            printf("Found, Enqueued\n");
    
        }
        else
        {
            printf("Not Found in the song library\n");
        }
    }
    printf("Playlist Ready!\n");
    
    stack *recent = NULL;
    char x;
    queue *temp = (queue *)malloc(sizeof(queue));
        
        temp->back = NULL;
        
        temp->front = NULL;
    while (1)
    {
        if (x != 10)
            printf("Play next song, previous songs or end? n/p:k/e\n");
        
        scanf("%c", &x);
        
        
        if (x == 'n')
        {
            
            char *buffer[20];
            if (playlist->back != NULL)
                
                printf("%s ",deque(playlist));
            if (*buffer != NULL)
            {
                printf("Playing %s", *buffer);
                push(recent, *buffer);
            }
            else
            {
                printf("Playlist empty\n");
                
            }
        }
        else if (x == 'p')
        {
            char y;
            int z;
            scanf("%c%d\n", &y, &z);
            int t = z;
            while (z--)
            {
                char *buffer[20];
                strcpy(*buffer, pop(recent));
                enqueue(temp, *buffer);
                printf("Playing %s\n", *buffer);
                if (*buffer == NULL)
                    break;
            }
            while (1)
            {
                char te[20];
                strcpy(te,deque(temp));
                if (te == NULL)
                    break;
                push(recent, te);
            }
            printf("There aren’t %d previous songs", t);
        }
        else if (x == 'e')
        {
            printf("Bye!\n");
            exit(0);
        }
    }
}