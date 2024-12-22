#include <stdio.h>
#include <string.h>

#define Max_Team 10

typedef struct{
	int id;
	char name[50];
	int win;
	int loss;
}Team;

void addnewTeam(const char *filename, Team *t, int *n){
	if(*(n) >= Max_Team){
		printf("No space left!\n"); return;
	}
	printf("Enter the team Id: ");
	scanf("%d",&t[*(n)].id);
	printf("Enter the team name: ");
	getchar();
	fgets(t[*(n)].name, 50, stdin);
	printf("Enter the total win and loss: ");
	scanf("%d %d",&t[*(n)].win, &t[*(n)].loss);
	FILE *file = fopen(filename,"wb");
	if(file == NULL){
		printf("File not opening"); 
		return;
	}
	fwrite(&t[*(n)],sizeof(Team),1,file);
	printf("Data added Successfully!\n");
	fclose(file);
	*(n)++;
}

void updateTeamRecord(const char *filename, Team *t, int *n){
	int id, upd=0;
	printf("Enter the id of the team u want to update: ");
	scanf("%d",&id);
	for(int i=0;i<*(n);i++){
		if (t[i].id == id){
			printf("Win or loss (w or l): ");
			char res; scanf(" %c",&res);
			if(res == 'w'){
				t[i].win++;
			}else if(res == 'l'){
				t[i].loss++;
			}
			upd = 1;
			break;
		}
	}
	
	if(upd == 0){
		printf("Id does not exist\n");return;
	}
	FILE *fptr = fopen(filename,"ab");
	if (fptr== NULL){
		printf("File could not open!\n");return;
	}
	for(int i=0;i<*(n);i++){
		fwrite(&t[i],sizeof(Team),1,fptr);
	}
	fclose(fptr);
	printf("Updated Successfully!\n");
}

void readteamrec(Team *t, int *n){
	int hw=0;float hp=0;
	
	for (int i=0; i < *(n); i++){
		int tp=0;
		if(t[i].win > hw){
			hw = t[i].win;
		}
		tp = (t[i].win) / (t[i].win + t[i].loss);
		if (hp < tp){
			hp = tp;
		}
	}
	
	printf("Team with the highest win and highest win percentages are: ");
	for (int i=0; i < *(n); i++){
		int tp=0;
		tp = (t[i].win) / (t[i].win + t[i].loss);
		if(hw == t[i].win){
			printf("Team %d\tTeam name: %s\t Team wins: %d\tTeam losses: %d\n",t[i].id,t[i].name,t[i].win,t[i].loss);
		}
		if (hp == tp){
			printf("Team %d\tTeam name: %s\t Team wins: %d\tTeam losses: %d\n",t[i].id,t[i].name,t[i].win,t[i].loss);
		}
	}
}

int main(){
	Team teams[Max_Team];
	int choice,n=0;
	
	while(1){
		printf("\n1.Add Team\n2.Update Team\n3.Team's record\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				addnewTeam("Record.dat",teams,&n);break;
			case 2:
				updateTeamRecord("Record.dat",teams,&n);break;
			case 3:
				readteamrec(teams,&n);break;
			case 4:
				printf("Exiting..............");return 0;
			default:
				printf("Enter correct choice!\n");
		}
	}
	
}