// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>

int i = 0;
pthread_mutex_t lock;


// Note the return type: void*
void* incrementingThreadFunction(){
    // TODO: increment i 1_000_000 times
    for(int index = 0; index < 1000000; index++){
		pthread_mutex_lock(&lock);
		i++;
		pthread_mutex_unlock(&lock);
	}
    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    for(int index = 0; index < 1000000; index++){
		pthread_mutex_lock(&lock);
		i--;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}


int main(){
    // TODO: 
    // start the two functions as their own threads using `pthread_create`
    // Hint: search the web! Maybe try "pthread_create example"?
    pthread_t thread1, thread2;
	
	if(pthread_mutex_init(&lock, NULL) != 0){
		perror("Failed to initialize mutex!");
		exit(1);
	}
	    
    if(pthread_create(&thread1, NULL, incrementingThreadFunction, NULL) != 0){
		perror("Failed to create the thread!");
		exit(1);
	}
	
	if(pthread_create(&thread2, NULL, decrementingThreadFunction, NULL) != 0){
		perror("Failed to create the thread!");
		exit(1);
	}
	
    // TODO:
    // wait for the two threads to be done before printing the final result
    // Hint: Use `pthread_join`    
    

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	pthread_mutex_destroy(&lock);
	
	printf("The magic number is: %d\n", i);

    return 0;
}
