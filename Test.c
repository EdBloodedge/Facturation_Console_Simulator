#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
 
#define K 0//This frequency is 0, it is not ringing, as an empty shot 
 
//All the following symbols representing notes come from the label of fl studio 14's fl keys, which may be different from the label of a general piano. 
//There are only three octave pitch frequencies, because the frequencies that the average human voice can reach will probably fall in these 
#define C4 523
#define C#4 554
#define D4 588
#define D#4 623
#define E4 660
#define F4 700
#define F#4 742
#define G4 786
#define G#4 833
#define A4 884
#define A#4 936
#define B4 992
 
#define C5 1046
#define C#5 1108
#define D5 1176
#define D#5 1246
#define E5 1320
#define F5 1400
#define F#5 1484
#define G5 1572
#define G#5 1666
#define A5 1768
#define A#5 1872
#define B5 1984
 
#define C6 2092
#define C#6 2216
#define D6 2352
#define D#6 2492
#define E6 2640
#define F6 2800
#define F#6 2968
#define G6 3144
#define G#6 3332
#define A6 3536
#define A#6 3744
#define B6 3968
#define P 125   //Converted to bpm==120, the original bpm is 105, here is an approximate value 
 
typedef struct
{
	int frequency;
	int duration;
}PU;
	//The following score is just a paragraph from "Good Socialism" 
PU t[]={B5,1,B5,2,B5,1,D6,2,B5,5,A5,2,G5,1,E5,2,G5,1,A5,2,B5,2,K,5,B5,1,B5,2,B5,1,D6,2,E6,4,D6,3,E5,1
,E5,2,E5,1,G5,2,A5,2,K,5,B5,3,A5,1,G5,3,G5,2,E5,1,D5,3,B5,2,D6,1,B5,2,A5,1,G5,2,A5,1,G5,2,A5,2,B5,3,E5,
3,G5,1,D5,2,K,5,B5,2,D6,1,B5,1,D6,2,E6,3,E6,2,D6,1,E6,5,B5,2,A5,3,B5,1,E6,3,D6,3,B5,3,A5,3,K,1,E6,2,D6,
1,B5,2,A5,1,G5,4,K,3,E6,2,D6,1,B5,2,A5,1,G5,4,};
int main()
{
    int i;
    //The length of the structure array sizeof(t)/sizeof(PU) is obtained, the total structure array size / the size of a single structure
    for (i=0; i<sizeof(t)/sizeof(PU); i++){
        Beep(t[i].frequency,t[i].duration*P);}

}
