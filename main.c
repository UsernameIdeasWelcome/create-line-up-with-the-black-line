//This code whas made by Jacob brown 2/8/2019.
//This code is lining the create up with the black line.
//John Stearman 2/14/2019.

#include <kipr/botball.h>

//I'm creating A function.
void find_the_line(int black,int curve,int speed);

int main()
{
    //I'm creating my vairiables.
    int black = 2700; 		
    int speed = 200;	
    int curve = 180;					

    create_connect();//I'm connecting to the create.

    find_the_line(black,curve,speed);//I'm calling my function.



    create_disconnect();//I'm disconnecting to the create.

    return 0;

}
//I'm defining my function.
void find_the_line(int black,int curve,int speed)
{
    while ( get_create_rcliff_amt() >= black || get_create_lcliff_amt() >= black )//Do the sensers see white?
    {
        if ( get_create_rcliff_amt() >= black && get_create_lcliff_amt() >= black )//Do both the sensers see white?
        {
            create_drive(speed, curve);
            msleep(50);

            create_drive(speed, -curve);
            msleep(50);
        }
        else if ( black >= get_create_rcliff_amt() )//Does the right sensers see black?
        {
            create_drive(100, -50);//The create is turning left.

        }

        else if ( black >= get_create_lcliff_amt() )//Does the left sensers see black?
        {
            create_drive(100, 50);//The create is turning right.

        }

        else if( get_create_rcliff_amt() >= black && get_create_lcliff_amt() >= black)//Do both the sensers see black?
        {
            break; //This breaks the while loop.       

        }
    }

}
