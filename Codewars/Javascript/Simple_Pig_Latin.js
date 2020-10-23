//Problem site : https://www.codewars.com/kata/520b9d2ad5c005041100000f
function pigIt(str) {
    let lol = str.split(' ');
    let result2 = [];
    let pop = '';
    for (let i = 0; i < lol.length; i++) {
        if (lol[i] === "?" || lol[i] === "!") {
            pop = lol.pop();
        }
    }

    lol.map((x) => {
        let result = x.split('');
        result.push(result.shift());
        let lolski = result.join('') + 'ay';
        result2.push(lolski);
    })
    if (pop === '') {
        return result2.join(' ');
    } else {
        return result2.join(' ') + " " + pop;
    }
}
