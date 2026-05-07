#include <iostream>
using namespace std;
// Mega project for iics on the topic of Linked List by Rahul Mishra
class Node
{
public:
int data;
Node *pre, *next;
Node()
{
data = 0;
pre = NULL;
next = NULL;
}
};
// Singly Linked List
class SinglyList
{
public:
Node *base;
SinglyList()
{
base = NULL;
}
// Create first node
void createNode()
{
if (base != NULL)
{
cout << "First node is already created" << endl;
}
else
{
base = new Node();
cout << "Enter data: ";
cin >> base->data;
base->next = NULL;
cout << "First node created successfully" << endl;
}
}
// Insert node at beginning
void insertAtBegining()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = new Node();
cout << "Enter data for begining node: ";
cin >> temp->data;
temp->next = base;
base = temp;
cout << "Node inserted at beginning successfully" << endl;
}
// Display list
void displayList()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
Node *temp = base;
while (temp != NULL)
{
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
}
// Find length of the list
int len()
{
if (base == NULL)
{
// Consider length 0 if list not created
return 0;
}
int l = 0;
Node *temp = base;
while (temp != NULL)
{
l++;
temp = temp->next;
}
return l;
}
// Insert node at end
void insertAtEnd()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
Node *temp = base;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = new Node();
cout << "Enter data for ending node: ";
cin >> temp->next->data;
temp->next->next = NULL;
cout << "Node created at end successfully" << endl;
}
// Insert node at middle
void insertAtMiddle()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int pos;
cout << "Enter position to insert: ";
cin >> pos;
int length = len();
if (pos < 1 || pos > length + 1)
{
cout << "You have entered invalid position" << endl;
return;
}
if (pos == 1)
{
insertAtBegining();
return;
}
if (pos == length + 1)
{
insertAtEnd();
return;
}
Node *temp1 = base;
for (int i = 1; i < pos - 1; i++)
{
temp1 = temp1->next;
}
Node *newNode = new Node();
cout << "Enter data for position that you want: ";
cin >> newNode->data;
newNode->next = temp1->next;
temp1->next = newNode;
cout << "Node created successfully at position " << pos << endl;
}
// Sum of node data
void sum()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int s = 0;
Node *temp = base;
while (temp != NULL)
{
s += temp->data;
temp = temp->next;
}
cout << "Sum of the node data is: " << s << endl;
}
// Delete from beginning
void deleteFromBegining()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
Node *temp = base;
base = base->next;
temp->next = NULL;
delete temp;
cout << "Node deleted from beginning successfully" << endl;
}
// Delete from end
void deleteFromEnd()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
if (base->next == NULL)
{
delete base;
base = NULL;
cout << "Node deleted from last successfully" << endl;
return;
}
Node *temp1 = base;
Node *temp2 = NULL;
while (temp1->next != NULL)
{
temp2 = temp1;
temp1 = temp1->next;
}
temp2->next = NULL;
delete temp1;
cout << "Node deleted from last successfully" << endl;
}
// Delete from middle
void deleteFromMiddle()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int pos;
cout << "Enter position to be deleted: ";
cin >> pos;
int length = len();
if (pos < 1 || pos > length)
{
cout << "Invalid position" << endl;
return;
}
if (pos == 1)
{
deleteFromBegining();
return;
}
if (pos == length)
{
deleteFromEnd();
return;
}
Node *temp1 = base;
Node *temp2 = NULL;
for (int i = 1; i < pos; i++)
{
temp2 = temp1;
temp1 = temp1->next;
}
temp2->next = temp1->next;
temp1->next = NULL;
delete temp1;
cout << "Deleted successfully" << endl;
}
// Search data
void searchData()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int search, flag = 0;
cout << "Enter number which you want to search: ";
cin >> search;
Node *temp = base;
while (temp != NULL)
{
if (temp->data == search)
{
flag = 1;
break;
}
temp = temp->next;
}
if (flag == 1)
cout << "Found" << endl;
else
cout << "Not found" << endl;
}
// Sort in ascending order
void sortingInAscending()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int length = len();
for (int i = 0; i < length - 1; i++)
{
Node *temp = base;
for (int j = 0; j < length - i - 1; j++)
{
if (temp->data > temp->next->data)
{
int d = temp->data;
temp->data = temp->next->data;
temp->next->data = d;
}
temp = temp->next;
}
}
cout << "List sorted in ascending order successfully" << endl;
}
// Sort in descending order
void sortingInDescending()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int length = len();
for (int i = 0; i < length - 1; i++)
{
Node *temp = base;
for (int j = 0; j < length - i - 1; j++)
{
if (temp->data < temp->next->data)
{
int d = temp->data;
temp->data = temp->next->data;
temp->next->data = d;
}
temp = temp->next;
}
}
cout << "List sorted in descending order successfully" << endl;
}
// Display list items in reverse order by traversing list and printing
void reverseOfList()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
// To print in reverse, use an array or stack
// But since no doubly links, we can collect data and print reversed
int n = len();
int *arr = new int[n];
Node *temp = base;
for (int i = 0; i < n; i++)
{
arr[i] = temp->data;
temp = temp->next;
}
cout << "List in reverse order: ";
for (int i = n - 1; i >= 0; i--)
{
cout << arr[i] << " ";
}
cout << endl;
delete[] arr;
}
};
// Doubly Linked List
class DoublyList
{
public:
Node *base;
DoublyList()
{
base = NULL;
}
void createNode()
{
if (base != NULL)
{
cout << "First node is already created" << endl;
return;
}
base = new Node();
cout << "Enter data for first node in Doubly Linked List: ";
cin >> base->data;
base->pre = NULL;
base->next = NULL;
cout << "First node created in Doubly List" << endl;
}
void insertAtBegining()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = new Node();
cout << "Enter data to insert node at beginning: ";
cin >> temp->data;
temp->pre = NULL;
temp->next = base;
base->pre = temp;
base = temp;
cout << "Node inserted at beginning of the list" << endl;
}
void insertAtEnd()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = base;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = new Node();
cout << "Enter data to insert node at end: ";
cin >> temp->next->data;
temp->next->pre = temp;
temp->next->next = NULL;
cout << "Node inserted at end of the list" << endl;
}
void insertAtMiddle()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
int pos;
cout << "Enter position to insert: ";
cin >> pos;
int length = len();
if (pos < 1 || pos > length + 1)
{
cout << "Invalid position entered" << endl;
return;
}
if (pos == 1)
{
insertAtBegining();
return;
}
if (pos == length + 1)
{
insertAtEnd();
return;
}
Node *temp1 = base;
for (int i = 1; i < pos - 1; i++)
{
temp1 = temp1->next;
}
Node *newNode = new Node();
cout << "Enter data for the node: ";
cin >> newNode->data;
Node *temp2 = temp1->next;
// Update links
newNode->next = temp2;
newNode->pre = temp1;
temp1->next = newNode;
temp2->pre = newNode;
cout << "Node inserted at given position successfully" << endl;
}
// Delete from beginning
void deleteFromBegining()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
if (base->next == NULL)
{
delete base;
base = NULL;
cout << "Deleted beginning node successfully from doubly list" << endl;
return;
}
Node *temp = base;
base = base->next;
base->pre = NULL;
temp->next = NULL;
delete temp;
cout << "Deleted beginning node successfully from doubly list" << endl;
}
// Delete from end
void deleteFromEnding()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
if (base->next == NULL)
{
delete base;
base = NULL;
cout << "Deleted end node successfully from doubly list" << endl;
return;
}
Node *temp1 = base;
Node *temp2 = NULL;
while (temp1->next != NULL)
{
temp2 = temp1;
temp1 = temp1->next;
}
temp2->next = NULL;
temp1->pre = NULL;
delete temp1;
cout << "Deleted end node successfully from doubly list" << endl;
}
// Delete from middle
void deleteFromMiddle()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
int pos;
cout << "Enter position to be deleted: ";
cin >> pos;
int length = len();
if (pos < 1 || pos > length)
{
cout << "Invalid position" << endl;
return;
}
if (pos == 1)
{
deleteFromBegining();
return;
}
if (pos == length)
{
deleteFromEnding();
return;
}
Node *temp1 = base;
Node *temp2 = NULL;
for (int i = 1; i < pos; i++)
{
temp2 = temp1;
temp1 = temp1->next;
}
temp2->next = temp1->next;
if (temp1->next != NULL)
temp1->next->pre = temp2;
temp1->next = NULL;
temp1->pre = NULL;
delete temp1;
cout << "Deleted node successfully from doubly list" << endl;
}
// Search data
void searchData()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int search, flag = 0;
cout << "Enter number which you want to search: ";
cin >> search;
Node *temp = base;
while (temp != NULL)
{
if (temp->data == search)
{
flag = 1;
break;
}
temp = temp->next;
}
if (flag == 1)
cout << "Found" << endl;
else
cout << "Not found" << endl;
}
// Sort in ascending order
void sortingInAscending()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int length = len();
for (int i = 0; i < length - 1; i++)
{
Node *temp = base;
for (int j = 0; j < length - i - 1; j++)
{
if (temp->data > temp->next->data)
{
int d = temp->data;
temp->data = temp->next->data;
temp->next->data = d;
}
temp = temp->next;
}
}
cout << "List sorted in ascending order successfully" << endl;
}
// Sort in descending order
void sortingInDescending()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int length = len();
for (int i = 0; i < length - 1; i++)
{
Node *temp = base;
for (int j = 0; j < length - i - 1; j++)
{
if (temp->data < temp->next->data)
{
int d = temp->data;
temp->data = temp->next->data;
temp->next->data = d;
}
temp = temp->next;
}
}
cout << "List sorted in descending order successfully" << endl;
}
// Sum of node data
void sum()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int s = 0;
Node *temp = base;
while (temp != NULL)
{
s += temp->data;
temp = temp->next;
}
cout << "Sum of the node data is: " << s << endl;
}
// Length of the list
int len()
{
if (base == NULL)
{
return 0;
}
int l = 0;
Node *temp = base;
while (temp != NULL)
{
l++;
temp = temp->next;
}
return l;
}
// Display doubly list
void displayDoubly()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = base;
while (temp != NULL)
{
cout << temp->data << " ";
temp = temp->next;
}
cout << endl;
}
// Display reverse list
void rev()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = base;
while (temp->next != NULL)
{
temp = temp->next;
}
while (temp != NULL)
{
cout << temp->data << " ";
temp = temp->pre;
}
cout << endl;
}
};
// Circular Linked List
class CircularList
{
public:
Node *base;
CircularList()
{
base = NULL;
}
void createNode()
{
if (base != NULL)
{
cout << "First node is already created" << endl;
return;
}
base = new Node();
cout << "Enter data: ";
cin >> base->data;
base->next = base;
cout << "First node created successfully" << endl;
}
void insertAtBegining()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = new Node();
cout << "Enter data: ";
cin >> temp->data;
Node *last = base;
while (last->next != base)
{
last = last->next;
}
temp->next = base;
last->next = temp;
base = temp;
cout << "Node inserted at beginning successfully" << endl;
}
void insertAtEnd()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = base;
while (temp->next != base)
{
temp = temp->next;
}
temp->next = new Node();
cout << "Enter data: ";
cin >> temp->next->data;
temp->next->next = base;
cout << "Node inserted at end of circular list" << endl;
}
void insertAtMiddle()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int pos;
cout << "Enter position to insert: ";
cin >> pos;
int length = len();
if (pos < 1 || pos > length + 1)
{
cout << "Invalid position entered" << endl;
return;
}
if (pos == 1)
{
insertAtBegining();
return;
}
if (pos == length + 1)
{
insertAtEnd();
return;
}
Node *temp = base;
for (int i = 1; i < pos - 1; i++)
{
temp = temp->next;
}
Node *newNode = new Node();
cout << "Enter data for position that you want: ";
cin >> newNode->data;
newNode->next = temp->next;
temp->next = newNode;
cout << "Node created successfully at position " << pos << endl;
}
void deleteFromBegining()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
if (base->next == base)
{
delete base;
base = NULL;
cout << "First node deleted successfully from circular list" << endl;
return;
}
Node *last = base;
while (last->next != base)
{
last = last->next;
}
Node *temp = base;
base = base->next;
last->next = base;
temp->next = NULL;
delete temp;
cout << "Node deleted from beginning successfully" << endl;
}
void deleteFromEnd()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
if (base->next == base)
{
delete base;
base = NULL;
cout << "Last node deleted successfully from circular list" << endl;
return;
}
Node *temp1 = base;
Node *temp2 = NULL;
while (temp1->next != base)
{
temp2 = temp1;
temp1 = temp1->next;
}
temp2->next = base;
delete temp1;
cout << "Last node deleted successfully from circular list" << endl;
}
void deleteFromMiddle()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int pos;
cout << "Enter position to be deleted: ";
cin >> pos;
int length = len();
if (pos < 1 || pos > length)
{
cout << "Invalid position" << endl;
return;
}
if (pos == 1)
{
deleteFromBegining();
return;
}
if (pos == length)
{
deleteFromEnd();
return;
}
Node *temp1 = base;
Node *temp2 = NULL;
for (int i = 1; i < pos; i++)
{
temp2 = temp1;
temp1 = temp1->next;
}
temp2->next = temp1->next;
temp1->next = NULL;
delete temp1;
cout << "Deleted successfully" << endl;
}
void searchItems()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int search, flag = 0;
cout << "Enter data to search: ";
cin >> search;
Node *temp = base;
do
{
if (temp->data == search)
{
flag = 1;
break;
}
temp = temp->next;
} while (temp != base);
if (flag == 1)
cout << "Data found" << endl;
else
cout << "Not found" << endl;
}
void sortingInAscending()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int length = len();
for (int i = 0; i < length - 1; i++)
{
Node *temp = base;
for (int j = 0; j < length - i - 1; j++)
{
if (temp->data > temp->next->data)
{
int d = temp->data;
temp->data = temp->next->data;
temp->next->data = d;
}
temp = temp->next;
}
}
cout << "List sorted in ascending order successfully" << endl;
}
void sortingInDescending()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int length = len();
for (int i = 0; i < length - 1; i++)
{
Node *temp = base;
for (int j = 0; j < length - i - 1; j++)
{
if (temp->data < temp->next->data)
{
int d = temp->data;
temp->data = temp->next->data;
temp->next->data = d;
}
temp = temp->next;
}
}
cout << "List sorted in descending order successfully" << endl;
}
void reverseOfList()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int n = len();
int *arr = new int[n];
Node *temp = base;
for (int i = 0; i < n; i++)
{
arr[i] = temp->data;
temp = temp->next;
}
cout << "List in reverse order:\n";
for (int i = n - 1; i >= 0; i--)
{
cout << arr[i] << " ";
}
cout << endl;
delete[] arr;
}
// Length of the list
int len()
{
if (base == NULL)
return 0;
int count = 0;
Node *temp = base;
do
{
count++;
temp = temp->next;
} while (temp != base);
return count;
}
void displayCircular()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = base;
do
{
cout << temp->data << " ";
temp = temp->next;
} while (temp != base);
cout << endl;
}
void sum()
{
if (base == NULL)
{
cout << "List is empty. Sum = 0" << endl;
return;
}
int total = 0;
Node *temp = base;
do
{
total += temp->data;
temp = temp->next;
} while (temp != base);
cout << "Sum of all nodes = " << total << endl;
}
};
// Doubly Circular Linked List
class DoublyCircularList
{
public:
Node *base;
DoublyCircularList()
{
base = NULL;
}
void createNode()
{
if (base != NULL)
{
cout << "First node is already created" << endl;
return;
}
base = new Node();
cout << "Enter data: ";
cin >> base->data;
base->next = base;
base->pre = base;
cout << "First node created successfully" << endl;
}
void insertAtBegining()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *last = base;
while (last->next != base)
{
last = last->next;
}
Node *newNode = new Node();
cout << "Enter data: ";
cin >> newNode->data;
newNode->next = base;
last->next = newNode;
base->pre = newNode;
newNode->pre = last;
base = newNode;
cout << "Node inserted successfully" << endl;
}
void insertAtEnding()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *last = base;
while (last->next != base)
{
last = last->next;
}
Node *newNode = new Node();
cout << "Enter data: ";
cin >> newNode->data;
last->next = newNode;
newNode->pre = last;
newNode->next = base;
base->pre = newNode;
cout << "Node inserted at end successfully" << endl;
}
void insertAtMiddle()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
int lenVal = len();
int pos;
cout << "Enter position to insert (1 to " << lenVal + 1 << "): ";
cin >> pos;
if (pos < 1 || pos > lenVal + 1)
{
cout << "Invalid position entered" << endl;
return;
}
if (pos == 1)
{
insertAtBegining();
return;
}
if (pos == lenVal + 1)
{
insertAtEnding();
return;
}
Node *temp1 = base;
for (int i = 1; i < pos - 1; ++i)
{
temp1 = temp1->next;
}
Node *newNode = new Node();
cout << "Enter data for the node: ";
cin >> newNode->data;
Node *temp2 = temp1->next;
// Insert newNode between temp1 and temp2
newNode->next = temp2;
newNode->pre = temp1;
temp1->next = newNode;
temp2->pre = newNode;
cout << "Node inserted at given position successfully" << endl;
}
int len()
{
if (base == NULL)
return 0;
int count = 0;
Node *temp = base;
do
{
count++;
temp = temp->next;
} while (temp != base);
return count;
}
void sumOfElement()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
int s = 0;
Node *temp = base;
do
{
s += temp->data;
temp = temp->next;
} while (temp != base);
cout << "Sum of elements is: " << s << endl;
}
void displayElements()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = base;
do
{
cout << temp->data << " ";
temp = temp->next;
} while (temp != base);
cout << endl;
}
void deleteFromBegining()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
if (base->next == base)
{
delete base;
base = NULL;
cout << "Node deleted from beginning successfully" << endl;
return;
}
Node *last = base;
while (last->next != base)
{
last = last->next;
}
Node *temp = base;
base = base->next;
base->pre = last;
last->next = base;
temp->next = NULL;
temp->pre = NULL;
delete temp;
cout << "Node deleted from beginning successfully" << endl;
}
void deleteFromEnding()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
if (base->next == base)
{
delete base;
base = NULL;
cout << "End node deleted successfully from list" << endl;
return;
}
Node *temp1 = base;
Node *temp2 = NULL;
while (temp1->next != base)
{
temp2 = temp1;
temp1 = temp1->next;
}
temp2->next = base;
base->pre = temp2;
temp1->next = NULL;
temp1->pre = NULL;
delete temp1;
cout << "End node deleted successfully from list" << endl;
}
void deleteFromMiddle()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
int pos;
cout << "Enter position to be deleted: ";
cin >> pos;
int length = len();
if (pos < 1 || pos > length)
{
cout << "Invalid position" << endl;
return;
}
if (pos == 1)
{
deleteFromBegining();
return;
}
if (pos == length)
{
deleteFromEnding();
return;
}
Node *temp1 = base;
Node *temp2 = NULL;
for (int i = 1; i < pos; i++)
{
temp2 = temp1;
temp1 = temp1->next;
}
temp2->next = temp1->next;
temp1->next->pre = temp2;
temp1->next = NULL;
temp1->pre = NULL;
delete temp1;
cout << "Node deleted successfully from the doubly circular list" << endl;
}
void sortingInAscending()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int length = len();
for (int i = 0; i < length - 1; i++)
{
Node *temp = base;
for (int j = 0; j < length - i - 1; j++)
{
if (temp->data > temp->next->data)
{
int d = temp->data;
temp->data = temp->next->data;
temp->next->data = d;
}
temp = temp->next;
}
}
cout << "List sorted in ascending order successfully" << endl;
}
void sortingInDescending()
{
if (base == NULL)
{
cout << "First node not created" << endl;
return;
}
int length = len();
for (int i = 0; i < length - 1; i++)
{
Node *temp = base;
for (int j = 0; j < length - i - 1; j++)
{
if (temp->data < temp->next->data)
{
int d = temp->data;
temp->data = temp->next->data;
temp->next->data = d;
}
temp = temp->next;
}
}
cout << "List sorted in descending order successfully" << endl;
}
void reverseList()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = base->pre;
cout << "List in reverse order: ";
do
{
cout << temp->data << " ";
temp = temp->pre;
} while (temp != base->pre);
cout << endl;
}
void displayDoublyCircular()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
Node *temp = base;
do
{
cout << temp->data << " ";
temp = temp->next;
} while (temp != base);
cout << endl;
}
void searchItems()
{
if (base == NULL)
{
cout << "First node is not created" << endl;
return;
}
int search, flag = 0;
cout << "Enter data to be searched: ";
cin >> search;
Node *temp = base;
do
{
if (temp->data == search)
{
flag = 1;
break;
}
temp = temp->next;
} while (temp != base);
if (flag == 1)
cout << "Data found" << endl;
else
cout << "Not found" << endl;
}
};
int main()
{
int listType, funcChoice;
SinglyList list;
DoublyList doublelist;
CircularList circularlist;
DoublyCircularList doubcircularlist;
while (true)
{
system("cls");
cout << "Here is given below List Type:\n";
cout << "1. Singly Linked List\n";
cout << "2. Doubly Linked List\n";
cout << "3. Circular Linked List\n";
cout << "4. Doubly Circular Linked List\n";
cout << "5. Exit\n";
cout << "Choose any list type option from 1 to 5: ";
cin >> listType;
if (listType == 5)
{
cout << "Exiting program...\n";
break;
}
else if (listType < 1 || listType > 4)
{
cout << "Invalid List Type. Please choose between 1 to 4.\n";
system("pause");
continue; // Ask again
}
// New loop to allow repeated function selection
while (true)
{
system("cls");
cout << "1. Create a node\n";
cout << "2. Insert Node at Beginning\n";
cout << "3. Insert Node at End\n";
cout << "4. Insert Node at Middle\n";
cout << "5. Delete Node from Beginning\n";
cout << "6. Delete Node from End\n";
cout << "7. Delete Node from Middle\n";
cout << "8. Display List items\n";
cout << "9. Search data\n";
cout << "10. Calculate length of the list\n";
cout << "11. Sort list items in ascending order\n";
cout << "12. Sort list items in descending order\n";
cout << "13. Display list items in reverse order\n";
cout << "14. Sum of the list items\n";
cout << "15. Go Back to List Selection\n";
cout << "Choose any function option between 1 to 15: ";
cin >> funcChoice;
if (funcChoice == 15)
break; // Go back to list type menu
switch (listType)
{
case 1:
switch (funcChoice)
{
case 1:
list.createNode();
break;
case 2:
list.insertAtBegining();
break;
case 3:
list.insertAtEnd();
break;
case 4:
list.insertAtMiddle();
break;
case 5:
list.deleteFromBegining();
break;
case 6:
list.deleteFromEnd();
break;
case 7:
list.deleteFromMiddle();
break;
case 8:
list.displayList();
break;
case 9:
list.searchData();
break;
case 10:
cout << "Length of the list is: " << list.len() << endl;
break;
case 11:
list.sortingInAscending();
break;
case 12:
list.sortingInDescending();
break;
case 13:
list.reverseOfList();
break;
case 14:
list.sum();
break;
default:
cout << "Invalid choice." << endl;
}
break;
case 2:
switch (funcChoice)
{
case 1:
doublelist.createNode();
break;
case 2:
doublelist.insertAtBegining();
break;
case 3:
doublelist.insertAtEnd();
break;
case 4:
doublelist.insertAtMiddle();
break;
case 5:
doublelist.deleteFromBegining();
break;
case 6:
doublelist.deleteFromEnding();
break;
case 7:
doublelist.deleteFromMiddle();
break;
case 8:
doublelist.displayDoubly();
break;
case 9:
doublelist.searchData();
break;
case 10:
cout << "Length of the list is: " << doublelist.len() << endl;
break;
case 11:
doublelist.sortingInAscending();
break;
case 12:
doublelist.sortingInDescending();
break;
case 13:
doublelist.rev();
break;
case 14:
doublelist.sum();
break;
default:
cout << "Invalid choice." << endl;
}
break;
case 3:
switch (funcChoice)
{
case 1:
circularlist.createNode();
break;
case 2:
circularlist.insertAtBegining();
break;
case 3:
circularlist.insertAtEnd();
break;
case 4:
circularlist.insertAtMiddle();
break;
case 5:
circularlist.deleteFromBegining();
break;
case 6:
circularlist.deleteFromEnd();
break;
case 7:
circularlist.deleteFromMiddle();
break;
case 8:
circularlist.displayCircular();
break;
case 9:
circularlist.searchItems();
break;
case 10:
cout << "Length of the list is: " << circularlist.len() << endl;
break;
case 11:
circularlist.sortingInAscending();
break;
case 12:
circularlist.sortingInDescending();
break;
case 13:
circularlist.reverseOfList();
break;
case 14:
circularlist.sum();
break;
default:
cout << "Invalid choice." << endl;
}
break;
case 4:
switch (funcChoice)
{
case 1:
doubcircularlist.createNode();
break;
case 2:
doubcircularlist.insertAtBegining();
break;
case 3:
doubcircularlist.insertAtEnding();
break;
case 4:
doubcircularlist.insertAtMiddle();
break;
case 5:
doubcircularlist.deleteFromBegining();
break;
case 6:
doubcircularlist.deleteFromEnding();
break;
case 7:
doubcircularlist.deleteFromMiddle();
break;
case 8:
doubcircularlist.displayDoublyCircular();
break;
case 9:
doubcircularlist.searchItems();
break;
case 10:
cout << "Length of the list: " << doubcircularlist.len() << endl;
break;
case 11:
doubcircularlist.sortingInAscending();
break;
case 12:
doubcircularlist.sortingInDescending();
break;
case 13:
doubcircularlist.reverseList();
break;
case 14:
doubcircularlist.sumOfElement();
break;
default:
cout << "Invalid choice." << endl;
}
break;
default:
cout << "Invalid list type." << endl;
}
system("pause"); // let user see output
}
}
return 0;
}
