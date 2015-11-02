import processing.serial.*;


Serial myPort;
int val = 1; 
int directionX =1;
int directionY =0;
float x=400;
float y=400;
float speed =1;
int incomingByte;


void setup(){
size(800,800);
background(255);
smooth();
frameRate(60);
  String portName = Serial.list()[10]; 
  myPort = new Serial(this, portName, 9600); 

}

void draw()
{
   x=x+speed*directionX;
  y=y+speed*directionY; 
    move();

  // check boundaries
  if ((x>width) || (x<0))
  {   
    directionX=-1;
  }
  if ((y>height) || (y<0))
  {   
    directionY=-1;
}

 
  if( val >=1){

    stroke(0);
  fill(255);
  ellipse(x, y, val, val);
    
 }
  //will make the lowest value 1 instead of 0
  else if (val == 0){
   val=1; 
   stroke(0);
   fill(255);
  ellipse(x, y, val, val);
 }
      
  noStroke();
  fill(255,255,255);
rect(375,height-40,60,20);
  // Prints inches
  fill(0);
  text(val + " inches", 375, height - 25);

}


void move(){
  incomingByte = myPort.read();
    if (incomingByte == 'L') {
      directionX=-1;
      directionY=0;
    } 
    else if (incomingByte == 'R') {
      directionX=1;
      directionY=0;
    }
    
    else if(incomingByte == 'U') {
      directionY=-1;
      directionX=0;
      
    }
    else if( incomingByte == 'D') {
      directionY=1;
      directionX=0;
      
    }
    else if( incomingByte == 'F') {
      directionY=0;
      directionX=0;
      
    }


}

void keyPressed()
{
  if (key == CODED)
  {
    
    if (keyCode == LEFT )
    {
      //if (directionX>0) { 
      directionX=-1;
      directionY=0;
      //}
    }
    else if (keyCode == RIGHT)
    {
      //if (directionX<0) {  
      directionX=1;
      directionY=0;
      //}
    }
    else if (keyCode == UP)
    {
      //if (directionY<0) {
      directionY=-1;
      directionX=0;
      //}
    }
    else if (keyCode == DOWN)
    {
      //if (directionY<0) { 
      directionY=1;
      directionX=0;
      //}
    }
  }
    erase();

}

void erase(){
  
 if(key == ' ')
  {
   background(255,255,255);
   
  } 
}
// When we hear something from the serial port
void serialEvent(Serial myPort)
{
  // Read the data until the new line character
  String data = myPort.readStringUntil(10);

  // If data exists
  if(data != null)
  {
    // Convert String into an integer
    val = int(trim(data));
    println(data);
  }

}


