/// @description Insert description here
// You can write your code in this editor
keyRight = keyboard_check(ord("D"));
keyUp = keyboard_check(ord("W"));
keyLeft = keyboard_check(ord("A"));
keyDown = keyboard_check(ord("S"));

//Calculate Speed based on Pixels/Second
var seconds_passed = delta_time/1000000;
var move_speed_this_frame = (speedCurrent*seconds_passed);

//Make sure Diagonal Movement Speed equals Hori/Verti Movement Speed
if moveX != 0 && moveY != 0
	{diag = 0.707;}
else 
	{diag = 1;}

//Calculating Movement based on Input
moveX = (keyRight - keyLeft) * (move_speed_this_frame) * (diag); 
moveY = (keyDown - keyUp) * (move_speed_this_frame) * (diag);

#region Collision Checks (This contains the code that makes Wall Glide possible)
// PLAYER MOVEMENT COLLISION
// Horizontal Collision

if (moveX != 0) {
	if (place_meeting(x+moveX, y, collision_solid)) 
	{repeat (abs(moveX)) 
		{if (!place_meeting(x+sign(moveX), y, collision_solid)) 
			{x += sign(moveX);} 
			else
			{
				for(var i = 0; i < 17; i++)
				{
					if moveY == 0
					{
						if !place_meeting(x+moveX,y+i,collision_solid)
						{
							y += sign(i) * move_speed_this_frame;
							break;
						}
						else if !place_meeting(x+moveX,y+-i,collision_solid)
						{
							y += sign(-i) * move_speed_this_frame;
							break;
						}
					}
				}
				break;
			}
		}
	moveX = 0;}}
	
//Vertical Collision
if (moveY != 0) {if (place_meeting(x, y+moveY, collision_solid))
	{repeat (abs(moveY)) 
		{if (!place_meeting(x, y+sign(moveY), collision_solid)) 
			{y += sign(moveY);} 
		else {
				for(var i = 0; i < 17; i++)
				{
					if moveX == 0
					{
						if !place_meeting(x+i,y+moveY,collision_solid)
						{
							x += sign(i) * move_speed_this_frame;
							break;
						}
						else if !place_meeting(x+-i,y+moveY,collision_solid)
						{
							x += sign(-i) * move_speed_this_frame;
							break;
						}
					}
				}
			break;
			}
		}
	moveY = 0;}}
	
#endregion

//Apply Speed
x += moveX;
y += moveY;

//Sprite Control
dir = change_dir(moveX,moveY,dir);
sprite_index = change_sprite(dir,sprRight,sprUp,sprLeft,sprDown);

if moveX == 0 && moveY == 0
{ image_speed = 0;}
else
{ image_speed = .5;}
