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

int pages[REFERENCE_STRING_SIZE];

int NUMBER_OF_FRAMES;

int LRU(){
    unordered_set<int> s;

    unordered_map<int, int> indexes;

    int page_faults = 0;
    for (int i = 0; i < REFERENCE_STRING_SIZE; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < NUMBER_OF_FRAMES)
        {
            // Insert it into set if not present
            // already which represents page fault
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);

                // increment page fault
                page_faults++;
            }

            // Store the recently used index of
            // each page
            indexes[pages[i]] = i;
        }

        // If the set is full then need to perform lru
        // i.e. remove the least recently used page
        // and insert the current page
        else
        {
            // Check if current page is not already
            // present in the set
            if (s.find(pages[i]) == s.end())
            {
                // Find the least recently used pages
                // that is present in the set
                int lru = INT_MAX, val;
                for (auto it=s.begin(); it!=s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }

                // Remove the indexes page
                s.erase(val);

                // insert the current page
                s.insert(pages[i]);

                // Increment page faults
                page_faults++;
            }

            // Update the current page index
            indexes[pages[i]] = i;
        }
    }

    return page_faults;
}

bool search(int key, vector<int>& fr){
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}

int predict(int pages[], vector<int>& frames, int index){
    int res = -1; 
    int farthest = index;
    for (int i = 0; i < frames.size(); i++) {
        int j;
        for (j = index; j < REFERENCE_STRING_SIZE; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        if (j == REFERENCE_STRING_SIZE)
            return i;
    }

    return (res == -1) ? 0 : res;
}

int OPTIMAL(){

    vector<int> frames;

    int hit = 0;
    for (int i = 0; i < REFERENCE_STRING_SIZE; i++) {

        if (search(pages[i], frames)) {
            hit++;
            continue;
        }

        if (frames.size() < NUMBER_OF_FRAMES)
            frames.push_back(pages[i]);

        else {
            int j = predict(pages, frames, i + 1);
            frames[j] = pages[i];
        }
    }
    return REFERENCE_STRING_SIZE - hit;
}

int FIFO()
{

    unordered_set<int> s;

    queue<int> indexes;

    int page_faults = 0;
    for (int i = 0; i < REFERENCE_STRING_SIZE; i++)
    {
        if (s.size() < NUMBER_OF_FRAMES)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }

        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }

    return page_faults;
}

int main(int argc, char *argv[]){


    for(int i = 0; i < RUN_COUNT; ++i){

        NUMBER_OF_FRAMES = rand() % FRAME_SIZE_RANGE + 1;

        cout<<"\n*************** TEST "<< i + 1 <<" ***************\n";

        cout<<"\nPage reference string:\n"<<endl;

        for(int j = 1; j <= REFERENCE_STRING_SIZE; ++j){
            pages[j-1] = rand() % PAGE_RANGE;
            cout<<pages[j-1]<<", ";
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

