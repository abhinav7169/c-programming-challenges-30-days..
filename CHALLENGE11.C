//ALGORITHM :
Start
Declare arrays to store water usage for 5 zones and 7 days.
Enter the daily water usage of all 5 zones
Check whether the entered values are valid
Display the water usage details of all zones
Calculate the total and average water usage of each zone
Find the highest water usage among all zones
Check whether water usage has increased by more than 40%
Display alerts for zones that use excess water
Calculate the extra water used by each zone
Arrange the zones according to their water usage
Generate an audit report showing the water usage details
Display water conservation suggestions for each zone
Stop the program
CODE :
#include <stdio.h>
#define ZONES 5
#define DAYS 7
void inputWaterData(int usage[ZONES][DAYS], int target[ZONES]);
void displayWaterData(int usage[ZONES][DAYS], int target[ZONES]);
void calculateZoneStats(int *usage, int *total, float *avg,          int*highest, int *day);
void detectWaterAlerts(int *usage, int target, int *over, int *excess, int *spike, int *alerts);
void generateAuditReport(int usage[ZONES][DAYS], int target[ZONES],int excess[],int over[],int spike[],int alerts[]);
void rankZones(int excess[]);
void displayConservationActions(int over[], int spike[], int alerts[]);
void printZoneName(int z)
{
if (z == 0)
printf("Academic Block");
else if (z == 1)
printf("Hostel");
else if (z == 2)
printf("Library");
else if (z == 3)
printf("Cafeteria");
else
printf("Sports Complex");
}
void inputWaterData(int usage[ZONES][DAYS], int target[ZONES])
{
int i,j;
for (i=0;i<ZONES;i++)
{
printf("\nEnter details for ");
printZoneName(i);
printf("\n");
printf("Enter daily target: ");
scanf("%d", &target[i]);
while (target[i] < 100 || target[i] > 50000)
{
printf("Invalid target! Enter again: ");
scanf("%d", &target[i]);
}
for (j = 0; j < DAYS; j++)
 {
printf("Enter water usage for Day %d: ", j + 1);
scanf("%d", &usage[i][j]);
while (usage[i][j] < 0 || usage[i][j] > 50000)
{
printf("Invalid value! Enter again: ");
scanf("%d", &usage[i][j]);
}
}
}
}
void displayWaterData(int usage[ZONES][DAYS], int target[ZONES])
{
int i, j;
printf("\nwater consumption data\n");
for (j = 0; j < DAYS; j++)
printf("Day%d\t", j + 1);
printf("Target\n");
for (i = 0; i < ZONES; i++)
{
printZoneName(i);
printf("\t");
for (j = 0; j < DAYS; j++)
{
printf("%d\t", usage[i][j]);
}
printf("%d\n", target[i]);
}
}
void calculateZoneStats(int *usage, int *total, float *avg,int *highest, int *day)
{
int i;
*total = 0;
*highest = usage[0];
*day = 1;
for (i = 0; i < DAYS; i++)
{
*total = *total + usage[i];
if (usage[i] > *highest)
{
*highest = usage[i];
*day = i + 1;
}
}
*avg = (float)*total / DAYS;
}
void detectWaterAlerts(int *usage, int target, int *over,int *excess, int *spike,int *alerts)
{
int i;
int overFlag, spikeFlag;
*over = 0;
*excess = 0;
*spike = 0;
*alerts = 0;
for (i = 0; i < DAYS; i++)
{
overFlag = 0;
spikeFlag = 0;
if (usage[i] > target)
{
overFlag = 1;
(*over)++;
*excess = *excess + (usage[i] - target);
}
if (i > 0 && usage[i] > usage[i - 1] * 1.40)
{
spikeFlag = 1;
(*spike)++;
}
if (overFlag == 1 || spikeFlag == 1)
{
(*alerts)++;
}
}
}
void generateAuditReport(int usage[ZONES][DAYS], int target[ZONES],int excess[],int over[],int spike[],int alerts[])
{
int i;
 int total, highest, day;
float avg;
printf("\nwater audit report\n");
for (i = 0; i < ZONES; i++)
{
calculateZoneStats(usage[i], &total, &avg, &highest, &day);
detectWaterAlerts(usage[i], target[i], &over[i],&excess[i], &spike[i],
&alerts[i]);
printf("\nZone: ");
printZoneName(i);
printf("\nWeekly Total: %d L", total);
printf("\nDaily Average: %.2f L", avg);
printf("\nHighest Usage: %d L on Day %d", highest, day);
printf("\nOver Limit Days: %d", over[i]);
printf("\nTotal Excess: %d L", excess[i]);
printf("\nSpike Days: %d", spike[i]);
printf("\nAlert Days: %d\n", alerts[i]);
}
}
void rankZones(int excess[])
{
int i, j, rank[ZONES];
for (i = 0; i < ZONES; i++)
{
rank[i] = 1;
for (j = 0; j < ZONES; j++)
{
if (excess[j] > excess[i])
{
rank[i]++;
}
}
}
printf("\nzone ranking\n");
for (i = 1; i <= ZONES; i++)
{
for (j = 0; j < ZONES; j++)
{
if (rank[j] == i)
{
 printf("Rank %d: ", i);
printZoneName(j);
printf("%d L\n", excess[j]);
}
}
}
}
void displayConservationActions(int over[], int spike[], int alerts[])
{
int i;
printf("\nwater conservation action\n");
for (i = 0; i < ZONES; i++)
{
printZoneName(i);
printf(":\n");
if (spike[i] > 0)
printf("Check for water leakage\n");
if (over[i] >= 3)
printf("educe water usage and conduct an audit\n");
else if (over[i] > 0)
printf("Monitor water usage regularly\n");
if (alerts[i] == 0)
printf("- Maintain current water-saving practices.\n");
}
}
int main()
{
int usage[ZONES][DAYS];
int target[ZONES];
int excess[ZONES], over[ZONES];
int spike[ZONES], alerts[ZONES];
int choice = 0;
int entered = 0;
while (choice != 6)
{
printf("\nwaterwise menu\n");
printf("1. Enter Water Data\n");
printf("2. Display Water Data\n");
printf("3. Generate Audit Report\n");
printf("4. Rank Zones\n");
printf("5. Conservation Actions\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
if (choice == 1)
{
inputWaterData(usage, target);
entered = 1;
}
else if (choice >= 2 && choice <= 5)
{
if (entered == 0)
{
printf("Please enter water data first!\n");
}
else
{
if (choice == 2)
{
displayWaterData(usage, target);
}
else
{
generateAuditReport(usage, target, excess,over, spike, alerts);
if (choice == 4)
rankZones(excess);
else if (choice == 5)
displayConservationActions(over, spike, alerts);
}
}
}
else if (choice == 6)
{
printf("Thank you! Save Water!\n");
}
else
{
printf("Invalid choice! Try again.\n");
}
}
return 0;
}
