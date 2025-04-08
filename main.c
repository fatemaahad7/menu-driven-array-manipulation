#include<stdio.h>
int a[50], size, i;
void display();
void insert();
void update_by_index();
void update_by_value();
void search();
void delete_by_index();
void delete_by_value();
void largest_smallest();

int main(){
    printf("Create an array a[50]\n");

    printf("Enter the number of elements you want to add(1-50): ");
    scanf("%d", &size);

    while(size > 50 || size < 1){
        printf("Value must be between 1 to 50, try again! \n");
        printf("Enter the number of elements you want to add(1-50): ");
        scanf("%d", &size);
    }
    
    for(i = 0; i < size; i++){
        printf("Enter any positive or negative value for a[%d]: ", i);
        scanf("%d", &a[i]);
        while(a[i] == 0){
            printf("0 is an invalid value.\nEnter any positive or negative value for a[%d]: ", i);
            scanf("%d", &a[i]);
        }
    }

    display();

    int choice;
    do{
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Largest & Smallest Value\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter Your Choice (1-7): ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                if(size == 50){
                    printf("Array is Full! Insertion cannot be performed. \n");
                }
                else{
                    printf("~ ~ ~ Insertion initiated ~ ~ ~ \n");
                    insert();
                }
                break;

            case 2:
                if(size == 0){
                    printf("Array is empty! Update cannot be performed. \n");
                }
                else{
                    printf("Options: \n");
                    int update_choice;
                    
                    printf("1. Update by index no. \n");
                    printf("2. Update by value. \n");
                    printf("Enter your choice (1-2): ");
                    scanf("%d", &update_choice);

                    switch(update_choice){
                        case 1:
                            printf("\n~ ~ ~ Update by index no. initiated ~ ~ ~ \n");
                            update_by_index();
                            break;
                            
                        case 2:
                            printf("\n~ ~ ~ Update by value initiated ~ ~ ~ \n");
                            update_by_value();
                            break;
                            
                        default:
                            printf("Invalid choice! \n");
                    }
                }
                break;
            case 3:
                if(size == 0){
                    printf("Array is empty! Search cannot be performed. \n");
                }
                else{
                    printf("~ ~ ~ Search initiated ~ ~ ~ \n");
                    search();
                }
                break;

            case 4:
                if(size == 0){
                    printf("Array is empty! Delete cannot be performed. \n");
                }
                else{
                    printf("Options: \n");
                    int delete_choice;
                    
                    printf("1. Delete by index no. \n");
                    printf("2. Delete by value. \n");
                    printf("Enter your choice (1-2): ");
                    scanf("%d", &delete_choice);
    
                    switch(delete_choice){
                        case 1:
                            printf("\n~ ~ ~ Delete by index no. initiated ~ ~ ~ \n");
                            delete_by_index();
                            break;
                            
                        case 2:
                            printf("\n~ ~ ~ Delete by value initiated ~ ~ ~ \n");
                            delete_by_value();
                            break;
                            
                        default:
                            printf("Invalid choice! \n");
                    }
                }
                break;

            case 5:
                if(size == 0){
                    printf("Array is empty! Finding largest & smallest value cannot be performed. \n");
                }
                else{
                    printf("~ ~ ~ Largest & Smallest Value ~ ~ ~ \n");
                    largest_smallest();
                }
                break;

            case 6:
                printf("~ ~ ~ Display initiated ~ ~ ~ \n");
                display();
                break;
        
            case 7:
                printf("Exiting the program.\n");
                break;
            
            default:
                printf("Invalid input, try again!\n");
        }
    }while(choice != 7);

    return 0;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *




// Display array elements Function
void display(){
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    if(size == 0){
        printf("Array is empty!!! No value to show.");
    }
    else{
        printf("Array elements a[%d]: ", size);
        for(i = 0; i < size; i++){
            printf("%d ",a[i]);
        }
    }
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


// Insert an element by index Function
void insert(){
    int insert_index, insert_value;
    
    printf("Enter the index no. where you want to insert (0-%d): ", size);
    scanf("%d", &insert_index);

    if(insert_index > size || insert_index < 0){
        printf("Invalid index no.! No insertion performed.\n");
    }
    else{
        printf("Enter any positive or negative value : ");
        scanf("%d", &insert_value);

        while(insert_value == 0){
            printf("0 is an invalid value.\nEnter any positive or negative value : ");
            scanf("%d", &insert_value);
        }
    
        for(i = size; i > insert_index; i--){
            a[i] = a[i-1];
        }
    
        a[insert_index] = insert_value;
        size++;
    }

    display();
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


// Update an element by index Function
void update_by_index(){
    int update_index, update_value;
    printf("Enter the index no. you want to update (0-%d): ", size-1);
    scanf("%d", &update_index);
    
    if(update_index > size-1 || update_index < 0){
        printf("Invalid index no.! No update performed.\n");
    }
    else{
        printf("Previous value of a[%d] = %d\n", update_index, a[update_index]);
        printf("Enter the updated value: ");
        scanf("%d", &update_value);

        while(update_value == 0){
            printf("0 is an invalid value.\nEnter any positive or negative value : ");
            scanf("%d", &update_value);
        }

        a[update_index] = update_value;   
    }
    
    display();
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


// Update an element by value Function
void update_by_value(){
    int old_value, old_value_count = 0, updated_value;

    printf("Enter the value you want to update: ");
    scanf("%d", &old_value);

    for(i = 0; i < size; i++){
        if(a[i] == old_value){
            old_value_count++;
        }
    }

    if(old_value_count == 0){
        printf("%d is not in the array! No update performed. \n", old_value);
    }
    else{
        printf("Enter the updated value: ");
        scanf("%d", &updated_value);

        while(updated_value == 0){
            printf("0 is an invalid value.\nEnter any positive or negative value : ");
            scanf("%d", &updated_value);
        }

        for(i = 0; i < size; i++){
            if(a[i] == old_value){
                a[i] = updated_value;
            }
        }
    }

    display();
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


// Search an element by value Function
void search(){
    int search_value, found_count = 0;
    
    printf("Enter the value you're searching? ");
    scanf("%d", &search_value);
    
    for(i = 0; i < size; i++){
        if(search_value == a[i]){
            found_count++;
        }
    }
    
    if(found_count == 0){
        printf("%d not found in the array.\n", search_value);
    }
    else if(found_count == 1){
        for(i = 0; i < size; i++){
            if(search_value == a[i]){
                printf("%d found in the array at index [%d]\n", search_value, i);
                break;
            }
        }
    }
    else{
        printf("%d found in multiple index: ", search_value);
        for(i = 0; i < size; i++){
            if(search_value == a[i]){
                printf("[%d] ", i);
            }
        }
        printf("\n");  
    }

    display();
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


// Delete an element by Index Function
void delete_by_index(){
    int delete_index;
    
    printf("Enter the index no. you want to delete (0-%d) : ", size-1);
    scanf("%d", &delete_index);
    
    if(delete_index >= size || delete_index < 0){
        printf("Invalid index no.! No deletion performed.\n");
    }
    else{
        for(i = delete_index; i < size; i++){
            a[i] = a[i+1];
        }
        size--;
    }

    display();
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


// Delete an element by Value Function
void delete_by_value(){
    int delete_value, i = 0, delete_value_count = 0, j;
    
    printf("Enter the value you want to delete? ");
    scanf("%d", &delete_value);

    for(j = 0; j < size; j++){
        if(delete_value == a[j]){
            delete_value_count++;
        }
    }

    if(delete_value_count == 0){
        printf("%d is not found in the array! No deletion performed.\n", delete_value);
    }
    else{
        for(j = 0; j < size; j++){
            if(delete_value != a[j]){
                a[i] = a[j];
                i++;
            }
        }
    }
    
    size -= delete_value_count;
    display();
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


// Largest & Smallest Value Function
void largest_smallest(){
    int largest_value = a[0], smallest_value = a[0];
    
    for(i = 1; i < size; i++){
        if(largest_value < a[i]){
            largest_value = a[i];
        }
        if(smallest_value > a[i]){
            smallest_value = a[i];
        }
    }
    printf("Largest Value = %d\n", largest_value);
    printf("Smallest Value = %d\n", smallest_value);

    display();
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *