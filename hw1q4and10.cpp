#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    Node *temp;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void insert(int x) //Inserts x to the front of the list
    {
        temp = new Node;
        temp->data = x;
        if (isEmpty())
        {
            temp->next = NULL;
            tail = temp;
        }
        else
            temp->next = head;
        head = temp;
    }

    void insertionSortLL(struct Node **head_ref)
    {
        // Initialize sorted linked list
        struct Node *sorted = NULL;

        // Traverse the given linked list and insert every
        // node to sorted
        struct Node *current = *head_ref;
        while (current != NULL)
        {
            // Store next for next iteration
            struct Node *next = current->next;

            // insert current in sorted linked list
            sortedInsertLL(&sorted, current);

            // Update current
            current = next;
        }

        // Update head_ref to point to sorted linked list
        *head_ref = sorted;
    }

    // Bubble sort the given linked list, note that this does not handle the empty case
    void bubbleSortLL(struct Node *start)
    {
        int swapped, i;
        struct Node *ptr1;
        struct Node *lptr = NULL;

        do
        {
            swapped = 0;
            ptr1 = start;

            while (ptr1->next != lptr)
            {
                if (ptr1->data > ptr1->next->data)
                {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    //Question 10
    LinkedList OddEvenSort(LinkedList list)
    {
        struct Node *current = list.head;
        LinkedList oddList;
        LinkedList evenList;
        while (current != NULL)
        {
            if (current->data % 2 == 0) //even number
            {
                evenList.insert(current->data);
            }
            else//odd number
            {
                oddList.insert(current->data);
            }
            current = current->next;
        }
        LinkedList done;
        done.head = oddList.head;
        oddList.tail->next = evenList.head;
        done.tail = evenList.tail;
        return done;
    }

    //prints out linkedList
    void display()
    {
        if (!isEmpty())
        {
            for (temp = head; temp != NULL; temp = temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "List is Empty!" << endl;
        }
    }

    //function to swap data of two nodes a and b (necessary for bubble sort)
private:
    void swap(struct Node *a, struct Node *b)
    {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

private:
    void sortedInsertLL(struct Node **head_ref, struct Node *new_node)
    {
        struct Node *current;
        // Special case for the head end
        if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
        {
            new_node->next = *head_ref;
            *head_ref = new_node;
        }
        else
        {
            // Locate the node before the point of insertion
            current = *head_ref;
            while (current->next != NULL &&
                   current->next->data < new_node->data)
            {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }
};

//insertionSort for an array of integers
void insertionSort(int arr[], int n)
{
    int i, num, j;
    for (i = 1; i < n; i++)
    {
        num = arr[i];
        j = i - 1;
        /* Move elements that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > num)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = num;
    }
}

// swap method, which is necessary for the bubble Sort below this function
void swapInts(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Bubble sort for an array of integers
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swapInts(&arr[j], &arr[j + 1]);
}

//used to print out the contents of an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    LinkedList l1;

    //initialize a random seed (necessary for the rand function call)
    srand(time(NULL));
    for (int i = 0; i < 10; i++)//fills linked list with random values
    {
        //randomly generate a number
        int num = rand() % 100;
        l1.insert(num);
    }

    cout << "\nL1 Randomly generated:" << endl;
    l1.display();

    //to see the result of the bubbleSort or insertionSort only  uncomment one of the function calls at a time
    cout << "\nL1 after using one of the sort methods:" << endl;
    //l1.bubbleSortLL(l1.head);
    //l1.insertionSortLL(&l1.head);
    l1.display();

    cout << "\nL1 with all of its odd numbers before all of its even numbers: (Question 10 function)" << endl;
    l1 = l1.OddEvenSort(l1);
    l1.display();

    int arr[10];
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < 10; i++)//fills array, arr with random values
    {
        //randomly generate a number
        int num = rand() % 100;
        arr[i] = num;
    }

    cout << "\n\nArray, arr, with randomly generated integers:" << endl;
    printArr(arr, arrSize);

    //to see the result of the bubbleSort or insertionSort only  uncomment one of the function calls at a time
    cout << "\nArr after using one of the sort methods:" << endl;
    //bubbleSort(arr, arrSize);
    //insertionSort(arr, arrSize);
    printArr(arr, arrSize);

}