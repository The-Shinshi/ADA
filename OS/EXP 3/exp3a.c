#include <stdio.h>
#include <stdlib.h>
int mutex = 1; // Initializing the mutex variable with the value 1.
int full = 0; // Initializing the full variable with the value 0.
int empty = 3, data = 0; // empty variable will store the number of empty slots in the buffer
void producer()// A function that will resemble producers' production of data
{
 --mutex; // decrementing the value of mutex
 ++full; // Increase the number of full slots
--empty; // decrementing the number of slots available
data++;// incrementing data which means that the data is produced
printf("\nProducer produces item number: %d\n", data); 
 ++mutex; // incrementing the value of mutex
}
void consumer()// A function that will resemble the consumer's consumption of data
{
--mutex;
--full;
++empty;
printf("\nConsumer consumes item number: %d.\n", data);
data--;
++mutex;
}
int main()
{
int n, i;
printf("\n1. Enter 1 for Producer"
"\n2. Enter 2 for Consumer"
"\n3. Enter 3 to Exit");
for (i = 1; i > 0; i++)
{
printf("\nEnter your choice: ");
scanf("%d", &n);
switch (n) // using switch case as there can be multiple types of choice.
{
case 1: if ((mutex == 1) && (empty != 0))
{
producer();
}
else
{
printf("The Buffer is full. New data cannot be produced!");
}
break;
case 2:
if ((mutex == 1) && (full != 0))
{
consumer();
}
else
{
printf("\n The Buffer is empty! New data cannot be consumed!\n");
}
break;
 case 3:
exit(0);
break;
}
}
}
