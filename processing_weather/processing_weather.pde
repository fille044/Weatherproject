import processing.serial.*;
Serial mySerial;
PrintWriter output;
void setup() {
  size(720,700);
  background(255);
  mySerial = new Serial(this, "COM5", 1200);
  output = createWriter( "data.txt" );
}
void draw() {
  if (mySerial.available() > 0 ) {
    String value = mySerial.readString();
    if ( value != null ) {
      fill(50);
      text(value,10,10,700,700);
      output.println("hehehehe");
      saveStrings("data.txt", value);
    }
  }
}

void keyPressed() {
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  exit(); // Stops the program
}