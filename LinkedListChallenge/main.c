#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <malloc.h>

typedef struct mylist
{
    int data;
    struct mylist *next;
}mylist_t;

typedef mylist_t *list_pointer;

void insert_at_beginning (list_pointer *head, int value);
void insert_at_end (list_pointer *head, int value);
void insert_at_position (list_pointer *head, int value, int position);
void delete_any_position (list_pointer *head, int position);
void update_value (list_pointer *head, int new_value, int old_value);
void search_element (list_pointer *head, int value);
void print_list (list_pointer current_ptr);

int main()
{
    list_pointer head = NULL;
    int user_data = 0;
    int choice = 0;
    int position = 0;
    int old_user_data = 0;
    while (1)
    {
        printf("1 to insert an element at the beginning \n"
           "2 to insert an element at the end \n"
           "3 to insert an element at any position \n"
           "4 to delete an element from any position \n"
           "5 to update value \n"
           "6 to search element \n"
           "7 to print list \n"
           "Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("\n%d", &user_data);
            insert_at_beginning(&head, user_data);
            break;
        case 2:
            printf("\nEnter data: ");
            scanf("\n%d", &user_data);
            insert_at_end(&head, user_data);
            break;
        case 3:
            printf("\nEnter data: ");
            scanf("\n%d", &user_data);
            printf("\nEnter position: ");
            scanf("\n%d", &position);
            insert_at_position(&head, user_data, position);
            break;
        case 4:
            printf("\nEnter position: ");
            scanf("\n%d", &position);
            delete_any_position(&head, position);
            break;
        case 5:
            printf("\nEnter old data to be updated: ");
            scanf("%d", &old_user_data);
            printf("\nEnter new data: ");
            scanf("%d", &user_data);
            update_value(&head, user_data, old_user_data);
            break;
        case 6:
            printf("Enter the value to search: ");
            scanf("%d", &user_data);
            search_element(&head, user_data);
            break;
        case 7:
            print_list(head);
            break;

        default:
            printf("\nInvalid choice");
            break;
        }


    }

    return 0;
}

void insert_at_beginning (list_pointer *head, int value)
{
    list_pointer new_node = malloc(sizeof(mylist_t));
    new_node->data= value;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end (list_pointer *head, int value)
{
    list_pointer current_pointer;
    current_pointer = *head;
    if (current_pointer != NULL)
    {
        while (current_pointer->next != NULL)
        {
            current_pointer=current_pointer->next;
        }
        current_pointer->next = malloc (sizeof(mylist_t));
        current_pointer->next->data = value;
        current_pointer->next->next = NULL;
    }
    else if (current_pointer == NULL)
    {
        current_pointer = malloc (sizeof(mylist_t));
        current_pointer->data = value;
        current_pointer->next = NULL;
        *head = current_pointer;
    }

}
void insert_at_position (list_pointer *head, int value, int position)
{
    int i = 0;
    list_pointer current_pointer;
    list_pointer previous_pointer;
    list_pointer new_node;

    new_node = malloc(sizeof(mylist_t));
    current_pointer = *head;

    if (new_node !=NULL)
    {
        new_node->data = value;
        new_node->next = NULL;
        previous_pointer = NULL;
        current_pointer = *head;

        for (i=0; i<(position-1); i++)
        {
            previous_pointer = current_pointer;
            current_pointer = current_pointer->next;
        }
        if (previous_pointer == NULL)
        {
            new_node->next = *head;
            *head = new_node;
        }
        else
        { //insert new node between previousPtr and currentPtr
            previous_pointer ->next = new_node;
            new_node->next = current_pointer;
        }
    }

    else
    {
        printf("%c not inserted. no memory available", value);
    }
}
void delete_any_position (list_pointer *head, int position)
{

}
void update_value (list_pointer *head, int new_value, int old_value)
{

}
void search_element (list_pointer *head, int value)
{

}

void print_list(list_pointer current_ptr)
{
    if (current_ptr!= NULL)
    {
        while (current_ptr!= NULL)
        {
            printf("%d-->", current_ptr->data);
            current_ptr=current_ptr->next;
        }
    }
    else
    {
        printf("\nThe list is empty");
    }

    printf("NULL\n\n");
}
