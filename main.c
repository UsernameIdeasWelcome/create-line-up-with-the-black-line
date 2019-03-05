<<<<<<< patch-1
//this code is lining the create up with the black line[Riley 2/14/2019]
//This code whas made by Jacob brown 2/8/2019.
//This code is lining the create up with the black line.
//John Stearman 2/14/2019.
// Added this line on 3/5/19 for the pull request that's required on period 3 documentation.
>>>>>>> master
#include <kipr/botball.h>

//I'm creating a function
void find_the_line(int black,int curve,int speed);

int main()
{
    //I'm creating my vairiables  
    int black = 2700; 		
    int speed = 200;	
    int curve = 180;					

    create_connect();//I'm connecting to the create

    find_the_line(black,curve,speed);//I'm calling my function

    create_disconnect();//I'm disconnecting from the create

    return 0;

}
//I'm defining my function
void find_the_line(int black,int curve,int speed)
{
    while ( get_create_rcliff_amt() >= black || get_create_lcliff_amt() >= black )//do either of the sensors see white
    {
        if ( get_create_rcliff_amt() >= black && get_create_lcliff_amt() >= black )//do both the sensors see white
        {
            create_drive(speed, curve);
            msleep(50);

            create_drive(speed, -curve);
            msleep(50);
        }
        else if ( black >= get_create_rcliff_amt() )//does the right sensor see black
        {
            create_drive(100, -50);//The create is turning left

        }

        else if ( black >= get_create_lcliff_amt() )//does the left sensor see black
        {
            create_drive(100, 50);//The create is turning right

        }

        else if( get_create_rcliff_amt() >= black && get_create_lcliff_amt() >= black)//do both the sensors see black
        {
            break; //this breaks the while loop            

        }
    }

}
