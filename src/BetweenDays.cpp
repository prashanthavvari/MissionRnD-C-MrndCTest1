/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int dates(struct node *head,struct  node *head2)
{
	int date = 0, month = 0, year = 0, i = 0, date2 = 0, month2 = 0, year2 = 0, j = 0, mondays1 = 0, nodays = 0, yearsbetwen = 0, daysbe = 0;
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysl[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (head != NULL)
	{
		if (i < 2)
		{
			date = date * 10 + head->data;
		}
		else if (i > 1 && i < 4)
		{
			month = month * 10 + head->data;
		}
		else if (i>3 && i < 8)
		{
			year = year * 10 + head->data;
		}
		head = head->next;
		i++;
	}
	i = 0;
	while (head2 != NULL)
	{
		if (i < 2)
		{
			date2 = date2 * 10 + head2->data;
		}
		else if (i > 1 && i < 4)
		{
			month2 = month2 * 10 + head2->data;
		}
		else if (i>3 && i < 8)
		{
			year2 = year2 * 10 + head2->data;
		}
		head2 = head2->next;
		i++;
	}
	if (year == year2)
	{
		if (month > month2)
		{
			for (j = month2; j < month; j++)
			{
				mondays1 = mondays1 + days[j];
			}
			if (date > date2)
			{
				nodays = mondays1 + date - date2 - 1;
			}
			else
			{
				nodays = mondays1 + date2 - date - 1;
			}
		}
		else
		{
			for (j = month; j < month2; j++)
			{
				mondays1 = mondays1 + days[j];
			}
			if (date > date2)
			{
				nodays = mondays1 + date - date2;
			}
			else
			{
				nodays = mondays1 + date2 - date;
			}
		}
		nodays = nodays - 1;
	}
	else{
		yearsbetwen = year2 - year;
		if (yearsbetwen == 1)
		{
			for (j = month; j < 12; j++)
			{
				daysbe = daysbe + days[j];
			}
			daysbe = daysbe - date - 1;
			for (j = 1; j < month2; j++)
			{
				daysbe = daysbe + days[j];
			}
			daysbe = daysbe + date2 - 1;
			if (date2 > date)
				nodays = daysbe + date2 - date;
			else
				nodays = daysbe + date - date2;
		}
		else
		{
			for (j = month; j < 12; j++)
			{
				daysbe = daysbe + days[j];
			}
			daysbe = daysbe - date - 1;
			for (j = 1; j < month2; j++)
			{
				daysbe = daysbe + days[j];
			}
			daysbe = daysbe + date2;
			nodays = daysbe + date - date2;
			yearsbetwen = (yearsbetwen - 1) * 365;
			nodays = nodays + yearsbetwen;
		}

	}
	return nodays;
}
int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL&&date2head == NULL)
		return -1;
	else{
		int i = 0;
		i=dates(date1head, date2head);
		return i;
	}
}