/*
 * DoubleLinkedList.c
 *
 * Created: 3 NOV 2022
 * Author : Mohamed Nagy
 */


#include "DoubleLinkedList.h"

int main()
{
    ST_node_t* DLL_1 = NULL;

    Insert_Node_At_Beginning(&DLL_1, 11);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_At_Beginning(&DLL_1, 22);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_At_Beginning(&DLL_1, 33);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Insert_Node_At_End(DLL_1, 99);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_At_End(DLL_1, 100);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");

    Insert_Node_After(DLL_1, 44, 2);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_After(DLL_1, 55, 3);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_After(DLL_1, 66, 5);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Insert_Node_Before(&DLL_1, 77, 3);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_Before(&DLL_1, 88, 1);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Delete_Node_At_Beginning(&DLL_1);
    Display_All_Nodes_Reverse(DLL_1);
    Delete_Node_At_Beginning(&DLL_1);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Delete_Node_At_End(DLL_1);
    Display_All_Nodes_Reverse(DLL_1);
    Delete_Node_At_End(DLL_1);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Delete_Node_At_Intermediate(DLL_1, 2);
    Display_All_Nodes_Reverse(DLL_1);
    Delete_Node_At_Intermediate(DLL_1, 3);
    Display_All_Nodes_Reverse(DLL_1);

    return 0;
}
