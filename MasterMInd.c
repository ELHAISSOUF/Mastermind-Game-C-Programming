/* * * * * * * * * * * * * *
*  BY : ELHAISSOUF ACHRAF  *
*                          *
*  * * * * * * * * * * * * */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
// Global variable
int RE,MP,BP,i,j,selectedOption,selectedOption1,joueur1[5],joueur2[5];int ply1=1,ply2=2,joker=0,decision=-1;
char nomJoueur1[50],nomJoueur2[50];
// Color
 void color(int couleur_DuTexte, int couleur_DeFond)
 {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleur_DeFond * 16 + couleur_DuTexte);
 }
 // Animation For Text
void afficherCaractereParCaractere(const char *message)
{
    for (int i = 0; message[i] != '\0'; ++i)
	{
        putchar(message[i]);
        fflush(stdout);
        usleep(35000);
    }
}
// loadingBar
void displayLoadingBar()
{
  color(4,0);
  afficherCaractereParCaractere("\t\t\t\t __  __    _    ____ _____ _____ ____  __  __ ___ _   _ ____\n");
  color(8,0);   afficherCaractereParCaractere("\t\t\t\t|  \\/  |  / \\  / ___|_   _| ____|  _ \\|  \\/  |_ _| \\ | |  _ \\ \n");
  color(4,0);  afficherCaractereParCaractere("\t\t\t\t| |\\/| | / _ \\ \\___ \\ | | |  _| | |_) | |\\/| || ||  \\| | | | |\n");
  color(8,0);   afficherCaractereParCaractere("\t\t\t\t| |  | |/ ___ \\ ___) || | | |___|  _ <| |  | || || |\\  | |_| |\n");
  color(4,0); afficherCaractereParCaractere("\t\t\t\t|_|  |_/_/   \\_\\____/ |_| |_____|_| \\_\\_|  |_|___|_| \\_|____/ \n");
  color(8,0);
  printf("\n");
  printf("                            .-\"\"-.-\"\"-.\n");
  printf("                           (   ");color(4,0);printf("CODE?");color(8,0);printf("   )\n");
  printf("                            (         )\n");
  printf("                             '---''--'\n");
  printf("                              ()\n");
  printf("                 /\"\"\"\"\"       O\n");
  printf("                |  (')')   o\n");
  printf("               C     _)\n");
  printf("                 \\   _|\n");
  printf("                  \\__/\n");
  printf("                 <___Y>\n");
  printf("                /  \\ :\\\\\n");
  printf("               /   |  :|\\\n");
  printf("               |___|  :|/\\\n");
  printf("                | |   :|\\ \\\n");
  printf("                \\ \\   :|  \\ \\_\n");
  printf("                 \\ \\==L|  \\\\\\\n");
  printf("                 ///` ||\n");
  printf("                  |   ||\n");
  printf("                  |   ||\n");
  printf("                  |   ||\n");
  printf("                  |   ||\n");
  printf("                  |   ||\n");
  printf("                  |   ||\n");
  printf("                  (____))");
}
// Welcome Message
void Welcome() {
    color(8, 0);
    printf("\t/////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\t//                                                                                             //\n");
    printf("\t//                                                                                             //\n");
    printf("\t//                              ");
    color(15, 4);
    printf("   - WELCOME TO MASTER MIND!! -   ");
    color(8, 0);
    printf("                             //\n");
    printf("\t//                                                                                             //\n");
    printf("\t//                                                                                             //\n");
    printf("\t/////////////////////////////////////////////////////////////////////////////////////////////////\n");
}
// Card of joker
void cardj()
{
 color(15,0);printf("\n\t\t\t\t\t\t\t\t     ");color(0,3);printf(" CARD JOKER ");color(15,0);printf("\n\n\t\t");
 color(0,13);printf("   _______________________ "); color(15,0);printf("\n\t\t");
 color(0,13);printf(" |                       | ");color(15,0); printf("\n\t\t");
 color(0,13);printf(" |%c          .=.        %c| ",3,3);color(15,0);printf("\n\t\t");
 color(0,13);printf(" |      _   //(`)_       | ");color(15,0);printf("\n\t\t");
 color(0,13);printf(" |     //`\\/ |\\ 0`\\\\     | ");color(15,0);printf("\n\t\t"); // Infos
 color(0,13);printf(" |J    ||-.\\_|_/.-||     | ");color(15,0);printf("\t\t\t");    printf("\" Be used for one time \"");printf("\n\t\t");
 color(0,13);printf(" |     )/ |_____| \\(     | ");color(15,0);printf("\n\t\t");
 color(0,13);printf(" |O    0  #/\\ /\\#  0     | ");color(15,0);printf("\t\t  ");  printf("\" Can display a number of your choice \" ");printf("\n\t\t");
 color(0,13);printf(" |       _| o o |_       | ");color(15,0);printf("\n\t\t");
 color(0,13);printf(" |K     ((|, ^ ,|))      | ");color(15,0);printf("\t\t\t");   printf("\" You lose 3 attempts \"");printf("\n\t\t");
 color(0,13);printf(" |       `||\\_/||`       | ");color(15,0);printf("\n\t\t");
 color(0,13);printf(" |E       || _ ||        | ");color(15,0);printf("\n\t\t");
 color(0,13);printf(" |        | \\_/ |        | ");color(15,0);printf("\n\t\t");
 color(0,13);printf(" |R   0.__.\\   /.__.0    | ");color(15,0);printf("\n\t\t");
 color(0,13);printf(" |     `._  `\"`  _.'     | ");color(15,0);printf("\n\t\t");
 color(0,13);printf(" |        / ;  \\ \\       | ");color(15,0);printf("\n\t\t");
 color(0,13);printf(" |%c     0'-' )/`'-0     %c| ",3,3);color(15,0);printf("\n\t\t");
 color(0,13);printf(" |          0`           | ");color(15,0);printf("\n\t\t");
 color(0,13);printf("  ~~~~~~~~~~~~~~~~~~~~~~~  ");color(15,0);printf("\n\t\t");
 color(15,0);printf("\n\t\t\t\t\t\t\t\t\t\t\t");color(0,7);printf(" >>SKIP   ");
 color(15,0);
 getch();
}
// Display Joker
void jokeer()
{
    color(13,0); printf("\n\n");  printf("     _\\@)_       ___\n");
    color(13,0);  printf("      /`\\      .' -,'-.__,@\n");
    color(13,0);    printf("     /        |     `).-'\n");
    color(13,0);    printf("   _/       _\\V^V^V^V/_\n");
    color(13,0);    printf("  | /\\     .=// ^.^ \\\\=.");printf("\t\t\t\t    ");color(0,15);      printf(" Need some help ?! ");printf("\n");
    color(13,0);    printf("  /\\ /     .'/| ._. |\\'.\n");
    color(13,0);    printf(" / /-`.       _\\___/_\n");
    color(13,0);    printf(" |/\\/\\   _@->`   _  `<-@._\n");
    color(13,0);    printf("    \\  \\.'  @-'`\\( `'-,@   '-.\n");
    color(13,0);    printf("     \\      ,    @    , _.-   '\\");printf("\t\t\t");color(0,8);  printf(" YES (1) ");color(15,0);printf("\t");color(0,8); printf(" NO (0) ");color(15,0); printf("\n");
    color(13,0);    printf("      \\   .'|    :    |` /'. _.'\n");
    color(13,0);    printf("       `\"`   \\   :    / /`\\_|  @\n");
    color(13,0);    printf("       @_  _.'`\"\"\"\"\"`'-\\_\\.--`;`\n");
    color(13,0);    printf("       `-.`      /,     `, .-'\n");
    color(13,0);    printf("       _.@--; .-'| '. ;-._;@\n");
    color(13,0);    printf("     .'     @' _.'.  `@  \\\n");
    color(13,0);    printf("   |     _.-'`    '-.    \\\n");
    color(13,0);    printf("    '-._  `-._n_     )   |\n");
    color(13,0);    printf("        `'-._ ) `-,.'   /\n");
    color(13,0);    printf("             u-'--;`@ .'\n");
    color(13,0);    printf("                  |  /\n");
    color(13,0);    printf("                 ,\\ /,\n");
    color(13,0);    printf("                 )\\.'/\n");
    color(13,0);    printf("                /   (\n");
    color(13,0);    printf("               \\_.. '._.@\n");
    color(13,0);    printf("                    `-.-'\n");
    color(15,0);
decision = _getch();
}
// Enter Username
void USERs(int a)
{
    color(11, 0);
	printf("\t\t\t\t===============\n");
	printf("\t\t\t\t#  ");color(11, 0);printf(" PLAYER%d ",a);color(8, 0);printf("  #\n",a);
	printf("\t\t\t\t===============\n");color(11, 0);
	printf("\t\t\t\t      _|_     \n");
	afficherCaractereParCaractere("\t\t\t\t   ");
	color(0, 15); printf(" USERNAME:");
	color(8, 0);printf(" --> ");
}
// Convert a string to uppercase
void toUpperCase(char *s)
{
    for (int i = 0; s[i] != '\0'; ++i)
	 {
        s[i] = toupper((unsigned char)s[i]);
    }
}
// Rules
void regles()
{
color(0, 11);
printf("\t\t\t\t\t\t  RULES  \n\n\n");color(8, 0); printf("\n=======================================================================================================================");
color(11, 0);	afficherCaractereParCaractere("\t\t\tCONCEPT:");
color(15, 0);printf("\n\t\t\t\t-Player 1 proposes a secret code of 5 digits.\n\t\t\t\t-Player 2 proposes another 5-digit code.\n\t\t\t\t-The program indicates the number of digits correctly placed and incorrectly placed.");
color(8, 0);printf("\n=======================================================================================================================");usleep(1000000);
color(11, 0);afficherCaractereParCaractere("\n\t\tJOKER:");
color(15, 0);printf("\n\t\t\t\t-Single-use only.\n\t\t\t\t-This option is activated from the 10th attempt onward.\n\t\t\t\t-The player can choose to reveal a digit of their choice in the secret code.\n\t\t\t\t-This option results in a penalty for Player 2, who loses 3 attempts.");
color(8, 0); printf("\n=======================================================================================================================");usleep(1000000);
color(11, 0);afficherCaractereParCaractere("\n\t\tLEVELS:");
color(15, 0);printf("\n\t\t\t\t-Level 1: All digits in the code are distinct.\n\t\t\t\t-Level 2: Digits can be repeated.\n\t\t\t\t-Level 3: Digits can be repeated.");
color(8, 0); printf("\n=======================================================================================================================");usleep(1000000);
color(11, 0);afficherCaractereParCaractere("\n\t\tEND:");
color(15, 0);printf("\n\t\t\t\t-If Player 2 finds the secret code.\n\t\t\t\t-If the maximum number of attempts (20 tries) is reached.");
color(8, 0);printf("\n=======================================================================================================================\n\n");
color(0, 8);printf("\t\t\t\t\t MENU(1) ");printf("\t\t QUIT(2) \n");color(15,0); decision = _getch();
}
// Initialize the game array
void Game_0(int Game[20][8])
{

    for (i = 0; i < 20; i++)
	{
        for (j = 0; j < 8; j++)
		{
            Game[i][j] = 0;
        }
    }
}
// Display the game array
void  Game_start(int Game[20][8])
{
	// Design of Array
    color(15,0);
    printf("\t\t\t\t\t ________________________________________________________\n");
    printf("\t\t\t\t\t|");color(0, 14);printf("  ATTEMPT   ");
	color(8, 0);printf("|");
	color(0, 7);printf("  ?  ");
	color(8, 0);printf("|");
	color(0, 7);printf("  ?  ");
	color(8, 0);printf("|");
	color(0, 7);printf("  ?  ");
	color(8, 0);printf("|");
	color(0, 7);printf("  ?  ");
	color(8, 0);printf("|");
	color(0, 7);printf("  ?  ");
	color(8, 0);printf("|");
	color(0, 2);printf("  CP  ");
	color(8, 0);printf("|");
	color(0, 4);printf("  IP  ");
	color(8,0);printf("|\n");
    printf("\t\t\t\t\t|////////////|/////|/////|/////|/////|/////|//////|//////|\n");
  for (i = 0; i < 20; i++)
   {
	     color(8,0);
        printf("\t\t\t\t\t|");
    for (j = 0; j < 8; j++)
		{
		    if(Game[i][j]==-1)
		    {
                    if (j == 0)
			{   // Attemps
			    color(14, 0);
                printf("      -     ", Game[i][j]);color(8,0);printf("|");
            }
			else if (j >= 1 && j <= 5)
			{   // Code of Player2
			    color(15,0);
              	printf("  -  ", Game[i][j]);color(8,0);printf("|");

            }
			else if(j==6 )
			{     // correctly placed numbers
			    color(2, 0);
            	printf("   -  ", Game[i][j]);color(8,0);printf("|");
			}
			else if(j==7)
			{     // Incorrectly placed numbers
			    color(4, 0);
				printf("   -  ", Game[i][j]);color(8,0);printf("|");
			}

		    }
		    else {
            if (j == 0)
			{   // Attemps
			    color(14, 0);
                printf("     %2d     ", Game[i][j]);color(8,0);printf("|");
            }
			else if (j >= 1 && j <= 5)
			{   // Code of Player2
			    color(15,0);
              	printf("  %d  ", Game[i][j]);color(8,0);printf("|");

            }
			else if(j==6 )
			{     // correctly placed numbers
			    color(2, 0);
            	printf("  %2d  ", Game[i][j]);color(8,0);printf("|");
			}
			else if(j==7)
			{     // Incorrectly placed numbers
			    color(4, 0);
				printf("  %2d  ", Game[i][j]);color(8,0);printf("|");
			}
			}

        }
        printf("\n");
    }
    color(8,0);
    printf("\t\t\t\t\t|////////////|/////|/////|/////|/////|/////|//////|//////|\n");
}
void greatjob(){
	system("cls");
          		system("color 20");
                printf("\t\t\t\t  ________                      __         __      ___.      ._.\n");
                printf("\t\t\t\t /  _____/______   ____ _____ _/  |_      |__| ____\\_ |__   | |\n");
                printf("\t\t\t\t/   \\  __\\_  __ \\_/ __ \\__   \\    __\\     |  |/  _ \\| __ \\  | |\n");
                printf("\t\t\t\t\\    \\_\\  \\  | \\/\\  ___/ / __ \\   |       |  (  <_> ) \\_\\ \\  \\|\n");
                printf("\t\t\t\t \\______  /__|    \\___  >____  /__|   /\\__|  |\\____/|___  /  __\n");
                printf("\t\t\t\t        \\/            \\/     \\/       \\______|          \\/   \\/\n\n\n\n\n\n\n");
}
void hardluck(){
		            system("cls");
	            system("color 40");
	            printf("\t\t\t\t.__                     .___ .__                 __     ._.\n");
                printf("\t\t\t\t|  |__ _____ _______  __| _/ |  |  __ __   ____ |  | __ | |\n");
                printf("\t\t\t\t|  |  \\\\__  \\\\_  __ \\/ __ |  |  | |  |  \\_/ ___\\|  |/ / | |\n");
                printf("\t\t\t\t|   Y  \\/ __ \\|  | \\/ /_/ |  |  |_|  |  /\\  \\___|    <   \\|\n");
                printf("\t\t\t\t|___|  (____  /__|  \\____ |  |____/____/  \\___  >__|_ \\  __\n");
                printf("\t\t\t\t     \\/     \\/           \\/                   \\/     \\/  \\/\n\n\n\n\n\n\n\n\n");
}
     // Code Verification
void verrifier(int *codeX)
{
       while (1)
    {
        // Enter Code
        color(15, 0);
        scanf("%d",codeX);
        if (*codeX>=99999)
		{
        	system("cls");
        	// Error Message
            color(4, 0);
            afficherCaractereParCaractere("\n\t\t\t\t\tThe entered code is not valid. Please try again.\n\n\t\t\t\t  ");
            color(8, 0);
            	continue;
		}
				   break;// Exit Loop
    }
}
   // Extract digits from the entered code
void Extraire(int code, int joueur[5])
{
   for (int i = 4; i >= 0; i--)
	  {
         joueur[i] = code % 10;
         code /= 10;
      }
}
void Fichier_game(const char *nomFichier, int maVariable)
{
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL)
	{
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        return;
    }
       fprintf(fichier, "%d", maVariable);
       fclose(fichier);
}
 int main(){ //The Variables
      	int codeS,codeG;int Game[20][8], code_temp[5];int key1 = 0;
    	 const char *options1[] ={"AMATEUR","EXPERT","MASTER"};
         const char *options[] = {"PLAY ","RULES","QUIT "};
         const int num_options1 = sizeof(options1) / sizeof(options1[0]);
          const int num_options = sizeof(options) / sizeof(options[0]);
    displayLoadingBar();
    sleep(4); // Delay System(cls)
    system("cls"); // Clear the Console
    while (1)
	 {
    	system("cls"); // Clear the Console
    	 Welcome(); // Welcome Message
        color(8, 0);
          printf("\n\n\t\t\t\t\t +-------------------------------+\n");
          printf("\t\t\t\t\t |           ");color(0, 11);
          printf(" MENU ");color(8, 0);printf("              |\n");
          printf("\t\t\t\t\t +-------------------------------+\n\n");
            // Display the Menu
        for (int l = 0; l < num_options; l++) {

            if (l == selectedOption) {
                color(8, 0);
                printf("\t\t\t\t\t |\t  >> %s <<\t\t |\n\n", options[l]);
            } else {
                color(8, 0);
                printf("\t\t\t\t\t |\t     %s\t\t |\n\n", options[l]);
            }
        }
        color(8, 0);
        printf("\t\t\t\t\t +-------------------------------+\n");
        int key =_getch();
        if (key == 224) {
            key =_getch();
            if (key == 72 && selectedOption > 0) { // Up Arrow
                selectedOption--;
            } else if (key == 80 && selectedOption < num_options - 1) { // Down Arrow
                selectedOption++;
            }
        } else if (key == 13 ) {
            // Execute the Selected Action
            if (selectedOption == num_options - 1)
            { // Quit option
                exit(0);
            }
            else if (selectedOption == 0)
            {
                while (1) {
        system("cls");
        Welcome();
        color(8, 0);// MENU of LEVELS
        printf("\n\n\t\t\t\t\t +--------------------------------+\n");
        printf("\t\t\t\t\t |           "); color(0, 11);
        printf(" LEVELS "); color(8, 0); printf("             |\n");
        printf("\t\t\t\t\t +--------------------------------+\n\n");

        // Display MENU
        for (int l = 0; l < num_options1; l++) {

            if (l == selectedOption1)
			{
                color(8, 0);
                printf("\t\t\t\t\t |\t  >> %s <<\t\t  |\n\n", options1[l]);
            } else {
                color(8, 0);
                printf("\t\t\t\t\t |\t     %s\t\t  |\n\n", options1[l]);
            }
        }
            color(8, 0);
            printf("\t\t\t\t\t +--------------------------------+\n");
        key1 = _getch();
        if (key1 == 224)
		{
            key1 = _getch();
            if (key1 == 72 && selectedOption1 > 0) { // UP Arrow
                selectedOption1--;
            } else if (key1 == 80 && selectedOption1 < num_options1 - 1) { // DOWN Arrow
                selectedOption1++;
            }
        }
		else if (key1 == 13) {
            // Execute the Selected Action
            if (selectedOption1 == num_options1 - 1)
			 {
                              // niveau 3
             }
			else if (selectedOption1 == 0)
			 {
              system("cls");
                //	Get usernames from players
			  printf("\n\n\n\n");  USERs(ply1); color(15, 0);scanf("%s", nomJoueur1);
			  printf("\n\n\n\n");  USERs(ply2); color(15, 0);scanf("%s", nomJoueur2);
			  system("cls");
			  toUpperCase(nomJoueur1);
			  toUpperCase(nomJoueur2);
			  color(0, 11);
			  printf("\n\t\t\t\t\t* Welcome to Level 1 with EL ACHRAF! *\n\n\n");
			  color(15,0);   afficherCaractereParCaractere("\n\n\n\t\tHello ");
			  color(0, 15); printf(" %s ",nomJoueur1),
			  color(15,0);afficherCaractereParCaractere(",\n\n\t\t\t\" You have the special task of creating a secret 5-digit code \"\n\n\t\t\t\" Choose each digit carefully, ensuring that they are all distinct \"\n\n\t\t      ");
			  color(0, 15);  printf(" %s ",nomJoueur2); color(15,0);afficherCaractereParCaractere(",\n\n\t\t\t\" You have task of guessing it \"\n\n\t\t\t\t\t\t\t\tMAY THE BEST ONE WIN ;)");
			  color(0, 7);afficherCaractereParCaractere("\n\n\n\n\t\t\t\t\t\t GOOD LUCK!! \n\n\n\n\n\n\t\t\t\t\t");
			  color(0,14 );
			  color(15,0);printf("\n\t\t\t\t\t\t\t\t\t\t\t");color(0,7);printf(" >>SKIP   ");
			  color(3,0);
			  getch();
			  system("cls");
  	          printf("\n\n\n\n\n\n\n\n\t\t\t\t\\\\ ");
			  color(0,3);
			  printf(" %s ",nomJoueur1);
		      color(3,0);printf(" \\\\");
			  color(11,0);afficherCaractereParCaractere("\n\n\t\t\t\t\t   Please enter a 5-digit code: ");
  while (1)
           {
               verrifier(&codeS);
               Extraire(codeS, joueur1);
             // Check for Duplicate Numbers
            RE=0;
            for (i = 0; i < 5; i++)
	    {
               for (j= i + 1; j < 5; j++)
			{
                if (joueur1[i] == joueur1[j])
				 {
                    RE = 1;
                    break;
                 }
            }
            if (RE != 0)
			{
                break;
            }
        }
        if (RE != 0)
		{
		     system("cls");
             color(4, 0);
             afficherCaractereParCaractere("\n\t\tError: Numbers must not repeat. Please try again.\n\n\t\t\t\t  ");
             color(8, 0);
             afficherCaractereParCaractere("-->code: ");
             continue;
        }
		    while (getchar() != '\n');
            break;
    }
            system("cls");
            printf("\n\n\n\t\t\t\t");
            color(0,14);
            afficherCaractereParCaractere(" ! Take the time to think and guess the secret code ! \n\n\t\t\t");
     	    color(15,0);printf("\n\t\t\t\t\t\t\t\t\t\t\t");color(0,7);printf(" >>SKIP   ");
            color(3,0);
            getch();
            system("cls");
            Game_0(Game);
            Game_start(Game);
		    int essay=0;
    while (essay < 20)
	{
        MP = 0;
        BP = 0;
    //  Prompt for Code on Each Attempt
      while(essay==10)
	   {
      	    sleep(3);
      	    system("cls");
      	    cardj();
      	    break;
	   }

        while(essay>=10 && essay<=17 && joker==0)
		{
		  if(essay>10){
			           sleep(3);
	                  }
                       system("cls");
                       jokeer();
            switch(decision)
			{
           	case '1':
			   system("cls");
               color(15,0);printf("\n\n\n\n\t\t\t\t");color(14,0);printf(" Chose the digit you want: ");
               color(15,0); 	scanf("%d",&decision);
           	   system("cls");
           	   printf("\n\n\n\t\t"); color(0,14);printf(" Code: ");
           	   color(15,0);printf("\n\n\t\t\t\t\t");
           	   printf(" ___________________");
			   color(15,0);printf("\n\t\t\t\t\t");  printf("|///|///|///|///|///|");
			   color(15,0);printf("\n\t\t\t\t\t");
           	for (i=1;i<=5;i++)
			   {
           		 if(i==decision)
				   {
                      color(15,0);printf("|");  color(0,1);printf(" %d ",joueur1[decision-1]);
				   }
				 else
				{
	              color(15,0);printf("|");color(0,15);printf(" ? ");

				}
			   }
			      color(15,0); printf("|\n");printf("\t\t\t\t\t");  printf("|///|///|///|///|///|");
           	      color(15,0);printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t");color(0,7);printf(" >>SKIP   ");
           		  color(15,0);
           	      getch();
           	      system("cls");

           	       int numEssay = essay + 2;

           	      for (int i = essay; i <=numEssay ; i++)
                    {
                       for (int j = 0; j < 8; j++)
                       {
                      Game[i][j] = -1;
                       }
                      essay+=1;
                    }
           	      joker=1;
           	      color(15,0);
           	      Game_start(Game);
           	     break;
           	case '0':

           	      system("cls");
           		  Game_start(Game);
           		 break;

            default:
			     continue;
		   }

			 break;
		}
    while (1)
	{
		    color(3,0);
			printf("\n\n\t\t\t\t\\\\ ");color(0,3);   printf(" %s ",nomJoueur2);
		    color(3,0);	printf(" \\\\");
		    color(11,0);
		    afficherCaractereParCaractere("\n\t\t\t\t\t   -->Code: ");
		    verrifier(&codeG);
            Extraire(codeG, joueur2);
            RE=0;
         for (i = 0; i < 5; i++)
		 {
              for (j= i + 1; j < 5; j++)
			  {
                if (joueur2[i] == joueur2[j])
				 {
                     RE = 1;
                    break;
                 }
               }
            if (RE != 0)
			{
                break;
            }
         }
        if (RE != 0)
		{
		    system("cls");
            color(4, 0);
            afficherCaractereParCaractere("\n\t\t\t\t\t Error: Numbers must not repeat. Please try again.\n\n\t\t\t\t  ");
            color(8, 0);
          continue;
        }
        break;
    }
        Game[essay][0] = essay + 1;
        Game[essay][1] = joueur2[0];
        Game[essay][2] = joueur2[1];
        Game[essay][3] = joueur2[2];
        Game[essay][4] = joueur2[3];
        Game[essay][5] = joueur2[4];
    for (int i = 0; i < 5; i++)
	{
       if (Game[essay][i + 1] == joueur1[i]) {
        BP++;
    } else {
        for (int j = 0; j < 5; j++)
		{
            if (Game[essay][i + 1] == joueur1[j])
			{
                MP++;
                break;
            }
        }
           }
    }
          Game[essay][6] = BP; // Store BP in column 6
          Game[essay][7] = MP;

           printf("\n");

       if (BP == 5) {
    greatjob();

    FILE *file = fopen("score.txt", "a");
    if (file != NULL) {
        fprintf(file,"USERNAME: %s SCORE: %d\n", nomJoueur2, essay);
        fclose(file);
        printf("The score has been saved in the 'score.txt' file.\n");
    } else {
        printf("Error opening the file.\n");
    }

    // Assurez-vous que l'utilisation de "break" est appropriée dans votre contexte
    break;

}
		else
		{
        	    essay++;
        	    system("cls");
                Game_start(Game);
        }
    }          // Demander le code à chaque tentative
    	if (essay == 20)
	 {
      hardluck();
     }
	                                                                                                                // niveau 1
                break;
            }
			 else if (selectedOption1 == 1)
			{
			system("cls");
                //	Get usernames from players
			  printf("\n\n\n\n");  USERs(ply1); color(15, 0);scanf("%s", nomJoueur1);
			  printf("\n\n\n\n");  USERs(ply2); color(15, 0);scanf("%s", nomJoueur2);
			  system("cls");
			  toUpperCase(nomJoueur1);
			  toUpperCase(nomJoueur2);
			  color(0, 11);
			  printf("\n\t\t\t\t\t* Welcome to Level 2 with EL ACHRAF! *\n\n\n");
			  color(15,0);   afficherCaractereParCaractere("\n\n\n\t\tHello ");
			  color(0, 15); printf(" %s ",nomJoueur1),
			  color(15,0);afficherCaractereParCaractere(",\n\n\t\t\t\" You have the special task of creating a secret 5-digit code \"\n\n\t\t      ");
			  color(0, 15);  printf(" %s ",nomJoueur2); color(15,0);afficherCaractereParCaractere(",\n\n\t\t\t\" You have task of guessing it \"\n\n\t\t\t\t\t\t\t\tMAY THE BEST ONE WIN ;)");
			  color(0, 7);afficherCaractereParCaractere("\n\n\n\n\t\t\t\t\t\t GOOD LUCK!! \n\n\n\n\n\n\t\t\t\t\t");
			  color(0,14 );
			  color(15,0);printf("\n\t\t\t\t\t\t\t\t\t\t\t");color(0,7);printf(" >>SKIP   ");
			  color(3,0);
			  getch();
			  system("cls");
  	          printf("\n\n\n\n\n\n\n\n\t\t\t\t\\\\ ");
			  color(0,3);
			  printf(" %s ",nomJoueur1);
		      color(3,0);printf(" \\\\");
			  color(11,0);afficherCaractereParCaractere("\n\n\t\t\t\t\t   Please enter a 5-digit code: ");
			  verrifier(&codeS);
              Extraire(codeS, joueur1);
		      system("cls");
              printf("\n\n\n\t\t\t\t");
              color(0,14);
              afficherCaractereParCaractere(" ! Take the time to think and guess the secret code ! \n\n\t\t\t");
     	      color(15,0);printf("\n\t\t\t\t\t\t\t\t\t\t\t");color(0,7);printf(" >>SKIP   ");
              color(3,0);
              getch();
              system("cls");
              Game_0(Game);
              Game_start(Game);
		      int essay=0;
    while (essay < 20)
	{
        MP = 0;
        BP = 0;
                 //  Prompt for Code on Each Attempt
      while(essay==10)
	   {
      	    sleep(3);
      	    system("cls");
      	    cardj();
      	    break;
	   }
        while(essay>=10 && essay<=17 && joker==0)
		{
		  if(essay>10){
			           sleep(3);
	                  }
                       system("cls");
                       jokeer();
            switch(decision)
			{
           	case '1':
			   system("cls");
               color(15,0);printf("\n\n\n\n\t\t\t\t");color(14,0);printf(" Chose the digit you want: ");
               color(15,0); scanf("%d",&decision);
           	   system("cls");
           	   printf("\n\n\n\t\t"); color(0,14);printf(" Code: ");
           	   color(15,0);printf("\n\n\t\t\t\t\t");
           	   printf(" ___________________");
			   color(15,0);printf("\n\t\t\t\t\t");  printf("|///|///|///|///|///|");
			   color(15,0);printf("\n\t\t\t\t\t");
           	for (i=1;i<=5;i++)
			   {
           		 if(i==decision)
				   {
                      color(15,0);printf("|");  color(0,1);printf(" %d ",joueur1[decision-1]);
				   }
				 else
				{
	              color(15,0);printf("|");color(0,15);printf(" ? ");

				}
			   }
			      color(15,0); printf("|\n");printf("\t\t\t\t\t");  printf("|///|///|///|///|///|");
           	      color(15,0);printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t");color(0,7);printf(" >>SKIP   ");
           		  color(15,0);
           	      getch();
           	      system("cls");
           	      int numEssay = essay + 2;

           	      for (int i = essay; i <=numEssay ; i++)
                    {
                       for (int j = 0; j < 8; j++)
                       {
                      Game[i][j] = -1;
                       }
                      essay+=1;
                    }

           	      joker=1;
           	      color(15,0);
           	      Game_start(Game);
           	     break;
           	case '0':

           	      system("cls");
           		  Game_start(Game);
           		 break;

            default:
			     continue;
		   }

			 break;
		}
			color(3,0);
			printf("\n\n\t\t\t\t\\\\ ");color(0,3);   printf(" %s ",nomJoueur2);
		    color(3,0);	printf(" \\\\");
		    color(11,0);
				 afficherCaractereParCaractere("\n\t\t\t\t\t   -->Code: ");
	    	 verrifier(&codeG);
            Extraire(codeG, joueur2);
   for (int i = 0; i < 5; i++)
   {
      code_temp[i] = joueur1[i];
	}
               Game[essay][0] = essay + 1;
               Game[essay][1] = joueur2[0];
               Game[essay][2] = joueur2[1];
               Game[essay][3] = joueur2[2];
               Game[essay][4] = joueur2[3];
               Game[essay][5] = joueur2[4];
    for (int i = 0; i < 5; i++)
	{
       if (Game[essay][i + 1] == code_temp[i])
    {
        BP++;
        code_temp[i]=10;
    }
	else
	{
        for (int j = 0; j < 5; j++)
		{
            if (Game[essay][i + 1] == code_temp[j])
			{
                MP++;
                break;
            }
        }
     }
    }
          Game[essay][6] = BP; // Store BP in column 6
          Game[essay][7] = MP;

           printf("\n");

        if (BP==5)
		{
		        greatjob();
	       break;
        }
		else
		{
        	    essay++;
        	    system("cls");
                Game_start(Game);
        }
    }          // Demander le code à chaque tentative
    	if (essay == 20)
	 {
      hardluck();
     }
	                                                                                                                // niveau 1
                break;

                                  // niveau 2
			}
        }

}
                break;
            }
            else if (selectedOption == 1)
            {
            	system("cls");
                regles();
                switch(decision){
                	case '1':
                	continue;
					    break;
                	case '2':
                	exit(0);
				}
                break;
            }

        }
    }

 }
