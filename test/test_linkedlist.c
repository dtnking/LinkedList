#include "unity.h"
#include "linkedlist.h"
#include "student.h"

void setUp(void)
{
}

void tearDown(void)
{
}

Student ali= {
		"Ali",
		23,
		72.35,
		1.78
		};
		
Item itemAli={
	(Item *)-1,
	(void*)&ali
	};
	
	
Student baba= {
		"BABA",
		22,
		73.35,
		1.80
		};
		
Item itemBaba={
	(Item *)-1,
	(void*)&baba
	};
	
Student Abu={
	"Abu",
	23,
	68.1,
	1.9
};

Item itemAbu={
	(Item *)-1,
	(void*)&Abu
};
	
void test_listInit_ensure_initialized_to_NULL_and_zero(void)
{
	LinkedList list={
	(Item *)-1,
	(Item *)-1,
	10
	};
	
    listInit(&list);
	
	TEST_ASSERT_NULL(list.head);
	TEST_ASSERT_NULL(list.tail);
	TEST_ASSERT_EQUAL(0,list.len);
}

/**
 *	
 *	Initial					After adding Ali
 *
 *	tail ----+				tail ----+
 *	head ----+				head ----+
 *			 |						 |
 *			NULL					next -------+	
 *									data --+    |	
 *										   |   NULL
 *										  Ali
 *										  ..			
 *
 * Given an empty linked list. Add Ali (student). Expect the linked list 
 * contain Ali.
 */										  
 
void test_listAdd_given_an_empty_linked_list_then_add_ali_expect_1_item_in_list(void){
	LinkedList list;
   
	listInit(&list);
	listAdd(&list,&itemAli);
	TEST_ASSERT_EQUAL_PTR(&itemAli,list.head);
	TEST_ASSERT_EQUAL_PTR(&itemAli,list.tail);
	TEST_ASSERT_EQUAL(1,list.len);
	TEST_ASSERT_NULL(itemAli.next);
	TEST_ASSERT_EQUAL_PTR(&ali,itemAli.data);
}

void test_listAdd_given_linked_list_with_Ali_then_add_Baba_expect_2_items_in_list(void){
	LinkedList list;
	
	list.head=&itemAli;
	list.tail=&itemAli;
	list.len=1;
	itemAli.next=NULL;
	itemBaba.next=(Item *)-1;
	
	listAdd(&list,&itemBaba);
	
	TEST_ASSERT_EQUAL_PTR(&itemAli,list.head);
	TEST_ASSERT_EQUAL_PTR(&itemBaba,list.tail);
	TEST_ASSERT_EQUAL(2,list.len);
	TEST_ASSERT_EQUAL_PTR(&itemBaba,itemAli.next);
	TEST_ASSERT_EQUAL_PTR(&baba,itemBaba.data);
	TEST_ASSERT_NULL(itemBaba.next);
	TEST_ASSERT_EQUAL_PTR(&baba,itemBaba.data);
}

void test_listAdd_given_linked_list_with_Ali_and_Baba_then_add_Abu_expect_3_items_in_list(void){
	LinkedList list;
	
	list.head=&itemAli;
	list.tail=&itemBaba;
	list.len=2;
	itemBaba.next=NULL;
	itemBaba.next=(Item *)-1;
	
	listAdd(&list,&itemAbu);
	
	TEST_ASSERT_EQUAL_PTR(&itemAli,list.head);
	TEST_ASSERT_EQUAL_PTR(&itemAbu,list.tail);
	TEST_ASSERT_EQUAL(3,list.len);
	TEST_ASSERT_EQUAL_PTR(&itemAbu,itemBaba.next);
	TEST_ASSERT_EQUAL_PTR(&Abu,itemAbu.data);
	TEST_ASSERT_NULL(itemAbu.next);
	TEST_ASSERT_EQUAL_PTR(&Abu,itemAbu.data);
	TEST_ASSERT_EQUAL_PTR(&baba,itemBaba.data);
}

