/* Condition Variables */
/* Pseudo code */

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
int done = 0;

void *T1() {
    pthread_mutex_lock(&m);
    while (done == 0)
        pthread_cond_wait(&cv, &m);
    pthread_mutex_unlock(&m);
    return 0;
}

void *T2() {
    pthread_mutex_lock(&m);
    done = 1;
    pthread_cond_broadcast(&cv);
    pthread_mutex_unlock(&m);
    return NULL;
}