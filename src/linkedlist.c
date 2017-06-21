#include <stdio.h>
#include "linkedlist.h"

void listInit(LinkedList *list){
	list->head=NULL;
	list->tail=NULL;
	list->len=0;
	}
	

void listAdd(LinkedList *list,Item *item){
	if(list->len==0){
		list->head=item;
		list->tail=item;
		list->len=1;
		item->next=NULL;
	}
	else
	{
		list->tail->next=item;
		list->len+=1;
		list->tail=item;
		item->next=NULL;
	}
}

Item *listRemove(LinkedList *list,char *name){
	Student *student;
	student =(Student *)(list->head->data);
	Item *temphead= list->head;
	Item *prev=NULL;
	Item *forw=NULL;
	
	if(list->head==NULL)
		return NULL;
	
	else{
		while(strcmp(student->name,name)!=0){
			prev=list->head;
			list->head=list->head->next;
			}
	
	/* 
	 * remove the last data...
	 */
			if(forw==NULL){
				list->head->next=NULL;		//delete the data;
				list->head=temphead;		//restore the head;
				list->tail=prev;
				list->len--;
				}
	
	/*
	 * remove the first data...
	 */
			else if(list->head==temphead){
				list->head=temphead->next;
				list->head->next=list.tail;
				list->len--;
				}
				
			
				
		}	
}