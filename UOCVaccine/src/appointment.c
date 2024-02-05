#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "appointment.h"

// Initializes a vaccination appointment data list
void appointmentData_init(tAppointmentData* list) {
    //////////////////////////////////
    // Ex PR3 1a
    /////////////////////////////////
	list->elems=NULL;
	list->count=0;
}

// Insert a new vaccination appointment
void appointmentData_insert(tAppointmentData* list, tDateTime timestamp, tVaccine* vaccine, tPerson* person) {
    //////////////////////////////////
    // Ex PR3 1b
    /////////////////////////////////
	
	assert(list != NULL);
	int i;
	int pos; 
	
	//The list is empty then
	if(list->count == 0){
		
		list->elems = (tAppointment*) malloc(sizeof(tAppointment));
		
		//Add element at first position
		list->elems[0].timestamp = timestamp;
		list->elems[0].person = person;
		list->elems[0].vaccine = vaccine;
		//Increment the count
        list->count++;
	
	} /*else if(list->count != 0){
		//The list is not empty then

			for(i=0; i < list->count; i++) { 
				//Date is the same
				if(dateTime_cmp(list->elems[i].timestamp,timestamp) == 0){
				    //Check doc order
					if(strcmp(list->elems[i].person->document,person->document) > 0){
						//Shift elements right
						for (pos=list->count; pos > i-1; pos--) {
								//list->elems[pos+1].timestamp = list->elems[pos].timestamp;
								list->elems[pos+1].person = list->elems[pos].person;
								//list->elems[pos+1].vaccine = list->elems[pos].vaccine;
							}

								//Get memory for one more element 
								list->elems=(tAppointment*)realloc(list->elems, (list->count + 1) * sizeof(tAppointment)); 
						
							    list->elems[pos].timestamp = timestamp;
								list->elems[pos].person = person;
								list->elems[pos].vaccine = vaccine;
							
							
							} 

						//Date is earlier
						} else if (dateTime_cmp(list->elems[i].timestamp,timestamp) > 0){
							
							//Get memory for one more element 
							list->elems=(tAppointment*)realloc(list->elems, (list->count + 1) * sizeof(tAppointment));
							
							//Shift elements time right
							for (pos=list->count; pos > i-1; pos--) {
								list->elems[pos+1].timestamp = list->elems[pos].timestamp;
								list->elems[pos+1].person = list->elems[pos].person;
								list->elems[pos+1].vaccine = list->elems[pos].vaccine;
								
						
								
						//Date is the last
						} else if (dateTime_cmp(list->elems[i].timestamp,timestamp) < 0){
							
							//Get memory for one more element 
							list->elems=(tAppointment*)realloc(list->elems, (list->count + 1) * sizeof(tAppointment));
							
						
							
							
						}
				
				
				
				}		
					

	}*/
}


// Remove a vaccination appointment
void appointmentData_remove(tAppointmentData* list, tDateTime timestamp, tPerson* person) {
    //////////////////////////////////
    // Ex PR3 1c
    /////////////////////////////////
	
	// Check input data
    assert(list != NULL);
	int i; 
	int pos; 
	
	pos = pos_find(list,timestamp, person);
	
		//Shift positions
		for(i=pos ; i < list->count-1; i++) {
			// Copy address of element on position i+1 to position i
			list->elems[i] = list->elems[i+1];
			
			}
		
			// Update the number of elements
			list->count--;
			
			// Resize the used memory
			if (list->count == 0) {
				// No element remaining
				free(list->elems);
				list->elems = NULL;
			} else {
				// Still some elements are remaining
				list->elems = (tAppointment*)realloc(list->elems, list->count * sizeof(tAppointment));
			}
						
					

   }
			


// Find the first instance of a vaccination appointment for given person
int appointmentData_find(tAppointmentData list, tPerson* person, int start_pos) {
    //////////////////////////////////
    // Ex PR3 1d
    /////////////////////////////////   
	int i;

	i = start_pos; 
		
		if(strcmp(list.elems[i].person->document,person->document)==0){
			return i; 
			
		} else {
			//Recursive call
		    appointmentData_find(list, person, i+1);
			
		}

	
    return -1;
}



// Release a vaccination appointment data list
void appointmentData_free(tAppointmentData* list) {
    //////////////////////////////////
    // Ex PR3 1e
    /////////////////////////////////
	
	  if(list->elems != NULL){
        list->elems = NULL;
        list->count = 0;
    }
	
}




//AUX

int pos_find(tAppointmentData* list, tDateTime timestamp, tPerson* person){
	int i; 
	int pos; 
	for(i=0; i<list->count;i++){
		//For the same day and document person
		if(dateTime_cmp(list->elems[i].timestamp, timestamp) == 0 && (strcmp(list->elems[i].person->document,person->document)==0)){
			return pos;
	}}
}
