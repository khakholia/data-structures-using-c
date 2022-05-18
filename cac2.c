#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Music Data Structure
// ADT - Doubly Linked List
struct Music
{
    int id;
    char name[100];
    int duration;

    struct Music *next;
    struct Music *prev;
};

// ref to start of playlist
struct Music *playlist;

// ref to current music
struct Music *current;

// method which takes id, name & duration of the new song to be inserted.
void insertMusic(int id, char *name, int duration)
{
    struct Music *newLink = playlist;
    struct Music *newMusic = (struct Music *)malloc(sizeof(struct Music));
    newMusic->id = id;
    strcpy(newMusic->name, name);
    newMusic->duration = duration;
    if (playlist != NULL)
    {

        newMusic->prev = playlist;
        newMusic->next = NULL;
        playlist->next = newMusic;
        playlist = playlist->next;
    }
    else
    {
        newMusic->prev = NULL;
        newMusic->next = NULL;
        playlist = current = newMusic;
    }
}

// method to display all the songs present in the list
// Order- last inserted-> first inserted
void displayPlaylist()
{
    struct Music *newLink = playlist;
    while (newLink != NULL)
    {
        printf("%d\t%d secs\t%s\n", newLink->id, (newLink->duration) / 60, newLink->name);
        newLink = newLink->prev;
    }
}

// switch to previous music if available
void prevMusic()
{
    if (current->prev != NULL)
    {
        current = current->prev;
    }
    else
    {
        printf("End of List.\n");
    }
}

// switchh to last music if available
void nextMusic()
{

    if (current->next != NULL)
    {
        current = current->next;
    }
    else
    {
        printf("End of List.\n");
    }
}

// show details of currently playing song
void currentlyPlaying()
{
    printf("Currently Playing %d %s...\n", current->id, current->name);
}

void main()
{

    insertMusic(1, "A", 100);
    insertMusic(2, "B", 200);
    insertMusic(3, "C", 300);
    insertMusic(4, "D", 400);
    insertMusic(5, "E", 500);
    insertMusic(6, "F", 600);
    insertMusic(7, "G", 700);
    insertMusic(8, "H", 800);
    insertMusic(9, "I", 900);
    insertMusic(10, "J", 1000);
    insertMusic(11, "K", 1100);
    displayPlaylist();
    currentlyPlaying();
    nextMusic();
    currentlyPlaying();
    nextMusic();
    nextMusic();
    currentlyPlaying();
    prevMusic();
    currentlyPlaying();
    prevMusic();
    prevMusic();
    currentlyPlaying();
    prevMusic();
    prevMusic();
    currentlyPlaying();
}