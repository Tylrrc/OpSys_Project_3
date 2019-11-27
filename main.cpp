#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <bits/stdc++.h>
#include <random>
#include <iostream>
#include <vector>

using namespace std;

#define PAGE_RANGE 50
#define REFERENCE_STRING_SIZE 100
#define FRAME_SIZE_RANGE 30
#define RUN_COUNT 10

int PAGES[REFERENCE_STRING_SIZE];

int NUMBER_OF_FRAMES;

/*
*   Function: LRU
*   ------------------------------------------------------
*   Description: Calculates the number of page faults that 
*       occur during the execution of the Least Recently 
*       Used (LRU) page replacement algorithm.
*   Pre: PAGES array must be populated with 100 random 
*       values ranging between 0 and 49
*   @param - None
*   @return - Number of page faults (misses)
*/
int LRU(){
    
    unordered_set<int> current_pages;
    unordered_map<int, int> indexes;

    int page_faults = 0;
    for (int i = 0; i < REFERENCE_STRING_SIZE; ++i)
    {
        if (current_pages.size() < NUMBER_OF_FRAMES)
        {
            if (current_pages.find(PAGES[i]) == current_pages.end())
            {
                current_pages.insert(PAGES[i]);
                page_faults++;
            }
            indexes[PAGES[i]] = i;
        }
        else
        {
            if (current_pages.find(PAGES[i]) == current_pages.end())
            {
                int LEAST_RECENTLY_USED = 1000000, val;
                for (auto it=current_pages.begin(); it!=current_pages.end(); ++it)
                {
                    if (indexes[*it] < LEAST_RECENTLY_USED)
                    {
                        LEAST_RECENTLY_USED = indexes[*it];
                        val = *it;
                    }
                }

                current_pages.erase(val);
                current_pages.insert(PAGES[i]);

                page_faults++;
            }
            indexes[PAGES[i]] = i;
        }
    }

    return page_faults;
}

/*
*   Function: search
*   ------------------------------------------------------
*   Description: Performs a linear search of the frames 
*       vector to find a match. If a match is found, then 
*       the page exists in the frame.
*   @param -
*       page - page to be found in the frame
*       frames - set of frames to be searched
*   @return - true if a match is found, otherwise false
*/
bool search(int page, vector<int>& frames){

    for (int i = 0; i < frames.size(); ++i)
        if (frames[i] == page) return true;

    return false;
}

/*
*   Function: predict
*   ------------------------------------------------------
*   Description: Finds which frame will not be used
*       in the near future
*   @param -
*       frames - set of frames to be searched
*       index - index of pages that will be used in the near 
*           future
*   @return - if no frames are found in the future, return 0, 
*       otherwise return the page to be replaced
*/
int predict(int index, vector<int>& frames){

    int temp = -1; 
    int farthest = index;
    for (int i = 0; i < frames.size(); ++i) {
        int j;
        for (j = index; j < REFERENCE_STRING_SIZE; ++j) {
            if (frames[i] == PAGES[j]) {
                if (j > farthest) { farthest = j; temp = i; }
                break;
            }
        }
        if (j == REFERENCE_STRING_SIZE) return i;
    }

    return (temp == -1) ? 0 : temp;
}

/*
*   Function: OPTIMAL
*   ------------------------------------------------------
*   Description: Calculates the number of page faults that 
*       occur during the execution of the Optimal 
*       page replacement algorithm.
*   Pre: PAGES array must be populated with 100 random 
*       values ranging between 0 and 49
*   @param - None
*   @return - Number of page faults (misses)
*/
int OPTIMAL(){

    vector<int> frames;

    int hit = 0;
    for (int i = 0; i < REFERENCE_STRING_SIZE; ++i) {

        if (search(PAGES[i], frames)) { hit++; continue; }

        if (frames.size() < NUMBER_OF_FRAMES) frames.push_back(PAGES[i]);

        else frames[predict(i + 1, frames)] = PAGES[i];
    }

    return REFERENCE_STRING_SIZE - hit;
}

/*
*   Function: FIFO  
*   ------------------------------------------------------
*   Description: Calculates the number of page faults that 
*       occur during the execution of the First In First 
*       Out (FIFO) page replacement algorithm.
*   Pre: PAGES array must be populated with 100 random 
*       values ranging between 0 and 49
*   @param - None
*   @return - Number of page faults (misses)
*/
int FIFO(){

    unordered_set<int>current_pages;
    queue<int> indexes;

    int page_faults = 0;
    for (int i = 0; i < REFERENCE_STRING_SIZE; ++i)
    {
        if (current_pages.size() < NUMBER_OF_FRAMES)
        {
            if (current_pages.find(PAGES[i]) == current_pages.end())
            {
                current_pages.insert(PAGES[i]);
                page_faults++;
                indexes.push(PAGES[i]);
            }
        }
        else
        {
            if (current_pages.find(PAGES[i]) == current_pages.end())
            {
                int val = indexes.front();
                indexes.pop();
                current_pages.erase(val);
                current_pages.insert(PAGES[i]);
                indexes.push(PAGES[i]);
                page_faults++;
            }
        }
    }
    return page_faults;
}

int main(){

    for(int i = 0; i < RUN_COUNT; ++i){

        NUMBER_OF_FRAMES = rand() % FRAME_SIZE_RANGE + 1;

        cout<<"\n*************** TEST "<< i + 1 <<" ***************\n";

        cout<<"\nPage reference string:\n"<<endl;

        for(int j = 1; j <= REFERENCE_STRING_SIZE; ++j){
            PAGES[j-1] = rand() % PAGE_RANGE;
            cout<<PAGES[j-1]<<" ";
            if (j % 20 == 0) cout<<"\n";
        }

        cout<<"\n\nNumber of page frames:\t"<<NUMBER_OF_FRAMES<<endl;

        cout<<"\nPage fault count: \n\n";

        cout<<"\tFIFO:\t\t"<<FIFO()<<endl;

        cout<<"\tLRU:\t\t"<<LRU()<<endl;

        cout<<"\tOPTIMAL:\t"<<OPTIMAL()<<endl<<endl;

    }

    return 0;
}

