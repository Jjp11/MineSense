#include <iostream>
#include <math.h>
using namespace std;
//public CSensor
class CSensor
{
	public: 
	
	//bool Calibrate();// calibrates the Sensor
 	bool Calibrate()
	{
		//assuming predefied code here...
		cout<<"Calibration started.... please wait..." <<endl;
		return true; //assuming return true for calibrated successfully..otherwise retrun false here..		
	}
	//void ReadData(int data[]);
	void ReadData(int data[])
	{
		//Assuming predefined code for reading data for sensor here;
		cout<< "Reading sensor data ..."<<endl;
//abcde...
	}
	//This function calculates average value of given sensor data....
	 float GetAvg(int val[],int size)
	 {
		 float average;
		 int i,total;
		 total =0;
		
		 for(i=0;i<size;i++)
		 { 
			 total =total+val[i];
		 }
			 average=float(total)/size;
			 
			 return average;
	 }
	
};

//Motor Class
//public CMotor
class CMotor
{
	public:
	//void ResetMotor();//Moves motor to the starting position
	
	void ResetMotor()
	{
		//Assuming predefined code for moving motor to starting position
		cout<<"Moving motor to starting position..."<<endl ;
	}
	
	//void MoveMotor(int distance);//moves motor to the measurement position
	void MoveMotor(int distance)
	{
		cout<<"Now moving motor to given position = " <<distance << endl;
	}
};

class DoorLatch
{
	public:
	 
	 /*value_latch function is used to read a value of door latch...it return true if door is closed 
	 * return false if door is opened*/
	 //Temporary assuming this function return true for sequential execution...
	 bool value_latch()
	 {
		 
		 cout<<"Now executing function to read value of door latch"<<endl;
		 return true; 
	 }
	 
};

int main()
{
	int data_1[]= {100,101,105,110,210,100,102,110,150,100};
	float value;
	CSensor sensor; 
	CMotor motor;
	DoorLatch latch;	
	if(sensor.Calibrate()==true)//Checks whether calibration done successfully or not....
	{
		sensor.ReadData(data_1); //Reading sensor data
		value=sensor.GetAvg(data_1,10);//Finding average for given data to move motor to specific position
		cout<<"Average ="<<value <<endl; //Printing average value 
		cout<<"round value ="<<round(value)<<endl; //printing round value of average 
		if(latch.value_latch() == true) //This function check whether door is closed 
		{
			motor.MoveMotor(round(value)); //If the door is closed the moves the motor to average value position after rounding it
		}
	}
	else //If the door is opened 
	{
		motor.ResetMotor(); //Moves motor to starting position
	}
	return 0;
}	
