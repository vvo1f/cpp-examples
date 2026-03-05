#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define N (1024, 1024)

int main() {
    key_t key = ftok("shmfile", 65); // Generate a unique key
    int shmid = shmget(key, N, 0644 | IPC_CREAT); // Create shared memory segment
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *r = (char *) shmat(shmid, NULL, 0); // Attach shared memory segment
    if (r == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    int i = 0;
    int j = N - 1;
    char c1, c2;

    do {
        scanf("%c", &c1); // Read a character from stdin
        r[i++] = c1; // Write the character to shared memory

        c2 = r[j--]; // Read a character from the end of shared memory
        fprintf(stdout, "%d\n", c2); // Print the character as an integer
    } while (1);

    // Detach from shared memory
    if (shmdt(r) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Destroy the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}