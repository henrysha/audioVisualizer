//audio visualizer displaying amplitudes of each audio input
//Copyright (C) 2013 Seong Wook Ha

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

const int leftInputPin = A0, rightInputPin = A1; //input pin no.
const int leftOut[] = {0, 1, 2, 3, 4, 5}; //left output pin no.
const int rightOut[] = {6, 7, 8, 9, 10, 11}; //right output pin no.
const int pinNoMax = 6; // number of output pins
int leftInput = 0, rightInput = 0; //default value of input voltages
int leftAnalyzed = 0, rightAnalyzed= 0; //default value of analyzed

//TODO setup the pins into INPUT and OUTPUT
void setup()
{
  pinMode (leftInputPin, INPUT);
  pinMode (rightInputPin, INPUT);
  pinMode (leftOut[0], OUTPUT);
  pinMode (leftOut[1], OUTPUT);
  pinMode (leftOut[2], OUTPUT);
  pinMode (leftOut[3], OUTPUT);
  pinMode (leftOut[4], OUTPUT);
  pinMode (leftOut[5], OUTPUT);
  pinMode (rightOut[0], OUTPUT);
  pinMode (rightOut[1], OUTPUT);
  pinMode (rightOut[2], OUTPUT);
  pinMode (rightOut[3], OUTPUT);
  pinMode (rightOut[4], OUTPUT);
  pinMode (rightOut[5], OUTPUT);
}

//TODO execute the program
void loop()
{
  leftInput = analogRead (leftInputPin);
  rightInput = analogRead (rightInputPin);
  leftAnalyzed = analyze (leftInput);
  rightAnalyzed = analyze (rightInput);
  lightUp (leftAnalyzed, leftOut);
  lightUp (rightAnalyzed, rightOut);
}

/*
* TODO analyze the input into 6 ranges.
 * param input
 */
int analyze(int input)
{
  if (input >= 426)
    return 6;
  else if (input >= 341)
    return 5;
  else if (input >= 256)
    return 4;
  else if (input >= 170)
    return 3;
  else if (input >= 85)
    return 2;
  else if (input > 5)//greater than 5(5/1024) in order to reduce noises.
    return 1;
  else return 0;
}

/*
* TODO light up the corresponding LEDs
 * param input, output[]
 */
void lightUp(int input, const int output[])
{
  for (int i = 0; i < pinNoMax; i++)
  {
    if (i < input)
      digitalWrite (output[i], HIGH);
    else digitalWrite (output[i], LOW);
  }
}

