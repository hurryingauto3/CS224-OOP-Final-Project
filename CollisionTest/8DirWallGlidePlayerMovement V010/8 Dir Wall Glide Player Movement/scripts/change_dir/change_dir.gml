///@function change_dir(moveX,moveY,dir)
///@argument moveX
///@argument moveY
///@argument dir

//Initialize Variables
var _moveX, _moveY, _dir;
_moveX = argument0;
_moveY = argument1;
_dir = argument2;

//If keyRight is pressed down
if _moveX > 0
{
	//Change Direction to 0(Right)
	_dir = 0;
}
//If keyUp is pressed down
else if _moveY < 0
{
	//Change Direction to 90(Up)
	_dir = 90;
}
//If keyLeft is pressed down
else if _moveX < 0
{
	//Change Direction to 180(Left)
	_dir = 180;
}
//If keyDown is pressed down
else if _moveY > 0
{
	//Change Direction to 270(Down)
	_dir = 270;
}

return(_dir);