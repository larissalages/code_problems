/* https://leetcode.com/problems/koko-eating-bananas/ */

/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
const minEatingSpeed = (piles, h) => {
    let left = 0;
    let right = Math.max(...piles);
    let mid;
    let hoursToEat;

    while (left <= right) {
        mid = Math.floor((left + right) / 2);

        hoursToEat = piles.reduce((sum, pile) => {
            sum += Math.ceil(pile / mid)
            return sum
        }, 0);

        if (hoursToEat > h) {
            // too long, eat more per hour so go right
            left = mid + 1;
        }

        if (hoursToEat <= h) {
            right = mid - 1;
        }
    }

    return left;
};
