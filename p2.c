#include <stdio.h>
#include <shared.h>

int main() {
    sem_t sharedMemorySemaphore;
    sem_t bufferEmptySemaphore;
    sem_t bufferFullSemaphore;

    sharedMemorySemaphore = sem_init(120621646);
    bufferEmptySemaphore = sem_init(220621646);
    bufferFullSemaphore = sem_init(320621646);

    sem_set(sharedMemorySemaphore, 1);
    sem_set(bufferEmptySemaphore, 1);
    sem_set(bufferFullSemaphore, 0);

    char *buffer;
    buffer = (char *)getmem(420621646);

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        PS(bufferEmptySemaphore);
        PS(sharedMemorySemaphore);

        *buffer = ch;

        VS(sharedMemorySemaphore);
        VS(bufferFullSemaphore);

        for (int i = 0; i < 1000000; i++);
    }

    printf("Producer process ended\n");
}
