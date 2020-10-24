//Problem site : https://www.codewars.com/kata/59a96d71dbe3b06c0200009c
function generateShape(integer){
  let column = [];
  let string = '';
  for(let i=0;i<integer;i++){
    let row = '';
    for(let j=0;j<integer;j++){
      row += '+';
    }
    if(i !== integer-1){
      column.push(row+"\n")
    } else {
      column.push(row);
    }
  }
  let result = column.join('');
  return result;
}
