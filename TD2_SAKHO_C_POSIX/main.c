#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_t createTask(void *(*start_routine)(void *), void *arg)
{
    pthread_t id;
    int erreur;
    erreur = pthread_create(&id, NULL, start_routine, arg);
    if (erreur != 0)
    {
        perror("Echec creation de tâche Posix");
        exit(-1);
    }
    return id;
}

void * displaySentence(void * s)
{
    printf("%s\n", (char *)s);
}

int main()
{
    int i;
    pthread_t task;
    char poeme[] = "Souvent, pour s’amuser, les hommes d’équipage\nPrennent des goélands, vastes oiseaux des mers,\nQui suivent, indolents compagnons de voyage,\nLe navire glissant sur les gouffres amers.";
	char delim[] = "\n";

	char *ptr = strtok(poeme, delim);

	while(ptr != NULL)
	{
        task = createTask(displaySentence, (void*)ptr);
        pthread_join( task, NULL);
        ptr = strtok(NULL, delim);
	}
    return 0;
}