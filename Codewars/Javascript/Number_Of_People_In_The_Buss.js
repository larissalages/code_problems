//Problem site : https://www.codewars.com/kata/5648b12ce68d9daa6b000099
var number = function(busStops){
  let result = 0;
  busStops.map((a) => {
    result += a[0] - a[1];
  });
  return result;
  // Good Luck!
}
