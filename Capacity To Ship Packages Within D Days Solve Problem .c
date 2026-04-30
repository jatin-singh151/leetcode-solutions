bool canShip(int allowedWeight, int *weights, int wSize, int days) {
    int curWeight = 0; 
    // atleast we will take 1 day if we use maximum of all weights (left)
    int daysTaken = 1;
    for(int i = 0; i < wSize; i++) {
        curWeight += weights[i];
        if(curWeight > allowedWeight) {         // overloaded
            daysTaken ++;
            // Not allowed to take last weight. So reset current weight to 
            // this weight. But send the ship by including day
            // eg. if curWeight is 5 and allowed is 10, we can't include 6
            // because it will become 11. So ship with 5 and reset curWeight
            // to 6 for next day to ship
            curWeight = weights[i];
        }
    }
    return daysTaken <= days;
}

int shipWithinDays(int* weights, int weightsSize, int days){
    int left = INT_MIN, right = 0;
    // Initial search scope: maximum of all weights is left and 
    // the sum of all weights is right
    for(int i = 0; i < weightsSize; i++) {
        left = fmax(left, weights[i]);
        right += weights[i];
    }
    
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(canShip(mid, weights, weightsSize, days))
            right = mid;
        else
            left = mid + 1; 
    }
    return left;
}
