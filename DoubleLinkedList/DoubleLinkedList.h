/*
 * DoubleLinkedList.h
 *
 * Created: 3 NOV 2022
 * Author : Mohamed Nagy
 */


#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H


 /************************************************************************/
 /*                   section : includes                                 */
 /************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "StdTypes.h"

 /************************************************************************/
 /*                   section: data type declaration                     */
 /************************************************************************/

typedef struct
{
    uint32 NodeData;
    ST_node_t* LeftNodeLink;
    ST_node_t* RightNodeLink;
}ST_node_t;


/************************************************************************/
/*                   section: functions declarations                    */
/************************************************************************/

void Insert_Node_At_Beginning(ST_node_t** List, uint32 Data);
void Insert_Node_At_End(ST_node_t* List, uint32 Data);
void Insert_Node_After(ST_node_t* List, uint32 Data, uint32 position);
void Insert_Node_Before(ST_node_t** List, uint32 Data, uint32 position);
void Delete_Node_At_Beginning(ST_node_t** List);
void Delete_Node_At_End(ST_node_t* List);
void Delete_Node_At_Intermediate(ST_node_t* List, uint32 position);
void Display_All_Nodes_Forward(ST_node_t* List);
void Display_All_Nodes_Reverse(ST_node_t* List);


#endif // _DOUBLE_LINKED_LIST_H