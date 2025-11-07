#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Function prototypes
void invoice_header(char *cust_name);
void invoice_headcal(char name[50], int qty, int price);
void invoice_grandtotal(int total);
void thanks();
void menue_layout();
void menue_layout1(int count, char item_name[], int item_price);
void headerprint();

struct data_quantity{
        char item[50];
        int item_price;
        int item_quantity;
        
    };
struct customer_data{
        char name[50];
        int no_of_item;
        struct data_quantity itm[50],itm_list;

    };
    struct menue {                   //menue_part
    char dish_name[50];
    int menue_price;
};


void main(){
          struct customer_data cust,cust_list;
            struct menue m[100];   //menue_part
              char conti = 'y';
              FILE *y;
              int count;
              int i; 
              char wlcome;              //menue_part
    int sel,n,total_1;
    char name[50],search_name[50];
    char save_it='y';
    FILE *fp;
    char con='y';
    int total=0;
    int search_counter;
    system("cls");
    headerprint();
    printf("Enter y to continue:");
    scanf(" %c",&wlcome);

    while(con=='y'){
        system("cls");
        sel=0;
    printf("\t\t*********Boisar 5-STAR Reasturant**********\n");
    printf("Please select your prefered operation:\n");
    printf("1.Generate Invoice\n");
    printf("2.Show all Invoice\n");
    printf("3.Search Invoice\n");
    printf("4.View Menue\n");
    printf("5.Add Items to menue\n");
    printf("6.Exit\n");
    printf("Enter choice:");
    scanf(" %d",&sel);
    //fgetc(stdin);
     // getchar();
    switch(sel){
        //taking invoice data
        
        case 1:system("cls");
        printf("please enter the name of customer:");
        
        scanf("%s",&cust.name);
        
        printf("please enter the number of items you want:");
        scanf("%d",&cust.no_of_item);
        n=cust.no_of_item;
        printf("\n\n");
        total=0;
        for(int i=0;i<n;i++){
            printf("please enter the item name %d:\t",i+1);
             scanf("%s",cust.itm[i].item);

            printf("please enter the unit price:\t");
            scanf("%d",&cust.itm[i].item_price);
            printf("please enter the quantity:\t");
            scanf("%d",&cust.itm[i].item_quantity);
            total +=cust.itm[i].item_price*cust.itm[i].item_quantity;
           //total_1+=total;
            printf("\n");
        }
       /*for(int i=0;i<n;i++){
            total_1+=itm[i].total;
        }*/ 
        system("cls");
        invoice_header(cust.name);
        for(int i=0;i<n;i++){
        invoice_headcal(cust.itm[i].item,cust.itm[i].item_quantity,cust.itm[i].item_price);
       
        }
         invoice_grandtotal(total);
         thanks();
         
         printf("Did you want to save invoice(y/n):");
         scanf(" %c",&save_it);
            getchar();

         if(save_it=='y'){
            fp=fopen("invoicedata.txt","a+");
            fwrite(&cust, sizeof(struct customer_data),1, fp); 
            //fwrite(&itm, sizeof(struct data_quantity), 50, fp);
            if(fwrite!=0){
                printf("sucssesfully saved\n");
               
               
                
            }
            else
            printf("error");
             fclose(fp);

         }
        
        break;
        case 2:system("cls");
        fp=fopen("invoicedata.txt","r");
        printf("\n\t**********Privious invoice data**********\n\n");
               while(fread(&cust_list,sizeof(struct customer_data),1,fp)){
               total=0;
                
                invoice_header(cust_list.name);
        for(int i=0;i<cust_list.no_of_item;i++){
        invoice_headcal(cust_list.itm[i].item,cust_list.itm[i].item_quantity,cust_list.itm[i].item_price);
         total +=cust_list.itm[i].item_price*cust_list.itm[i].item_quantity;
          // total_1+=total;
       
        }
         invoice_grandtotal(total);
         thanks();
        
                        }
            fclose(fp);

        break;
        case 3:system("cls");
        printf("Enter the name of customer to get invoice:\n");
         scanf(" %s",search_name);
        //fgets(search_name,50,stdin);
       getchar();

        fp=fopen("invoicedata.txt","r");
        search_counter=0;
         while(fread(&cust_list,sizeof(struct customer_data),1,fp)){
        if(strcmp(cust_list.name,search_name)==0){
            
               total=0;
                
                invoice_header(cust_list.name);
        for(int i=0;i<cust_list.no_of_item;i++){
        invoice_headcal(cust_list.itm[i].item,cust_list.itm[i].item_quantity,cust_list.itm[i].item_price);
         total +=cust_list.itm[i].item_price*cust_list.itm[i].item_quantity;
               
        }
         invoice_grandtotal(total);
         thanks();
         
         search_counter=1;
            }
         }
         fclose(fp);
          if(!search_counter){
            printf("no such name invoice available\n");
        }
        break;
        case 6:
        system("cls");
        exit(1);
        break;
        default:printf("wrong input\n");
        break;
         case 5:                                                    //menue_part(case for add items)
                system("cls");
                printf("*****Add menu*****\n");
                y = fopen("menue.txt", "a+");
                i=0;
                do {
                    printf("enter the item name: ");
                    scanf("%s", m[i].dish_name);
                    printf("enter the price of item: ");
                    scanf("%d", &m[i].menue_price);
                    fwrite(&m[i], sizeof(struct menue), 1, y);
                    printf("did you want to add more items? enter(y/n): ");
                    scanf(" %c", &conti);
                    i++;
                } while (conti == 'y');
                fclose(y);
                system("cls");
                printf("Data added successfully\n");
                break;

            case 4:system("cls");                                           //menue_part(veiw menue card)
                //printf("**********Menu card*********\n");
                menue_layout();
                y = fopen("menue.txt", "r");
                i=0;
                count=0;
                while (fread(&m[i], sizeof(struct menue), 1, y)) {
                    //printf("Item: %s - Price: %d\n", m.dish_name, m.menue_price);
                   count++;
                menue_layout1(count,m[i].dish_name,m[i].menue_price);
                  // printf("\n\ncount:%d\n\n",count);
                  i++;
                }
                fclose(y);
                break;
        
    }
     
     printf("Do you want to continue(y/n):");
     scanf(" %c",&con);
     fgetc(stdin);
       // getchar();
     
  }
  system("cls");
}

//date and invoice title_column
void invoice_header(char *cust_name){
    printf("*********Boisar 5-STAR Reasturant**********\n\t     -----------------\n");
   printf("Date: %s\n", __DATE__);
    printf("Invoice of:%s",cust_name);
     printf("\n-----------------------------------------\n");
    printf("Items\t\tQty\t\tTotal\n");
    printf("-----------------------------------------\n");
   
}

//invoice item,qty,total calculation

void invoice_headcal(char name[50],int qty,int price){
   
    printf("%s\t\t%d\t\t%d\n",name,qty,qty*price);
}
//Invoice sub_total and offer calculation

void invoice_grandtotal(int total){
    int a,b,c;
    printf("-----------------------------------------\n");
    printf("sub total\t\t   \t%d\n",total);
    printf("Discount @10%\t\t   \t%d\n",a=0.1*total);
    printf("  \t\t   \t\t-------\n");
    printf("net total\t\t   \t%d\n",b=total-a);
    printf("cgst @9%\t\t   \t\t%d\n",c=0.09*b);
    printf("sgst @9%\t\t   \t\t%d\n",c=0.09*b);
    printf("\n-----------------------------------------\n");
    printf("Grand total\t\t   \t%d\n",b+2*c);
    printf("\n-----------------------------------------\n");



}
void menue_layout(){                                            //menue_part(function)
    printf("\n\n************Menu card*************\n\n");
    printf("\n_______________________________________________\n");
    printf("sr.no\t\tItem\t\t\tprice\n");
        printf("_______________________________________________\n");

}
void menue_layout1(int count,char item_name[],int item_price){
   // printf("%d\t\t%s\t\t%d\n",count,item_name,item_price);
     printf("%-6d\t\t%-15s\t\t%d\n", count, item_name, item_price);

}

void thanks(){
    printf("   \t@Thank you %c%c\n",1,1);
}



void headerprint() {
    
    
    int row, col, space;
    for(space=1;space<3; space++)
            printf("\n");
    for(row=1; row<6; row++)
    {
//B
         for(space=1; space<10; space++)
            printf("  ");
        for(col=1; col<6; col++){ 
            if(col==1 || row==3 && ( col==2 || col==3 || col==4) || (row==1 || row==5 )&&(col==2 || col==3 || col==4) || col==5 && (row==2 || row==4))    
            printf("B ");
            else 
            printf("  ");
            
        }
//O
            for(space=1;space<5; space++)
            printf(" ");
             for(col=1; col<6; col++){
                if( (row==1 || row==5) && (col==2 || col==3|| col==4) || (col==1|| col==5) && (row==2 ||row==3 ||row==4 )  )
            printf("O ");
              else 
            printf("  ");

        }
//I
         for(space=1;space<5; space++)
            printf(" ");
        for(col=1; col<6; col++){
            if(row==1 || col==3 || row==5)
            printf("I ");
            else 
            printf("  ");
        }

//S
            for(space=1;space<5; space++)
            printf(" ");
             for(col=1; col<6; col++){
               if( row==3 || row==5 && (col==2|| col==3||col==4|| col==1) || col==1 && (row==2) || col==5 && row==4 || row==1&& (col==2|| col==3||col==4|| col==5) )
                
            printf("S ");
            else 
            printf("  ");

             
        }

//A
        for(space=1;space<5; space++)
            printf(" ");
             for(col=1; col<6; col++){
                if(row==1 && (col==2|| col==3 || col==4  ) ||  row==3 || row==2 && (col==1 || col==5) || row==4 && (col==1 || col==5)  || row==5 && (col==1 || col==5))
            printf("A ");
            else
            printf("  ");
           
        }

//R

        for(space=1;space<5; space++)
            printf(" ");
             for(col=1; col<6; col++){
                if(col==1|| row==3 || row==1 && ( col==2|| col==3|| col==4) || row==4&& col==4 || row==2 && col==5 ||row==5&& col==5)
            printf("R ");
             else
            printf("  ");
        }
        


printf("\n");



//SAVOR WORD

    }
    for(space=1;space<3; space++)
            printf("\n");
for(row=1; row<6; row++)
    { 
  //S  
  for(space=1; space<14; space++)
            printf("  ");
    
           for(col=1; col<6; col++){
            if( row==3 || row==5 && (col==2|| col==3||col==4|| col==1) || col==1 && (row==2) || col==5 && row==4 || row==1&& (col==2|| col==3||col==4|| col==5) )
                
            printf("S ");
            else 
            printf("  ");
             

        }

            for(space=1;space<5; space++)
            printf(" ");
   //A    
         for(col=1; col<6; col++){
           if(row==1 && (col==2|| col==3 || col==4  ) ||  row==3 || row==2 && (col==1 || col==5) || row==4 && (col==1 || col==5)  || row==5 && (col==1 || col==5))
            printf("A ");
            else
            printf("  ");
        }

        for(space=1;space<5; space++)
     //V  
          printf(" ");
             for(col=1; col<6; col++){
                if((col==1 || col==5)&& (row==1|| row==2|| row==3) || row==4 && (col==2 || col==4) || row==5 && col==3)
            printf("V ");
            else
            printf("  ");
            
        }

        for(space=1;space<5; space++)
 //O        
           printf(" ");
            for(col=1; col<6; col++){
               if( (row==1 || row==5) && (col==2 || col==3|| col==4) || (col==1|| col==5) && (row==2 ||row==3 ||row==4 )  )
            printf("O ");
              else 
            printf("  ");
            }


        for(space=1;space<5; space++)
            printf(" ");
   //R  
           for(col=1; col<6; col++){
            if(col==1|| row==3 || row==1 && ( col==2|| col==3|| col==4) || row==4&& col==4 || row==2 && col==5 ||row==5&& col==5)
            printf("R ");
             else
            printf("  ");
        
        }
        printf("\n");
        }
    }

   
   
    
   
