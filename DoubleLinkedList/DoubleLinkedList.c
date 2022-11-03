/*
 * DoubleLinkedList.c
 *
 * Created: 3 NOV 2022
 * Author : Mohamed Nagy
 */


#include "DoubleLinkedList.h"

#define DELETE_NODE_AT_BEGINNING



 /**
   * @brief  Inserts a new node at the beggining of the list.
             Validate the case of temp head node
             and validate the case of empty linked list
   * @param  (List) pointer to linked list head structure.
             (Data) the data to be inserted
   * @retval void ret.
   */
void Insert_Node_At_Beginning(ST_node_t** List, uint32 Data)
{
    ST_node_t* TempNode = NULL; /* Points to the new node */

    TempNode = (ST_node_t*)malloc(sizeof(ST_node_t));
    if (NULL != TempNode)
    {
        TempNode->NodeData = Data;
        /* Check if the list is empty */
        if (NULL == *List)
        {
            TempNode->LeftNodeLink = NULL;  /* This is the only node */
            TempNode->RightNodeLink = NULL; /* This is the only node */
            (*List) = TempNode;   /* Make the Head pointer points to this only node */
        }
        else
        {
            TempNode->RightNodeLink = (*List); /* Make the new node to be the head */
            TempNode->LeftNodeLink = NULL;     /* The LeftNodeLink always NULL in the Head node */
            (*List)->LeftNodeLink = TempNode;  /* This now became the second node */
            (*List) = TempNode; /* Make the Head pointer points to the new node */
        }
    }
    else
    {
        printf("Can't allocate the new node !! \n");
    }
}



/**
  * @brief  Inserts a new node at the end of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
            (Data) the data to be inserted
  * @retval void ret.
  */
void Insert_Node_At_End(ST_node_t* List, uint32 Data)
{
    ST_node_t* TempNode = NULL; /* Points to the new node */
    ST_node_t* NodeListCounterOne = NULL;  /* Traverse to the needed node */
    TempNode = (ST_node_t*)malloc(sizeof(ST_node_t));
    if (NULL != TempNode)
    {
        TempNode->NodeData = Data;
        TempNode->RightNodeLink = NULL;
        NodeListCounterOne = List;
        while (NULL != NodeListCounterOne->RightNodeLink)
        {
            NodeListCounterOne = NodeListCounterOne->RightNodeLink;
        }
        TempNode->LeftNodeLink = NodeListCounterOne;
        NodeListCounterOne->RightNodeLink = TempNode;
    }
    else
    {
        printf("Can't allocate the new node !! \n");
    }
}



/**
  * @brief  Inserts a new node after specific index of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.

            (Data) the data to be inserted
  * @retval void ret.
  */
void Insert_Node_After(ST_node_t* List, uint32 Data, uint32 position)
{
    ST_node_t* TempNode = NULL;            /* Points to the new node */
    ST_node_t* NodeListCounterOne = NULL;  /* Traverse to the needed node */
    ST_node_t* NodeListCounterTwo = NULL;  /* Traverse to the needed node */

    NodeListCounterOne = List; /* Points to the head node now */
    while (position != 1)
    {
        NodeListCounterOne = NodeListCounterOne->RightNodeLink; /* Move the pointer */
        position--;
    }

    /* Create the new node */
    TempNode = (ST_node_t*)malloc(sizeof(ST_node_t));
    if (NULL != TempNode)
    {
        TempNode->NodeData = Data;
        /* Check if we reach the End Node of the List :: Adding the new node at the end */
        if (NULL == NodeListCounterOne->RightNodeLink)
        {
            NodeListCounterOne->RightNodeLink = TempNode;
            TempNode->LeftNodeLink = NodeListCounterOne;
            TempNode->RightNodeLink = NULL;
        }
        else
        {
            NodeListCounterTwo = NodeListCounterOne->RightNodeLink;
            /* Update the information of the new node */
            NodeListCounterOne->RightNodeLink = TempNode; /* Make the left node points to the new node */
            NodeListCounterTwo->LeftNodeLink = TempNode;  /* Make the right node points to the new node */
            TempNode->LeftNodeLink = NodeListCounterOne;  /* Update the left pointer of the new node */
            TempNode->RightNodeLink = NodeListCounterTwo; /* Update the right pointer of the new node */
        }
    }
    else
    {
        printf("Can't allocate the new node !! \n");
    }
}



/**
  * @brief  Inserts a new node before specific index of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
            (Data) the data to be inserted
  * @retval void ret.
  */
void Insert_Node_Before(ST_node_t** List, uint32 Data, uint32 position)
{
    ST_node_t* TempNode = NULL;            /* Points to the new node */
    ST_node_t* NodeListCounterOne = NULL;  /* Traverse to the needed node */
    ST_node_t* NodeListCounterTwo = NULL;  /* Traverse to the needed node */
    uint32 NodePosition = position;

    NodeListCounterOne = (*List); /* Points to the head node now */
    while (NodePosition > position - 1)
    { /* This to point to the node before the given position */
        NodeListCounterOne = NodeListCounterOne->RightNodeLink;
        NodePosition--;
    }

    /* Create the new node */
    TempNode = (ST_node_t*)malloc(sizeof(ST_node_t));
    if (NULL != TempNode)
    {
        TempNode->NodeData = Data;
        /* Check if the position = 1 :: Adding the new node at the beginning */
        if (1 == position)
        {
            TempNode->LeftNodeLink = NULL;  /* This is the only node */
            TempNode->RightNodeLink = *List;
            (*List)->LeftNodeLink = TempNode;
            *List = TempNode;
        }
        else
        {
            NodeListCounterTwo = NodeListCounterOne->RightNodeLink;
            NodeListCounterOne->RightNodeLink = TempNode;
            NodeListCounterTwo->LeftNodeLink = TempNode;
            TempNode->RightNodeLink = NodeListCounterTwo;
            TempNode->LeftNodeLink = NodeListCounterOne;
        }
    }
    else {
        printf("Can't allocate the new node !! \n");
    }
}



/**
  * @brief  Deletes a node from the beggining of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval void ret.
  */
void Delete_Node_At_Beginning(ST_node_t** List)
{
    struct Node* TempNode = *List; /* Points to the node that we need to delete */

#ifdef DELETE_NODE_AT_BEGINNING
    /* Update the head node */
    * List = (*List)->RightNodeLink;
    (*List)->LeftNodeLink = NULL;
    /* Free the first node */
    free(TempNode);
    TempNode = NULL;
#else
    * List = (*List)->RightNodeLink;
    free((*List)->LeftNodeLink);
    (*List)->LeftNodeLink = NULL;
#endif
}



/**
  * @brief  Deletes a node from the end of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval void ret.
  */
void Delete_Node_At_End(ST_node_t* List)
{
    ST_node_t* NodeListCounterOne = NULL;
    ST_node_t* NodeListCounterTwo = NULL;

    NodeListCounterOne = List;
    while (NodeListCounterOne->RightNodeLink != NULL)
    {
        NodeListCounterOne = NodeListCounterOne->RightNodeLink;
    }
    NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
    NodeListCounterTwo->RightNodeLink = NULL;
    free(NodeListCounterOne);
    NodeListCounterOne = NULL;
}



/**
  * @brief  Inserts a new node at the beggining of the list.
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
            (position) the position of the node to be deleted
  * @retval void ret.
  */
void Delete_Node_At_Intermediate(ST_node_t* List, uint32 position)
{
    ST_node_t* NodeListCounterOne = NULL;
    ST_node_t* NodeListCounterTwo = NULL;
    uint32 NodePosition = position;

    if (1 == NodePosition)
    {
        printf("Please use the Delete_Node_At_Beginning !! \n");
    }
    else {
        NodeListCounterOne = List;
        while (NodePosition > 1)
        {
            NodeListCounterOne = NodeListCounterOne->RightNodeLink;
            NodePosition--;
        }

        NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
        NodeListCounterTwo->RightNodeLink = NodeListCounterOne->RightNodeLink;
        NodeListCounterOne->RightNodeLink->LeftNodeLink = NodeListCounterTwo;
        free(NodeListCounterOne);
        NodeListCounterOne = NULL;
    }
}



/**
  * @brief  Deletes all the nodes of the list in the forward direction
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval void ret.
  */
void Display_All_Nodes_Forward(ST_node_t* List)
{
    ST_node_t* TempNode = List;

    printf("\nTraversal in forward direction ==> ");
    printf("Data : ");
    printf("%d -> ", TempNode->NodeData);
    while (TempNode->RightNodeLink != NULL)
    {
        TempNode = TempNode->RightNodeLink;
        printf("%d -> ", TempNode->NodeData);
    }
    if (NULL == TempNode->RightNodeLink)
    {
        printf("NULL");
    }
    printf("\n");
}



/**
  * @brief  Deletes all the nodes of the list in the reverse direction
            Validate the case of temp head node
            and validate the case of empty linked list
  * @param  (List) pointer to linked list head structure.
  * @retval void ret.
  */
void Display_All_Nodes_Reverse(ST_node_t* List)
{
    ST_node_t* TempNode = List;

    printf("\nTraversal in reverse direction ==> ");
    printf("Data : ");
    while (TempNode->RightNodeLink != NULL)
    {
        TempNode = TempNode->RightNodeLink;
    }
    while (TempNode != NULL)
    {
        printf("%d -> ", TempNode->NodeData);
        TempNode = TempNode->LeftNodeLink;
    }
    if (NULL == TempNode)
    {
        printf("NULL");
    }
    printf("\n");
}