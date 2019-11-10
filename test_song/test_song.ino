//Store all note frequencies for each octave in a 2 dimensional array
double octaves[7][7] = 
 {  
  //Octave1 Notes:      c1      d1      e1      f1      g1      a1      b1
  /* 1st octave */   {32.703, 36.708, 41.203, 43.654, 48.990, 55.000, 61.735},
   
  //Octave2 Notes:      c2      d2      e2      f2      g2       a2       b2
  /* 2nd octave */   {65.406, 73.416, 82.407, 87.307, 97.999, 110.000, 123.470},
     
  //Octave3 Notes:       c3       d3       e3       f3       g3       a3       b3 
  /* 3rd octave */   {130.810, 146.830, 164.810, 174.610, 196.000, 220.000, 246.940},
      
  //Octave4 Notes:       c4       d4       e4       f4       g4       a4       b4
  /* 4th octave */   {261.630, 293.660, 329.630, 349.230, 392.000, 440.000, 493.880},
     
  //Octave5 Notes:       c5       d5       e5       f5       g5       a5       b5
  /* 5th octave */   {523.250, 587.330, 659.250, 698.460, 783.990, 880.000, 987.770},
   
  //Octave6 Notes:        c6        d6        e6        f6        g6        a6        b6  
  /* 6th octave */   {1046.500, 1174.700, 1318.500, 1396.900, 1568.000, 1760.000, 1979.500},
   
  //Octave7 Notes:        c7        d7        e7        f7        g7        a7        b7  
  /* 7th octave */   {2093.000, 2349.300, 2637.000, 2793.800, 3136.000, 3520.000, 3951.100}
 };


//Store the sharp note frequencies for each octave in a 2 dimensional array
double sharpOctaves[7][5] =
{
  //Octave1 Sharps:     C1      D1      F1      G1      A1 
  /* 1st octave */   {34.648, 38.891, 46.249, 51.913, 58.270},
  
  //Octave2 Sharps:     C2      D2      F2       G2       A2 
  /* 2nd octave */  {69.296, 77.782, 92.499, 103.830, 116.540},
  
  //Octave3 Sharps:      C3       D3       F3       G3       A3 
  /* 3rd octave */  {138.590, 155.560, 185.000, 207.650, 233.080},
  
  //Octave4 Sharps:      C4       D4       F4       G4       A4 
  /* 4th octave */  {227.180, 311.130, 369.990, 415.300, 466.160},

  //Octave5 Sharps:      C5       D5       F5       G5       A5 
  /* 5th octave */  {554.370, 622.250, 739.990, 830.610, 932.330},

  //Octave6 Sharps:       C6        D6        F6        G6        A6
  /* 6th octave */  {1108.700, 1244.500, 1480.000, 1661.200, 1864.700},

  //Octave7 Sharps:       C7        D7        F7        G7        A7 
  /* 7th octave */  {2217.500, 2489.000, 2960.000, 3322.400, 3729.300}
};

int buzzerPin = 9;
int led1 = 5;
int led2 = 6;
int led3 = 10;
int led4 = 11;
int led5 = 12;
void setup()
{
  pinMode(buzzerPin,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  
  // the tempo is 100 whole notes per minute
  int tempo = 100; 

  //the typical length notes in the song are quarter notes
  double typicalNoteLength = 0.25; 

  //store the modified note lengths for the song
  double newNoteLength[ ] = {0.0167, 0.3333};

  String fullMelody[ ] =
  {
    "e5!0-=e5-=e5   -=c5e5-=  g5-=-=-= g4-=-=-=",
    "c5-=-=g4 -=-=e4-= -=a4-=b4 -=A4a4-=",
    "!1g4!1e5!1g5 a5-=f5g5 -=e5-=c5 d5b4-=-=",
    "c5-=-=g4 -=-=e4-= -=a4-=b4 -=A4a4-=",
    "!1g4!1e5!1g5 a5-=f5g5 -=e5-=c5 d5b4-=-=",
    "-=-=g5F5 f5D5-=e5 -=G4a4c5 -=a4c5d5",
    "-=-=g5F5 f5D5-=e5 -=c6-=c6 c6-=-=-=",
    "-=-=g5F5 f5D5-=e5 -=G4a4c5 -=a4c5d5",
    "-=-=D5-= -=d5-=-= c5-=-=-= -=-=-=-=",
    "-=-=g5F5 f5D5-=e5 -=G4a4c5 -=a4c5d5",
    "-=-=g5F5 f5D5-=e5 -=c6-=c6 c6-=-=-=",
    "-=-=g5F5 f5D5-=e5 -=G4a4c5 -=a4c5d5",
    "-=-=D5-= -=d5-=-= c5-=-=-= -=-=-=-=",
    "c5c5-=c5 -=c5d5-= e5c5-=a4 g4-=-=-=",
    "c5c5-=c5 -=c5d5e5 -=-=-=-= -=-=-=-=",
    "c5c5-=c5 -=c5d5-= e5c5-=a4 g4-=-=-=",
    "e5e5-=e5 -=c5e5-= g5-=-=-= g4-=-=-=",
    "c5-=-=g4 -=-=e4-= -=a4-=b4 -=A4a4-=",
    "!1g4!1e5!1g5 a5-=f5g5 -=e5-=c5 d5b4-=-=",
    "c5-=-=g4 -=-=e4-= -=a4-=b4 -=A4a4-=",
    "!1g4!1e5!1g5 a5-=f5g5 -=e5-=c5 d5b4-=-=",
    "e5c5-=g4 -=-=G4-= a4f5-=f5 a4-=-=-=",
    "!1b4!1a5!1a5 !1a5!1g5!1f5 e5c5-=a4 g4-=-=-=",
    "e5c5-=g4 -=-=G4-= a4f5-=f5 a4-=-=-=",
    "b4f5-=f5 !1f5!1e5!1d5 c5e4-=e4 c4-=-=-="
  };
  /*calculate the number of lines in melody array
    THIS MUST BE DONE IN SAME SCOPE AS ARRAY DEFENITON*/
  int numLines = sizeof(fullMelody)/sizeof(fullMelody[0]);

  printf("testing line");
  playMelody(fullMelody, typicalNoteLength, tempo, newNoteLength, numLines);
  
}

void playMelody(String song[ ], double typicalNoteLength, int tempo, double newNoteLength[ ], int numLines)
{
    //Loop through and play each line of song
    for(int i = 0; i < numLines; i++)
    {
      playLine(song[i], typicalNoteLength, tempo, newNoteLength);
    }
}

void playLine(String songLine, double typicalNoteLength, int tempo, double newNoteLength[])
{
  //remove spaces from song
  String lineNotes = removeWhiteSpace(songLine);
  for( int i = 0; i < lineNotes.length(); i+=2)
  {
      //get the current note to be played
      char noteLetter = lineNotes[i];
      //get octave number of note to be played
      char noteNum = lineNotes[i+1];
      //convert noteDigit from char to int so it can be used as an  array index
      int noteOctaveNum = charToDigit(noteNum);
      //declare noteLengthMs before if statement
      int noteLengthMs;
      
      //Check to see if the typical note length or a modified note length should be used to play the next note
      if(noteLetter == '!')//use modified note length 
      {
      //Calculate the notes length in milliseconds (for modified note lengths)
      noteLengthMs = noteLengthToMs(newNoteLength[noteOctaveNum], tempo);

      i+=2;//increment index to grab the note following the "!0" length modifier
      noteLetter = lineNotes[i]; 

      //get octave number of note to be played after "!0" length modifier
      noteNum = lineNotes[i+1];
      //convert noteDigit from char to int so it can be used as an  array index
      noteOctaveNum = charToDigit(noteNum);

      }
      else//use typical note length 
      {
      //Calculate the notes length in milliseconds (for typical note lengths)
      noteLengthMs = noteLengthToMs(typicalNoteLength, tempo);
      }
      playNote(noteLetter, noteOctaveNum ,noteLengthMs);
   }
}
String removeWhiteSpace(String input)
{
  String temp = "";
  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] != ' ')
    {
    temp = temp+input[i];
    }
  }
  return temp;
}

int charToDigit(char character)
{
  return character - '0';
}

/*Converts tempo based note length (full note, 1/2 note, 1/4 note, ect..) 
to the notes play length in milliseconds*/
int noteLengthToMs(double noteLen ,int tempo)
{ 
  //Convert tempo from notes per minute to notes per second
  double notesPerSecond = tempo/60.0;

  //Calculate the length of one whole note in milliseconds
  int wholeNoteMs = 1000/notesPerSecond;
  
  //Calculate the length of note (whole, 1/2, 1/4 ect) in milliseconds
  return wholeNoteMs*noteLen;
}
void playNote(char note, int noteOctaveNum ,int noteLengthMs)
{ 
  int noteFreqIndex;
  int octaveIndex;
  double freq;
  if(note == '-')
  {
    //Play nothing
    delay(noteLengthMs);
  }
  else if(isupper(note))
  {
    //Convert the sharp note letter to an array index
    noteFreqIndex = sharpToIndex(note);

    //Convert octave number to an array index
    octaveIndex = noteOctaveNum - 1;
    
    //Use indices to retrieve  corresponding frequency from the array
    freq = sharpOctaves[octaveIndex][noteFreqIndex];
    playFreq(buzzerPin, freq, noteLengthMs);
  }
  else
  {
    //Convert the note letter to an array index
    noteFreqIndex = noteToIndex(note);

    //Convert octave number to an array index
    octaveIndex = noteOctaveNum - 1;
    
    //Obtain note frequency
    freq = octaves[octaveIndex][noteFreqIndex]; 
    playFreq(buzzerPin, freq, noteLengthMs); 
  }
}

int sharpToIndex(char note)
{
  switch(note)
  {
    case 'C':
      return 0;
      break; 
    case 'D':
      return 1;
      break; 
    case 'F':
      return 2;
      break; 
    case 'G':
      return 3;
      break; 
    case 'A':
      return 4;
      break; 
    default:
    //Plays a error tone if none of the note letters match
    playFreq(buzzerPin, 6000, 225); 
  }
}
int noteToIndex(char note)
{
  switch(note)
  {
    case 'c':
      return 0;
      break; 
    case 'd':
      return 1;
      break; 
    case 'e':
      return 2;
      break;
    case 'f':
      return 3;
      break;
    case 'g':
      return 4;
      break;
    case 'a':
      return 5;
      break;
    case 'b':
      return 6;
      break;
    default:
      //Plays a error tone if none of the note letters match
      playFreq(buzzerPin, 6000, 225); 
  }
}


void playFreq(int buzzerPin, double freqHz, int durationMs)
{
    //Calculate the period in microseconds
    int periodMicro = int((1/freqHz)*1000000);
    int halfPeriod = periodMicro/2;

    //store start time
    int startTime = millis();
    //(millis() - startTime) is elapsed play time
    while ((millis() - startTime) < durationMs)
    {
        digitalWrite(buzzerPin, HIGH);
        //PORTA |= (1 << PORTA1);
        delayMicroseconds(halfPeriod);
        digitalWrite(buzzerPin, LOW);
        //PORTA &= ~(1 << PORTA1);
        delayMicroseconds(halfPeriod);
    }
}

void loop() 
{
}
