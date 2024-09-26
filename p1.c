#include <stdio.h>
#include <shared.h>

int main() {
    sem_t sharedMemorySemaphore;
    sem_t bufferEmptySemaphore;
    sem_t bufferFullSemaphore;

    sharedMemorySemaphore = sem_init(120621646);
    bufferEmptySemaphore = sem_init(220621646);
    bufferFullSemaphore = sem_init(320621646);

    char *buffer;
    buffer = (char *)getmem(520621646);

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        PS(bufferFullSemaphore);
        PS(sharedMemorySemaphore);

        printf("%c\n", *buffer);

        VS(bufferEmptySemaphore);
        VS(sharedMemorySemaphore);

        for (int i = 0; i < 1000000; i++);
    }

    sem_remove(sharedMemorySemaphore);
    sem_remove(bufferEmptySemaphore);
    sem_remove(bufferFullSemaphore);

    printf("\nConsumer process ended\n");
}
