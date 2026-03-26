#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void instructions()
{
    printf("\n\n========== GAME INSTRUCTIONS ==========");

    printf("\n\n OBJECTIVE:");
    printf("\nReach a distance of 100 to complete the mission.");

    printf("\n\n YOUR RESOURCES:");
    printf("\nFuel   - Needed to move the ship");
    printf("\nOxygen - Needed to keep crew alive");
    printf("\nHealth - Overall crew condition");

    printf("\n\n HOW TO PLAY:");
    printf("\n -In each situation, choose option 1, 2, or 3.");
    printf("\n -Each choice affects your resources differently.");
    printf("\n -Good choices move you forward faster.");

    printf("\n\n LEVELS:");
    printf("\nLevel 1 - Easy problems");
    printf("\nLevel 2 - Dangerous situations");
    printf("\nLevel 3 - Critical emergencies");

    printf("\n\n WIN CONDITION:");
    printf("\nReach distance 100 with all resources above zero.");

    printf("\n\n YOU LOSE IF:");
    printf("\nFuel, Oxygen, or Health becomes zero.");

    printf("\n\n========================================\n");
}

void showResult(int fuel,int oxygen,int health,int distance)
{
    printf("\n\n========== FINAL REPORT ==========");

    printf("\n\nFinal Status:");
    printf("\nFuel Remaining    : %d", fuel);
    printf("\nOxygen Remaining  : %d", oxygen);
    printf("\nHealth Remaining  : %d", health);
    printf("\nDistance Covered  : %d", distance);

    printf("\n\n----------------------------------");

    if(distance>=100 && fuel>0 && oxygen>0 && health>0)
    {
        printf("\n===== MISSION SUCCESSFUL! ===== ");
        printf("\nYou safely reached Earth!");
    }
    else
    {
        printf("\n===== MISSION FAILED! =====");

        printf("\n\nReason of Failure:");

        if(fuel<=0)
            printf("\n- Fuel exhausted. Ship could not move.");

        if(oxygen<=0)
            printf("\n- Oxygen depleted. Life support failed.");

        if(health<=0)
            printf("\n- Health critical. Crew could not survive.");

        if(distance<100)
            printf("\n- Mission incomplete. Destination not reached.");
    }

    printf("\n\n==================================");
}


void applyEffects(int choice,int level,int *fuel,int *oxygen,int *health,int *distance)
{
    if(choice==1) // GOOD
    {
        *fuel -= 8*level;
        *oxygen -= 6*level;
        *health -= 5*level;
        *distance += 12;
    }
    else if(choice==2) // MEDIUM
    {
        *fuel -= 12*level;
        *oxygen -= 10*level;
        *health -= 8*level;
        *distance += 6;
    }
    else // BAD
    {
        *fuel -= 18*level;
        *oxygen -= 15*level;
        *health -= 12*level;
        *distance -= 6;
    }
}



void playGame()
{
    
    int fuel=100, oxygen=100, health=100, distance=0;
    int level=1, event, choice, lastEvent=0;
int prevLevel=1;   // to detect level upgrade


    srand(time(0));

    printf("\n----- Mission Started! -----\n");

    while(fuel>0 && oxygen>0 && health>0 && distance<100)
    {
        if(distance>=50 && distance<85) level=2;
        else if(distance>=85) level=3;

        // ===== LEVEL UP BONUS =====
     if(level > prevLevel)
     {
    printf("\n Congratulations! You got a Level-Up Bonus!");
    fuel += 20;
    oxygen += 10;
    health += 10;
    prevLevel = level;
    }



        printf("\n--------------------------------");
        printf("\nLevel:%d Fuel:%d Oxygen:%d Health:%d Distance:%d",
               level,fuel,oxygen,health,distance);

        do
    {
    event = rand()%8 + 1;
    } while(event == lastEvent);

lastEvent = event;


        // ================= LEVEL 1 (MILD PROBLEMS) =================
        if(level==1)
        {
         
           if(event==1) printf("\nFuel pipe dripping!\n1 Seal it\n2 Adjust flow\n3 Ignore\n");
            else if(event==2) printf("\nTiny asteroid ahead!\n1 Shield\n2 Slow\n3 Rush\n");
            else if(event==3) printf("\nOxygen alarm beeping!\n1 Check tank\n2 Breathe slow\n3 Ignore\n");
            else if(event==4) printf("\nLoose wire sparking!\n1 Fix\n2 Cut power\n3 Ignore\n");
            else if(event==5) printf("\nCabin temperature rising!\n1 Cool system\n2 Reduce power\n3 Ignore\n");
            else if(event==6) printf("\nStrange object floating!\n1 Capture it\n2 Scan it\n3 Ignore\n");

            else if(event==7) printf("\nFood running low!\n1 Eat meal\n2 Half meal\n3 Skip\n");
            else printf("\nStrange signal heard!\n1 Respond\n2 Scan\n3 Ignore\n");
        }

        // ================= LEVEL 2 (DANGEROUS PROBLEMS) =================
        else if(level==2)
        {
        
                if(event==1) printf("\nEngine overheating!\n1 Cool\n2 Slow\n3 Push\n");
            else if(event==2) printf("\nMeteor rain!\n1 Shield\n2 Dodge\n3 Rush\n");
            else if(event==3) printf("\nMajor oxygen leak!\n1 Seal\n2 Backup\n3 Ignore\n");
            else if(event==4) printf("\nRadiation burst!\n1 Suit\n2 Hide\n3 Ignore\n");
            else if(event==5) printf("\nNavigation failure!\n1 Manual\n2 Restart\n3 Blind fly\n");
            else if(event==6) printf("\nSpace debris hit!\n1 Shield\n2 Repair\n3 Ignore\n");
            else if(event==7) printf("\nCommunication lost!\n1 Fix antenna\n2 Wait\n3 Ignore\n");
            else printf("\nStrange alien wave!\n1 Block\n2 Study\n3 Ignore\n");
        }

        // ================= LEVEL 3 (CRITICAL DISASTERS) =================
        else
        {
    

    if(event==1) printf("\nCritical hull breach!\n1 Seal breach\n2 Divert power\n3 Ignore\n");
    else if(event==2) printf("\nMain engine explosion risk!\n1 Emergency shutdown\n2 Stabilize\n3 Ignore\n");
    else if(event==3) printf("\nOxygen chamber empty!\n1 Refill manually\n2 Use backup\n3 Ignore\n");
    else if(event==4) printf("\nNavigation system hacked!\n1 Override control\n2 Reset system\n3 Ignore\n");
    else if(event==5) printf("\nBlack hole gravity surge!\n1 Full thrust\n2 Adjust orbit\n3 Do nothing\n");
    else if(event==6) printf("\nLife support collapsing!\n1 Repair immediately\n2 Reduce usage\n3 Ignore\n");
    else if(event==7) printf("\nExtreme cosmic storm!\n1 Activate shields\n2 Escape fast\n3 Hide\n");
    else printf("\nReactor meltdown warning!\n1 Cool reactor\n2 Shutdown core\n3 Ignore\n");


        }
    // choice input from user
        scanf("%d",&choice);
        while(getchar()!='\n');
     // function calling
        applyEffects(choice,level,&fuel,&oxygen,&health,&distance);

        // Passive survival drain
          fuel -= 1;
          oxygen -= 1;
          


        if(fuel>100) fuel=100;
        if(oxygen>100) oxygen=100;
        if(health>100) health=100;
        if(distance<0) distance=0;
    }

    showResult(fuel,oxygen,health,distance);
}

int main()
{
    int choice;

    do
    {
        printf("\n\n===== SPACE MISSION GAME =====");
        printf("\n1 Start Mission");
        printf("\n2 Instructions");
        printf("\n3 Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        while(getchar()!='\n');

        switch(choice)
        {
        case 1: playGame(); break;
        case 2: instructions(); break;
        case 3: printf("\nGoodbye Commander!\n"); break;
        default: printf("\nInvalid choice!");
        }

    }while(choice!=3);

    return 0;
}