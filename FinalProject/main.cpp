#include<iostream>
#include<string.h>
#include<stdio.h>
#include "LibraryMap.h"
#include "Song.h"
#include "PlayListMap.h"
#include "UserInterFace.h"
    using namespace std;
    int main()
    {
//        //Hey there
//        char str[5][20], t[20];
//        int i, j;
//        cout<<"\n Enter Any Five Names : \n\n";
//        for(i=0; i<5; i++)
//        {
//            cout<<" ";
//            cin>>str[i];
//        }
//        for(i=1; i<5; i++)
//        {
//            for(j=1; j<5; j++)
//            {
//                if(strcmp(str[j-1], str[j])>0)
//                {
//                    strcpy(t, str[j-1]);
//                    strcpy(str[j-1], str[j]);
//                    strcpy(str[j], t);
//                }
//            }
//        }
//        cout<<"\n Names Sorted in Alphabetical Order : \n\n";
//        for(i=0; i<5; i++)
//        {
//            cout<<" ";
//            cout<<str[i]<<"\n";
//        }


    LibraryMap<Song>* library= new LibraryMap<Song>();
    Song song1=Song("Grateful Dead","Box of Rain",2);
    Song song2=Song("Genesis","That's All",2);
    Song song3=Song("Men At Work","Land Down Under", 2);
    Song song4=Song("Grateful Dead","Brown Eyed Women",4);

    library->put(song1);
    library->put(song2);
    library->put(song3);
    library->put(song4);
    //cout<<"\n Songs Sorted in Alphabetical Order by Artist : \n\n";
    std::cout<<library->display()<<std::endl;
    std::cout<<"--done--"<<std::endl;

        return 0;

}