/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "vector.h"

/* Define what our struct is */
struct vector_t {
	size_t size;
	int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Create a new vector */
vector_t *vector_new() {
	vector_t *retval;  

	/* First, we need to allocate the memory for the struct */
	retval = malloc(1 * sizeof(vector_t));

	/* Check our return value to make sure we got memory */
	if(retval == NULL)
                allocation_failed();
	 
	/* Now we need to initialize our data */
	retval->size = 1;
	retval->data = malloc(retval->size * sizeof(int));

	/* Check our return value to make sure we got memory */
	if(retval->data == NULL) {
		free(retval);
                allocation_failed();
	}

	retval->data[0] = 0;
	
	/* and return... */
	return retval;
}

/* Free up the memory allocated for the passed vector */
void vector_delete(vector_t *v) {
	/* Remember, you need to free up ALL the memory that is allocated */

	/* ADD CODE HERE */
	if (v) { //if vector is not null
		free(v->data);
		free(v);
	}
}

/* Return the value in the vector */
int vector_get(vector_t *v, size_t loc) {

	/* If we are passed a NULL pointer for our vector, complain about it and
         * exit.
	 */
	if(v == NULL) {
		fprintf(stderr, "vector_get: passed a NULL vector.\n");
                abort();
	}

	/* If the requested location is higher than we have allocated, return 0.
	 * Otherwise, return what is in the passed location.
	 */
	if(loc < v->size) {
		return v->data[loc];
	} else {
		return 0;
	}
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
	/* What do you need to do if the location is greater than the size we have
	 * allocated?  Remember that unset locations should contain a value of 0.
	 */

	/* ADD CODE HERE */
	if (loc > v->size) {
		int* space = realloc(v->data, sizeof(int) * (loc + 1)); //+1?
		for (int i = 0; i < loc + 1; i++) {
			if (i < v->size) {  //at the index we are still smaller than the size of the array
				space[i] = v->data[i];
			} else if (i != loc) {  //it must be zero
				space[i] = 0;
			} else {
				space[i] = value;
			}
		}
		//free(v->data);
		//v->data = space; //data is now the realloc space
		v->size = loc + 1; //the size increased since we made the memory space bigger
	} 
	v->data[loc] = value;
}



