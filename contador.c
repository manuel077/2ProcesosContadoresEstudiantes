#include <stdio.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>



sem_t disponible_puertaA; //Semaforos usados para saber la disponibilidad de entrada o no del los porteros
sem_t disponible_puertaB;

void *contar_estudiante_para_c1();
void *contar_estudiante_para_c2();


pthread_create(&hilo_INTERNO1, NULL, contar_estudiante_para_c1, (void *) "Cola A"); // el "hilo_EXTERNO1" esto cambiaria dependiendo del hilo de portero de la estructura externa. 
pthread_create(&hilo_INTERNO2, NULL, contar_estudiante_para_c2, (void *) "Cola B");// el "hilo_EXTERNO2" esto cambiaria dependiendo del hilo de portero de la estructura externa.




void *contar_estudiante_para_c1(){
	int cantidad_estudiantes;


	while(true)
	{
		sem_getvalue(&disponible_puertaA, &i); // si no se se evalua si hay o no acceso de estudiantes
		
		if(i==0){
			printf("\n\t--No hay mas espacio --\n\n");
		}else{
		sem_wait(&disponible_puertaA); //esperar por la senal del estudiante
			
		cantidad_estudiantes = cantidad_estudiantes + 1;
				//printf("\t Cantidad de estudiantes ingresados: %d, en la cola 1 \n", cantidad_estudiantes);
			//simular retardo
			system("sleep 2.00");
		sem_post(&disponible_puertaA);			
		}
		return(cantidad_estudiantes);			

		}
}



void *contar_estudiante_para_c2(){
	int cantidad_estudiantes;

	while(true)
	{
		sem_getvalue(&disponible_puertaB, &i); // si no se se evalua si hay o no acceso de estudiantes
		
		if(i==0){
			printf("\n\t--No hay mas espacio --\n\n");
		}else{
		sem_wait(&disponible_puertaB); //esperar por la senal del estudiante
			
		cantidad_estudiantes = cantidad_estudiantes + 1;
				//printf("\t Cantidad de estudiantes ingresados: %d, en la cola 1 \n", cantidad_estudiantes);
			//simular retardo
			system("sleep 2.00");
		sem_post(&disponible_puertaB);			
		}
		return(cantidad_estudiantes);			

	}
}

