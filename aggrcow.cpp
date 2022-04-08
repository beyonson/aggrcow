#include <iostream>

int main() {

    std::size_t cows, stalls; // number of stalls and cows and min
    std::cout << "enter number of cows: "; std::cin >> cows;
    std::cout << "enter number of stalls: "; std::cin >> stalls;

    if (cows > stalls) {
        std::cout << "too many cows!" << std::endl;
        return -1;
    }
    
    bool cowsfit = 0; // cows fit

    std::size_t *locs = new std::size_t[stalls];

    // getting locations
    //std::cout << "enter locations: \n";
    for (int i = 0; i < stalls; i++) 
        locs[i] = i;
    

    // bubble sorting the vector least to greatest
    for(int j = 0; j < stalls; j++) {
        for(int i = 0; i < stalls-1; i++) {
            if (locs[i] > locs[i+1]) {
                int temp = locs[i+1];
                locs[i+1] = locs[i];
                locs[i] = temp;
            }
        }
    }
   
    int best = (locs[0]+locs[stalls-1])/cows; // best case scenario

    while(!cowsfit) {
        int currStall = 0;
        int cowsLeft = cows-1;
        int min = best;
        best = min;

        for(int j = 0; j < stalls; j++) {   
            if(abs(locs[currStall]-locs[j]) >= best) {
               cowsLeft--;
               currStall = j;
            }

            if (cowsLeft == 0) {
                cowsfit = 1;
                break;
            }
        }

        min--;
    }

    std::cout<< "minimum space : " << best <<std::endl;

    return 0;
}