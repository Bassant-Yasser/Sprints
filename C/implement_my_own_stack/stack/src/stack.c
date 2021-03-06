#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char   uint8_t;

void push(uint8_t u8_data);
void pull();
uint8_t top();
void printStack();
int is_empty();
uint8_t* balanced_prantheses(char brackets[]);

struct stack{
	char array[1000];
	int size;
}stack1;



int main(void) {
	int n = 0;
	char brackets[100];
	stack1.size = 0;

	scanf("%d", &n);
	scanf("%s", brackets);

	char* result = balanced_prantheses(brackets);
	printf("%s", result);
}

uint8_t* balanced_prantheses(char brackets[])
{
	int flag = 0;
	for(int j = 0; j < strlen(brackets) ; j++)
	{
		if(brackets[j] != '{' && brackets[j] != '(' && brackets[j] != '[' && brackets[j] != '<'
			&& brackets[j] != '}' && brackets[j] != ')' && brackets[j] != ']' && brackets[j] != '>')
			continue;

		if(brackets[j] == '{' || brackets[j] == '(' || brackets[j] == '[' || brackets[j] == '<')
		{
			push(brackets[j]);
		}
		else if(is_empty() == 0)
		{
			if((top() == '(' && brackets[j] == ')') || (top() == '{' && brackets[j] == '}') || (top() == '[' && brackets[j] == ']')
					|| (top() == '<' && brackets[j] == '>'))
			{
				pull();

			}
			else
			{
				//printf("NO \n");
				flag = 1;
				break;
			}
		}
		else if(is_empty() == 1)  // if stack is empty
		{
			//printf("NO \n");
			flag = 1;
			break;
		}
	}
	if(!flag && is_empty() == 1)
	{
		return "Balanced";
	}
	else
		return "Not balanced";
}


void push(uint8_t u8_data)
{
	if(stack1.size < 1000)
	{
		stack1.array[stack1.size] = u8_data;
		stack1.size++;
	}

}

void pull()
{
	stack1.size--;
}

uint8_t top()
{
	return(stack1.array[stack1.size - 1]);
}

void printStack()
{
	int size = stack1.size;

	for(int i =0; i < size; i++)
	{
		printf("%c \n", stack1.array[i]);
	}
	printf("\n-------------\n");
}

int is_empty()
{
	if(stack1.size == 0)
		return 1;       //means empty
	else
		return 0;
}
