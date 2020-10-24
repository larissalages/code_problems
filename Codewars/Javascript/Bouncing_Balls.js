//Problem link : https://www.codewars.com/kata/5544c7a5cb454edb3c000047
function bouncingBall(h,  bounce,  window) {
  let n = 0;
  if(h > 0 && window < h && bounce > 0 && bounce < 1){
    while(h > window){
      h = h * bounce;
      n++;
    }
    return n*2-1;
  }else {
    return -1;
  }
}
