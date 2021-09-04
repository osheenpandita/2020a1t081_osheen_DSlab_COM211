#include<stdio.h>//header file for Standard input and output 
#include<stdlib.h>//Header file for standard library used to allocate memory(malloc function, free function)

void data();//data function prototype
void view();//view function prototype
void min();//min function prototype

//in 14th line we are using typedef so that instead of using 
//struct data again and again we can simply use structure variable 
typedef struct data//Structure of the node
{
	char *shop;//structre member which is a string and will hold the name of the shop
	int walnuts;//integer type structure member which will store the price of walnut
	int Almonds;//integer type structure member which will store the price of almonds
	struct data *next;//this will hold the address of the next node
}node;

node *head=NULL;//this variable will hold the address of first node in the list 

int main()
{
	int choice;//variable declaration
	do
	{
		//as it is a menu based program so here we are giving user the choice 
		printf("Press 1 to insert data\n");
		printf("Press 2 to find the minimum price of walnuts\n");
		printf("Press 3 to view all data\n");
		printf("Press 4 to exit\n");
		scanf("%d",&choice);

		switch(choice)	
			{
				case 1:
					data();
					break;

				case 2:
					min();
					break;

			    case 3:
					view();
					break;

				case 4:
					printf("Thanks visit again\n");
					break;	

				default:
					printf("Wrong input entered\n");
						
			}
	}while(choice!=4);
}

void data()//data function definition which will store the data of shops and item
{
	node *ptr, *temp;//node declaration
	ptr=(node*) malloc(sizeof(node));//allocation of node in the memory

	if (ptr==NULL)//if ptr returns null that means the memory is not available in the ram
	{
		printf("Memory not available\n");
	}
	else
	{
		printf("Enter the shop name\n");//Asking the user to enter the shop name
		scanf("\n%[^\n]*c",ptr->shop);//taking input from the user using scanf function
		printf("Enter the price of walnuts per kg\n");//Asking the user to enter the price of the walnuts
		scanf("%d",&ptr->walnuts);//taking input from the user using scanf function
		printf("Enter the price of Almonds per kg\n");//Asking the user to enter the price of the walnuts
		scanf("%d",&ptr->Almonds);//taking input from the user using scanf function
		ptr->next=NULL;

		if (head==NULL)//if the list is empty
		{
			head=ptr;//head will be equal to ptr which is a very
		}
		else//else we will enter the data at the end
		{
			temp=head;//assigning the value of head to a temporary variable i.e. temp
			while(temp->next!=NULL)//traversing the list to the last element of the list
			{
				temp=temp->next;
			}
			temp->next=ptr;//assigning the next of temp the address of ptr which is the new node
		}
	}

}

void min()//function to finding the minimum value of walnut
{
	int min, a;//variable declaration
	char *s;//variable declaration
	node *temp, *ptr;//temporary node declaration
	temp=head;//assigning the value of head to a temporary variable i.e. temp

	if (head==NULL)//if the list is empty
	{
		printf("No data available\n");
	}
	else
	{
		s=temp->shop;//initialising s with the name of shop which is stored in the shop member of temp node
		min=temp->walnuts;//initialising min with the price of walnut which is stored in the walnut member of temp node
		a=temp->Almonds;//initialising a with the price of almonds which is stored in the Almonds member of temp node
		
		while(temp!=NULL)//traversing the list till the end
		{
			if (min>temp->walnuts)//if the price of min i.e. price of walnut is greater than the price of the walnut of next shop
			{
				s=temp->shop;// then teh value of s, a and min will move to the shop which has the price of walnut less than the previous shop
				a=temp->Almonds;
				min=temp->walnuts;
			}
			temp=temp->next;
		}
			printf("Shop name:%s\n",s);//printing the name of the shop with the cheapest price
			printf("Cheapest price of walnuts:%d/kg\n",min);//printing the price of walnuts with the cheapest price
			printf("Price of almonds:%d/kg\n",a);//printing the price of almonds
	}
		
}

void view()//function to view all the data
{
	node *temp;
	if (head==NULL)//if the list is empty
	{
		printf("No data available\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)//traversing the list
		{
			printf("Shop name:%s\n",temp->shop);//printing the name of the shop
			printf("Price of walnuts:%d/kg\n",temp->walnuts);//printing the price of walnuts
			printf("Price of almonds:%d/kg\n",temp->Almonds);//printing the price of almonds
			printf("\n");
			temp=temp->next;
		}
	}
}