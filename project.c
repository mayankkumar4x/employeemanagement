#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// structure declaration
struct emp{
    int id;
    char name[50];
    int salary;
    float exp;
};
//Function declaration
void display(struct emp *e, int n);
void idsort(struct emp *e, int n);
void namesort(struct emp *e, int n);
void salarysort(struct emp *e, int n);
void expsort(struct emp *e, int n);
void tdisplay(struct emp *e, int n);
int choice(struct emp *e, int n);
void change(struct emp *e, int n);
void search(struct emp *e, int n);
void add(struct emp *e, int *n);
void delete(struct emp *e, int *n);
void hsalary(struct emp *e, int n);
void hexp(struct emp *e, int n);
// data entering
struct emp enterdata() {
    struct emp e;
     int i=0,c=0;
        do{
            if(i==0){
                printf("Enter id number in 3 digits.\n");
                scanf("%d", &e.id);
            }
            else{
                printf("Entered id number is not in 3 digits.\n");
                printf("Enter id number in 3 digits.\n");
                scanf("%d", &e.id);
            }
            c=0;
            for(int j=e.id; j!=0; j=j/10)
            c++;
            i++;
        }while(c!=3);
    fflush(stdin);
    printf("Enter name of the employee.\n");
    scanf("%[^\n]s", e.name);
    i=c=0;
        do{
            if(i==0){
                printf("Enter salary in 5 digits.\n");
                scanf("%d", &e.salary);
            }
            else{
                printf("Entered salary is not in 5 digits.\n");
                printf("Enter salary in 5 digits.\n");
                scanf("%d", &e.salary);
            }
            c=0;
            for(int j=e.salary; j!=0; j=j/10)
            c++;
            i++;
        }while(c!=5);
    printf("Enter work experience in years.\n");
    scanf("%f", &e.exp);
    return e;
}
// display
void display(struct emp *e, int n) {
    printf("\n");
    for(int i=0; i<n; i++){
    printf("Info related to %d employee:\n", i+1);
    printf("Id number: %d \n", e[i].id);
    printf("Name: %s\n", e[i].name);
    printf("Salary: %d\n", e[i].salary);
    printf("Work experience: %.2f years\n\n", e[i].exp);
    }
}
//For tabular display after sorting
void tdisplay(struct emp *e, int n){
    printf("********************Tabular display of data********************\n");
    printf(" _________________________________________________________________\n");
    printf("|                                                                 |\n");
    printf("|S. No.|Id number|  Salary  | Work experience  |       Name       |\n");
    printf("|_________________________________________________________________|\n");
    for(int i=0; i<n; i++){
        printf("|  %d   |   %d   |  %d   |    %.2f years    |   %s        \n",i+1,  e[i].id, e[i].salary, e[i].exp, e[i].name);
    }
    printf("|_________________________________________________________________|\n");
}
//For sorting according to id number
void idsort(struct emp *e, int n){
    int t;
    char temp[50];
    for(int i=0; i<(n-1); i++){
        for(int j=i+1; j<n; j++){
            if(e[i].id>e[j].id){
                t=e[i].id;
                e[i].id=e[j].id;
                e[j].id=t;
                t=e[i].salary;
                e[i].salary=e[j].salary;
                e[j].salary=t;
                t=e[i].exp;
                e[i].exp=e[j].exp;
                e[j].exp=t;
                strcpy(temp,e[i].name);
                strcpy(e[i].name,e[j].name);
                strcpy(e[j].name, temp);
            }
        }
    }
}
//For sorting according to names
void namesort(struct emp *e, int n){
     int t;
    char temp[50];
    for(int i=0; i<(n-1); i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(e[i].name,e[j].name)>0){
                t=e[i].id;
                e[i].id=e[j].id;
                e[j].id=t;
                t=e[i].salary;
                e[i].salary=e[j].salary;
                e[j].salary=t;
                t=e[i].exp;
                e[i].exp=e[j].exp;
                e[j].exp=t;
                strcpy(temp,e[i].name);
                strcpy(e[i].name,e[j].name);
                strcpy(e[j].name, temp);
            }
        }
    }
}
//For sorting according to salary
void salarysort(struct emp *e, int n){
    int t;
    char temp[50];
    for(int i=0; i<(n-1); i++){
        for(int j=i+1; j<n; j++){
            if(e[i].salary>e[j].salary){
                t=e[i].id;
                e[i].id=e[j].id;
                e[j].id=t;
                t=e[i].salary;
                e[i].salary=e[j].salary;
                e[j].salary=t;
                t=e[i].exp;
                e[i].exp=e[j].exp;
                e[j].exp=t;
                strcpy(temp,e[i].name);
                strcpy(e[i].name,e[j].name);
                strcpy(e[j].name, temp);
            }
        }
    }
}
//For sorting according to work experience
void expsort(struct emp *e, int n){
    int t;
    char temp[50];
    for(int i=0; i<(n-1); i++){
        for(int j=i+1; j<n; j++){
            if(e[i].exp>e[j].exp){
                t=e[i].id;
                e[i].id=e[j].id;
                e[j].id=t;
                t=e[i].salary;
                e[i].salary=e[j].salary;
                e[j].salary=t;
                t=e[i].exp;
                e[i].exp=e[j].exp;
                e[j].exp=t;
                strcpy(temp,e[i].name);
                strcpy(e[i].name,e[j].name);
                strcpy(e[j].name, temp);
            }
        }
    }
}
//For highest salary
void hsalary(struct emp *e, int n){
    int i,j,temp;
    int max=0;
    for(i=1;i<n;i++){
        if(e[max].salary<e[i].salary) 
        {
            max=i;
        }   
    }
    printf("Person with highest salary is:\n");
    printf(" _________________________________________________________\n");
    printf("|                                                         |\n");
    printf("|Id number|  Salary  | Work experience |       Name       |\n");
    printf("|_________________________________________________________|\n");
    printf("|   %d   |  %d   |    %.2f years    |   %s",  e[max].id, e[max].salary, e[max].exp, e[max].name);
    printf("\n|_________________________________________________________|\n");
}
//For highest work experience
void hexp(struct emp *e, int n){
    int i,j,temp;
    int max=0;
    for(i=1;i<n;i++){
        if(e[max].exp<e[i].exp) 
        {
            max=i;
        }   
    }
    printf("Person with highest work experience is:\n");
    printf(" _________________________________________________________\n");
    printf("|                                                         |\n");
    printf("|Id number|  Salary  | Work experience |       Name       |\n");
    printf("|_________________________________________________________|\n");
    printf("|   %d   |  %d   |    %.2f years    |   %s",  e[max].id, e[max].salary, e[max].exp, e[max].name);
    printf("\n|_________________________________________________________|\n");
}
//For searching data
void search(struct emp *e, int n){
    int i, id,m=0;
    char name[50];
    printf("Press 1 to search data using id number.\nPress 2 to search data using name.\n");
    scanf("%d",  &i);
    if(i==1){
        printf("Enter the id number to search data.\n");
        scanf("%d", &id);
        printf(" _________________________________________________________\n");
        printf("|                                                         |\n");
        printf("|Id number|  Salary  | Work experience |       Name       |\n");
        printf("|_________________________________________________________|\n");
        for(int k=0; k<n; k++){
            if(id==e[k].id){
                printf("|   %d   |  %d   |    %.2f years    |   %s",  e[k].id, e[k].salary, e[k].exp, e[k].name);
                printf("\n");
                m++;
            }
        }
        if(m==0){
            printf("|              NO DATA FOUND WITH THIS ID                 |");
            printf("\n");
        }
        printf("|_________________________________________________________|\n");
    }
    else if(i==2){
        fflush(stdin);
        printf("Enter the name to search data.\n");
        scanf("%[^\n]s", name);
        printf(" _________________________________________________________\n");
        printf("|                                                         |\n");
        printf("|Id number|  Salary  | Work experience |       Name       |\n");
        printf("|_________________________________________________________|\n");
        for(int k=0; k<n; k++){
            if(strcmp(name, e[k].name)==0){
                printf("|   %d   |  %d   |    %.2f years    |   %s",  e[k].id, e[k].salary, e[k].exp, e[k].name);
                printf("\n");
                m++;
            }
        }
        if(m==0){
            printf("|             NO DATA FOUND WITH THIS NAME                |");
            printf("\n");
        }
        printf("|_________________________________________________________|\n");
    }
    else{
    printf("Wrong choice.\n");
    search(e,n);
    }
}
//For modification of data
void change(struct emp *e, int n){
    int id,m=0,p=0,j;
    char name[50];
    printf("Enter the id number to change data.\n");
    scanf("%d", &id);
    for(int k=0; k<n; k++){
        if(id==e[k].id){
            m++;
            do{
                p=0;
                printf("Press 1 to change id number.\nPress 2 to change name.\nPress 3 to change salary.\nPress 4 to change work experience.\n");
                scanf("%d", &j);
                switch(j){
                case 1:
                printf("Enter the new id number.\n");
                scanf("%d", &e[k].id);
                printf("*************************DATA AFTER MODIFICATION***************************\n");
                display(e,n);
                tdisplay(e,n);
                break;
                case 2:
                printf("Enter the new name.\n");
                fflush(stdin);
                scanf("%[^\n]s", name);
                strcpy(e[k].name, name);
                printf("*************************DATA AFTER MODIFICATION***************************\n");
                display(e,n);
                tdisplay(e,n);
                break;
                case 3:
                printf("Enter the new salary.\n");
                scanf("%d", &e[k].salary);
                printf("*************************DATA AFTER MODIFICATION***************************\n");
                display(e,n);
                tdisplay(e,n);
                break;
                case 4:
                printf("Enter the new work experience.\n");
                scanf("%f", &e[k].exp);
                printf("*************************DATA AFTER MODIFICATION***************************\n");
                display(e,n);
                tdisplay(e,n);
                break;
                default:
                p++;
                printf("Wrong choice.\n");
                break;
                }
            }while(p!=0);
        } 
    }   
    if(m==0){
        printf("Wrong choice.\n");
        change(e,n);
    }
}
//For adding data
void add(struct emp *e, int *n){
    int k,c=0 ,i=0,d=1;
    printf("Enter the number of employees to enter the data.\n");
    scanf("%d", &k);
    *n = *n + k;
    for(int m=*n-k; m< *n; m++){
        printf("Enter the details of %d employee.\n", d);
        i=0;
        do{
            if(i==0){
                printf("Enter id number in 3 digits.\n");
                scanf("%d", &e[m].id);
            }
            else{
                printf("Entered id number is not in 3 digits.\n");
                printf("Enter id number in 3 digits.\n");
                scanf("%d", &e[m].id);
            }
            c=0;
            for(int j=e[m].id; j!=0; j=j/10)
            c++;
            i++;
        }while(c!=3);
        fflush(stdin);
        printf("Enter name of the employee.\n");
        scanf("%[^\n]s", e[m].name);
        i=c=0;
        do{
            if(i==0){
                printf("Enter salary in 5 digits.\n");
                scanf("%d", &e[m].salary);
            }
            else{
                printf("Entered salary is not in 5 digits.\n");
                printf("Enter salary in 5 digits.\n");
                scanf("%d", &e[m].salary);
            }
            c=0;
            for(int j=e[m].salary; j!=0; j=j/10)
            c++;
            i++;
        }while(c!=5);
    printf("Enter work experience in years.\n");
    scanf("%f", &e[m].exp);
    d++;
    }
}
//For deleting data
void delete(struct emp *e, int *n){
    int id, k,t=0;
    do{
        if(t==0){
            printf("Enter the number of employees whose data is to be deleted (less than %d).\n", *n);
            scanf("%d", &k);
        }
        else{
            printf("Wrong choice.\n");
            printf("Enter the number of employees whose data is to be deleted (less than %d).\n", *n);
            scanf("%d", &k);
        }
        t++;
    }while(k>=*n);
    for(int i=1; i<=k; i++){
        t=0;
        do{
            if(t==0){
                printf("Enter the %d id number of the employee to delete the data.\n", i);
                scanf("%d",&id);
            }    
            else{
                printf("Wrong choice.\n");
                printf("Enter the %d id number of the employee to delete the data.\n", i);
                scanf("%d",&id);
            }
            t=0;
            for(int j=0; j<*n; j++){
                if(e[j].id==id){
                    for(int p=j; p<*n-1; p++){
                        e[p].id=e[p+1].id;
                        strcpy(e[p].name, e[p+1].name);
                        e[p].salary=e[p+1].salary;
                        e[p].exp=e[p+1].exp;
                    }
                }
                else
                    t++;
            }
        }while(t>=*n);
        *n=*n-1;
    }
}
//For choice making for functioning of program
int choice(struct emp *e, int n){
    int dec;
    char ch;
        printf("Press 1 to sort according to id number.\n");
        printf("Press 2 to sort according to names.\n");
        printf("Press 3 to sort according to work experience.\n");
        printf("Press 4 to sort according to salary.\n");
        printf("Press 5 to get the details of person with highest salary.\n");
        printf("Press 6 to get the details of person with highest work experience.\n");
        printf("Press 7 to search data using id or name.\n");
        printf("Press 8 to modify data of an employee using id number.\n");
        printf("Press 9 to add data of more employees.\n");
        printf("Press 10 to delete data of an employee.\n");
        scanf("%d", &dec);
        if(dec==1){
            idsort(e,n);
            printf("Employee details after sorting according to Id number\n");
            display(e,n);
            tdisplay(e,n);
        }
        else if(dec==2){
            namesort(e,n);
            printf("Employee details after sorting according to Names\n");
            display(e,n);
            tdisplay(e,n);
        }
        else if(dec==3){
            expsort(e,n);
            printf("Employee details after sorting according to Work experience\n");
            display(e,n);
            tdisplay(e,n);
        }
        else if(dec==4){
            salarysort(e,n);
            printf("Employee details after sorting according to Salary\n");
            display(e,n);
            tdisplay(e,n);
        }
        else if(dec==5){
            hsalary(e,n);
        }
        else if(dec==6){
            hexp(e,n);
        }
        else if(dec==7){
           do{
                search(e,n);
                do{
                    printf("Press N to exit search or Y to continue search.\n");
                    fflush(stdin);
                    scanf("%c", &ch);
                    if(ch=='n' || ch=='N' || ch=='y'|| ch=='Y')
                        break;
                    else
                        printf("Wrong choice.\n");
                }while(ch!='n' && ch!='N' && ch!='y' && ch!='Y');
            }while(ch=='y' || ch=='Y');
        }
        else if(dec==8){
            do{
                change(e,n);
                do{
                    printf("Press N to exit changes or Y to continue changing data.\n");
                    fflush(stdin);
                    scanf("%c", &ch);
                    if(ch=='n' || ch=='N' || ch=='y'|| ch=='Y')
                        break;
                    else
                        printf("Wrong choice.\n");
                }while(ch!='n' && ch!='N' && ch!='y' && ch!='Y');
            }while(ch=='y' || ch=='Y');
        }
        else if(dec==9){
            add(e,&n);
            printf("*********************************DATA AFTER ADDING*******************************\n");
            display(e,n);
            tdisplay(e,n);
        }
        else if(dec==10){
            delete(e,&n);
            printf("*********************************DATA AFTER DELETING*******************************\n");
            display(e,n);
            tdisplay(e,n);
        }
        else{
            printf("Wrong choice.\n");
            choice(e,n);
        }
    return n;   
}
//main function
int main() {
    int i, n;
    char ch;
    printf("Enter the number of employees.\n");
    scanf("%d", &n);
    struct emp e[n];
    for(i=0; i<n; i++){
        printf("Enter the details of %d employee.\n", i+1);
        e[i]=enterdata();
    }
    system("cls");
    display(e,n);
    tdisplay(e,n);
    do{
        n=choice(e,n);
        do{
            printf("Press N to exit program or Y to continue.\n");
            fflush(stdin);
            scanf("%c", &ch);
            if(ch=='n' || ch=='N' || ch=='y'|| ch=='Y')
            break;
            else
            printf("Wrong choice.\n");
        }while(ch!='n' && ch!='N' && ch!='y' && ch!='Y');
    }while(ch=='y' || ch=='Y');
    printf("********************PROGRAM HAS BEEN TERMINATED*********************\n \n");
    printf("*****************************THANK YOU!*****************************\n");
    return 0;
}