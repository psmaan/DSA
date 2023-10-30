#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Task{
	char subject[50];
	char task_des[100];
	char deadline[20];
	int hours;
	int minutes;
	struct Task *next;
};

struct Task * tasklist = NULL;

void add(char subject[], char task_des[],char deadline[],int hours, int minutes){
	struct Task * newTask = (struct Task*)malloc(sizeof(struct Task));
	strcpy(newTask->subject,subject);
	strcpy(newTask->task_des,task_des);
	strcpy(newTask->deadline,deadline);
	newTask->hours = hours;
	newTask->minutes = minutes;
	newTask->next = NULL;
	
	if(tasklist==NULL){
		tasklist= newTask;
	}
	else{
		struct Task * current = tasklist;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newTask;
	}
}

int compareTask(const void* task1, const void * task2){
	struct Task * t1 = *(struct Task**)task1;
	struct Task * t2 = *(struct Task**)task2;
	
	int deadlineComparsion = strcmp(t1->deadline, t2->deadline);
	if(deadlineComparsion != 0){
		return deadlineComparsion;
	}
	if(t1->hours < t2->hours){
		return -1;
	}
	else if(t1->hours > t2->hours){
		return 1;
	}
	else{
		if(t1->minutes < t2-> minutes){
			return -1;
		}
		else if(t1-> minutes > t2-> minutes){
			return 1;
		}
		else{
			return 0;
		}
	}
	
}

struct Task * search_task(char subject[]){
	struct Task * current = tasklist;
	while(current != NULL){
		if(strcmp(current->subject,subject) == 0){
			return current;
		}
		current = current->next;
	}
	return NULL;
}

void sort(){
	struct Task*current = tasklist;
	while(current != NULL){
		struct Task* min_task = current;
		struct Task * next_task = current->next;
		while(next_task != NULL){
			if(compareTask(&min_task,&next_task) > 0){
				min_task = next_task;
			}
			next_task = next_task->next;
		}
		
		struct Task temp;
		strcpy(temp.subject, current->subject);
		strcpy(temp.task_des, current->task_des);
		strcpy(temp.deadline,current->deadline);
		temp.hours = current->hours;
		temp.minutes = current->minutes;
		
		strcpy(current->subject, min_task->subject);
		strcpy(current->task_des, min_task->task_des);
		strcpy(current->deadline, min_task->deadline);
		current->hours = min_task->hours;
		current->minutes = min_task->minutes;
		
		strcpy(min_task->subject, temp.subject);
		strcpy(min_task->task_des,temp.task_des);
		strcpy(min_task->deadline,temp.deadline);
		min_task->hours = temp.hours;
		min_task->minutes = temp.minutes;
		
		current = current->next;
		
	}
}


void display(){
	int i;
	struct Task * taskArray[100];
	struct Task* current = tasklist;
	int taskcount = 0;
	
	while(current != NULL ){
		taskArray[taskcount] = current;
		taskcount++;
		current = current->next;
	}
	qsort(taskArray,taskcount,sizeof(struct Task*),compareTask);
	
	for(i = 0 ; i < taskcount ; i++){
		printf("Subject: %s\n", taskArray[i]->subject); // Corrected the struct member name
        printf("Description: %s\n", taskArray[i]->task_des); // Corrected the struct member name
        printf("Deadline: %s %02d:%02d\n", taskArray[i]->deadline, taskArray[i]->hours, taskArray[i]->minutes);
        printf("\n");
	}
}

void free_task(){
	struct Task* current = tasklist;
	while(current != NULL){
		struct Task * temp = current;
		current = current->next;
		free(temp);
	}
}

int main(){
	int choice = 0;
	char subject[50], task_des[100], deadline[20];
	int hours , minutes;
	
	printf("----------TASK SCHEDULER FOR STUDENTS--------------------\n");
	
	while(1){
		printf(".............Task Scheduler Operation...................\n");
		printf("1. Add Task \n");
		printf("2. Display Tasks \n");
		printf("3. Search Task by title \n");
		printf("4. Sort Tasks by Time \n");
		printf("5. Exit \n");
		printf("Follow the operation from 1 to 5 : ");
		scanf("%d",&choice);
		
		while(getchar() != '\n');
		
		switch(choice){
			case 1:
				printf("Enter the subject : ");
				scanf(" %[^\n]", &subject);
				while(getchar() != '\n');
				
				printf("Enter the description of the task  : ");
				scanf(" %[^\n]", &task_des);
				while(getchar() != '\n');
				
				printf("Enter the deadline (YYYY-MM-DD) : ");
				scanf("%s", &deadline);
				while(getchar() != '\n');
				
				printf("Enter the deadline time(HH:MM) : ");
				scanf("%d:%d",&hours,&minutes);
				while(getchar() != '\n');
				
				add(subject,task_des,deadline,hours,minutes);
				break;
				
			case 2:
				printf("Task List(Deadline and Time):\n");
				display();
				break;
				
			case 3:
				printf("Enter the task subject to search : ");
				scanf("%[^\n]",subject);
				while(getchar() != '\n');
				
				struct Task* found_task = search_task(subject);
				if(found_task != NULL){
					printf("Task found : \n");
					printf("Subject : %s\n", found_task->subject);
					printf("Description : %s\n", found_task->task_des);
					printf("Deadline : %s %02d:%02d\n", found_task->deadline, found_task->hours, found_task->minutes);
					
				}
				else{
					printf("Task not found.\n");
					
				}
				break;
				
			case 4: 
				printf("Sorting Task by time......\n");
				sort();
				display();
				printf("Tasks sorted.......\n");
				break;
			
			case 5:
				free_task();
				exit(0);
				break;
			
			default:
				printf("Invalid Choice.....\n");
				break;			
		}
	}
	return 0;
}
