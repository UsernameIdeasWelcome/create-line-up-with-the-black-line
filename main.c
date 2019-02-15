//this code is lining the create up with the black line
//Ryan Sizemore, 2/14
#include <kipr/botball.h>

//I'm creating A function
void find_the_line(int black,int curve,int speed);

int main()
{
    //I'm creating my variables  
    int black = 2700; 		
    int speed = 200;	
    int curve = 180;					

    create_connect();//I'm connecting to the create

    find_the_line(black,curve,speed);//I'm calling my function



    create_disconnect();//I'm disconnecting to the create

    return 0;

}
//I'm defining my function
void find_the_line(int black,int curve,int speed)
{
    while ( get_create_rcliff_amt() >= black || get_create_lcliff_amt() >= black )//do the sensors see white
    {
        if ( get_create_rcliff_amt() >= black && get_create_lcliff_amt() >= black )//do both the sensors see white
        {
            create_drive(speed, curve);
            msleep(50);

            create_drive(speed, -curve);
            msleep(50);
        }
        else if ( black >= get_create_rcliff_amt() )//does the right sensors see black
        {
            create_drive(100, -50);//The create is turning left

        }

        else if ( black >= get_create_lcliff_amt() )//does the left sensors see black
        {
            create_drive(100, 50);//The create is turning right

        }

        else if( get_create_rcliff_amt() >= black && get_create_lcliff_amt() >= black)//do both the sensers see black
        {
            break; //this breaks the while loop            

        }
    }

}
