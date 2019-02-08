//this code is lining the create up with the black line
#include <kipr/botball.h>

//I'm createing A function
void find_the_line(int black,int curve,int speed);

int main()
{
    //I'm createing my vairiables  
    int black = 2700; 		
    int speed = 200;	
    int curve = 180;					

    create_connect();//I'm connecting to the create

    find_the_line(black,curve,speed);//I'm calling my function



    create_disconnect();//I'm disconnecting to the create

    return 0;

}
//I'm difineing my function
void find_the_line(int black,int curve,int speed)
{
    while ( get_create_rcliff_amt() >= black || get_create_lcliff_amt() >= black )//do the sensres see wight
    {
        if ( get_create_rcliff_amt() >= black && get_create_lcliff_amt() >= black )//do bullth the sensres see wight
        {
            create_drive(speed, curve);
            msleep(50);

            create_drive(speed, -curve);
            msleep(50);
        }
        else if ( black >= get_create_rcliff_amt() )//does the right sensres see black
        {
            create_drive(100, -50);//The create is trening left

        }

        else if ( black >= get_create_lcliff_amt() )//does the left sensres see black
        {
            create_drive(100, 50);//The create is trening right

        }

        else if( get_create_rcliff_amt() >= black && get_create_lcliff_amt() >= black)//do bullth the sensres see black
        {
            break; //this breaks the while loop            

        }
    }

}
